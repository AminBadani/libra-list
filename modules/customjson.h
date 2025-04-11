#include <iostream>
#include <fstream>
#include "../lib/nlohmann/include/json.hpp"
using namespace std;

using json = nlohmann::json;

/**
 * Struct untuk menyimpan informasi tertentu dari buku
 */
struct Buku {
    string title;
    string authors;
    int year;
    string isbn;
};

/**
 * Mengubah string menjadi integer dengan memastikan string tidak kosong
 * @param str<string> String yang ingin diubah menjadi integer
 */
int safe_stoi(string str) {;
    if (str.size() != 4) return 0;
    return stoi(str);
}

/**
 * Membaca isi dari file .json dan memasukkannya ke dalam array of struct
 * @param namaFile Nama dari file .json yang ingin dibaca: contoh "books.json"
 */
vector<Buku> bacaJSON(string namaFile) {
    // cari file
    ifstream fileBuku(namaFile);
    
    // periksa apakah file ada
    if (fileBuku.is_open() == false) {
        cerr << "File tidak ditemukan: " << namaFile << endl;
        return vector<Buku>();
    }
    
    // baca isi dari file
    json isiJson = json::parse(fileBuku);
    // digunakan untuk menyimpan data dari .json
    vector<Buku> listBuku;

    // masukkan informasi dari setiap buku ke dalam listBuku
    for (const auto item : isiJson) {
        Buku dataBuku;
        
        dataBuku.title = to_string(item["title"]);
        dataBuku.authors = to_string(item["authors"]);
        
        dataBuku.year = safe_stoi( to_string(item["original_publication_year"]) );
        dataBuku.isbn = to_string(item["isbn"]);
        
        listBuku.push_back(dataBuku);
    }

    return listBuku;
}
