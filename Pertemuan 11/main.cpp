#include <iostream>
using namespace std;

int main() {
    int size, a[50], i, j, minIndex, temp;

    cout << "=== PROGRAM SELECTION SORT ===\n";
    cout << "Masukkan ukuran array : ";
    cin >> size;

    // Input elemen array
    cout << "Masukkan elemen-elemen array:\n";
    for (i = 0; i < size; i++) {
        cin >> a[i];
    }

    // Cetak sebelum diurutkan
    cout << "\nSebelum Selection Sort:\n";
    for (i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Proses Selection Sort
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        // Tukar posisi
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    // Cetak setelah diurutkan
    cout << "\nSetelah Selection Sort:\n";
    for (i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
