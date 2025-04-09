#include <iostream>
#include "modules/customtree.h"
using namespace std;

CustomTree tree;

int main() {
    CustomTree *pohon = NULL;
    tambahSimpul(pohon, 25);
    tambahSimpul(pohon->left, 24);
    tambahSimpul(pohon->right, 26);
    tambahSimpul(pohon->left->left, 23);
    tambahSimpul(pohon->left->right, 27);
    tambahSimpul(pohon->right->left, 20);
    tambahSimpul(pohon->right->left->right, 30);

    printBT(pohon);

    preOrder(pohon);

    cout << endl;
}