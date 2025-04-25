#ifndef ANGGOTA_H
#define ANGGOTA_H
#include <iostream>
#include <string>
#include "data.cpp"
#include <vector>

#define head headAnggota
using namespace std;

void addAnggota(anggotaNode *&head, string nama, string telp, int umur, string paket, string jenisKelamin, string pelatih, string passAnggota) {
    string baseUsername = nama;
    string username = baseUsername;
    int counter = 1;

    // Ensure the username is unique
    anggotaNode *current = head;
    while (current != NULL) {
        if (current->username == username) {
            username = baseUsername + to_string(counter);
            counter++;
            current = head; // Restart the check
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
    while (current != NULL) {
        cout << "\nNama: "
             << current->nama << "\nNo. Telp: "
             << current->telp << "\nUmur: "
             << current->umur << "\nPaket: "
             << current->paket << "\nJenis Kelamin: "
             << current->jenisKelamin << "\nPelatih: "
             << current->pelatih << "\nUsername: "
             << current->username << "\nPassword: "
             << current->pass << endl << endl;
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
    initializeRandomSeed(); // Inisialisasi seed untuk random
    char passAnggotaArray[7] = {};
    char newChar;
    for (int i = 0; i < 6; i++) {
        newChar = randomLetter();
        passAnggotaArray[i] = newChar;
    }
    passAnggotaArray[6] = '\0'; // Menambahkan null terminator
    string passAnggota = string(passAnggotaArray);
    string telp;
    int umur;
    string nama;
    string paket;
    string jenisKelamin;
    string pelatih;
    cout << "Masukkan nama anggota: ";
    getline(cin, nama);
    cout << "Masukkan nomor telepon anggota: ";
    getline(cin, telp);
    cout << "Masukkan umur anggota: ";
    cin >> umur;
    cin.ignore();
    cout << "Masukkan paket anggota: ";
    getline(cin, paket);
    cout << "Masukkan jenis kelamin anggota: ";
    getline(cin, jenisKelamin);
    cout << "Masukkan nama pelatih anggota: ";
    getline(cin, pelatih);
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
    string username;
    string nama;
    string telp;
    int umur;
    string paket;
    string jenisKelamin;
    string pelatih;
    cout << "Masukkan username anggota yang ingin diedit: ";
    cin >> username;
    cin.ignore();
    cout << "Masukkan nama baru anggota: ";
    getline(cin, nama);
    cout << "Masukkan nomor telepon baru anggota: ";
    getline(cin, telp);
    cout << "Masukkan umur baru anggota: ";
    cin >> umur;
    cin.ignore();
    cout << "Masukkan paket baru anggota: ";
    getline(cin, paket);
    cout << "Masukkan jenis kelamin baru anggota: ";
    getline(cin, jenisKelamin);
    cout << "Masukkan nama pelatih baru anggota: ";
    getline(cin, pelatih);
    editAnggota(head, username, nama, telp, umur, paket, jenisKelamin, pelatih);
    cout << "Data anggota dengan username " << username << " telah diperbarui." << endl;
}

void menuAnggota() {
    int pilihan;
    pilihan = 0;
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
        if (pilihan == 1) {
            fungsiTambahAnggota();
            continue;
        } else if (pilihan == 2) {
            fungsiHapusAnggota();
            continue;
        } else if (pilihan == 3) {
            viewAnggota();
            continue;
        } else if (pilihan == 4) {
            fungsiEditAnggota();
            continue;
        } else if (pilihan != 0) {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            continue;
        } else {
            break;
        }
    }
}
#endif