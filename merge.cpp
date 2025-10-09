#include <iostream>
#include <vector>
using namespace std;

// Menggabungkan dua bagian array yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Panjang bagian kiri
    int n2 = right - mid;     // Panjang bagian kanan

    vector<int> L(n1), R(n2); // Array sementara untuk kiri dan kanan

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i]; // Salin bagian kiri
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; // Salin bagian kanan

    int i = 0, j = 0, k = left; // Indeks awal

    // Proses penggabungan dua bagian terurut
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; // Ambil dari kiri jika lebih kecil
            i++;
        } else {
            arr[k] = R[j]; // Ambil dari kanan jika lebih kecil
            j++;
        }
        k++;
    }

    // Salin sisa elemen kiri jika ada
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen kanan jika ada
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi rekursif utama merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return; // Basis rekursi

    int mid = left + (right - left) / 2; // Cari titik tengah

    mergeSort(arr, left, mid);       // Urutkan bagian kiri
    mergeSort(arr, mid + 1, right);  // Urutkan bagian kanan
    merge(arr, left, mid, right);    // Gabungkan hasilnya
}

// Cetak isi array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "Array sebelum diurutkan: ";
    printArray(data);

    mergeSort(data, 0, n - 1); // Proses pengurutan merge sort

    cout << "Array setelah diurutkan: ";
    printArray(data);

    return 0;
} 