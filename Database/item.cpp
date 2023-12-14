#include "item.hpp"

std::vector<std::string> Item::formFields = {"Name", "Price", "Stock", "Vendor", "Description"};
std::vector<std::string> Item::columns = {"ID","Name", "Price", "Stock", "Vendor", "Description"};
std::vector<wxTextValidatorStyle> Item::formFilters = {wxFILTER_ASCII, wxFILTER_NUMERIC, wxFILTER_DIGITS, wxFILTER_DIGITS, wxFILTER_ASCII};
int Item::id_count = 0;

Item::Item(std::vector<std::string> itemInfo) {
    assert(itemInfo.size() == Item::columns.size());
    id = std::stoi(itemInfo[0]);
    name = itemInfo[1];
    price = std::stof(itemInfo[2]);
    num_instock = std::stoi(itemInfo[3]);
    vendor = std::stoi(itemInfo[4]);
    description = itemInfo[5];
}

int Item::generateID() {
    id_count++;
    return id_count;
}

std::string Item::serialize() const {
    std::string ret = std::to_string(id);
    ret += " " + name;
    ret += " " + std::to_string(price);
    ret += " " + std::to_string(num_instock);
    ret += " " + std::to_string(vendor);
    ret += " " + description;
    return ret;
}
std::vector<std::string> Item::to_vec() const {
    std::string str = serialize();
    std::vector<std::string> vec;
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(" ")) != std::string::npos) {
        token = str.substr(0, pos);
        vec.push_back(token);
        str.erase(0, pos + 1);
    }
    vec.push_back(str);
    return vec;
}

