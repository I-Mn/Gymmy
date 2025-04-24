#ifndef ANGGOTA_H
#define ANGGOTA_H
#include <iostream>
#include <string>
#include <vector>
#include "data.h"
#include <iomanip>
#include <cctype>
#define head headAnggota
using namespace std;

bool inputValid(string type, const string& a){
    if (a.empty()) return false;

    if (type == "telp"){
        for (char c : a){
            if (!isdigit(c) && c != '+' && c != '-' && c !=' ') return false;
        }
        int countDigit = 0;
        for (char c : a){
            if (isdigit(c)) countDigit++;
        }
        if (countDigit < 10 || countDigit > 15) return false;
    }

    if (type == "kelamin"){
        if (a != "Laki laki" && a != "Perempuan") return false;
    }

    if (type == "pelatih") {
        bool found = false;
        for (int i = 0; i < jumlahpelatih; i++) {
            if (datapelatih[i].username == a) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

void addAnggota(anggotaNode *&head, string nama, string telp, int umur, string paket, string jenisKelamin, string pelatih, string passAnggota) {
    string baseUsername = nama;
    string username = baseUsername;
    int counter = 1;

    anggotaNode *current = head;
    while (current != NULL) {
        if (current->username == username) {
            username = baseUsername + to_string(counter);
            counter++;
            current = head;
        } else {
            current = current->next;
        }
    }

    loadAnggota(head, nama, telp, umur, paket, jenisKelamin, pelatih, passAnggota, username);
    countIdAnggota++;
    saveToDatabase();
}

void viewAnggota() {
    anggotaNode *current = head;
    if (head == NULL) {
        cout << "Tidak ada anggota yang terdaftar." << endl;
        return;
    }
    cout << "\n======================= DAFTAR ANGGOTA =======================\n";

    cout << left << setw(20) << "Nama"
         << setw(15) << "Username"
         << setw(12) << "Password"
         << setw(18) << "No. Telp"
         << setw(6)  << "Umur"
         << setw(12) << "Paket"
         << setw(15) << "Jenis Kelamin"
         << setw(20) << "Nama Pelatih" << endl;
    
    cout << string(118, '-') << endl;

    while (current != NULL){
        cout << left << setw(20) << current->nama
             << setw(15) << current->username
             << setw(12) << current->pass
             << setw(18) << current->telp
             << setw(6)  << current->umur
             << setw(12) << current->paket
             << setw(15) << current->jenisKelamin
             << setw(20) << current->pelatih << endl;
        cout << string(118, '-') << endl;
        current = current->next;
    }
}

void editAnggota(anggotaNode *&head, string username, string nama, string telp, int umur, string paket, string jenisKelamin, string pelatih) {
    anggotaNode *current = head;
    while (current != NULL && current->username != username) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "Anggota tidak ditemukan" << endl;
        return;
    }
    current->nama = nama;
    current->telp = telp;
    current->umur = umur;
    current->paket = paket;
    current->jenisKelamin = jenisKelamin;
    current->pelatih = pelatih;
    saveToDatabase();
}

void hapusAnggota(anggotaNode *&head, string username) {
    anggotaNode *current = head;
    anggotaNode *previous = NULL;
    while (current != NULL && current->username != username) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        cout << "Anggota dengan username " << username << " tidak ditemukan." << endl;
        return;
    }
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    delete current;
    cout << "Anggota dengan username " << username << " telah dihapus." << endl;
    saveToDatabase();
}

void fungsiTambahAnggota() {
    initializeRandomSeed();
    char passAnggotaArray[7] = {};
    for (int i = 0; i < 6; i++) {
        passAnggotaArray[i] = randomLetter();
    }
    passAnggotaArray[6] = '\0';
    string passAnggota = string(passAnggotaArray);

    string telp, nama, paket, jenisKelamin, pelatih;
    int umur;

    while (true) {
        cout << "Masukkan nama anggota: ";
        getline(cin, nama);
        if (!nama.empty()) break;
        cout << "Nama tidak boleh kosong. Coba lagi.\n";
    }

    while (true) {
        cout << "Masukkan nomor telepon anggota: ";
        getline(cin, telp);
        if (inputValid("telp", telp)) break;
        cout << "Nomor telepon tidak valid. Coba lagi.\n";
    }

    while (true) {
        cout << "Masukkan umur anggota: ";
        cin >> umur;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid, masukkan angka bulat!\n";
        } else break;
    }
    cin.ignore();

    while (true) {
        cout << "Masukkan paket anggota: ";
        getline(cin, paket);
        if (!paket.empty()) break;
        cout << "Paket tidak boleh kosong. Coba lagi.\n";
    }

    while (true) {
        cout << "Masukkan jenis kelamin anggota: ";
        getline(cin, jenisKelamin);
        if (inputValid("kelamin", jenisKelamin)) break;
        cout << "Jenis kelamin harus 'Laki laki' atau 'Perempuan'. Coba lagi.\n";
    }

    while (true) {
        cout << "Masukkan nama pelatih anggota: ";
        getline(cin, pelatih);
        if (inputValid("pelatih", pelatih)) break;
        cout << "Pelatih tidak ditemukan. Masukkan nama pelatih yang valid.\n";
    }

    addAnggota(head, nama, telp, umur, paket, jenisKelamin, pelatih, passAnggota);
    cout << "Anggota berhasil ditambahkan dengan username: " << nama << endl;
}

