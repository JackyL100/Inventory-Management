#include <wx/wx.h>
#include <vector>
#include <string>
#include <iostream>
#include "Database/item.hpp"

class NewItemDialog : public wxDialog {
    private:
        std::vector<wxTextCtrl*> form;
    public:
        NewItemDialog();
        Item getItem();
}