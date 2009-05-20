/***************************************************************
 * Name:      APOMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Paweł Zembrzuski ()
 * Created:   2009-04-03
 * Copyright: Paweł Zembrzuski ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "APOMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(APOFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(APOFrame)
const long APOFrame::ID_STATICBITMAP1 = wxNewId();
const long APOFrame::ID_BUTTON1 = wxNewId();
const long APOFrame::ID_PANEL1 = wxNewId();
const long APOFrame::ID_MENUITEM1 = wxNewId();
const long APOFrame::idMenuQuit = wxNewId();
const long APOFrame::ID_MENUITEM2 = wxNewId();
const long APOFrame::ID_MENUITEM3 = wxNewId();
const long APOFrame::ID_MENUITEM4 = wxNewId();
const long APOFrame::ID_MENUITEM5 = wxNewId();
const long APOFrame::ID_MENUITEM14 = wxNewId();
const long APOFrame::ID_MENUITEM16 = wxNewId();
const long APOFrame::ID_MENUITEM17 = wxNewId();
const long APOFrame::ID_MENUITEM18 = wxNewId();
const long APOFrame::ID_MENUITEM19 = wxNewId();
const long APOFrame::ID_MENUITEM20 = wxNewId();
const long APOFrame::cw3_1_1 = wxNewId();
const long APOFrame::ID_MENUITEM8 = wxNewId();
const long APOFrame::ID_MENUITEM9 = wxNewId();
const long APOFrame::ID_MENUITEM10 = wxNewId();
const long APOFrame::ID_MENUITEM6 = wxNewId();
const long APOFrame::ID_MENUITEM11 = wxNewId();
const long APOFrame::ID_MENUITEM12 = wxNewId();
const long APOFrame::ID_MENUITEM13 = wxNewId();
const long APOFrame::idMenuAbout = wxNewId();
const long APOFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(APOFrame,wxFrame)
    //(*EventTable(APOFrame)
    //*)
END_EVENT_TABLE()

APOFrame::APOFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(APOFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenu* Menu7;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableCol(1);
    FlexGridSizer1->AddGrowableRow(0);
    FlexGridSizer1->AddGrowableRow(1);
    StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    FlexGridSizer1->Add(StaticBitmap1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Wybierz Obraz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Wybierz obraz"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Wyjście\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Plik"));
    Menu3 = new wxMenu();
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM2, _("Sposób 1"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu3, ID_MENUITEM3, _("Sposób 2"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu3, ID_MENUITEM4, _("Sposób 3"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(Menu3, ID_MENUITEM5, _("Sposób własny"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem7);
    MenuBar1->Append(Menu3, _("Zajęcia 1"));
    Menu4 = new wxMenu();
    MenuItem16 = new wxMenuItem(Menu4, ID_MENUITEM14, _("Zadanie 1"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem16);
    MenuItem18 = new wxMenuItem(Menu4, ID_MENUITEM16, _("Zadanie 2"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem18);
    MenuItem19 = new wxMenuItem(Menu4, ID_MENUITEM17, _("Zadanie 3"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem19);
    MenuItem20 = new wxMenuItem(Menu4, ID_MENUITEM18, _("Zadanie 4"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem20);
    MenuItem21 = new wxMenuItem(Menu4, ID_MENUITEM19, _("Zadanie 5"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem21);
    MenuItem22 = new wxMenuItem(Menu4, ID_MENUITEM20, _("Zadanie 6"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem22);
    MenuBar1->Append(Menu4, _("Zajęcia 2"));
    Menu5 = new wxMenu();
    MenuItem8 = new wxMenu();
    MenuItem9 = new wxMenuItem(MenuItem8, cw3_1_1, _("Wyostrzanie 1"), wxEmptyString, wxITEM_NORMAL);
    MenuItem8->Append(MenuItem9);
    MenuItem10 = new wxMenuItem(MenuItem8, ID_MENUITEM8, _("Wyostrzanie 2"), wxEmptyString, wxITEM_NORMAL);
    MenuItem8->Append(MenuItem10);
    MenuItem11 = new wxMenuItem(MenuItem8, ID_MENUITEM9, _("Detekcja Krawędzi 1"), wxEmptyString, wxITEM_NORMAL);
    MenuItem8->Append(MenuItem11);
    MenuItem12 = new wxMenuItem(MenuItem8, ID_MENUITEM10, _("Detekcja Krawędzi 2"), wxEmptyString, wxITEM_NORMAL);
    MenuItem8->Append(MenuItem12);
    Menu5->Append(ID_MENUITEM6, _("Zadanie 1"), MenuItem8, wxEmptyString);
    MenuItem13 = new wxMenuItem(Menu5, ID_MENUITEM11, _("Zadanie 3"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem13);
    MenuItem14 = new wxMenuItem(Menu5, ID_MENUITEM12, _("Zadanie 5"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem14);
    MenuItem15 = new wxMenuItem(Menu5, ID_MENUITEM13, _("Zadanie 6"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuItem15);
    MenuBar1->Append(Menu5, _("Zajęcia 3"));
    Menu6 = new wxMenu();
    MenuBar1->Append(Menu6, _("Zajęcia 4"));
    Menu7 = new wxMenu();
    MenuBar1->Append(Menu7, _("Zajęcia 5"));
    Menu8 = new wxMenu();
    MenuBar1->Append(Menu8, _("Zajęcia 6"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Informacje\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Pomoc"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&APOFrame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&APOFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&APOFrame::OnAbout);
    //*)
}

APOFrame::~APOFrame()
{
    //(*Destroy(APOFrame)
    //*)
}

void APOFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void APOFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void APOFrame::OnButton1Click(wxCommandEvent& event)
{

}
