#include <iostream>
using namespace std;
#include "data.h"

//Melihat Pelatih
void lihatpelatih(){
    if (jumlahpelatih == 0){
        cout << "Belum ada pelatih" << endl;
        return;
    }

    for (int i = 0; i < jumlahpelatih; i++)
    {
        pelatih* p = &datapelatih[i];
        cout << "[" << i + 1 << "]" << endl;
        cout << "Nama : " << p -> nama << endl;
        cout << "Spesialis : " << p -> spesialis << endl;
        cout << "Umur : " << p -> umur << endl;
        cout << "Jenis Kelamin : " << p -> jeniskelamin << endl;
        cout << "No. Telepon : " << p-> notelp << endl;
    }
}

//Menambah Pelatih
void tambahpelatih(){
    if (jumlahpelatih >= MAX)
    {
        cout << "Data Penuh." << endl;
        return;
    }

    pelatih* p = &datapelatih[jumlahpelatih];

    cin.ignore();
    cout << "Nama : "; getline(cin, p -> nama);
    cout << "Spesialis : "; getline(cin, p -> spesialis);
    cout << "Umur : "; cin >> p -> umur; 
    cin.ignore();
    cout << "Jenis Kelamin : "; getline(cin, p -> jeniskelamin);
    cout << "No. Telepon : "; getline(cin, p -> notelp);

    jumlahpelatih++;
    cout << "Pelatih berhasil ditambahkan." << endl;
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

            cout << "Nama Baru : "; getline(cin, p -> nama);
            cout << "Spesialis Baru : "; getline(cin, p -> spesialis);
            cout << "Umur Baru : "; cin >> p -> umur; cin.ignore();
            cout << "Jenis Kelamin Baru :  "; getline(cin, p -> jeniskelamin);
            cout << "No. Telepon Baru : "; getline(cin, p -> notelp);

            cout << "Data berhasil diedit." << endl;
            saveToDatabase();
            return;
        }
    }
    cout << "Pelatih tidak ditemukan." ;
    cout << "\n";
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
            cout << "Kembali ke menu utama.";
            break;
        } else{
            cout << "Pilihan tidak valid. Silahkan coba lagi.";
        }
    }
}

int main(){
    menupelatih();
    return 0;
}