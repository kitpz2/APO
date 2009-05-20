/***************************************************************
 * Name:      apo1Main.h
 * Purpose:   Defines Application Frame
 * Author:    Paweł Zembrzuski ()
 * Created:   2009-03-06
 * Copyright: Paweł Zembrzuski ()
 * License:
 **************************************************************/

#ifndef APO1MAIN_H
#define APO1MAIN_H
#include <wx/image.h>
#include "Image_show.h"
//(*Headers(apo1Frame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/filedlg.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class apo1Frame: public wxFrame
{
    public:

        apo1Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~apo1Frame();

    private:
        wxImage obraz;
        bool loaded;
        //(*Handlers(apo1Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(apo1Frame)
        static const long ID_BUTTON1;
        static const long ID_STATICBITMAP1;
        static const long ID_CHECKBOX1;
        static const long ID_CHECKBOX2;
        static const long ID_CHECKBOX4;
        static const long ID_CHECKBOX3;
        static const long ID_CHECKBOX6;
        static const long ID_CHECKBOX7;
        static const long ID_CHECKBOX5;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(apo1Frame)
        wxCheckBox* metoda2;
        wxStaticBitmap* podglad;
        wxButton* Button1;
        wxCheckBox* metoda5;
        wxCheckBox* metoda6;
        wxPanel* Panel1;
        wxFileDialog* FileDialog1;
        wxButton* Button2;
        wxCheckBox* metoda3;
        wxCheckBox* metoda1;
        wxStatusBar* StatusBar1;
        wxCheckBox* metoda7;
        wxCheckBox* metoda4;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // APO1MAIN_H
