//g++ -std=c++20 masterClient.cpp mainFrame.cpp Database/DB.cpp Database/item.cpp Database/StatementAssembler.cpp Database/sqlite3.o customWidgets/NewItemDialog.cpp customWidgets/SearchPanel.cpp `/usr/local/wxWidgets-3.2.3/macbuild/wx-config --cxxflags --libs`

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include "masterClient.hpp"

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "Hello Bear", wxPoint(50, 50), wxSize(1440, 790) );
    frame->Center();
    frame->Show( true );
    return true;
}
