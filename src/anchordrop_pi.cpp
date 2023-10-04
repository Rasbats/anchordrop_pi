/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  SAR Plugin
 * Author:   SaltyPaws
 *
 ***************************************************************************
 *   Copyright (C) 2012 by Brazil BrokeTail                                *
 *   $EMAIL$                                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include "anchordrop_pi.h"

// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new anchordrop_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}

//---------------------------------------------------------------------------------------------------------
//
//    Calculator PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

anchordrop_pi::anchordrop_pi(void *ppimgr)
      :opencpn_plugin_116(ppimgr)
{
    // Create the PlugIn icons
    initialize_images();

	wxFileName fn;
	

	auto path = GetPluginDataDir("sar_pi");
	fn.SetPath(path);
	fn.AppendDir(_T("data"));
	fn.SetFullName("sar_panel_icon.png");
	  
    path = fn.GetFullPath();

    wxInitAllImageHandlers();

    wxLogDebug(wxString("Using icon path: ") + path);
    if (!wxImage::CanRead(path)) {
        wxLogDebug("Initiating image handlers.");
        wxInitAllImageHandlers();
    }
    wxImage panelIcon(path);
    if (panelIcon.IsOk())
        m_panelBitmap = wxBitmap(panelIcon);
    else
		wxLogWarning(_("SAR panel icon has NOT been loaded"));

	m_bShowSAR = false;
}

int anchordrop_pi::Init(void)
{
      AddLocaleCatalog(_T("opencpn-sar_pi"));

      // Set some default private member parameters
      m_route_dialog_x = 0;
      m_route_dialog_y = 0;
      ::wxDisplaySize(&m_display_width, &m_display_height);

      //    Get a pointer to the opencpn display canvas, to use as a parent for the POI Manager dialog
      m_parent_window = GetOCPNCanvasWindow();

      //    Get a pointer to the opencpn configuration object
      m_pconfig = GetOCPNConfigObject();

      //    And load the configuration items
      LoadConfig();

      //    This PlugIn needs a toolbar icon, so request its insertion
#ifdef PLUGIN_USE_SVG
	  m_leftclick_tool_id = InsertPlugInToolSVG("SAR", _svg_sar, _svg_sar, _svg_sar_toggled,
		  wxITEM_CHECK, _("SAR"), "", NULL, CALCULATOR_TOOL_POSITION, 0, this);
#else
      m_leftclick_tool_id  = InsertPlugInTool(_T(""), _img_rescue, _img_rescue, wxITEM_NORMAL,
            _("SAR"), _T(""), NULL,
             CALCULATOR_TOOL_POSITION, 0, this);
#endif

	  

	  wxMenu dummy_menu;
	  m_position_menu_id = AddCanvasContextMenuItem

	  (new wxMenuItem(&dummy_menu, -1, _("Select SAR Datum Point")), this);
	  SetCanvasContextMenuItemViz(m_position_menu_id, false);

      m_pDialog = NULL;

      return (WANTS_CURSOR_LATLON      |
              WANTS_TOOLBAR_CALLBACK    |
              INSTALLS_TOOLBAR_TOOL     |
              WANTS_NMEA_EVENTS         |
              WANTS_PREFERENCES         |
              WANTS_CONFIG
           );
}

bool anchordrop_pi::DeInit(void)
{
      //    Record the dialog position
      if (NULL != m_pDialog)
      {
		  

		  //Capture dialog position
            wxPoint p = m_pDialog->GetPosition();
            SetCalculatorDialogX(p.x);
            SetCalculatorDialogY(p.y);
            m_pDialog->Close();
            delete m_pDialog;
            m_pDialog = NULL;

			m_bShowSAR = false;
			SetToolbarItemState(m_leftclick_tool_id, m_bShowSAR);
      }
      SaveConfig();

      return true;
}

int anchordrop_pi::GetAPIVersionMajor()
{
    return atoi(API_VERSION);
}

int anchordrop_pi::GetAPIVersionMinor()
{
    std::string v(API_VERSION);
    size_t dotpos = v.find('.');
    return atoi(v.substr(dotpos + 1).c_str());
}

int anchordrop_pi::GetPlugInVersionMajor()
{
      return PLUGIN_VERSION_MAJOR;
}

int anchordrop_pi::GetPlugInVersionMinor()
{
      return PLUGIN_VERSION_MINOR;
}

wxString anchordrop_pi::GetCommonName()
{
	return "sar";
}

wxBitmap *anchordrop_pi::GetPlugInBitmap()
{
	return &m_panelBitmap;
}


wxString anchordrop_pi::GetShortDescription()
{
      return _("Search and Rescue Patterns");
}

wxString anchordrop_pi::GetLongDescription()
{
      return _("Creates GPX files with Search and Rescue patterns");
}

int anchordrop_pi::GetToolbarToolCount(void)
{
      return 1;
}

void anchordrop_pi::SetColorScheme(PI_ColorScheme cs)
{
      if (NULL == m_pDialog)
            return;

      DimeWindow(m_pDialog);
}

