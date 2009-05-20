/***************************************************************
 * Name:      APOApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Paweł Zembrzuski ()
 * Created:   2009-04-03
 * Copyright: Paweł Zembrzuski ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "APOApp.h"

//(*AppHeaders
#include "APOMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(APOApp);

bool APOApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	APOFrame* Frame = new APOFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
