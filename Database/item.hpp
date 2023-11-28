#include <string>
#include <vector>
class Item {
    private:
        float price;
        int id;
        int num_instock;
        int vendor;
        std::string description;
        std::string name;
    public:
        Item(std::vector<std::string> itemInfo);
};