#include <iostream>
using namespace std;

int queue[100], n = 100, front = -1, rear = -1;

void Insert() {
    int val;
    if (rear == n - 1) {
        cout << "Queue Overflow" << endl;
    } else {
        if (front == -1) front = 0;
        cout << "Masukan Data Dalam Antrian : ";
        cin >> val;
        rear++;
        queue[rear] = val;
    }
}

void Delete() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
    } else {
        cout << "Hapus data dalam Antrian : " << queue[front] << endl;
        front++;
    }
}

void Display() {
    if (front == -1) {
        cout << "Data Antrian Kosong" << endl;
    } else {
        cout << "Data Antrian anda : ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int ch;
    cout << "1) Masukan Data ke Antrian" << endl;
    cout << "2) Hapus Data Dalam Antrian" << endl;
    cout << "3) Tampilkan Data Dalam Antrian" << endl;
    cout << "4) Exit" << endl;
    do {
        cout << "Masukan Pilihan : ";
        cin >> ch;
        switch (ch) {
            case 1: Insert(); break;
            case 2: Delete(); break;
            case 3: Display(); break;
            case 4: cout << "Exit" << endl; break;
            default: cout << "Pilihan Salah" << endl;
        }
    } while (ch != 4);
    return 0;
}

