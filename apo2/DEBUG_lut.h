#ifndef DEBUG_LUT_H
#define DEBUG_LUT_H
#include "../apo_lib.hpp"

//(*Headers(DEBUG_lut)
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/frame.h>
//*)

class DEBUG_lut: public wxFrame
{
	public:

		DEBUG_lut(LUT *lut, wxString window_name, wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DEBUG_lut();

		//(*Declarations(DEBUG_lut)
		wxStaticBitmap* bitmapa;
		wxPanel* Panel1;
		//*)

	protected:

		//(*Identifiers(DEBUG_lut)
		static const long ID_STATICBITMAP1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(DEBUG_lut)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
