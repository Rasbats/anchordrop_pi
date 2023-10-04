/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  ROUTE Plugin
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

#include "anchordropgui_impl.h"

CfgDlg::CfgDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : CfgDlgDef( parent, id, title, pos, size, style )
{
}

Dlg::Dlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DlgDef( parent, id, title, pos, size, style )
{
    this->Fit();

    dbg=false; //for debug output set to true

    //initialise images

    //m_bitmap_trackln->SetBitmap(* _img_trackln);
}

void Dlg::OnConvertToDegree( wxCommandEvent& event )
{
    ConvertToDegree();
}

void Dlg::ConvertToDegree()
{
    double DDLat;
    double DDLon;

    double DDLat1;
    double DDLon1;

    double MMLat;
    double MMLon;

    double SSLat;
    double SSLon;

    int DDlat1;
    int DDlon1;

    int MMlat1;
    int MMlon1;

    int NS;
    int EW;

    double MMlat0;
    double MMlon0;

    double MMlat2;
    double MMlon2;

    double SSlat1;
    double SSlon1;

    double value;

    wxString s;
    wxString s1;
    wxString m1;
    wxString d1;

    //set cell values to 0 if they are empty. This ensures conversion goes ok.
    double test_value;
    if (!this->m_Lat1_d->GetValue().ToDouble(&test_value)) { m_Lat1_d->SetValue(wxString::Format(wxT("%i"), 0)); }
    if (!this->m_Lat1_m->GetValue().ToDouble(&test_value)) { m_Lat1_m->SetValue(wxString::Format(wxT("%i"), 0)); }
    if (!this->m_Lat1_s->GetValue().ToDouble(&test_value)) { m_Lat1_s->SetValue(wxString::Format(wxT("%i"), 0)); }

    if (!this->m_Lon1_d->GetValue().ToDouble(&test_value)) { m_Lon1_d->SetValue(wxString::Format(wxT("%i"), 0)); }
    if (!this->m_Lon1_m->GetValue().ToDouble(&test_value)) { m_Lon1_m->SetValue(wxString::Format(wxT("%i"), 0)); }
    if (!this->m_Lon1_s->GetValue().ToDouble(&test_value)) { m_Lon1_s->SetValue(wxString::Format(wxT("%i"), 0)); }

    if (!this->m_Lat1_d1->GetValue().ToDouble(&test_value)) { m_Lat1_d1->SetValue(wxString::Format(wxT("%i"), 0)); }
    if (!this->m_Lat1_m1->GetValue().ToDouble(&test_value)) { m_Lat1_m1->SetValue(wxString::Format(wxT("%i"), 0)); }

    if (!this->m_Lon1_d1->GetValue().ToDouble(&test_value)) { m_Lon1_d1->SetValue(wxString::Format(wxT("%i"), 0)); }
    if (!this->m_Lon1_m1->GetValue().ToDouble(&test_value)) { m_Lon1_m1->SetValue(wxString::Format(wxT("%i"), 0)); }



}






void Dlg::OnClose(wxCloseEvent& event){

    plugin->OnSARDialogClose();
}

void Dlg::OnCursor(wxCommandEvent& event ){OnCursor();}
void Dlg::OnCursor(void){
    this->m_Lat1->SetValue(wxString::Format(wxT("%.6f"), plugin->GetCursorLat() ));
    this->m_Lon1->SetValue(wxString::Format(wxT("%.6f"), plugin->GetCursorLon() ));

    setDDMM(); // Copies the lat.lon to the DDMM page

    m_wxNotebook234->SetSelection(0);
    m_Lat1->SetFocus();
}

void Dlg::OnShip(wxCommandEvent& event ){OnShip();}
void Dlg::OnShip(void){
    this->m_Lat1->SetValue(wxString::Format(wxT("%.6f"), plugin->GetShipLat() ));
    this->m_Lon1->SetValue(wxString::Format(wxT("%.6f"), plugin->GetShipLon() ));

    setDDMM(); // Copies the lat.lon to the DDMM page

    m_wxNotebook234->SetSelection(0);
    m_Lat1->SetFocus();
}


void Dlg::key_shortcut(wxKeyEvent& event) {
    // of course, it doesn't have to be the control key. You can use others:
    // http://docs.wxwidgets.org/stable/wx_wxkeyevent.html
    if(event.GetModifiers() == wxMOD_CONTROL) {
        switch(event.GetKeyCode()) {
            case 'S': // can return the upper ASCII value of a key
                // do whatever you like for a Ctrl+G event here!
                //wxMessageBox(_("CTRL+G") );
                OnCursor();
                break;/*
            case WXK_LEFT: // we also have special keycodes for non-ascii values.
                // get a full list of special keycodes here:
                // http://docs.wxwidgets.org/stable/wx_keycodes.html
                wxMessageBox(_("CTRL+Left") );
                break;*/
            default: // do nothing
                break;
        }
    }
    event.Skip();
}
/*
void Dlg::mouse_shortcut(wxMouseEvent& event) {
    // of course, it doesn't have to be the control key. You can use others:
    // http://docs.wxwidgets.org/stable/wx_wxkeyevent.html
    if(event.LeftDown() == true) {
        wxMessageBox(_("CTRL+G") );
        OnCursor();
    }
    //else{
        event.Skip();
    //}

}*/


