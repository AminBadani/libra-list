#include <iostream>
#include <vector>
#include <fstream>
#include "lib/nlohmann/include/json.hpp"
using namespace std;

using json = nlohmann::json;

struct Buku {
    string title;
    string authors;
    int year;
    string isbn;
};

int safe_stoi(string s) {;
    if (s.size() != 4) return 0;
    return stoi(s);
}

int main() {
    system("clear");
    ifstream fileBuku("books.json");

    if (fileBuku.is_open() == false) {
        cerr << "File tidak ditemukan" << endl;
        return 0;
    }

    json isiJson = json::parse(fileBuku);

    vector<Buku> listBuku;

    for (const auto item : isiJson) {
        Buku bukuBaru;
        
        bukuBaru.title = to_string(item["title"]);
        bukuBaru.authors = to_string(item["authors"]);
        
        bukuBaru.year = safe_stoi( to_string(item["original_publication_year"]) );
        bukuBaru.isbn = to_string(item["isbn"]);
        
        listBuku.push_back(bukuBaru);
    }

    cout << listBuku[0].title << endl;
    cout << listBuku[0].authors << endl;
    cout << listBuku[0].year << endl;
    cout << listBuku[0].isbn << endl;

    cout << endl;
}