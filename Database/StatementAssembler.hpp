#include <string>
#include <vector> 
#include "item.hpp"

class StatementAssembler {
    private:
        void AddListToQuery(std::string& stmt, const std::vector<std::string>& list, std::string delim = ",");
    public:

        std::string AssembleInsert(std::string table, const std::vector<std::string>& columns, const std::vector<std::string>& values);
        std::string AssembleInsert(const std::vector<std::string>& values);

        std::string AssembleViewTable(std::string table);
        std::string AssembleDelete(std::string table, int id);
        //std::string AssembleUpdate(std::string table, int id, std::string column, std::string update); 
};