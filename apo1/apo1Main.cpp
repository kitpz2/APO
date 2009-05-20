/***************************************************************
 * Name:      apo1Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Paweł Zembrzuski ()
 * Created:   2009-03-06
 * Copyright: Paweł Zembrzuski ()
 * License:
 **************************************************************/

#include "apo1Main.h"
#include <wx/msgdlg.h>
#include "../apo_lib.hpp"
#include <cstdlib>
#include <cstdio>

//(*InternalHeaders(apo1Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

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

//(*IdInit(apo1Frame)
const long apo1Frame::ID_BUTTON1 = wxNewId();
const long apo1Frame::ID_STATICBITMAP1 = wxNewId();
const long apo1Frame::ID_CHECKBOX1 = wxNewId();
const long apo1Frame::ID_CHECKBOX2 = wxNewId();
const long apo1Frame::ID_CHECKBOX4 = wxNewId();
const long apo1Frame::ID_CHECKBOX3 = wxNewId();
const long apo1Frame::ID_BUTTON2 = wxNewId();
const long apo1Frame::ID_PANEL1 = wxNewId();
const long apo1Frame::idMenuQuit = wxNewId();
const long apo1Frame::idMenuAbout = wxNewId();
const long apo1Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(apo1Frame,wxFrame)
    //(*EventTable(apo1Frame)
    //*)
END_EVENT_TABLE()

apo1Frame::apo1Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(apo1Frame)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxGridSizer* GridSizer1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(1);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Krok 1"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Wybierz obraz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    podglad = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxSize(250,250), 0, _T("ID_STATICBITMAP1"));
    FlexGridSizer2->Add(podglad, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Krok 2"));
    GridSizer1 = new wxGridSizer(0, 2, 0, 0);
    metoda1 = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Sposób 1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    metoda1->SetValue(false);
    GridSizer1->Add(metoda1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    metoda2 = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Sposób 2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    metoda2->SetValue(false);
    GridSizer1->Add(metoda2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    metoda3 = new wxCheckBox(Panel1, ID_CHECKBOX4, _("Sposób 3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    metoda3->SetValue(false);
    GridSizer1->Add(metoda3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wlasna = new wxCheckBox(Panel1, ID_CHECKBOX3, _("Sposób własny"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    wlasna->SetValue(false);
    GridSizer1->Add(wlasna, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(GridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Krok 3"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Wykonaj operacje"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("*.bmp|*.bmp|*.bmp|*.bmp|*.gif|*.gif|*.jpg|*.jpg|*.png|*.png"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&apo1Frame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&apo1Frame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&apo1Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&apo1Frame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&apo1Frame::OnClose);
    //*)

    loaded=false;
}

apo1Frame::~apo1Frame()
{
    //(*Destroy(apo1Frame)
    //*)
}

void apo1Frame::OnQuit(wxCommandEvent& event)
{
    exit(0);
    //Close();
}

void apo1Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void apo1Frame::OnButton1Click(wxCommandEvent& event)
{
    if (FileDialog1->ShowModal())
    {
        if (obraz.LoadFile(FileDialog1->GetPath()))
        {
            loaded = true;
            if (obraz.GetWidth()>250 || obraz.GetHeight()>250)
            {
                float scale;
                if (obraz.GetWidth()/250>obraz.GetHeight()/250)
                {
                    scale=obraz.GetWidth()/250;
                }
                else
                {
                    scale=obraz.GetHeight()/250;
                }
                obraz.Rescale(obraz.GetWidth()/scale,obraz.GetHeight()/scale);
                podglad->SetBitmap(obraz);
            }
            else
            {
                podglad->SetBitmap(obraz);
            }
        }
        else
            loaded=false;
    }
}


void apo1Frame::OnClose(wxCloseEvent& event)
{
    //delete this;
    exit(0);
    //Close();
}

void apo1Frame::OnButton2Click(wxCommandEvent& event)
{
    if (loaded)
    {
        if (metoda1->IsChecked())
        {
            Image_show *okno=new Image_show(FileDialog1->GetPath(), obraz, _("Sposób 1"),1);
            okno->Show();
        }
        if (metoda2->IsChecked())
        {
            fprintf(stderr,"(%s-%d)M2->",__FILE__,__LINE__);
            Image_show *okno=new Image_show(FileDialog1->GetPath(), obraz, _("Sposób 2"),2);
            okno->Show();
        }
        if (metoda3->IsChecked())
        {
            Image_show *okno=new Image_show(FileDialog1->GetPath(), obraz, _("Sposób 3"),3);
            okno->Show();
        }
        if (wlasna->IsChecked())
        {
            Image_show *okno=new Image_show(FileDialog1->GetPath(), obraz, _("Sposób własny"),4);
            okno->Show();
        }
    }
    else
    {
        wxMessageBox(_("Trzeba najpierw wybrać obraz"), _("ERROR"));
    }
}