void anchordrop_pi::OnToolbarToolCallback(int id)
{
      if(NULL == m_pDialog)
      {
            m_pDialog = new Dlg(m_parent_window);
            m_pDialog->plugin = this;
            m_pDialog->Move(wxPoint(m_route_dialog_x, m_route_dialog_y));
      }
	  m_pDialog->Fit();

	  //Toggle 
	  m_bShowSAR = !m_bShowSAR;

	  //    Toggle dialog? 
	  if (m_bShowSAR) {
		  m_pDialog->Show();
		  SetCanvasContextMenuItemViz(m_position_menu_id, true);
	  }
	  else {
		  m_pDialog->Hide();
		  SetCanvasContextMenuItemViz(m_position_menu_id, false);
	  }	 

	  // Toggle is handled by the toolbar but we must keep plugin manager b_toggle updated
	  // to actual status to ensure correct status upon toolbar rebuild
	  SetToolbarItemState(m_leftclick_tool_id, m_bShowSAR);

	  RequestRefresh(m_parent_window); // refresh main window

}

bool anchordrop_pi::LoadConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T( "/Settings/anchordrop_pi" ) );
            pConf->Read ( _T ( "Opacity" ),  &m_iOpacity, 255 );
           // pConf->Read       dialog->m_cpConnectorColor->SetColour(m_sConnectorColor);
            m_route_dialog_x =  pConf->Read ( _T ( "DialogPosX" ), 20L );
            m_route_dialog_y =  pConf->Read ( _T ( "DialogPosY" ), 20L );
            m_bCaptureCursor =  pConf->Read ( _T ( "CaptureCursor" ), true );
            m_bCaptureShip =  pConf->Read ( _T ( "CaptureShip" ), true );

            if((m_route_dialog_x < 0) || (m_route_dialog_x > m_display_width))
                  m_route_dialog_x = 5;
            if((m_route_dialog_y < 0) || (m_route_dialog_y > m_display_height))
                  m_route_dialog_y = 5;
            return true;
      }
      else
            return false;
}

bool anchordrop_pi::SaveConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T ( "/Settings/anchordrop_pi" ) );
            pConf->Write ( _T ( "Opacity" ), m_iOpacity );
            pConf->Write ( _T ( "DialogPosX" ),   m_route_dialog_x );
            pConf->Write ( _T ( "DialogPosY" ),   m_route_dialog_y );
            pConf->Write ( _T ( "CaptureCursor" ), m_bCaptureCursor );
            pConf->Write ( _T ( "CaptureShip" ),  m_bCaptureShip );
            return true;
      }
      else
            return false;
}

void anchordrop_pi::ShowPreferencesDialog( wxWindow* parent )
{
      CfgDlg *dialog = new CfgDlg( parent, wxID_ANY, _("Route Preferences"), wxPoint( m_route_dialog_x, m_route_dialog_y), wxDefaultSize, wxDEFAULT_DIALOG_STYLE );
      dialog->Fit();
      wxColour cl;
      DimeWindow(dialog);
      dialog->m_sOpacity->SetValue(m_iOpacity);
      dialog->m_CaptureCursor->SetValue(m_bCaptureCursor);
      dialog->m_CaptureShip->SetValue(m_bCaptureShip);

      if(dialog->ShowModal() == wxID_OK)
      {
            m_iOpacity = dialog->m_sOpacity->GetValue();
            m_bCaptureCursor = dialog->m_CaptureCursor->GetValue();
            m_bCaptureShip = dialog->m_CaptureCursor->GetValue();
            SaveConfig();
      }
      delete dialog;
	  dialog = NULL;

}

void anchordrop_pi::SetCursorLatLon(double lat, double lon)
{
    //if (m_bCaptureShip){ //Option to save CPU
        m_cursor_lat=lat;
        m_cursor_lon=lon;
    //}
    //std::cout<<"Cursor--> Lat: "<<m_cursor_lat<<" Lon: "<<m_cursor_lon<<std::endl;
}

void anchordrop_pi::SetPositionFix(PlugIn_Position_Fix &pfix)
{
    //if (m_bCaptureCursor){ //Option to save CPU
        m_ship_lon = pfix.Lon;
        m_ship_lat = pfix.Lat;
        //std::cout<<"Ship--> Lat: "<<m_ship_lat<<" Lon: "<<m_ship_lon<<std::endl;
    //}
}

void anchordrop_pi::OnContextMenuItemCallback(int id)
{
	if (!m_pDialog)
		return;

	if (id == m_position_menu_id) {
		m_cursor_lat = GetCursorLat();
		m_cursor_lon = GetCursorLon();
		m_pDialog->getDatum(m_cursor_lat, m_cursor_lon);
	}
}

void anchordrop_pi::OnSARDialogClose() {

	m_bShowSAR = false;
	SetToolbarItemState(m_leftclick_tool_id, m_bShowSAR);
	m_pDialog->Hide();
	SaveConfig();

	SetCanvasContextMenuItemViz(m_position_menu_id, false);

	RequestRefresh(m_parent_window); // refresh main window

}
