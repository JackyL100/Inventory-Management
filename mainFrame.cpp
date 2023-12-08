#include "mainFrame.hpp"

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size) 
{
    menuFile = new wxMenu;
    menuHelp = new wxMenu;
    menuBar = new wxMenuBar;
    frameSplitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);
    searchPanel = new SearchPanel(frameSplitter);
    wxPanel* panel = new wxPanel(frameSplitter);

    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->Append(ID_NewItem, "&Add Item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    menuHelp->Append(wxID_ABOUT);

    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    menuFile->Bind(wxEVT_MENU, &MyFrame::OnAbout, this, ID_Hello);
    menuFile->Bind(wxEVT_MENU, &SearchPanel::CreateNewItem, searchPanel, ID_NewItem);
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );

    panel->SetBackgroundColour(wxColor(100,100,200));
    frameSplitter->SetMinimumPaneSize(200);
    frameSplitter->SplitVertically(panel, searchPanel->searchSplitter);
    frameSplitter->SetSashPosition(200, true);
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
void MyFrame::OnTextEntered(wxCommandEvent& event)
{
    wxLogMessage(event.GetString());
}

void MyFrame::Search(wxCommandEvent& event) 
{
    std::cout << event.GetString() << "\n";
}