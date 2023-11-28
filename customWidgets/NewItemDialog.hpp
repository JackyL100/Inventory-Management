#include <wx/wx.h>
#include <wx/valtext.h>
#include <vector>
#include <string>
#include <iostream>

class NewItemDialog : public wxDialog {
    private:
        std::vector<wxTextCtrl*> form;
    public:
        NewItemDialog(std::vector<wxString>& itemInfo);
};