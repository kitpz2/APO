#ifndef TEST_1_1_H
#define TEST_1_1_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(Test_1_1)
	#include <wx/sizer.h>
	#include <wx/panel.h>
	#include <wx/filedlg.h>
	#include <wx/statbmp.h>
	#include <wx/button.h>
	#include <wx/frame.h>
	//*)
#endif
//(*Headers(Test_1_1)
//*)
#include "apo_lib.hpp"

class Test_1_1: public wxFrame
{
	public:

		Test_1_1(wxWindow* parent=0,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Test_1_1();

		//(*Declarations(Test_1_1)
		wxStaticBitmap* obraz4;
		wxStaticBitmap* obraz3;
		wxButton* Button1;
		wxPanel* Panel1;
		wxFileDialog* FileDialog1;
		wxButton* Button2;
		wxStaticBitmap* obraz1;
		wxButton* Button3;
		wxStaticBitmap* obraz2;
		//*)

	protected:

		//(*Identifiers(Test_1_1)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICBITMAP1;
		static const long ID_STATICBITMAP2;
		static const long ID_STATICBITMAP3;
		static const long ID_STATICBITMAP4;
		static const long ID_BUTTON3;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(Test_1_1)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click1(wxCommandEvent& event);
		void OnButton2Click1(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		//*)
        bool loaded, loaded2;
        IMG *ObrazUkrywany, *ObrazUkrywajacy;

		DECLARE_EVENT_TABLE()
};

#endif
