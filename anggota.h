#ifndef ANGGOTA_H
#define ANGGOTA_H
#include <iostream>
#include <string>
#include "data.h"
#define head headAnggota
using namespace std;

void addAnggota(anggotaNode *&head, int id, string nama, string telp, int umur, string paket, string jenisKelamin, string pelatih, string passAnggota){
    loadAnggota(head, id, nama, telp, umur, paket, jenisKelamin, pelatih, passAnggota);
    countIdAnggota++;
    saveToDatabase();
};

void viewAnggota(){
    anggotaNode *current = head;
    if (head == NULL){
        cout << "Tidak ada anggota yang terdaftar." << endl;
        return;
    }
    while (current != NULL){
        cout << "ID: "<<current->id<<"\nNama: "<<current->nama<<"\nNo. Telp: "<<current->telp<<"\nUmur: "<<current->umur<<"\nPaket: "<<current->paket<<"\nJenis Kelamin: "<<current->jenisKelamin<<"\nPelatih: "<<current->pelatih<<endl<<endl;
        current = current->next;
    }
}

void editAnggota(anggotaNode *&head, int id, string nama, string telp, int umur, string paket, string jenisKelamin, string pelatih){
    anggotaNode *current = head;
    while (current != NULL && current->id != id){
        current = current->next;
    }
    if (current == NULL){
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

void hapusAnggota(anggotaNode *&head, int id){
    anggotaNode *current = head;
    anggotaNode *previous = NULL;
    while (current != NULL && current->id != id){
        previous = current;
        current = current->next;
    }
    if (current == NULL){
        cout << "Anggota dengan ID " << id << " tidak ditemukan." << endl;
        return;
    }
    if (previous == NULL){
        head = current->next;
    } else {
        previous->next = current->next;
    }
    delete current;
    cout << "Anggota dengan ID " << id << " telah dihapus." << endl;
    saveToDatabase();
}

void fungsiTambahAnggota(){
    int id = countIdAnggota + 1;
    char passAnggotaArray[7]={};
    char newChar;
    for (int i = 0; i < 6; i++){
        newChar = randomLetter();
        passAnggotaArray[i] = newChar;
    }
    passAnggotaArray[6] = '\0'; // Menambahkan null terminator
    string passAnggota = string (passAnggotaArray);
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
    addAnggota(head, id, nama, telp, umur, paket, jenisKelamin, pelatih, passAnggota);
    cout << "Anggota berhasil ditambahkan dengan ID: " << id << endl;
}

void fungsiHapusAnggota(){
    int id;
    cout << "Masukkan ID anggota yang ingin dihapus: ";
    cin >> id;
    hapusAnggota(head, id);
}

void fungsiEditAnggota(){
    int id;
    string nama;
    string telp;
    int umur;
    string paket;
    string jenisKelamin;
    string pelatih;
    cout << "Masukkan id anggota yang ingin diedit: ";
    cin >> id;
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
    editAnggota(head, id, nama, telp, umur, paket, jenisKelamin, pelatih);
    cout << "Data anggota dengan ID " << id << " telah diperbarui." << endl;
}

void menuAnggota(){
    int pilihan;
    pilihan = 0;
    while (true){
        cout << "\nMenu Manajemen Anggota:" << endl;
        cout << "1. Tambah Anggota" << endl;
        cout << "2. Hapus Anggota" << endl;
        cout << "3. Lihat Anggota" << endl;
        cout << "4. Edit Anggota" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilih menu: ";

        cin >> pilihan;
        cin.ignore();
        if (pilihan == 1){
            fungsiTambahAnggota();
            continue;
        } else if (pilihan == 2){
            fungsiHapusAnggota();
            continue;
        } else if (pilihan == 3){
            viewAnggota();
            continue;
        } else if (pilihan == 4){
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