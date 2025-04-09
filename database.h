#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>

struct Record {
    int id;
    std::string name;
    int age;
};

class Database {
public:
    void addRecord(int id, const std::string& name, int age);
    void displayRecords() const;
    Record* searchRecord(int id);

    // Fungsi untuk menyimpan dan memuat data dalam format JSON
    void saveToJson(const std::string& filename) const;
    void loadFromJson(const std::string& filename);

private:
    std::vector<Record> records;
};

#endif // DATABASE_H