#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int pil;
int add_pilih_admin1();
int add_baru_admin2();
int add_depan_admin3();
int add_belakang_admin4();
int delete_depan_admin5();
int delete_belakang_admin6();
int add_tampil_admin7();

struct simpul {
    char admin1[15]; // NIM
    char admin2[20]; // Nama
    char admin3[20]; // Prodi
    struct simpul *next;
} *baru, *awal = NULL, *akhir = NULL, *hapus, *bantu;

int clrscr() {
    system("cls");
    return 0;
}

int main() {
    do {
        clrscr();
        cout << "==== MENU SINGLE LINKED LIST ====" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Keluar" << endl;
        cout << "Inputkan pilihan Anda : ";
        cin >> pil;
        add_pilih_admin1();
    } while (pil != 6);
    return 0;
}

int add_pilih_admin1() {
    if (pil == 1)
        add_depan_admin3();
    else if (pil == 2)
        add_belakang_admin4();
    else if (pil == 3)
        delete_depan_admin5();
    else if (pil == 4)
        delete_belakang_admin6();
    else if (pil == 5)
        add_tampil_admin7();
    else if (pil == 6)
        cout << "Keluar dari program..." << endl;
    else
        cout << "Pilihan tidak valid!" << endl;

    return 0;
}

int add_baru_admin2() {
    baru = (simpul*)malloc(sizeof(simpul));
    cout << "Input NIM   : ";
    cin >> baru->admin1;
    cout << "Input Nama  : ";
    cin >> baru->admin2;
    cout << "Input Prodi : ";
    cin >> baru->admin3;
    baru->next = NULL;
    return 0;
}

int add_depan_admin3() {
    add_baru_admin2();
    if (awal == NULL) {
        awal = baru;
        akhir = baru;
    } else {
        baru->next = awal;
        awal = baru;
    }
    cout << "\nData berhasil ditambahkan di depan!\n";
    getch();
    return 0;
}

int add_belakang_admin4() {
    add_baru_admin2();
    if (awal == NULL) {
        awal = baru;
        akhir = baru;
    } else {
        akhir->next = baru;
        akhir = baru;
    }
    cout << "\nData berhasil ditambahkan di belakang!\n";
    getch();
    return 0;
}

int delete_depan_admin5() {
    if (awal == NULL) {
        cout << "\nData masih kosong!\n";
    } else {
        hapus = awal;
        awal = awal->next;
        free(hapus);
        if (awal == NULL)
            akhir = NULL;
        cout << "\nData berhasil dihapus dari depan!\n";
    }
    getch();
    return 0;
}

int delete_belakang_admin6() {
    if (awal == NULL) {
        cout << "\nData masih kosong!\n";
    } else if (awal == akhir) {
        free(awal);
        awal = NULL;
        akhir = NULL;
        cout << "\nData terakhir dihapus!\n";
    } else {
        bantu = awal;
        while (bantu->next != akhir) {
            bantu = bantu->next;
        }
        hapus = akhir;
        akhir = bantu;
        akhir->next = NULL;
        free(hapus);
        cout << "\nData berhasil dihapus dari belakang!\n";
    }
    getch();
    return 0;
}

int add_tampil_admin7() {
    if (awal == NULL) {
        cout << "\nData masih kosong!\n";
    } else {
        bantu = awal;
        cout << "\n===== DAFTAR DATA ADMIN =====\n";
        while (bantu != NULL) {
            cout << "NIM   : " << bantu->admin1 << endl;
            cout << "Nama  : " << bantu->admin2 << endl;
            cout << "Prodi : " << bantu->admin3 << endl;
            cout << "-----------------------------\n";
            bantu = bantu->next;
        }
    }
    getch();
    return 0;
}
