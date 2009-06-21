#include "wx_pch.h"
#include "Test_1_1.h"

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(Test_1_1)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#endif
//(*InternalHeaders(Test_1_1)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//(*IdInit(Test_1_1)
const long Test_1_1::ID_BUTTON1 = wxNewId();
const long Test_1_1::ID_BUTTON2 = wxNewId();
const long Test_1_1::ID_STATICBITMAP1 = wxNewId();
const long Test_1_1::ID_STATICBITMAP2 = wxNewId();
const long Test_1_1::ID_STATICBITMAP3 = wxNewId();
const long Test_1_1::ID_STATICBITMAP4 = wxNewId();
const long Test_1_1::ID_BUTTON3 = wxNewId();
const long Test_1_1::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Test_1_1,wxFrame)
    //(*EventTable(Test_1_1)
    //*)
END_EVENT_TABLE()

Test_1_1::Test_1_1(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(Test_1_1)
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE, _T("ID_PANEL1"));
    Panel1->SetExtraStyle( Panel1->GetExtraStyle() | wxWS_EX_VALIDATE_RECURSIVELY );
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer1->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    obraz1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_OTHER,wxSize(250,250)), wxDefaultPosition, wxSize(250,250), 0, _T("ID_STATICBITMAP1"));
    obraz1->Disable();
    FlexGridSizer1->Add(obraz1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    obraz2 = new wxStaticBitmap(Panel1, ID_STATICBITMAP2, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_OTHER,wxSize(250,250)), wxDefaultPosition, wxSize(250,250), 0, _T("ID_STATICBITMAP2"));
    obraz2->Disable();
    FlexGridSizer1->Add(obraz2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    obraz3 = new wxStaticBitmap(Panel1, ID_STATICBITMAP3, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_OTHER,wxSize(250,250)), wxDefaultPosition, wxSize(250,250), 0, _T("ID_STATICBITMAP3"));
    obraz3->Disable();
    FlexGridSizer1->Add(obraz3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    obraz4 = new wxStaticBitmap(Panel1, ID_STATICBITMAP4, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_OTHER,wxSize(250,250)), wxDefaultPosition, wxSize(250,250), 0, _T("ID_STATICBITMAP4"));
    obraz4->Disable();
    FlexGridSizer1->Add(obraz4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->Disable();
    FlexGridSizer1->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Test_1_1::OnButton1Click1);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Test_1_1::OnButton2Click1);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Test_1_1::OnButton3Click);
    //*)
    loaded=loaded2=false;
}

Test_1_1::~Test_1_1()
{
    //(*Destroy(Test_1_1)
    //*)
}


void Test_1_1::OnButton1Click1(wxCommandEvent& event)
{
    IMG obraz;
    if (FileDialog1->ShowModal()==wxID_OK)
    {
        if (obraz.LoadFile(FileDialog1->GetPath()))
        {
            ObrazUkrywany=new IMG(FileDialog1->GetPath());
            loaded = true;
            obraz1->Enable();
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
                obraz1->SetBitmap(obraz);
            }
            else
            {
                obraz1->SetBitmap(obraz);
            }
        }
        else
            loaded=false;
    }

    if (loaded && loaded2)
    {
        Button3->Enable();
    }

}

void Test_1_1::OnButton2Click1(wxCommandEvent& event)
{
    IMG obraz;
    if (FileDialog1->ShowModal()==wxID_OK)
    {
        if (obraz.LoadFile(FileDialog1->GetPath()))
        {
            ObrazUkrywajacy=new IMG(FileDialog1->GetPath());
            loaded2 = true;
            obraz2->Enable();
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
                obraz2->SetBitmap(obraz);
                obraz2->Show();
                obraz2->Enable();

            }
            else
            {
                obraz2->SetBitmap(obraz);
                obraz2->Show();
                obraz2->Enable();
            }
        }
        else
            loaded=false;
    }
    if (loaded && loaded2)
    {
        Button3->Enable();
    }
}


void Test_1_1::OnButton3Click(wxCommandEvent& event)
{
    ObrazWBitach *tmp=new ObrazWBitach(*ObrazUkrywajacy);
    ObrazWBitach *tmp2=new ObrazWBitach(*ObrazUkrywany);
    ObrazWBitach *tmp4=new ObrazWBitach(*tmp2->LZWCompress());
    line;
    IMG *obraz_przed=tmp->GetIMG();
    line;
    try
    {
        tmp->Ukryj(*tmp4,5);
    }
    catch (wxString &t)
    {
        wxMessageBox(t,_("Uwaga!"));
        return;
    }
    ObrazWBitach *tmp8=tmp->Odkryj();
    line;
    ObrazWBitach *tmp3=tmp8->LZWDecompress();
    IMG *obraz_odkodowany=tmp3->GetIMG();
    line;
    IMG *obraz=tmp->GetIMG();
    line;
    //obraz3->SetBitmap(*tmp2);
    //obraz3->Enable();

    if (obraz->GetWidth()>250 || obraz->GetHeight()>250)
    {
        line;
        float scale;
        if (obraz->GetWidth()/250>obraz->GetHeight()/250)
        {
            scale=obraz->GetWidth()/250;
        }
        else
        {
            scale=obraz->GetHeight()/250;
        }
        obraz->Rescale(obraz->GetWidth()/scale,obraz->GetHeight()/scale);
        obraz3->SetBitmap(*obraz);
        obraz3->Show();
        obraz3->Enable();
        line;

    }
    else
    {
        line;
        obraz3->SetBitmap(*obraz);
        obraz3->Show();
        obraz3->Enable();
        line;
    }

    if (obraz_odkodowany->GetWidth()>250 || obraz_odkodowany->GetHeight()>250)
    {
        line;
        float scale;
        if (obraz_odkodowany->GetWidth()/250>obraz_odkodowany->GetHeight()/250)
        {
            scale=obraz_odkodowany->GetWidth()/250;
        }
        else
        {
            scale=obraz_odkodowany->GetHeight()/250;
        }
        line;
        obraz_odkodowany->Rescale(obraz_odkodowany->GetWidth()/scale,obraz_odkodowany->GetHeight()/scale);
        obraz4->SetBitmap(*obraz_odkodowany);
        obraz4->Show();
        obraz4->Enable();
        line;

    }
    else
    {
        line;
        obraz4->SetBitmap(*obraz_odkodowany);
        obraz4->Show();
        obraz4->Enable();
        line;
    }
    line;
}
