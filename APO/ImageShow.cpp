#include "wx_pch.h"
#include "ImageShow.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(ImageShow)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(ImageShow)
//*)

#include "apo_lib.hpp"

//(*IdInit(ImageShow)
const long ImageShow::ID_STATICBITMAP1 = wxNewId();
const long ImageShow::ID_STATICBITMAP3 = wxNewId();
const long ImageShow::ID_STATICBITMAP4 = wxNewId();
const long ImageShow::ID_STATICBITMAP5 = wxNewId();
const long ImageShow::ID_BUTTON1 = wxNewId();
const long ImageShow::ID_STATICBITMAP2 = wxNewId();
const long ImageShow::ID_STATICBITMAP6 = wxNewId();
const long ImageShow::ID_STATICBITMAP7 = wxNewId();
const long ImageShow::ID_STATICBITMAP8 = wxNewId();
const long ImageShow::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ImageShow,wxFrame)
	//(*EventTable(ImageShow)
	//*)
END_EVENT_TABLE()

ImageShow::ImageShow(IMG *org_n, IMG *przetworzony_n, wxWindow* parent)
{
	//(*Initialize(ImageShow)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxFlexGridSizer* FlexGridSizer2;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Po przetworzeniu"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableCol(1);
	FlexGridSizer1->AddGrowableRow(0);
	FlexGridSizer1->AddGrowableRow(1);
	bmp = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxSize(256,256), 0, _T("ID_STATICBITMAP1"));
	FlexGridSizer1->Add(bmp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Histogram"));
	r = new wxStaticBitmap(Panel1, ID_STATICBITMAP3, wxNullBitmap, wxDefaultPosition, wxSize(256,256), 0, _T("ID_STATICBITMAP3"));
	StaticBoxSizer3->Add(r, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	g = new wxStaticBitmap(Panel1, ID_STATICBITMAP4, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP4"));
	StaticBoxSizer3->Add(g, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	b = new wxStaticBitmap(Panel1, ID_STATICBITMAP5, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP5"));
	StaticBoxSizer3->Add(b, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Zapisz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Oryginalny"));
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer2->AddGrowableCol(0);
	FlexGridSizer2->AddGrowableCol(1);
	FlexGridSizer2->AddGrowableRow(0);
	FlexGridSizer2->AddGrowableRow(1);
	bmp_org = new wxStaticBitmap(Panel1, ID_STATICBITMAP2, wxNullBitmap, wxDefaultPosition, wxSize(256,256), 0, _T("ID_STATICBITMAP2"));
	FlexGridSizer2->Add(bmp_org, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Histogram"));
	r_org = new wxStaticBitmap(Panel1, ID_STATICBITMAP6, wxNullBitmap, wxDefaultPosition, wxSize(256,256), 0, _T("ID_STATICBITMAP6"));
	StaticBoxSizer4->Add(r_org, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	g_org = new wxStaticBitmap(Panel1, ID_STATICBITMAP7, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP7"));
	StaticBoxSizer4->Add(g_org, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	b_org = new wxStaticBitmap(Panel1, ID_STATICBITMAP8, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP8"));
	StaticBoxSizer4->Add(b_org, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ImageShow::OnButton1Click);
	//*)
}

ImageShow::~ImageShow()
{
	//(*Destroy(ImageShow)
	//*)
}


void ImageShow::OnButton1Click(wxCommandEvent& event)
{
}
