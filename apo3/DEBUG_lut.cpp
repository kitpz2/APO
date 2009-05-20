#include "DEBUG_lut.h"

//(*InternalHeaders(DEBUG_lut)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DEBUG_lut)
const long DEBUG_lut::ID_STATICBITMAP1 = wxNewId();
const long DEBUG_lut::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DEBUG_lut,wxFrame)
	//(*EventTable(DEBUG_lut)
	//*)
END_EVENT_TABLE()

DEBUG_lut::DEBUG_lut(LUT *lut, wxString window_name, wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DEBUG_lut)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	bitmapa = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxSize(256,256), 0, _T("ID_STATICBITMAP1"));
	BoxSizer2->Add(bitmapa, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
	SetTitle(window_name);
	if(lut!=NULL)
        bitmapa->SetBitmap(*lut->GetLutHistogram());
}

DEBUG_lut::~DEBUG_lut()
{
	//(*Destroy(DEBUG_lut)
	//*)
}

