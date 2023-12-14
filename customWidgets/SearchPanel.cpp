#include "SearchPanel.hpp"


SearchPanel::SearchPanel(wxSplitterWindow* splitter) {
    searchSplitter = new wxSplitterWindow(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);
    searchbar = new wxSearchCtrl(searchSplitter, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    searchResults = new wxListView(searchSplitter, wxID_ANY, wxDefaultPosition, wxDefaultSize);

    for (int i = 0; i < Item::columns.size(); i++) {
        searchResults->AppendColumn(Item::columns[i]);
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

std::vector<std::string> SearchPanel::CreateNewItem() {
    std::cout << "Creating Item\n";
    int id = Item::generateID();
    std::vector<wxString> itemInfo;
    std::cout << "Showing Dialog\n";
    NewItemDialog dlg(itemInfo, Item::formFields, Item::formFilters);
    dlg.ShowModal();
    std::vector<std::string> itemData;
    itemData.push_back(std::to_string(id));
    std::cout << "Created Item\n";
    searchResults->InsertItem(numItems, wxString::Format(wxT("%i"), id));   
    for (int i = 1; i < Item::columns.size(); i++) {
        searchResults->SetItem(numItems, i, itemInfo[i - 1]);
        itemData.push_back(itemInfo[i - 1].ToStdString());
    }
    return itemData;
}