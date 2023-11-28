#include "NewItemDialog.hpp"

NewItemDialog::NewItemDialog(std::vector<wxString>& itemInfo) : wxDialog(NULL, wxID_ANY, _("Create New Item"), wxDefaultPosition, wxSize(640, 360)) 
{
    std::vector<std::string> formFields = {"Name", "Price", "Stock", "Vendor", "Description"};
    std::vector<wxTextValidatorStyle> formFilters = {wxFILTER_ASCII, wxFILTER_NUMERIC, wxFILTER_DIGITS, wxFILTER_ASCII, wxFILTER_ASCII};
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