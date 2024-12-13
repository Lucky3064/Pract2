/*Write C++ program using STL for sorting and searching user defined records
such as personalrecords (Name, DOB, Telephone number etc) using vector 
container.
OR
Write C++ program using STL for sorting and searching user defined records
such as Item records (Item code, name, cost, quantity etc) using vector
container.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
    string name, dob, phone;
    bool operator<(Record& other) { return name < other.name; }
};

void display(vector<Record>& records) {
    for (auto& rec : records)
        cout << "Name: " << rec.name << ", DOB: " << rec.dob << ", Phone: " << rec.phone << endl;
}

int main() {
    vector<Record> records = {{"Alice", "1990-05-15", "1234567890"},
                              {"Bob", "1985-10-30", "9876543210"},
                              {"Charlie", "1992-07-20", "5556667777"}};

    // Sort records by name
    sort(records.begin(), records.end());
    cout << "Sorted Records:\n";
    display(records);

    // Search by name
    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;

    auto it = find_if(records.begin(), records.end(),
                      [&searchName](Record& r) { return r.name == searchName; });

    if (it != records.end())
        cout << "Found: " << it->name << ", DOB: " << it->dob << ", Phone: " << it->phone << endl;
    else
        cout << "Record not found!" << endl;

    return 0;
}
