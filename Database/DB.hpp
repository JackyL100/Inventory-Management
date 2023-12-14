#include "sqlite3.h"
#include <string>
#include <iostream>
#include <cassert>
#include "item.hpp"
#include "StatementAssembler.hpp"

enum DB_TYPES {
    INTEGER,
    TEXT,
    REAL
};

class DB {
    private:
        sqlite3* db;
        sqlite3_stmt* currentPreparedStatement;
        std::vector<std::string> column_names;
        StatementAssembler assembler;
    public:
        static std::string type_to_string(DB_TYPES type);
        ~DB();
        DB(std::string db_path);
        DB(std::string db_path, std::string db_name, const std::vector<std::string>& column_names, const std::vector<DB_TYPES>& types);
        void viewTable(std::string table);
        void InsertItem(const Item& item);
        void DeleteItem(int id);
        void UpdateItem(std::string table, int id, std::string update);
};