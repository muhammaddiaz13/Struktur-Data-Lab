#include <iostream>
#include <algorithm> // untuk sort()
#include <math.h>    // untuk floor()
using namespace std;

int main() {
    int N;

    cout << "Masukkan jumlah data: ";
    cin >> N;

    int data[N];
    cout << "Masukkan " << N << " data (acak):\n";
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    // Urutkan data ascending agar bisa digunakan untuk Interpolation Search
    sort(data, data + N);

    cout << "\nData setelah diurutkan: ";
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    int cari;
    cout << "\nMasukkan data yang ingin dicari: ";
    cin >> cari;

    int low = 0, high = N - 1, flag = 0;
    int posisi;
    float posisi1;

    // Proses Interpolation Search
    while (low <= high && cari >= data[low] && cari <= data[high]) {
        posisi1 = low + (float)(cari - data[low]) * (high - low) / (data[high] - data[low]);
        int pos = floor(posisi1); // pembulatan ke bawah

        cout << "Posisi perkiraan: " << posisi << " -> dibulatkan posisi" << endl;

        if (data[pos] == cari) {
            flag = 1;
            posisi = pos;
            break; 
        }

        if (data[pos] > cari) {
            high = pos - 1;

        } else {
            low = posisi + 1;
        }
    }
    

    cout << "\n\nHasil: ";
    if (flag == 1)
        cout << "Data " << cari << " ditemukan pada indeks ke-" << posisi << endl;
    else
        cout << "Data " << cari << " tidak ditemukan dalam array." << endl;

    return 0;
}