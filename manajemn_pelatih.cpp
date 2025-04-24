#include <iostream>
#include <regex> 
using namespace std;
#include "data.h"

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

// Melihat Pelatih
void lihatpelatih(){
    if (jumlahpelatih == 0){
        cout << "Belum ada pelatih" << endl;
        return;
    }

    for (int i = 0; i < jumlahpelatih; i++)
    {
        pelatih* p = &datapelatih[i];
        cout << "[" << i + 1 << "]" << endl;
        cout << "Nama : " << p->nama << endl;
        cout << "Spesialis : " << p->spesialis << endl;
        cout << "Umur : " << p->umur << endl;
        cout << "Jenis Kelamin : " << p->jeniskelamin << endl;
        cout << "No. Telepon : " << p->notelp << endl;
    }
}

//Menambah Pelatih
void tambahpelatih(){
    if (jumlahpelatih >= MAX) {
        cout << "Data Penuh." << endl;
        return;
    }

    pelatih* p = &datapelatih[jumlahpelatih];

    cin.ignore();
    cout << "Nama : "; getline(cin, p->nama);
    cout << "Spesialis : "; getline(cin, p->spesialis);

    //Validasi umur
    string umurStr;
    while (true) {
        cout << "Umur : "; getline(cin, umurStr);
        if (isNumber(umurStr)) {
            p->umur = stoi(umurStr);
            break;
        } else {
            cout << "Umur harus berupa angka. Silahkan coba lagi!" << endl;
        }
    }

    //Validasi jenis kelamin
    string gender;
    while (true) {
        cout << "Jenis Kelamin (Laki-laki/Perempuan) : "; getline(cin, gender);
        if (isValidGender(gender)) {
            if (gender == "laki-laki") gender = "Laki-laki";
            else if (gender == "perempuan") gender = "Perempuan";
            p->jeniskelamin = gender;
            break;
        } else {
            cout << "Jenis kelamin hanya bisa 'Laki-laki' atau 'Perempuan'. Silahkan coba lagi." << endl;
        }
    }

    //Validasi nomor telepon
    string notelp;
    while (true) {
        cout << "No. Telepon : "; getline(cin, notelp);
        if (isValidPhone(notelp)) {
            p->notelp = notelp;
            break;
        } else {
            cout << "Nomor telepon hanya boleh angka dan bisa diawali dengan '+'. Silahkan coba lagi." << endl;
        }
    }

    //Generate unique username
    string baseUsername = p->nama;
    string username = baseUsername;
    int counter = 1;
    for (int i = 0; i < jumlahpelatih; i++) {
        if (datapelatih[i].username == username) {
            username = baseUsername + to_string(counter);
            counter++;
            i = -1; //Restart the check
        }
    }
    p->username = username;

    //Generate random password
    initializeRandomSeed();
    char passPelatihArray[7] = {};
    for (int i = 0; i < 6; i++) {
        passPelatihArray[i] = randomLetter();
    }
    passPelatihArray[6] = '\0';
    p->password = string(passPelatihArray);

    jumlahpelatih++;
    cout << "Pelatih berhasil ditambahkan dengan username: " << p->username 
         << " dan password: " << p->password << endl;
    saveToDatabase();
}

//Mengedit Pelatih
void editpelatih(){
    string nama;
    cout << "Masukkan nama pelatih yang ingin diedit: "; cin.ignore(); getline(cin, nama);

    for (int i = 0; i < jumlahpelatih; i++){
        if (datapelatih[i].nama == nama)
        {
            pelatih* p = &datapelatih[i];

            cout << "Nama Baru : "; getline(cin, p->nama);
            cout << "Spesialis Baru : "; getline(cin, p->spesialis);

            //Validasi umur
            string umurStr;
            while (true) {
                cout << "Umur Baru : "; getline(cin, umurStr);
                if (isNumber(umurStr)) {
                    p->umur = stoi(umurStr);
                    break;
                } else {
                    cout << "Umur harus berupa angka. Coba lagi." << endl;
                }
            }

            //Validasi jenis kelamin
            string gender;
            while (true) {
                cout << "Jenis Kelamin Baru (Laki-laki/Perempuan) : "; getline(cin, gender);
                if (isValidGender(gender)) {
                    if (gender == "laki-laki") gender = "Laki-laki";
                    else if (gender == "perempuan") gender = "Perempuan";
                    p->jeniskelamin = gender;
                    break;
                } else {
                    cout << "Jenis kelamin hanya bisa 'Laki-laki' atau 'Perempuan'. Silahkan coba lagi." << endl;
                }
            }

            //Validasi nomor telepon
            string notelp;
            while (true) {
                cout << "No. Telepon Baru : "; getline(cin, notelp);
                if (isValidPhone(notelp)) {
                    p->notelp = notelp;
                    break;
                } else {
                    cout << "Nomor telepon hanya boleh angka dan bisa diawali dengan '+'. Silahkan coba lagi." << endl;
                }
            }

            cout << "Data berhasil diedit." << endl;
            saveToDatabase();
            return;
        }
    }
    cout << "Pelatih tidak ditemukan." << endl;
}

//Menghapus Pelatih
void hapuspelatih()
{
    string nama;
    cout << "Masukkan nama pelatih yang ingin dihapus : ";
    cin.ignore();
    getline(cin, nama);

    for (int i = 0; i < jumlahpelatih; i++)
    {
        if (datapelatih[i].nama == nama)
        {
            for (int j = i; j < jumlahpelatih - 1; j++)
            {
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

//Menu Manajemen Pelatih
void menupelatih(){
    int pilihan;

    while (true){
        cout << "=== Menu Manajemen Pelatih==="<< endl;
        cout << "1. Lihat Pelatih" << endl;
        cout << "2. Tambah Pelatih" << endl;
        cout << "3. Edit Pelatih" << endl;
        cout << "4. Hapus Pelatih" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilih menu : "; cin >> pilihan;

        if (pilihan == 1){
            lihatpelatih();
        } else if (pilihan == 2){
            tambahpelatih();
        } else if (pilihan == 3){
            editpelatih();
        } else if (pilihan == 4){
            hapuspelatih();
        } else if (pilihan == 0){
            cout << "Kembali ke menu utama." << endl;
            break;
        } else{
            cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
        }
    }
}