void fungsiHapusAnggota() {
    string username;
    cout << "Masukkan username anggota yang ingin dihapus: ";
    cin >> username;
    hapusAnggota(head, username);
}

void fungsiEditAnggota() {
    string username, nama, telp, paket, jenisKelamin, pelatih;
    int umur;

    cout << "Masukkan username anggota yang ingin diedit: ";
    cin >> username;
    cin.ignore();

    while (true) {
        cout << "Masukkan nama baru anggota: ";
        getline(cin, nama);
        if (!nama.empty()) break;
        cout << "Nama tidak boleh kosong. Coba lagi.\n";
    }

    while (true) {
        cout << "Masukkan nomor telepon baru anggota: ";
        getline(cin, telp);
        if (inputValid("telp", telp)) break;
        cout << "Nomor telepon tidak valid. Coba lagi.\n";
    }

    while (true) {
        cout << "Masukkan umur baru anggota: ";
        cin >> umur;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid, masukkan angka bulat!\n";
        } else break;
    }
    cin.ignore();

    while (true) {
        cout << "Masukkan paket baru anggota: ";
        getline(cin, paket);
        if (!paket.empty()) break;
        cout << "Paket tidak boleh kosong. Coba lagi.\n";
    }

    while (true) {
        cout << "Masukkan jenis kelamin baru anggota: ";
        getline(cin, jenisKelamin);
        if (inputValid("kelamin", jenisKelamin)) break;
        cout << "Jenis kelamin harus 'Laki laki' atau 'Perempuan'. Coba lagi.\n";
    }

    while (true) {
        cout << "Masukkan nama pelatih baru anggota: ";
        getline(cin, pelatih);
        if (inputValid("pelatih", pelatih)) break;
        cout << "Pelatih tidak ditemukan. Masukkan nama pelatih yang valid.\n";
    }

    editAnggota(head, username, nama, telp, umur, paket, jenisKelamin, pelatih);
    cout << "Data anggota dengan username " << username << " telah diperbarui." << endl;
}

void menuAnggota() {
    int pilihan = 0;
    while (true) {
        cout << "\nMenu Manajemen Anggota:" << endl;
        cout << "1. Tambah Anggota" << endl;
        cout << "2. Hapus Anggota" << endl;
        cout << "3. Lihat Anggota" << endl;
        cout << "4. Edit Anggota" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilih menu: ";

        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) fungsiTambahAnggota();
        else if (pilihan == 2) fungsiHapusAnggota();
        else if (pilihan == 3) viewAnggota();
        else if (pilihan == 4) fungsiEditAnggota();
        else if (pilihan == 0) break;
        else cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
    }
}

#endif
