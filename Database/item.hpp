#pragma once

#include <string>
#include <vector>
#include <wx/wx.h>
#include <wx/valtext.h>

class Item {
    private:
        float price;
        int id;
        int num_instock;
        int vendor;
        std::string description;
        std::string name;
    public:
        static std::vector<std::string> formFields;
        static std::vector<std::string> columns;
        static std::vector<wxTextValidatorStyle> formFilters;
        static int generateID();
        static int id_count;
        Item(std::vector<std::string> itemInfo);
        std::string serialize() const;
        std::vector<std::string> to_vec() const;
};