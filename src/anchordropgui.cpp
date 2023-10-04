///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SARgui.h"

///////////////////////////////////////////////////////////////////////////

DlgDef::DlgDef( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );

	bSframe = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );

	m_wxNotebook234 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel11 = new wxPanel( m_wxNotebook234, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizerDDMMSS;
	sbSizerDDMMSS = new wxStaticBoxSizer( new wxStaticBox( m_panel11, wxID_ANY, _("DATUM / CSP (Start of Search)") ), wxVERTICAL );

	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer1321;
	bSizer1321 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1431;
	bSizer1431 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3231 = new wxStaticText( sbSizerDDMMSS->GetStaticBox(), wxID_ANY, _("Lattitude  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3231->Wrap( -1 );
	bSizer1431->Add( m_staticText3231, 0, wxALL, 5 );

	m_Lat1 = new wxTextCtrl( sbSizerDDMMSS->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1431->Add( m_Lat1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText3331 = new wxStaticText( sbSizerDDMMSS->GetStaticBox(), wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3331->Wrap( -1 );
	bSizer1431->Add( m_staticText3331, 0, wxALL, 5 );


	bSizer1321->Add( bSizer1431, 0, 0, 5 );

	wxBoxSizer* bSizer14311;
	bSizer14311 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32311 = new wxStaticText( sbSizerDDMMSS->GetStaticBox(), wxID_ANY, _("Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32311->Wrap( -1 );
	bSizer14311->Add( m_staticText32311, 0, wxALL, 5 );

	m_Lon1 = new wxTextCtrl( sbSizerDDMMSS->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14311->Add( m_Lon1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText33311 = new wxStaticText( sbSizerDDMMSS->GetStaticBox(), wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33311->Wrap( -1 );
	bSizer14311->Add( m_staticText33311, 0, wxALL, 5 );


	bSizer1321->Add( bSizer14311, 0, 0, 5 );


	bSizer60->Add( bSizer1321, 0, 0, 5 );

	m_panel14 = new wxPanel( sbSizerDDMMSS->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );

	m_button11 = new wxButton( m_panel14, wxID_ANY, _("Ship"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button11->SetToolTip( _("Copy ship position (GPS fix required)") );

	bSizer61->Add( m_button11, 0, wxALL, 5 );

	m_Cursor = new wxButton( m_panel14, wxID_ANY, _("Cursor"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( m_Cursor, 0, wxALL, 5 );


	m_panel14->SetSizer( bSizer61 );
	m_panel14->Layout();
	bSizer61->Fit( m_panel14 );
	bSizer60->Add( m_panel14, 0, wxEXPAND | wxALL, 5 );


	sbSizerDDMMSS->Add( bSizer60, 1, wxEXPAND, 5 );


	bSizer40->Add( sbSizerDDMMSS, 0, wxEXPAND, 5 );


	m_panel11->SetSizer( bSizer40 );
	m_panel11->Layout();
	bSizer40->Fit( m_panel11 );
	m_wxNotebook234->AddPage( m_panel11, _("D.ddd"), true );
	m_panelDegreesMinutes = new wxPanel( m_wxNotebook234, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4011;
	bSizer4011 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer721;
	sbSizer721 = new wxStaticBoxSizer( new wxStaticBox( m_panelDegreesMinutes, wxID_ANY, _("Datum (Start of Search)") ), wxVERTICAL );

	wxBoxSizer* bSizer132121;
	bSizer132121 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer143131;
	bSizer143131 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText323131 = new wxStaticText( sbSizer721->GetStaticBox(), wxID_ANY, _("Lat "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323131->Wrap( -1 );
	bSizer143131->Add( m_staticText323131, 0, wxALL, 5 );

	m_Lat1_d1 = new wxTextCtrl( sbSizer721->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer143131->Add( m_Lat1_d1, 0, wxALL, 5 );

	m_staticText333131 = new wxStaticText( sbSizer721->GetStaticBox(), wxID_ANY, _("deg"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText333131->Wrap( -1 );
	bSizer143131->Add( m_staticText333131, 0, wxALL, 5 );

	m_Lat1_m1 = new wxTextCtrl( sbSizer721->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer143131->Add( m_Lat1_m1, 0, wxALL|wxEXPAND, 5 );

	m_staticText11431 = new wxStaticText( sbSizer721->GetStaticBox(), wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11431->Wrap( -1 );
	bSizer143131->Add( m_staticText11431, 0, wxALL, 5 );

	wxString m_Lat1_NS1Choices[] = { _("N"), _("S") };
	int m_Lat1_NS1NChoices = sizeof( m_Lat1_NS1Choices ) / sizeof( wxString );
	m_Lat1_NS1 = new wxChoice( sbSizer721->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Lat1_NS1NChoices, m_Lat1_NS1Choices, 0 );
	m_Lat1_NS1->SetSelection( 0 );
	bSizer143131->Add( m_Lat1_NS1, 0, wxALL, 5 );


	bSizer132121->Add( bSizer143131, 0, 0, 5 );

	wxBoxSizer* bSizer1431121;
	bSizer1431121 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3231121 = new wxStaticText( sbSizer721->GetStaticBox(), wxID_ANY, _("Lon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3231121->Wrap( -1 );
	bSizer1431121->Add( m_staticText3231121, 0, wxALL, 5 );

	m_Lon1_d1 = new wxTextCtrl( sbSizer721->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer1431121->Add( m_Lon1_d1, 0, wxALL, 5 );

	m_staticText3331121 = new wxStaticText( sbSizer721->GetStaticBox(), wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3331121->Wrap( -1 );
	bSizer1431121->Add( m_staticText3331121, 0, wxALL, 5 );

	m_Lon1_m1 = new wxTextCtrl( sbSizer721->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer1431121->Add( m_Lon1_m1, 0, wxALL|wxEXPAND, 5 );

	m_staticText114121 = new wxStaticText( sbSizer721->GetStaticBox(), wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText114121->Wrap( -1 );
	bSizer1431121->Add( m_staticText114121, 0, wxALL, 5 );

	wxString m_Lon1_EW1Choices[] = { _("E"), _("W") };
	int m_Lon1_EW1NChoices = sizeof( m_Lon1_EW1Choices ) / sizeof( wxString );
	m_Lon1_EW1 = new wxChoice( sbSizer721->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Lon1_EW1NChoices, m_Lon1_EW1Choices, 0 );
	m_Lon1_EW1->SetSelection( 0 );
	bSizer1431121->Add( m_Lon1_EW1, 0, wxALL, 5 );


	bSizer132121->Add( bSizer1431121, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	sbSizer721->Add( bSizer132121, 0, 0, 5 );


	bSizer4011->Add( sbSizer721, 0, 0, 5 );

	wxBoxSizer* bSizer4811;
	bSizer4811 = new wxBoxSizer( wxHORIZONTAL );

	m_button811 = new wxButton( m_panelDegreesMinutes, wxID_ANY, _("Convert to Degree"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4811->Add( m_button811, 0, wxALL, 5 );


	bSizer4011->Add( bSizer4811, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panelDegreesMinutes->SetSizer( bSizer4011 );
	m_panelDegreesMinutes->Layout();
	bSizer4011->Fit( m_panelDegreesMinutes );
	m_wxNotebook234->AddPage( m_panelDegreesMinutes, _("D MM.mmm"), false );
	m_panel15 = new wxPanel( m_wxNotebook234, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer401;
	bSizer401 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer72;
	sbSizer72 = new wxStaticBoxSizer( new wxStaticBox( m_panel15, wxID_ANY, _("Datum (Start of Search)") ), wxVERTICAL );

	wxBoxSizer* bSizer13212;
	bSizer13212 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer14313;
	bSizer14313 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32313 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("Lat "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32313->Wrap( -1 );
	bSizer14313->Add( m_staticText32313, 0, wxALL, 5 );

	m_Lat1_d = new wxTextCtrl( sbSizer72->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer14313->Add( m_Lat1_d, 0, wxALL, 5 );

	m_staticText33313 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("deg"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText33313->Wrap( -1 );
	bSizer14313->Add( m_staticText33313, 0, wxALL, 5 );

	m_Lat1_m = new wxTextCtrl( sbSizer72->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer14313->Add( m_Lat1_m, 0, wxALL, 5 );

	m_staticText1143 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1143->Wrap( -1 );
	bSizer14313->Add( m_staticText1143, 0, wxALL, 5 );

	m_Lat1_s = new wxTextCtrl( sbSizer72->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer14313->Add( m_Lat1_s, 0, wxALL, 5 );

	m_staticText1153 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("\""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1153->Wrap( -1 );
	bSizer14313->Add( m_staticText1153, 0, wxALL, 5 );

	wxString m_Lat1_NSChoices[] = { _("N"), _("S") };
	int m_Lat1_NSNChoices = sizeof( m_Lat1_NSChoices ) / sizeof( wxString );
	m_Lat1_NS = new wxChoice( sbSizer72->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Lat1_NSNChoices, m_Lat1_NSChoices, 0 );
	m_Lat1_NS->SetSelection( 0 );
	bSizer14313->Add( m_Lat1_NS, 0, wxALL, 5 );


	bSizer13212->Add( bSizer14313, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer143112;
	bSizer143112 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText323112 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("Lon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText323112->Wrap( -1 );
	bSizer143112->Add( m_staticText323112, 0, wxALL, 5 );

	m_Lon1_d = new wxTextCtrl( sbSizer72->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), 0 );
	bSizer143112->Add( m_Lon1_d, 0, wxALL, 5 );

	m_staticText333112 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText333112->Wrap( -1 );
	bSizer143112->Add( m_staticText333112, 0, wxALL, 5 );

	m_Lon1_m = new wxTextCtrl( sbSizer72->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer143112->Add( m_Lon1_m, 0, wxALL, 5 );

	m_staticText11412 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("'"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11412->Wrap( -1 );
	bSizer143112->Add( m_staticText11412, 0, wxALL, 5 );

	m_Lon1_s = new wxTextCtrl( sbSizer72->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer143112->Add( m_Lon1_s, 0, wxALL, 5 );

	m_staticText11512 = new wxStaticText( sbSizer72->GetStaticBox(), wxID_ANY, _("\""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11512->Wrap( -1 );
	bSizer143112->Add( m_staticText11512, 0, wxALL, 5 );

	wxString m_Lon1_EWChoices[] = { _("E"), _("W") };
	int m_Lon1_EWNChoices = sizeof( m_Lon1_EWChoices ) / sizeof( wxString );
	m_Lon1_EW = new wxChoice( sbSizer72->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_Lon1_EWNChoices, m_Lon1_EWChoices, 0 );
	m_Lon1_EW->SetSelection( 0 );
	bSizer143112->Add( m_Lon1_EW, 0, wxALL, 5 );


	bSizer13212->Add( bSizer143112, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	sbSizer72->Add( bSizer13212, 0, wxEXPAND, 5 );


	bSizer401->Add( sbSizer72, 0, 0, 5 );

	wxBoxSizer* bSizer481;
	bSizer481 = new wxBoxSizer( wxHORIZONTAL );

	m_button81 = new wxButton( m_panel15, wxID_ANY, _("Convert to Degree"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer481->Add( m_button81, 0, wxALL, 5 );


	bSizer401->Add( bSizer481, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel15->SetSizer( bSizer401 );
	m_panel15->Layout();
	bSizer401->Fit( m_panel15 );
	m_wxNotebook234->AddPage( m_panel15, _("D MM SS"), false );

	bSizer35->Add( m_wxNotebook234, 0, wxALL|wxEXPAND, 5 );


	bSframe->Add( bSizer35, 0, 0, 5 );


	this->SetSizer( bSframe );
	this->Layout();
	bSframe->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DlgDef::OnClose ) );
	m_wxNotebook234->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( DlgDef::key_shortcut ), NULL, this );
	m_wxNotebook234->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( DlgDef::OnNoteBookFit ), NULL, this );
	m_panel11->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( DlgDef::key_shortcut ), NULL, this );
	m_Lat1->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( DlgDef::key_shortcut ), NULL, this );
	m_Lon1->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( DlgDef::key_shortcut ), NULL, this );
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnShip ), NULL, this );
	m_Cursor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnCursor ), NULL, this );
	m_button811->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnConvertToDegree ), NULL, this );
	m_button81->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnConvertToDegree ), NULL, this );
}

DlgDef::~DlgDef()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DlgDef::OnClose ) );
	m_wxNotebook234->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( DlgDef::key_shortcut ), NULL, this );
	m_wxNotebook234->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( DlgDef::OnNoteBookFit ), NULL, this );
	m_panel11->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( DlgDef::key_shortcut ), NULL, this );
	m_Lat1->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( DlgDef::key_shortcut ), NULL, this );
	m_Lon1->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( DlgDef::key_shortcut ), NULL, this );
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnShip ), NULL, this );
	m_Cursor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnCursor ), NULL, this );
	m_button811->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnConvertToDegree ), NULL, this );
	m_button81->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DlgDef::OnConvertToDegree ), NULL, this );

}

CfgDlgDef::CfgDlgDef( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("General settings") ), wxVERTICAL );

	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText17 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, _("Opacity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	fgSizer3->Add( m_staticText17, 0, wxALL, 5 );

	m_sOpacity = new wxSlider( sbSizer4->GetStaticBox(), wxID_ANY, 50, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	fgSizer3->Add( m_sOpacity, 0, wxALL|wxEXPAND, 5 );


	sbSizer4->Add( fgSizer3, 1, wxEXPAND, 5 );


	bSizer2->Add( sbSizer4, 0, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("CPU saving settings") ), wxVERTICAL );

	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_CaptureShip = new wxCheckBox( sbSizer3->GetStaticBox(), wxID_ANY, _("Capture Ship Position"), wxDefaultPosition, wxDefaultSize, 0 );
	m_CaptureShip->SetValue(true);
	m_CaptureShip->SetToolTip( _("Leave ticked, so you can use ship's position") );

	bSizer3->Add( m_CaptureShip, 0, wxALL, 5 );

	m_CaptureCursor = new wxCheckBox( sbSizer3->GetStaticBox(), wxID_ANY, _("Capture Cursor Position"), wxDefaultPosition, wxDefaultSize, 0 );
	m_CaptureCursor->SetValue(true);
	m_CaptureCursor->SetToolTip( _("Leave ticked, so that you can use cursor position.") );

	bSizer3->Add( m_CaptureCursor, 0, wxALL, 5 );


	fgSizer4->Add( bSizer3, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );


	fgSizer4->Add( bSizer4, 1, wxEXPAND, 5 );


	sbSizer3->Add( fgSizer4, 1, wxEXPAND, 5 );


	bSizer2->Add( sbSizer3, 0, wxALL|wxEXPAND, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();

	bSizer1->Add( m_sdbSizer1, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );

	this->Centre( wxBOTH );
}

CfgDlgDef::~CfgDlgDef()
{
}
