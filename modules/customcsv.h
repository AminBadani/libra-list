#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

struct Book {
    string title;
    string authors;
    int year;
    int isbn;
};


/**
 * Baca baris pertama dari .csv yang berisi header 
 * buat menjadi key-value pair. Key = index | value = header kolom 
 * @param file File yang akan dibaca
 */
unordered_map<string, int> bacaHeader(ifstream &file, string kolom) {
    string baris;

    getline(file, baris);
    stringstream headerColumn(baris);
    unordered_map<string, int> colNameToIndex;
    int index = 0;
    while (getline(headerColumn, kolom, ',')) {
        colNameToIndex[kolom] = index++;
    }

    return colNameToIndex;
}

/**
 * Baca .csv file dan setiap buku yang ada ke dalam struct Buku
 * @param listBuku List buku berupa array of struct yang memuat semua buku 
 * @param namaFile Nama dari file .csv yang ingin dibaca
 */
void bacaCSV(vector<Book> &listBuku, string namaFile) {
    ifstream file(namaFile);

    // Cek apakah file ditemukan
    if (file.is_open() == false) {
        cerr << "File '" << namaFile << "' tidak ditemukan" << endl;
    }
    
    string kolom;
    /**
     * Baca baris pertama dari .csv yang berisi header 
     * buat menjadi key-value pair. Key = index | value = header kolom 
     */
    unordered_map<string, int> headerNameToIndex = bacaHeader(file, kolom);

    vector<string> kolomDipilih = {"original_title"};
    vector<int> indexDipilih;

    // Masukkan index dari kolom header yang dipilih ke dalam indexDipilih
    for (const string name : kolomDipilih) {
        if (headerNameToIndex.count(name)) {
            indexDipilih.push_back(headerNameToIndex[name]);
        } else {
            cerr << "Kolom tidak ditemukan: " << name << endl;
        }
    }

    // Baca setiap kolom dan masukkan ke dalam struct Buku
    while (getline(file, kolom)) {
        stringstream rowStream(kolom);
        string cell;
        vector<string> allCells;

        while (getline(rowStream, cell, ',')) {
            allCells.push_back(cell);
        }

        Book bukuBaru;
        bukuBaru.title = allCells[indexDipilih[0]];

        listBuku.push_back(bukuBaru);
    }
} 
