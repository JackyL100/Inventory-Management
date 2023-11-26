#include "NewItemDialog.hpp"

NewItemDialog::NewItemDialog() : wxDialog(NULL, wxID_ANY, _("Create New Item")) 
{
    std::vector<std::string> formFields = {"Name", "Price", "Stock", "Vendor", "Description"};
    wxFlexSizer* formSizer = new wxFlexSizer(formFields.size(), 2);
    for (int i = 0; i < formFields.size(); i++) {
        formSizer->Add(new wxStaticText(this, wxID_ANY, _("&" + formFields[i] + ": ")), 0, wxALL | wxALIGN_RIGHT, 5);
        form.emplace_back(this, wxID_ANY);
        formSizer->Add(form[i], 0, wxALL, 5); 
    }
    wxBoxSizer* dialogSizer = new wxBoxSizer(wxVERTICAL);
    dialogSizer->Add(formSizer, 0, wxALL, 5);
    dialogSizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxALL, 5);
    SetSizerAndFit(dialogSizer);
    Center();
}

Item NewItemDialog::getItem() 
{
    // add code to make item
    // find way to generalize so item members can be easily changed
    std::cout << "Created Item\n";
}