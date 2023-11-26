#include "sqlite3.h"
#include <string>
#include <iostream>
#include <cassert>

enum class DB_TYPES {
    INTEGER,
    TEXT,
    REAL
};

template <typename object>
class DB {
    private:
        sqlite3* db;
        sqlite3_stmt* currentPreparedStatement;
        std::vector<std::string> column_names;
    public:
        static std::string type_to_string(DB_TYPES type);
        DB(std::string db_path);
        DB(std::string db_path, std::string db_name, const std::vector<std::string>& column_names, const std::vector<DB_TYPES>& types);
        void viewTable(std::string table);
        std::vector<object> queryDB(std::string query);
};