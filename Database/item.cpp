#include "item.hpp"

std::vector<std::string> Item::formFields = {"Name", "Price", "Stock", "Vendor", "Description"};
std::vector<wxTextValidatorStyle> Item::formFilters = {wxFILTER_ASCII, wxFILTER_NUMERIC, wxFILTER_DIGITS, wxFILTER_ASCII, wxFILTER_ASCII};

Item::Item(std::vector<std::string> itemInfo) {
    
}

