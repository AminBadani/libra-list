#include <iostream>
using namespace std;

/**
 * Tipe data bentukan untuk membuat tree 
 */
struct CustomTree {
    int data;
    CustomTree *left;
    CustomTree *right;
};

/**
 * Tampilkan hierarki tree dan semua simpul yang ada di dalamnya
 */
void printBT(const std::string &prefix, const CustomTree *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        // print the value of the node
        std::cout << node->data << std::endl;
        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

/**
 * Tampilkan hierarki tree dan semua simpul yang ada di dalamnya
 * @param node Simpul akar atau simpul paling awal dari tree
 */
void printBT(const CustomTree* node)
{
    printBT("", node, false);
}

/**
 * Tambah simpul baru ke dalam tree 
 * @param simpul Simpul baru yang ingin ditambahkan
 * @param dataBaru Data baru yang ingin dimasukkan
 */
void tambahSimpul(CustomTree *&simpul, int dataBaru) {
    if (simpul == nullptr) {
        CustomTree *simpulBaru = new CustomTree;
        simpulBaru->data = dataBaru;
        simpulBaru->left = nullptr;
        simpulBaru->right = nullptr;
        simpul = simpulBaru;

    } else if (dataBaru < simpul->data) {
        tambahSimpul(simpul->left, dataBaru);

    } else if (dataBaru > simpul->data) {
        tambahSimpul(simpul->right, dataBaru);

    } else if (dataBaru == simpul->data) {
        cout << "Data sudah ada!";
    }
}

/**
 * Mengunjungi (travese) semua simpul dalam tree
 * @param simpul Simpul akal atau simpul palin awal dari tree
 */
void preOrder(CustomTree *simpul) {
    if (simpul != nullptr) {
        cout << simpul->data << " ";
        preOrder(simpul->left);
        preOrder(simpul->right);
    }
}