#include <iostream>
#include <vector>
#include "modules/customjson.h"
using namespace std;


int main() {
    system("clear");
    vector<Buku> listBuku = bacaJSON("books.json");

    cout << listBuku[0].title << endl;
    cout << listBuku[0].authors << endl;
    cout << listBuku[0].year << endl;
    cout << listBuku[0].isbn << endl;

    cout << endl;
}