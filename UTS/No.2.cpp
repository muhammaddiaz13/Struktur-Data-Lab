#include <iostream>
#include <string>
using namespace std;

struct Film {
    string judul;
    int tahun;
    int rating;
    Film* next;
};

class DaftarFilm {
private:
    Film* head;

public:
    DaftarFilm() {
        head = NULL;
    }

    void tambahDepan(string judul, int tahun, int rating) {
        Film* newFilm = new Film();
        newFilm->judul = judul;
        newFilm->tahun = tahun;
        newFilm->rating = rating;
        newFilm->next = head;
        head = newFilm;
    }

    void tambahTengah(string judul, int tahun, int rating, string setelah) {
        Film* current = head;
        while (current != NULL) {
            if (current->judul == setelah) {
                Film* newFilm = new Film();
                newFilm->judul = judul;
                newFilm->tahun = tahun;
                newFilm->rating = rating;
                newFilm->next = current->next;
                current->next = newFilm;
                return;
            }
            current = current->next;
        }
        cout << "Film " << setelah << " tidak ditemukan!\n";
    }

    void tambahBelakang(string judul, int tahun, int rating) {
        Film* newFilm = new Film();
        newFilm->judul = judul;
        newFilm->tahun = tahun;
        newFilm->rating = rating;
        newFilm->next = NULL;

        if (head == NULL) {
            head = newFilm;
            return;
        }

        Film* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newFilm;
    }

    void hapusFilm(string judul) {
        if (head == NULL) {
            cout << "Daftar film kosong!\n";
            return;
        }

        if (head->judul == judul) {
            Film* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Film* current = head;
        while (current->next != NULL) {
            if (current->next->judul == judul) {
                Film* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
        cout << "Film " << judul << " tidak ditemukan!\n";
    }

    void tampilkanDaftar() {
        Film* current = head;
        int count = 0;
        while (current != NULL) {
            cout << current->judul << " (" << current->tahun << ") - " 
                 << current->rating << endl;
            current = current->next;
            count++;
        }
        cout << "Total film tersisa: " << count << endl;
    }

    ~DaftarFilm() {
        Film* current = head;
        while (current != NULL) {
            Film* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    DaftarFilm daftar;
    int jumlahFilm;
    
    cout << "Masukkan jumlah film awal: ";
    cin >> jumlahFilm;
    cin.ignore();

    for (int i = 0; i < jumlahFilm; i++) {
        string judul;
        int tahun, rating;

        cout << "\nFilm " << i + 1 << ":\n";
        cout << "Judul: ";
        getline(cin, judul);
        cout << "Tahun: ";
        cin >> tahun;
        cout << "Rating: ";
        cin >> rating;
        cin.ignore();

        daftar.tambahBelakang(judul, tahun, rating);
    }

    char hapus;
    cout << "\nApakah ingin menghapus film? (y/n): ";
    cin >> hapus;
    
    if (hapus == 'y') {
        string judulHapus;
        cout << "Masukkan judul film yang sudah ditonton: ";
        cin.ignore();
        getline(cin, judulHapus);
        daftar.hapusFilm(judulHapus);
    }

    cout << "\nDaftar Film:\n";
    daftar.tampilkanDaftar();

    return 0;
}