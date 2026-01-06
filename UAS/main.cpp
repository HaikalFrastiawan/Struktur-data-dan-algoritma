#include <iostream>
#include <string>
using namespace std;

// Struktur Node BST
struct Node {
    int id;
    string nama;
    string jabatan;
    Node* left;
    Node* right;
};

// Fungsi membuat node baru
Node* createNode(int id, string nama, string jabatan) {
    Node* newNode = new Node();
    newNode->id = id;
    newNode->nama = nama;
    newNode->jabatan = jabatan;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi insert ke BST
Node* insert(Node* root, int id, string nama, string jabatan) {
    if (root == NULL) {
        return createNode(id, nama, jabatan);
    }

    if (id < root->id) {
        root->left = insert(root->left, id, nama, jabatan);
    } else if (id > root->id) {
        root->right = insert(root->right, id, nama, jabatan);
    }

    return root;
}

// Fungsi pencarian berdasarkan ID
Node* search(Node* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }

    if (id < root->id) {
        return search(root->left, id);
    }
    return search(root->right, id);
}

// Traversal PreOrder
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->id << " - " << root->nama << " (" << root->jabatan << ")" << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Traversal InOrder
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->id << " - " << root->nama << " (" << root->jabatan << ")" << endl;
        inOrder(root->right);
    }
}

// Traversal PostOrder
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->id << " - " << root->nama << " (" << root->jabatan << ")" << endl;
    }
}

int main() {
    Node* root = NULL;

    // Data awal karyawan (sesuai soal)
    root = insert(root, 100, "CEO", "CEO");
    root = insert(root, 80, "Andi", "Direktur Operasional");
    root = insert(root, 120, "Budi", "Direktur Teknologi");
    root = insert(root, 70, "Deni", "Manager Dev");
    root = insert(root, 90, "Eko", "Manager QA");
    root = insert(root, 110, "Fani", "Manager Sales");
    root = insert(root, 130, "Gita", "Manager HR");
    root = insert(root, 65, "Joko", "Staff");
    root = insert(root, 75, "Indra", "Staff");
    root = insert(root, 85, "Sari", "Staff");
    root = insert(root, 105, "Kiki", "Staff");
    root = insert(root, 115, "Lina", "Staff");

    cout << "\n=== Traversal InOrder ===\n";
    inOrder(root);

    cout << "\n=== Traversal PreOrder ===\n";
    preOrder(root);

    cout << "\n=== Traversal PostOrder ===\n";
    postOrder(root);

    // Pencarian karyawan
    int cariID;
    cout << "\nMasukkan ID yang ingin dicari: ";
    cin >> cariID;

    Node* hasil = search(root, cariID);
    if (hasil != NULL) {
        cout << "Data ditemukan:\n";
        cout << hasil->id << " - " << hasil->nama << " (" << hasil->jabatan << ")\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    return 0;
}
