#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama;
    string jenisHewan;
    int umur;
    int tingkatDarurat;
    int waktuKedatangan;
};

class AntrianPasien {
private:
    Pasien* antrian;
    int kapasitas;
    int jumlahPasien;

public:
    AntrianPasien(int ukuran) {
        kapasitas = ukuran;
        antrian = new Pasien[kapasitas];
        jumlahPasien = 0;
    }

    void tambahPasien(string nama, string jenisHewan, int umur, int tingkatDarurat) {
        if (jumlahPasien < kapasitas) {
            antrian[jumlahPasien].nama = nama;
            antrian[jumlahPasien].jenisHewan = jenisHewan;
            antrian[jumlahPasien].umur = umur;
            antrian[jumlahPasien].tingkatDarurat = tingkatDarurat;
            antrian[jumlahPasien].waktuKedatangan = jumlahPasien;
            jumlahPasien++;
        }
    }

    void urutkanPasien() {
        for (int i = 0; i < jumlahPasien - 1; i++) {
            for (int j = 0; j < jumlahPasien - i - 1; j++) {
                if (antrian[j].tingkatDarurat < antrian[j + 1].tingkatDarurat ||
                    (antrian[j].tingkatDarurat == antrian[j + 1].tingkatDarurat &&
                     antrian[j].waktuKedatangan > antrian[j + 1].waktuKedatangan)) {
                    Pasien temp = antrian[j];
                    antrian[j] = antrian[j + 1];
                    antrian[j + 1] = temp;
                }
            }
        }
    }

    void tampilkanUrutan() {
        for (int i = 0; i < jumlahPasien; i++) {
            cout << i + 1 << ". " << antrian[i].nama << " (" 
                 << antrian[i].umur << " tahun) - Darurat "
                 << antrian[i].tingkatDarurat << endl;
        }
    }

    ~AntrianPasien() {
        delete[] antrian;
    }
};

int main() {
    int jumlahPasien;
    cout << "Masukkan jumlah pasien: ";
    cin >> jumlahPasien;
    cin.ignore();

    AntrianPasien antrian(jumlahPasien);

    for (int i = 0; i < jumlahPasien; i++) {
        string nama, jenisHewan;
        int umur, tingkatDarurat;

        cout << "\nPasien " << i + 1 << ":\n";
        cout << "Nama hewan: ";
        getline(cin, nama);

        cout << "Jenis hewan: ";
        getline(cin, jenisHewan);

        cout << "Umur: ";
        cin >> umur;

        cout << "Tingkat darurat (1-5): ";
        cin >> tingkatDarurat;
        cin.ignore();

        antrian.tambahPasien(nama, jenisHewan, umur, tingkatDarurat);
    }

    cout << "\n-----------------------------------\n";
    cout << "Prioritas Penanganan Pasien:\n";
    cout << "-----------------------------------\n";
    
    antrian.urutkanPasien();
    antrian.tampilkanUrutan();

    return 0;
}