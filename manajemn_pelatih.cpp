#include <iostream>
#include <regex>
#include <iomanip> //Untuk setw()
#include "data.h"
using namespace std;

//Validasi angka
bool isNumber(const string& str) {
    return regex_match(str, regex("^[0-9]+$"));
}

//Validasi nomor telepon
bool isValidPhone(const string& str) {
    return regex_match(str, regex("^\\+?[0-9]+$"));
}

//Validasi jenis kelamin
bool isValidGender(const string& str) {
    return (str == "Laki-laki" || str == "Perempuan" || str == "laki-laki" || str == "perempuan");
}

//Fungi Lihat Pelatih (Memakai array 2D untuk tampilan tabel)
void lihatpelatih() {
    if (jumlahpelatih == 0) {
        cout << "Belum ada pelatih." << endl;
        return;
    }

    string tabel[MAX][6]; //6 kolom

    for (int i = 0; i < jumlahpelatih; i++) {
        tabel[i][0] = to_string(i + 1);
        tabel[i][1] = datapelatih[i].nama;
        tabel[i][2] = datapelatih[i].spesialis;
        tabel[i][3] = to_string(datapelatih[i].umur);
        tabel[i][4] = datapelatih[i].jeniskelamin;
        tabel[i][5] = datapelatih[i].notelp;
    }

    //Header tabel
    cout << left << setw(5) << "No."
         << setw(20) << "Nama"
         << setw(15) << "Spesialis"
         << setw(6) << "Umur"
         << setw(15) << "Jenis Kelamin"
         << setw(15) << "No. Telepon" << endl;
    cout << string(76, '-') << endl;

    //Isi tabel
    for (int i = 0; i < jumlahpelatih; i++) {
        cout << left << setw(5) << tabel[i][0]
             << setw(20) << tabel[i][1]
             << setw(15) << tabel[i][2]
             << setw(6) << tabel[i][3]
             << setw(15) << tabel[i][4]
             << setw(15) << tabel[i][5] << endl;
    }
}

//Fungi Tambah Pelatih
void tambahpelatih() {
    if (jumlahpelatih >= MAX) {
        cout << "Data penuh." << endl;
        return;
    }

    pelatih* p = &datapelatih[jumlahpelatih];

    cin.ignore();
    cout << "Nama: "; getline(cin, p->nama);
    cout << "Spesialis: "; getline(cin, p->spesialis);

    string umurStr;
    while (true) {
        cout << "Umur: "; getline(cin, umurStr);
        if (isNumber(umurStr)) {
            p->umur = stoi(umurStr);
            break;
        } else {
            cout << "Umur harus berupa angka. Coba lagi!" << endl;
        }
    }

    string gender;
    while (true) {
        cout << "Jenis Kelamin (Laki-laki/Perempuan): "; getline(cin, gender);
        if (isValidGender(gender)) {
            if (gender == "laki-laki") gender = "Laki-laki";
            else if (gender == "perempuan") gender = "Perempuan";
            p->jeniskelamin = gender;
            break;
        } else {
            cout << "Masukkan hanya 'Laki-laki' atau 'Perempuan'." << endl;
        }
    }

    string notelp;
    while (true) {
        cout << "No. Telepon: "; getline(cin, notelp);
        if (isValidPhone(notelp)) {
            p->notelp = notelp;
            break;
        } else {
            cout << "Nomor hanya angka, bisa diawali dengan '+'. Coba lagi!" << endl;
        }
    }

    //Username unik
    string baseUsername = p->nama;
    string username = baseUsername;
    int counter = 1;
    for (int i = 0; i < jumlahpelatih; i++) {
        if (datapelatih[i].username == username) {
            username = baseUsername + to_string(counter++);
            i = -1;
        }
    }
    p->username = username;

    //Password acak
    initializeRandomSeed();
    char pass[7] = {};
    for (int i = 0; i < 6; i++) pass[i] = randomLetter();
    pass[6] = '\0';
    p->password = string(pass);

    jumlahpelatih++;
    cout << "Pelatih berhasil ditambahkan!" << endl;
    cout << "Username: " << p->username << " | Password: " << p->password << endl;

    saveToDatabase();
}

//Fungsi Edit Pelatih
void editpelatih() {
    string nama;
    cout << "Masukkan nama pelatih yang ingin diedit: ";
    cin.ignore(); getline(cin, nama);

    for (int i = 0; i < jumlahpelatih; i++) {
        if (datapelatih[i].nama == nama) {
            pelatih* p = &datapelatih[i];

            cout << "Nama Baru: "; getline(cin, p->nama);
            cout << "Spesialis Baru: "; getline(cin, p->spesialis);

            string umurStr;
            while (true) {
                cout << "Umur Baru: "; getline(cin, umurStr);
                if (isNumber(umurStr)) {
                    p->umur = stoi(umurStr);
                    break;
                } else {
                    cout << "Umur harus angka!" << endl;
                }
            }

            string gender;
            while (true) {
                cout << "Jenis Kelamin Baru (Laki-laki/Perempuan): "; getline(cin, gender);
                if (isValidGender(gender)) {
                    if (gender == "laki-laki") gender = "Laki-laki";
                    else if (gender == "perempuan") gender = "Perempuan";
                    p->jeniskelamin = gender;
                    break;
                } else {
                    cout << "Hanya 'Laki-laki' atau 'Perempuan'." << endl;
                }
            }

            string notelp;
            while (true) {
                cout << "No. Telepon Baru: "; getline(cin, notelp);
                if (isValidPhone(notelp)) {
                    p->notelp = notelp;
                    break;
                } else {
                    cout << "Format nomor salah!" << endl;
                }
            }

            cout << "Data berhasil diedit." << endl;
            saveToDatabase();
            return;
        }
    }
    cout << "Pelatih tidak ditemukan." << endl;
}

//Fungsi Hapus Pelatih
void hapuspelatih() {
    string nama;
    cout << "Masukkan nama pelatih yang ingin dihapus: ";
    cin.ignore(); getline(cin, nama);

    for (int i = 0; i < jumlahpelatih; i++) {
        if (datapelatih[i].nama == nama) {
            for (int j = i; j < jumlahpelatih - 1; j++) {
                datapelatih[j] = datapelatih[j + 1];
            }
            jumlahpelatih--;
            cout << "Pelatih berhasil dihapus." << endl;
            saveToDatabase();
            return;
        }
    }
    cout << "Pelatih tidak ditemukan." << endl;
}

//Menu Pelatih
void menupelatih() {
    int pilihan;
    while (true) {
        cout << "\n=== MENU MANAJEMEN PELATIH ===" << endl;
        cout << "1. Lihat Pelatih" << endl;
        cout << "2. Tambah Pelatih" << endl;
        cout << "3. Edit Pelatih" << endl;
        cout << "4. Hapus Pelatih" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            lihatpelatih();
        } else if (pilihan == 2) {
            tambahpelatih();
        } else if (pilihan == 3) {
            editpelatih();
        } else if (pilihan == 4) {
            hapuspelatih();
        } else if (pilihan == 0) {
            break;
        } else {
            cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }
    }
}
