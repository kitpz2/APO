#ifndef IMAGE_SHOW_H
#define IMAGE_SHOW_H

#include <sys/timex.h>
#include "../apo_lib.hpp" //nasze
#include "DEBUG_lut.h"
//(*Headers(Image_show)
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/filedlg.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class Image_show: public wxFrame
{
	public:

		Image_show(wxString sciezka, wxImage &obraz, wxString window_name=_(""), char metoda=0, wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);

		virtual ~Image_show();

		//(*Declarations(Image_show)
		wxStaticBitmap* Obraz_po;
		wxStaticBitmap* Hist_po_R;
		wxScrolledWindow* ScrolledWindow1;
		wxStaticBitmap* Obraz_bmp;
		wxButton* Button1;
		wxStaticBitmap* Hist_R;
		wxStaticText* czas_wczyt;
		wxStaticText* czas;
		wxFileDialog* FileDialog1;
		wxStaticBitmap* Hist_G;
		wxStaticBitmap* Hist_po_B;
		wxStaticBitmap* Hist_po_G;
		wxStaticBitmap* Hist_B;
		//*)
        IMG *obrazek;   //obrazek ktory trzeba wczytac (obrazek oryginalny)
        IMG *obrazek_po;    //obrazek zwracany
        wxImage scaled; //zeskalwany obrazek przed
        wxImage scaled_po; //po jak wyzej
	protected:

		//(*Identifiers(Image_show)
		static const long ID_STATICBITMAP5;
		static const long ID_STATICBITMAP6;
		static const long ID_STATICBITMAP7;
		static const long ID_STATICBITMAP8;
		static const long ID_STATICBITMAP1;
		static const long ID_STATICBITMAP2;
		static const long ID_STATICBITMAP3;
		static const long ID_STATICBITMAP4;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON1;
		static const long ID_SCROLLEDWINDOW1;
		//*)

	private:

		//(*Handlers(Image_show)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
