/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  anchordrop Plugin
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

#ifndef _CALCULATORGUI_IMPL_H_
#define _CALCULATORGUI_IMPL_H_

//#include <cstdlib>
//#include <cstdio>
#ifdef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "anchordropgui.h"
#include "bitmaps.h"
#include "anchordrop_pi.h"
#include "NavFunc.h"
#include "tinyxml.h"
#include <cmath>

using namespace std;

class anchordrop_pi;

class CfgDlg : public CfgDlgDef
{
public:
      CfgDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("anchordrop preferences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
};

class Dlg : public DlgDef
{
public:
        Dlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("anchordrop Plugin by SaltyPaws/Rasbats"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION| wxDEFAULT_DIALOG_STYLE | wxMINIMIZE_BOX | wxRESIZE_BORDER);
        //void OnToggle( wxCommandEvent& event );
        void OnConvertToDegree( wxCommandEvent& event );
        void ConvertToDegree();

        void OnShip( wxCommandEvent& event );
        void OnCursor( wxCommandEvent& event );
        void OnShip( void );
        void OnCursor( void );
        void key_shortcut(wxKeyEvent& event);
        void OnCursorSelect( wxCommandEvent& event );

        // For right click datum selection
        void getDatum(double m_lat, double m_lon);

        //void mouse_shortcut(wxMouseEvent& event);


        void Addpoint(TiXmlElement* Route, wxString ptlat, wxString ptlon, wxString ptname, wxString ptsym, wxString pttype);

        //friend class function;
        anchordrop_pi *plugin;
        double m_ship_lon,m_ship_lat,m_cursor_lon,m_cursor_lat;

        void setDDMM();
        void OnClose(wxCloseEvent& event);

private:

        wxPoint xy;
        wxSize  wh;
        double lat1, lon1, lat2, lon2, targetAz;
        //double F(double x);
        bool error_found;
        bool dbg;
};

#endif
