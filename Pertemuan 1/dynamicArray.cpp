#include <iostream>
using namespace std;

int main() 
{
    system("clear");
    int n;
    cout << "Masukkan Jumlah Elemen  Array : ";
    cin >> n;

    int* arr = new int[n];

    cout << "Masukkan " << n << " angka : \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Isi Array : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;

}