void Dlg::OnCursorSelect(wxCommandEvent& event){

    m_wxNotebook234->SetSelection(0);
    m_Lat1->SetFocus();
    m_Lat1->Clear();
    m_Lon1->Clear();

    wxMessageBox(_("To copy the cursor location place the cursor on the chart \n     ...and press <CTRL>+S") );
   // wxMessageBox(_("While this button is selected, or the cursor is in the lattitude or longitude box, you can copy the cursor location with <CTRL>+S") );
    event.Skip();
}

void Dlg::getDatum(double m_lat, double m_lon) {

    wxString myLat = wxString::Format("%f", m_lat);
    wxString myLon = wxString::Format("%f", m_lon);

    m_Lat1->SetValue(myLat);
    m_Lon1->SetValue(myLon);

    setDDMM();

    m_wxNotebook234->SetSelection(0);
    m_Lat1->SetFocus();

}


void Dlg::setDDMM() {  // after entering dd.dddd from cursor, menu, lat

    double DDLat;
    double DDLon;

    int DDlat1;
    int DDlon1;

    double MMlat0;
    double MMlon0;

    double MMlat2;
    double MMlon2;

    double SSlat1;
    double SSlon1;

    double value;

    wxString s;
    wxString s1;
    wxString m1;
    wxString d1;

    //set cell values to 0 if they are empty. This ensures conversion goes ok.
    double test_value;
    if (!this->m_Lat1_d->GetValue().ToDouble(&test_value)) { m_Lat1_d->SetValue(wxString::Format(wxT("%i"), 0)); }
    if (!this->m_Lat1_m->GetValue().ToDouble(&test_value)) { m_Lat1_m->SetValue(wxString::Format(wxT("%i"), 0)); }
    if (!this->m_Lat1_s->GetValue().ToDouble(&test_value)) { m_Lat1_s->SetValue(wxString::Format(wxT("%i"), 0)); }

    if (!this->m_Lon1_d->GetValue().ToDouble(&test_value)) { m_Lon1_d->SetValue(wxString::Format(wxT("%i"), 0)); }
    if (!this->m_Lon1_m->GetValue().ToDouble(&test_value)) { m_Lon1_m->SetValue(wxString::Format(wxT("%i"), 0)); }
    if (!this->m_Lon1_s->GetValue().ToDouble(&test_value)) { m_Lon1_s->SetValue(wxString::Format(wxT("%i"), 0)); }

    if (!this->m_Lat1_d1->GetValue().ToDouble(&test_value)) { m_Lat1_d1->SetValue(wxString::Format(wxT("%i"), 0)); }
    if (!this->m_Lat1_m1->GetValue().ToDouble(&test_value)) { m_Lat1_m1->SetValue(wxString::Format(wxT("%i"), 0)); }

    if (!this->m_Lon1_d1->GetValue().ToDouble(&test_value)) { m_Lon1_d1->SetValue(wxString::Format(wxT("%i"), 0)); }
    if (!this->m_Lon1_m1->GetValue().ToDouble(&test_value)) { m_Lon1_m1->SetValue(wxString::Format(wxT("%i"), 0)); }

    s = m_Lat1->GetValue();
    s.ToDouble(&value);
    DDLat = value;
    s = m_Lon1->GetValue();
    s.ToDouble(&value);
    DDLon = value;

    DDlat1 = abs(int(DDLat));
    DDlon1 = abs(int(DDLon));

    // set the ddmm page

    m_Lat1_d1->SetValue(wxString::Format(_T("%i"), (int)DDlat1));
    m_Lon1_d1->SetValue(wxString::Format(_T("%i"), (int)DDlon1));

    MMlat0 = (fabs(DDLat) - double(DDlat1)) * 60;
    MMlon0 = (fabs(DDLon) - double(DDlon1)) * 60;

    m_Lat1_m1->SetValue(wxString::Format(_T("%.6f"), MMlat0));
    m_Lon1_m1->SetValue(wxString::Format(_T("%.6f"), MMlon0));

    if (DDLat > 0) {
        m_Lat1_NS1->SetSelection(0);
        m_Lat1_NS->SetSelection(0);
    }
    else {
        m_Lat1_NS1->SetSelection(1);
        m_Lat1_NS->SetSelection(1);
    }

    if (DDLon > 0) {
        m_Lon1_EW1->SetSelection(0);
        m_Lon1_EW->SetSelection(0);
    }
    else {
        m_Lon1_EW1->SetSelection(1);
        m_Lon1_EW->SetSelection(1);
    }

    // set the ddmmss page

    m_Lat1_d->SetValue(wxString::Format(_T("%i"), abs((int)DDlat1)));
    m_Lon1_d->SetValue(wxString::Format(_T("%i"), abs((int)DDlon1)));

    m_Lat1_m->SetValue(wxString::Format(_T("%i"), abs((int)MMlat0)));
    m_Lon1_m->SetValue(wxString::Format(_T("%i"), abs((int)MMlon0)));

    MMlat2 = int(MMlat0);
    MMlon2 = int(MMlon0);

    SSlat1 = (MMlat0 - MMlat2) * 60;
    SSlon1 = (MMlon0 - MMlon2) * 60;

    m_Lat1_s->SetValue(wxString::Format(_T("%.6f"), SSlat1));
    m_Lon1_s->SetValue(wxString::Format(_T("%.6f"), SSlon1));


}



