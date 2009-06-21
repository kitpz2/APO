/***************************************************************
 * Name:      SteganografiaMain.h
 * Purpose:   Defines Application Frame
 * Author:    Paweł Zembrzuski, Łukasz Pijarczyk (kitpz@gmail.com)
 * Created:   2009-06-10
 * Copyright: Paweł Zembrzuski, Łukasz Pijarczyk ()
 * License:
 **************************************************************/

#ifndef STEGANOGRAFIAMAIN_H
#define STEGANOGRAFIAMAIN_H

//(*Headers(SteganografiaFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class SteganografiaFrame: public wxFrame
{
    public:

        SteganografiaFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SteganografiaFrame();

    private:

        //(*Handlers(SteganografiaFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(SteganografiaFrame)
        static const long ID_BUTTON1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(SteganografiaFrame)
        wxButton* Button1;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // STEGANOGRAFIAMAIN_H
