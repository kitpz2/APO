#include "Image_show.h"
#include <cstdio>

//(*InternalHeaders(Image_show)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Image_show)
const long Image_show::ID_STATICBITMAP5 = wxNewId();
const long Image_show::ID_STATICBITMAP6 = wxNewId();
const long Image_show::ID_STATICBITMAP7 = wxNewId();
const long Image_show::ID_STATICBITMAP8 = wxNewId();
const long Image_show::ID_STATICBITMAP1 = wxNewId();
const long Image_show::ID_STATICBITMAP2 = wxNewId();
const long Image_show::ID_STATICBITMAP3 = wxNewId();
const long Image_show::ID_STATICBITMAP4 = wxNewId();
const long Image_show::ID_STATICTEXT2 = wxNewId();
const long Image_show::ID_STATICTEXT1 = wxNewId();
const long Image_show::ID_BUTTON1 = wxNewId();
const long Image_show::ID_SCROLLEDWINDOW1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Image_show,wxFrame)
    //(*EventTable(Image_show)
    //*)
END_EVENT_TABLE()

Image_show::Image_show(wxString sciezka, wxImage &obraz, wxString window_name, char metoda, wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(Image_show)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    ScrolledWindow1 = new wxScrolledWindow(this, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL|wxFULL_REPAINT_ON_RESIZE, _T("ID_SCROLLEDWINDOW1"));
    FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(0);
    FlexGridSizer1->AddGrowableRow(1);
    FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer4->AddGrowableCol(0);
    FlexGridSizer4->AddGrowableCol(1);
    FlexGridSizer4->AddGrowableCol(2);
    FlexGridSizer4->AddGrowableCol(3);
    FlexGridSizer4->AddGrowableRow(0);
    Obraz_po = new wxStaticBitmap(ScrolledWindow1, ID_STATICBITMAP5, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP5"));
    Obraz_po->SetMinSize(wxSize(250,250));
    FlexGridSizer4->Add(Obraz_po, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("Histogram po"));
    FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer5->AddGrowableCol(0);
    FlexGridSizer5->AddGrowableCol(1);
    FlexGridSizer5->AddGrowableCol(2);
    FlexGridSizer5->AddGrowableRow(0);
    Hist_po_R = new wxStaticBitmap(ScrolledWindow1, ID_STATICBITMAP6, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP6"));
    Hist_po_R->SetMinSize(wxSize(256,256));
    FlexGridSizer5->Add(Hist_po_R, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Hist_po_G = new wxStaticBitmap(ScrolledWindow1, ID_STATICBITMAP7, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP7"));
    FlexGridSizer5->Add(Hist_po_G, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Hist_po_B = new wxStaticBitmap(ScrolledWindow1, ID_STATICBITMAP8, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP8"));
    FlexGridSizer5->Add(Hist_po_B, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(FlexGridSizer5, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableCol(1);
    FlexGridSizer2->AddGrowableCol(2);
    FlexGridSizer2->AddGrowableCol(3);
    FlexGridSizer2->AddGrowableRow(0);
    Obraz_bmp = new wxStaticBitmap(ScrolledWindow1, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    Obraz_bmp->SetMinSize(wxSize(250,250));
    FlexGridSizer2->Add(Obraz_bmp, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, ScrolledWindow1, _("Histogram oryginalny"));
    FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer3->AddGrowableCol(0);
    FlexGridSizer3->AddGrowableCol(1);
    FlexGridSizer3->AddGrowableCol(2);
    FlexGridSizer3->AddGrowableRow(0);
    Hist_R = new wxStaticBitmap(ScrolledWindow1, ID_STATICBITMAP2, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP2"));
    Hist_R->SetMinSize(wxSize(256,256));
    FlexGridSizer3->Add(Hist_R, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Hist_G = new wxStaticBitmap(ScrolledWindow1, ID_STATICBITMAP3, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP3"));
    FlexGridSizer3->Add(Hist_G, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Hist_B = new wxStaticBitmap(ScrolledWindow1, ID_STATICBITMAP4, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP4"));
    FlexGridSizer3->Add(Hist_B, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer3, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    czas_wczyt = new wxStaticText(ScrolledWindow1, ID_STATICTEXT2, _("Czas wczytywania: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(czas_wczyt, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    czas = new wxStaticText(ScrolledWindow1, ID_STATICTEXT1, _("Czas wykonywania: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(czas, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(ScrolledWindow1, ID_BUTTON1, _("Zapisz Zmieniony obraz do pliku"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ScrolledWindow1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(ScrolledWindow1);
    FlexGridSizer1->SetSizeHints(ScrolledWindow1);
    BoxSizer1->Add(ScrolledWindow1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_SAVE|wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Image_show::OnButton1Click);
    //*)
    SetTitle(window_name);
    /*if (obraz2!=NULL)
    {
        obraz2->DrawHistogram(Hist_R, Hist_G, Hist_B);
        //obraz2->DrawDystrybuanta(Dyst_R, Dyst_G, Dyst_B);

        if (obraz2->GetWidth()>250 || obraz2->GetHeight()>250)
        {
            float scale;
            if (obraz2->GetWidth()/250>obraz2->GetHeight()/250)
            {
                scale=obraz2->GetWidth()/250;
            }
            else
            {
                scale=obraz2->GetHeight()/250;
            }
            scaled=obraz2->Scale(obraz2->GetWidth()/scale,obraz2->GetHeight()/scale);
            Obraz_bmp->SetBitmap(scaled);
        }
        else
        {
            Obraz_bmp->SetBitmap(obraz);
        }
    }
    else
    {*/
    struct ntptimeval start;
    struct ntptimeval stop;
    wxString temp;
    ntp_gettime(&start);
    Obraz_bmp->SetBitmap(obraz);

    obrazek=new IMG(sciezka);
    obrazek->DrawHistogram(Hist_R, Hist_G, Hist_B);
    ntp_gettime(&stop);
    temp.Clear();
    temp<<_("Czas Wczytywania obazu: ");
    temp<<double(((stop.time.tv_sec * 1000000)+stop.time.tv_usec) - ((start.time.tv_sec * 1000000 + -start.time.tv_usec)))/double(1000000);
    temp<<_(" s");
    czas_wczyt->SetLabel(temp);

    ntp_gettime(&start);
    if(metoda==1)
        obrazek_po=obrazek->HistogramEqualisation_1();
    else if(metoda==2)
        obrazek_po=obrazek->HistogramEqualisation_2();
    else if(metoda==3)
        obrazek_po=obrazek->HistogramEqualisation_3();
    else
        obrazek_po=obrazek->HistogramEqualisation_wlasna();
    obrazek_po->DrawHistogram(Hist_po_R, Hist_po_G, Hist_po_B);
    if (obrazek_po->GetWidth()>250 || obrazek_po->GetHeight()>250)
    {
        float scale;
        if (obrazek_po->GetWidth()/250>obrazek_po->GetHeight()/250)
        {
            scale=obrazek_po->GetWidth()/250;
        }
        else
        {
            scale=obrazek_po->GetHeight()/250;
        }
        scaled_po=obrazek_po->Scale(obrazek_po->GetWidth()/scale,obrazek_po->GetHeight()/scale);
        Obraz_po->SetBitmap(scaled_po);
    }
    else
    {
        Obraz_po->SetBitmap(*obrazek_po);
    }
    ntp_gettime(&stop);

    temp.Clear();
    temp<<_("Czas wykonywania obliczeń: ");
    temp<<double(((stop.time.tv_sec * 1000000)+stop.time.tv_usec) - ((start.time.tv_sec * 1000000 + -start.time.tv_usec)))/double(1000000);
    temp<<_(" s");
    czas->SetLabel(temp);
    //DEBUG_lut *temp=new DEBUG_lut(obrazek->GetLut(),window_name);
    //temp->Show();
}




Image_show::~Image_show()
{
    //(*Destroy(Image_show)
    //*)
}


void Image_show::OnButton1Click(wxCommandEvent& event)
{
    if(FileDialog1->ShowModal()==wxID_OK)
    {
        if(obrazek_po->SaveFile(FileDialog1->GetPath())==false)
        {
            if(obrazek_po->SaveFile(FileDialog1->GetPath(),wxBITMAP_TYPE_PNG)==false)
                wxMessageBox(_("Błąd przy zapisywaniu pliku!"), _("ERROR"));
        }
    }

}
