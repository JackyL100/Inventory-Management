#include "StatementAssembler.hpp"

void StatementAssembler::AddListToQuery(std::string& stmt, const std::vector<std::string>& list, std::string delim) {
        for (int i = 0; i < list.size(); i++) {
            bool isText = i > 0 && Item::formFilters[i - 1] == wxFILTER_ASCII;
            if (isText) stmt += "'";
            stmt += list[i];
            if (isText) stmt += "'";
            stmt += ", ";
        }
    stmt.pop_back();
    stmt.pop_back();
}

std::string StatementAssembler::AssembleInsert(std::string table, const std::vector<std::string>& columns, const std::vector<std::string>& values) {
    std::string stmt = "INSERT INTO ";
    stmt += table + " (";
    AddListToQuery(stmt, columns);
    stmt += ") VALUES (";
    AddListToQuery(stmt, values);
    stmt += ");";
    return stmt;
}

std::string StatementAssembler::AssembleViewTable(std::string table) {
    return "SELECT * FROM " + table + ";";
}

std::string StatementAssembler::AssembleDelete(std::string table, int id) {
    return "DELETE FROM " + table + " WHERE id = " + std::to_string(id) + ";";
}