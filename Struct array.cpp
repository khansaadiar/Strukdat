#include<iostream>
#include<string>
#include<cstdlib>
#include<conio.h>

using namespace std;

struct Orang {
    string ktp;
    string nama;
    string makananKesukaan;
    string warnaFavorit;
    string tanggalLahir;
    bool isDeleted;
};

const int MAX_ORANG = 10;
Orang database[MAX_ORANG];

// Fungsi untuk menampilkan data
void TampilkanData(int indeks) {
    if (indeks >= 0 && indeks < MAX_ORANG && !database[indeks].isDeleted) {
        cout << "Nomor KTP     : " << database[indeks].ktp << endl;
        cout << "Nama          : " << database[indeks].nama << endl;
        cout << "Makanan Fav   : " << database[indeks].makananKesukaan << endl;
        cout << "Warna Favorit : " << database[indeks].warnaFavorit << endl;
        cout << "Tanggal Lahir : " << database[indeks].tanggalLahir << endl;
    } else {
        cout << "Data tdk tersedia." << endl;
    }
}

// menambahkan data
void TambahData() {
    for (int i = 0; i < MAX_ORANG; ++i) {
        if (database[i].isDeleted) {
            cout << "Nomor KTP     : ";
            cin >> database[i].ktp;
            cout << "Nama          : ";
            cin >> database[i].nama;
            cout << "Makanan Fav   : ";
            cin >> database[i].makananKesukaan;
            cout << "Warna Favorit : ";
            cin >> database[i].warnaFavorit;
            cout << "Tanggal Lahir : ";
            cin >> database[i].tanggalLahir;
            database[i].isDeleted = false;
            cout << "Data berhasil ditambah!" << endl;
            return;
        }
    }
    cout << "Database penuh." << endl;
}

// menghapus data
void HapusData(int indeks) {
    if (indeks >= 0 && indeks < MAX_ORANG) {
        database[indeks].isDeleted = true;
        cout << "Data berhasil dihapus." << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

// mengubah data
void UbahData(int indeks) {
    if (indeks >= 0 && indeks < MAX_ORANG) {
        cout << "Nomor KTP     : ";
        cin >> database[indeks].ktp;
        cout << "Nama          : ";
        cin >> database[indeks].nama;
        cout << "Makanan Fav   : ";
        cin >> database[indeks].makananKesukaan;
        cout << "Warna Favorit : ";
        cin >> database[indeks].warnaFavorit;
        cout << "Tanggal Lahir : ";
        cin >> database[indeks].tanggalLahir;
        cout << "Data berhasil diperbarui!" << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

int main() {
    for (int i = 0; i < MAX_ORANG; ++i) {
        database[i].isDeleted = true;
    }

    int pilihan;
    while (true) {
        system("cls");
        cout << "Database Identitas Orang : " << endl;
        cout << "[1] Tambah Data" << endl;
        cout << "[2] Hapus Data" << endl;
        cout << "[3] Ubah Data" << endl;
        cout << "[4] Tampilkan Data" << endl;
        cout << "[5] Keluar" << endl;
        cout << "Input: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                TambahData();
                break;
            case 2:
                int indeksHapus;
                cout << "data yang ingin dihapus: ";
                cin >> indeksHapus;
                HapusData(indeksHapus);
                break;
            case 3:
                int indeksUbah;
                cout << "data yang ingin diubah: ";
                cin >> indeksUbah;
                UbahData(indeksUbah);
                break;
            case 4:
                int indeksTampil;
                cout << "data yang ingin ditampilkan: ";
                cin >> indeksTampil;
                TampilkanData(indeksTampil);
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                return 0;
            default:
                cout << "please try again." << endl;
                break;
        }

        cout << "klik tombol apapun untk next.";
        getch();
    }

    return 0;
}