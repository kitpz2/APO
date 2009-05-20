/***************************************************************
 * Name:      apo1App.cpp
 * Purpose:   Code for Application Class
 * Author:    Paweł Zembrzuski ()
 * Created:   2009-03-06
 * Copyright: Paweł Zembrzuski ()
 * License:
 **************************************************************/

#include "apo1App.h"

//(*AppHeaders
#include "apo1Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(apo1App);

bool apo1App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	apo1Frame* Frame = new apo1Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
