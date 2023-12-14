#include "DB.hpp"


DB::DB(std::string db_path) {
    sqlite3_open(db_path.c_str(), &db);
    char* err;
    int rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS inventory(id INTEGER PRIMARY KEY, price REAL, num_stock INTEGER, vendor INTEGER, name TEXT, description TEXT)", NULL, NULL, &err);
    if (rc != SQLITE_OK) {
        std::cout << "error creating table\n";
    }

}


DB::DB(std::string db_path, std::string db_name, const std::vector<std::string>& column_names, const std::vector<DB_TYPES>& types){
    assert(column_names.size() == types.size() && "size of column_names list different from size of types");
    sqlite3_open(db_path.c_str(), &db);
    char* err;
    std::string creation_stmt = "CREATE TABLE IF NOT EXISTS " + db_name + "(";
    for (int i = 0; i < column_names.size(); i++) {
        std::string column_type = DB::type_to_string(types[i]);
        creation_stmt += column_names[i] + " " + column_type;
        if (i != column_names.size() - 1) {
            creation_stmt += ", ";
        } else {
            creation_stmt += ")";
        }
    }
    int rc = sqlite3_exec(db, creation_stmt.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK) {
        std::cout << "error creating table\n";
    }
}

DB::~DB() {
    sqlite3_close(db);
}


std::string DB::type_to_string(DB_TYPES type) {
    switch(type) {
        case DB_TYPES::INTEGER:
            return "INTEGER";
        case DB_TYPES::REAL:
            return "REAL";
        case DB_TYPES::TEXT:
            return "TEXT";
        default:
            return "";
    }
}

void DB::viewTable(std::string table) {
    std::string query = "SELECT * FROM " + table + ";";
    sqlite3_prepare_v2(db, query.c_str(), -1, &currentPreparedStatement, NULL);
    while (sqlite3_step(currentPreparedStatement) != SQLITE_DONE) {
        int id = sqlite3_column_int(currentPreparedStatement, 0);
        float price = sqlite3_column_double(currentPreparedStatement, 1);
        int num = sqlite3_column_int(currentPreparedStatement, 2);
        int vendor = sqlite3_column_int(currentPreparedStatement, 3);
        std::string name(reinterpret_cast<const char*>(sqlite3_column_text(currentPreparedStatement, 4)));
        std::string description(reinterpret_cast<const char*>(sqlite3_column_text(currentPreparedStatement, 5))); 
    }
}

void DB::InsertItem(const Item& item) {
    std::vector<std::string> values = item.to_vec();
    std::string query = assembler.AssembleInsert("inventory",Item::columns, values);
    char* e;
    std::cout << "Running query: " << query << "\n";
    int err = sqlite3_exec(db, query.c_str(), NULL, 0, &e);
    if (err != SQLITE_OK) {
        std::cout << "Error Inserting because " << e << "\n";
        sqlite3_free(e);
    } else {
        std::cout << "Successfully added Item\n";
    }
}

void DB::DeleteItem(int id) {

}

void DB::UpdateItem(std::string table, int id, std::string update) {

}