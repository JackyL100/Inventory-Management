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
        SearchPanel(wxSplitterWindow* splitter);
        void CreateNewItem(wxCommandEvent& event);
};