#include <iostream>
using namespace std;

int data[10];
int n;

void tampil()
{
    for (int i = 0; i < n; i++)
    {
        cout << "[" << data[i] << "] ";
    }
    cout << endl;
}

int main()
{
    cout << "ALGORITMA BUBBLE SORT" << endl;
    cout << "----------------------" << endl;

    // Menentukan banyaknya jumlah data
    cout << "Masukkan jumlah data = ";
    cin >> n;

    cout << endl;

    // Input data
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan data ke-" << i + 1 << " = ";
        cin >> data[i];
    }

    cout << endl;
    cout << "Proses Bubble Sort:" << endl;

    tampil();

    // Proses sorting bubble
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (data[j] < data[j - 1])
            {
                // Tukar posisi data
                int t = data[j - 1];
                data[j - 1] = data[j];
                data[j] = t;
            }
        }
        tampil(); // Menampilkan hasil setiap tahap
    }

    cout << endl;
    cout << "Hasil akhir setelah diurutkan: ";
    tampil();

    return 0;
}
