#include <iostream>
using namespace std;

int main() {
    system("clear");
    int n;
    cout << "Masukkan jumlah elemen data : ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data : ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Algoritma Bubble Sort dari terkecil hingga terbesar
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp; 
            }
        }
    }

    cout << "Data setelah diurutkan dari terkecil hingga terbesar : ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}