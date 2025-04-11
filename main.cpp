#include <iostream>
#include <vector>
#include "modules/customhash.h"
using namespace std;

int main() {
    vector<Book> listBuku; 

    bacaCSV(listBuku, "books.csv");
    cout << listBuku[0].title << endl;

    cout << endl;
}