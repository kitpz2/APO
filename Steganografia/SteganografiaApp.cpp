/***************************************************************
 * Name:      SteganografiaApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Paweł Zembrzuski, Łukasz Pijarczyk (kitpz@gmail.com)
 * Created:   2009-06-10
 * Copyright: Paweł Zembrzuski, Łukasz Pijarczyk ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "SteganografiaApp.h"

//(*AppHeaders
#include "Test_1_1.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SteganografiaApp);

bool SteganografiaApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Test_1_1* Frame = new Test_1_1(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
