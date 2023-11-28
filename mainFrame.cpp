#include "mainFrame.hpp"

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->Append(ID_NewItem, "&Add Item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    menuFile->Bind(wxEVT_MENU, &MyFrame::OnAbout, this, ID_Hello);
    menuFile->Bind(wxEVT_MENU, &MyFrame::CreateNewItem, this, ID_NewItem);
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );

    wxSplitterWindow* frameSplitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);
    wxSplitterWindow* searchSplitter = new wxSplitterWindow(frameSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);
    wxSearchCtrl* searchbar = new wxSearchCtrl(searchSplitter, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    wxListView* searchResults = new wxListView(searchSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize);

    searchResults->InsertColumn(0, "Name");
    searchResults->InsertItem(0, "wah");
    searchResults->SetBackgroundColour(wxColor(100,200,200));
    searchResults->SetForegroundColour(wxColor(0,0,0));

    searchSplitter->SetMinimumPaneSize(25);
    searchSplitter->SplitHorizontally(searchbar, searchResults, 25);
    searchSplitter->SetBackgroundColour(wxColor(200,200,200));
    searchSplitter->SetSashInvisible(true);

    searchbar->Bind(wxEVT_SEARCHCTRL_SEARCH_BTN, &MyFrame::Search, this);
    searchbar->SetBackgroundColour(wxColor(100,100,100));

    wxPanel* panel = new wxPanel(frameSplitter);
    panel->SetBackgroundColour(wxColor(100,100,200));
    frameSplitter->SetMinimumPaneSize(200);
    frameSplitter->SplitVertically(panel, searchSplitter);
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

void MyFrame::CreateNewItem(wxCommandEvent& event)
{
    std::vector<wxString> itemInfo;
    NewItemDialog dlg(itemInfo);
    dlg.ShowModal();
    std::cout << "Created Item with: ";
    for (auto& data : itemInfo) {
        std::cout << data << "|";
    }
    std::cout << "\n";
}