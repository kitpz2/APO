#ifndef IMAGESHOW_H
#define IMAGESHOW_H

#include "apo_lib.hpp"
#ifndef WX_PRECOMP
	//(*HeadersPCH(ImageShow)
	#include <wx/sizer.h>
	#include <wx/panel.h>
	#include <wx/statbmp.h>
	#include <wx/button.h>
	#include <wx/frame.h>
	//*)
#endif
//(*Headers(ImageShow)
//*)

class ImageShow: public wxFrame
{
	public:

		ImageShow(IMG *org_n, IMG *przetworzony_n, wxWindow* parent=0);
		virtual ~ImageShow();

		//(*Declarations(ImageShow)
		wxStaticBitmap* g;
		wxStaticBitmap* b;
		wxStaticBitmap* b_org;
		wxButton* Button1;
		wxPanel* Panel1;
		wxStaticBitmap* g_org;
		wxStaticBitmap* bmp;
		wxStaticBitmap* r_org;
		wxStaticBitmap* r;
		wxStaticBitmap* bmp_org;
		//*)

	protected:

		//(*Identifiers(ImageShow)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICBITMAP3;
		static const long ID_STATICBITMAP4;
		static const long ID_STATICBITMAP5;
		static const long ID_BUTTON1;
		static const long ID_STATICBITMAP2;
		static const long ID_STATICBITMAP6;
		static const long ID_STATICBITMAP7;
		static const long ID_STATICBITMAP8;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(ImageShow)
		void OnButton1Click(wxCommandEvent& event);
		//*)

        IMG *org, *przetworzony;
		DECLARE_EVENT_TABLE()
};

#endif
