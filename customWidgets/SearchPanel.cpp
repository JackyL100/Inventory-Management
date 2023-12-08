#include "SearchPanel.hpp"


SearchPanel::SearchPanel(wxSplitterWindow* splitter) {
    searchSplitter = new wxSplitterWindow(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);
    searchbar = new wxSearchCtrl(searchSplitter, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    searchResults = new wxListView(searchSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize);

    for (int i = 0; i < Item::formFields.size(); i++) {
        searchResults->AppendColumn(Item::formFields[i]);
    }
    
    searchResults->SetBackgroundColour(wxColor(100,200,200));
    searchResults->SetForegroundColour(wxColor(0,0,0));

    searchSplitter->SetMinimumPaneSize(25);
    searchSplitter->SplitHorizontally(searchbar, searchResults, 25);
    searchSplitter->SetBackgroundColour(wxColor(200,200,200));
    searchSplitter->SetSashInvisible(true);

    //searchbar->Bind(wxEVT_SEARCHCTRL_SEARCH_BTN, &MyFrame::Search, this);
    searchbar->SetBackgroundColour(wxColor(100,100,100));

    numItems = 0;
}

void SearchPanel::CreateNewItem(wxCommandEvent& event) {
    std::vector<wxString> itemInfo;
    NewItemDialog dlg(itemInfo, Item::formFields, Item::formFilters);
    dlg.ShowModal();
    std::vector<std::string> itemData;
    std::cout << "Created Item\n";
    searchResults->InsertItem(numItems, itemInfo[0]);
    for (int i = 1; i < itemInfo.size(); i++) {
        searchResults->SetItem(numItems, i, itemInfo[i]);
        itemData.push_back(itemInfo[i].ToStdString());
    }
    numItems++;
}