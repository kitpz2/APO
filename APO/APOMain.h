/***************************************************************
 * Name:      APOMain.h
 * Purpose:   Defines Application Frame
 * Author:    Paweł Zembrzuski ()
 * Created:   2009-04-03
 * Copyright: Paweł Zembrzuski ()
 * License:
 **************************************************************/

#ifndef APOMAIN_H
#define APOMAIN_H

//(*Headers(APOFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class APOFrame: public wxFrame
{
    public:

        APOFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~APOFrame();

    private:
        IMG *org;
        //(*Handlers(APOFrame)
        void OnQuit(wxCommandEveInt& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(APOFrame)
        static const long ID_STATICBITMAP1;
        static const long ID_BUTTON1;
        static const long ID_PANEL1;
        static const long ID_MENUITEM1;
        static const long idMenuQuit;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM14;
        static const long ID_MENUITEM16;
        static const long ID_MENUITEM17;
        static const long ID_MENUITEM18;
        static const long ID_MENUITEM19;
        static const long ID_MENUITEM20;
        static const long cw3_1_1;
        static const long ID_MENUITEM8;
        static const long ID_MENUITEM9;
        static const long ID_MENUITEM10;
        static const long ID_MENUITEM6;
        static const long ID_MENUITEM11;
        static const long ID_MENUITEM12;
        static const long ID_MENUITEM13;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(APOFrame)
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem5;
        wxMenu* Menu3;
        wxButton* Button1;
        wxStaticBitmap* StaticBitmap1;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem14;
        wxMenuItem* MenuItem11;
        wxMenuItem* MenuItem15;
        wxMenuItem* MenuItem22;
        wxPanel* Panel1;
        wxMenuItem* MenuItem13;
        wxMenu* MenuItem8;
        wxMenuItem* MenuItem10;
        wxMenuItem* MenuItem12;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem20;
        wxStatusBar* StatusBar1;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem21;
        wxMenuItem* MenuItem16;
        wxMenu* Menu8;
        wxMenu* Menu6;
        wxMenuItem* MenuItem9;
        wxMenuItem* MenuItem18;
        wxMenu* Menu5;
        wxMenu* Menu4;
        wxMenuItem* MenuItem19;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // APOMAIN_H
