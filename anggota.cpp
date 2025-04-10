#include <iostream>
#include <string>
#include "data.cpp"
using namespace std;

void addAnggota(anggotaNode *&head, int id, string nama, int umur, string jenisKelamin){
    anggotaNode *newMember = new anggotaNode;
    anggotaNode *current = head;
    if (head != NULL){
    newMember->id = id;
    newMember->nama = nama;
    newMember->umur = umur;
    newMember->jenisKelamin = jenisKelamin;
    newMember->next = NULL;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = newMember;}
    else{
        newMember->id = id;
        newMember->nama = nama;
        newMember->umur = umur;
        newMember->jenisKelamin = jenisKelamin;
        newMember->next = head;
        head = newMember;
    }
    countIdAnggota++;
};

void viewAnggota(){
    anggotaNode *current;
    current = head;
    if (head == NULL){
        cout << "Tidak ada anggota yang terdaftar." << endl;
        return;
    }
    cout << "ID\tNama\tUmur\tJenis Kelamin" << endl;
    while (current != NULL){
        cout << current->id << "\t" << current->nama << "\t" << current->umur << "\t" << current->jenisKelamin << endl;
        current = current->next;
    }
}

void editAnggota(anggotaNode *&head, int id, string nama, int umur, string jenisKelamin){
    anggotaNode *current;
    current = head;
    while (current != NULL && current->id != id){
        current = current->next;
    }
    if (current == NULL){
        cout << "Anggota tidak ditemukan"<<endl;
        return;
    }
    current->nama = nama;
    current->umur = umur;
    current->jenisKelamin = jenisKelamin;
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
}

void fungsiTambahAnggota(){
    int id = countIdAnggota + 1;
    int umur;
    string nama;
    string jenisKelamin;
    cout << "Masukkan nama anggota: ";
    getline(cin, nama);
    cout << "Masukkan umur anggota: ";
    cin >> umur;
    cin.ignore();
    cout << "Masukkan jenis kelamin anggota: ";
    getline(cin, jenisKelamin);
    addAnggota(head, id, nama, umur, jenisKelamin);
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
    int umur;
    string jenisKelamin;
    cout << "Masukkan id anggota yang ingin diedit: ";
    cin >> id;
    cin.ignore();
    cout << "Masukkan nama baru anggota: ";
    getline (cin, nama);
    cout << "Masukkan umur baru anggota: ";
    cin >> umur;
    cin.ignore();
    cout << "Masukkan jenis kelamin baru anggota: ";
    getline (cin, jenisKelamin);
    editAnggota(head, id, nama, umur, jenisKelamin);
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
            continue;;
        } else if (pilihan == 2){
            fungsiHapusAnggota();
            continue;
        } else if (pilihan == 3){
            viewAnggota();
            continue;
        }else if (pilihan == 4){
            fungsiEditAnggota();
            continue;
        } else if(pilihan != 0) {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            continue;
        }
        else {
            break;
        }
}}