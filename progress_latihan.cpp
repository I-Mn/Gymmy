#include <iostream>
#include <string>
#include "data.h" // Include data.h for shared structures and functions
using namespace std;

void tambah() {
    dataList[data_ke] = new progress_latihan;

    cout << "=== Tambah Progress Latihan ===" << endl;

    cout << "Username anggota  : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer
    getline(cin, dataList[data_ke]->username);
    cout << "Jenis Latihan    : ";
    getline(cin, dataList[data_ke]->Jenis_Latihan); // Tidak perlu cin.ignore lagi
    cout << "Jumlah Set       : ";
    getline(cin, dataList[data_ke]->Jumlah_Set);
    cout << "Beban (kg)       : ";
    getline(cin, dataList[data_ke]->Beban);
    cout << "Durasi (menit)   : ";
    getline(cin, dataList[data_ke]->Durasi);
    cout << "Skala Latihan    : ";
    getline(cin, dataList[data_ke]->Skala_Latihan);
    cout << "Progress         : ";
    getline(cin, dataList[data_ke]->Progress);
    cout << "Catatan          : ";
    getline(cin, dataList[data_ke]->Catatan);

    data_ke++;
    saveToDatabase(); // Save to database after adding
    cout << "Data berhasil ditambahkan.\n";
}

void edit() {
    if (sesiRole != "PELATIH") {
        cout << "Hanya pelatih yang dapat mengedit data progress.\n";
        return;
    }

    string usernameToEdit, jenisLatihanToEdit;
    cout << "Masukkan username anggota yang ingin diedit: ";
    cin >> usernameToEdit;
    cin.ignore();
    cout << "Masukkan jenis latihan yang ingin diedit: ";
    getline(cin, jenisLatihanToEdit);

    int index = -1;
    for (int i = 0; i < data_ke; ++i) {
        if (dataList[i]->username == usernameToEdit && dataList[i]->Jenis_Latihan == jenisLatihanToEdit) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Data progress untuk username dan jenis latihan tersebut tidak ditemukan.\n";
        return;
    }

    cout << "=== Edit Progress Latihan ===" << endl;

    cout << "\nData untuk username: " << usernameToEdit << " dan jenis latihan: " << jenisLatihanToEdit << "\n";
    cout << "Jenis Latihan    : ";
    getline(cin, dataList[index]->Jenis_Latihan);
    cout << "Jumlah Set       : ";
    getline(cin, dataList[index]->Jumlah_Set);
    cout << "Beban (kg)       : ";
    getline(cin, dataList[index]->Beban);
    cout << "Durasi (menit)   : ";
    getline(cin, dataList[index]->Durasi);
    cout << "Skala Latihan    : ";
    getline(cin, dataList[index]->Skala_Latihan);
    cout << "Progress         : ";
    getline(cin, dataList[index]->Progress);
    cout << "Catatan          : ";
    getline(cin, dataList[index]->Catatan);

    saveToDatabase(); // Save to database after editing
    cout << "Data berhasil diedit.\n";
}

void hapus() {
    int index;
    cout << "Mau hapus data keberapa? ";
    cin >> index;
    if (index < 1 || index > data_ke) {
        cout << "Data tidak ditemukan.\n";
        return;
    }

    for (int i = index - 1; i < data_ke - 1; ++i) {
        dataList[i] = dataList[i + 1];
    }

    data_ke--;
    saveToDatabase(); // Save to database after deleting
    cout << "Data berhasil dihapus.\n";
}

void tampil() {
    if (sesiRole == "ANGGOTA"){
        for (int i = 0; i < data_ke; ++i){
            if (sesiUser == dataList[i]->username){
                cout << "\n=== Data Progress Latihan ===\n";
                cout << "Jenis Latihan    : " << dataList[i]->Jenis_Latihan << endl;
                cout << "Jumlah Set       : " << dataList[i]->Jumlah_Set << endl;
                cout << "Beban (kg)       : " << dataList[i]->Beban << endl;
                cout << "Durasi (menit)   : " << dataList[i]->Durasi << endl;
                cout << "Skala Latihan    : " << dataList[i]->Skala_Latihan << endl;
                cout << "Progress         : " << dataList[i]->Progress << endl;
                cout << "Catatan          : " << dataList[i]->Catatan << endl;
            }
        }
    }
    else{
    for (int i = 0; i < data_ke; ++i) {
        cout << "\nData ke-" << i + 1 << ":\n";
        cout << "\n=== Data Progress Latihan ===\n";
        cout << "Jenis Latihan    : " << dataList[i]->Jenis_Latihan << endl;
        cout << "Jumlah Set       : " << dataList[i]->Jumlah_Set << endl;
        cout << "Beban (kg)       : " << dataList[i]->Beban << endl;
        cout << "Durasi (menit)   : " << dataList[i]->Durasi << endl;
        cout << "Skala Latihan    : " << dataList[i]->Skala_Latihan << endl;
        cout << "Progress         : " << dataList[i]->Progress << endl;
        cout << "Catatan          : " << dataList[i]->Catatan << endl;
    }}
}

void menuProgress() {
    loadFromDatabase(); // Load data from database at the start
    int pilihan;

    while (true) {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Edit Data\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1)
            tambah();
        else if (pilihan == 2)
            edit();
        else if (pilihan == 3)
            tampil();
        else if (pilihan == 4)
            hapus();
        else if (pilihan == 5) {
            cout << "Keluar\n";
            break;
        } else {
            cout << "Pilih angka 1-5\n";
        }
    }
}