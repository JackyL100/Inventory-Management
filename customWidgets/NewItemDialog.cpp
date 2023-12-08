#include "NewItemDialog.hpp"

// move formFields and formFilters to item class
// create function that creates each field so more flexible
void NewItemDialog::createField(std::vector<std::string> fields, std::vector<wxTextValidatorStyle> filters) {
    
}


NewItemDialog::NewItemDialog(std::vector<wxString>& itemInfo, const std::vector<std::string>& formFields, const std::vector<wxTextValidatorStyle>& formFilters) : wxDialog(NULL, wxID_ANY, _("Create New Item"), wxDefaultPosition, wxSize(640, 360)) 
{

    wxFlexGridSizer* formSizer = new wxFlexGridSizer(formFields.size(), 2, 5, 5);
    itemInfo.resize(formFields.size());
    for (int i = 0; i < formFields.size(); i++) {
        formSizer->Add(new wxStaticText(this, wxID_ANY, _("&" + formFields[i] + ": ")), 0, wxALL | wxALIGN_RIGHT, 5);
        wxTextCtrl* textInput = new wxTextCtrl(this, wxID_ANY);
        form.push_back(textInput);
        form[i]->SetValidator(wxTextValidator(formFilters[i], &itemInfo[i]));
        formSizer->Add(form[i], 0, wxALL, 5); 
        textInput = nullptr;
    }
    wxBoxSizer* dialogSizer = new wxBoxSizer(wxVERTICAL);
    dialogSizer->Add(formSizer, 0, wxALL, 5);
    dialogSizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxALL, 5);
    SetSizerAndFit(dialogSizer);
    Center();
}