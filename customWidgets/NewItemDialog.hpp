#pragma once

#include <wx/wx.h>
#include <wx/valtext.h>
#include <vector>
#include <string>
#include <iostream>

class NewItemDialog : public wxDialog {
    private:
        std::vector<wxTextCtrl*> form;
        void createField(std::vector<std::string> fields, std::vector<wxTextValidatorStyle> filters);
    public:
        NewItemDialog(std::vector<wxString>& itemInfo, const std::vector<std::string>& formFields, const std::vector<wxTextValidatorStyle>& formFilters);
};