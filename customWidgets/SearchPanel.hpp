#include <wx/wx.h>
#include <wx/srchctrl.h>
#include <wx/splitter.h>
#include <wx/listctrl.h>
#include "../Database/item.hpp"
#include "NewItemDialog.hpp"

class SearchPanel {
    private:
        int numItems;
    public:
        wxSplitterWindow* searchSplitter;
        wxSearchCtrl* searchbar;
        wxListView* searchResults;
        SearchPanel(wxSplitterWindow* splitter); // creates SearchPanel object with splitter as the parent
        std::vector<std::string> CreateNewItem(); // creates NewItemDialog instance
};