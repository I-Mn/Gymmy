#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "data.h" // Include data.h for shared structures and functions
using namespace std;

void tambah() {
    dataList[data_ke] = new progress_latihan;

    cout << "=== Tambah Progress Latihan ===" << endl;

    cout << "Username anggota       : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, dataList[data_ke]->username);

    while (true) {
        cout << "Jenis Latihan      : ";
        getline(cin, dataList[data_ke]->Jenis_Latihan);
        int valid = 1;
        for (int i = 0; i < dataList[data_ke]->Jenis_Latihan.length(); i++) {
            if (!( (dataList[data_ke]->Jenis_Latihan[i] >= 'A' && dataList[data_ke]->Jenis_Latihan[i] <= 'Z') || 
                   (dataList[data_ke]->Jenis_Latihan[i] >= 'a' && dataList[data_ke]->Jenis_Latihan[i] <= 'z') || 
                   dataList[data_ke]->Jenis_Latihan[i] == ' ')) {
                cout << "Harus huruf tidak boleh angka\n";
                valid = 0; 
                break;
            }
        }
        if (valid == 1) break;
    }

    while (true) {
        cout << "Jumlah Set         : ";
        getline(cin, dataList[data_ke]->Jumlah_Set);
        int angka_valid = 1;
        for (int i = 0; i < dataList[data_ke]->Jumlah_Set.length(); i++) {
            if (dataList[data_ke]->Jumlah_Set[i] < '0' || dataList[data_ke]->Jumlah_Set[i] > '9') {
                angka_valid = 0;
                break;
            }
        }
        if (angka_valid == 1) break;
        cout << "Harus angka tidak boleh huruf\n";
    }

    while (true) {
        cout << "Beban (kg)         : ";
        getline(cin, dataList[data_ke]->Beban);
        int beban_valid = 1; // 1 berarti valid
        for (int i = 0; i < dataList[data_ke]->Beban.length(); i++) {
            if (dataList[data_ke]->Beban[i] < '0' || dataList[data_ke]->Beban[i] > '9') {
                beban_valid = 0; // 0 berarti tidak valid
                break;
            }
        }
        if (beban_valid == 1) break;
        cout << "Harus angka tidak boleh huruf\n";
    }

    while (true) {
        cout << "Durasi (menit)      : ";
        getline(cin, dataList[data_ke]->Durasi);
        int durasi_valid = 1;
        for (int i = 0; i < dataList[data_ke]->Durasi.length(); i++) {
            if (dataList[data_ke]->Durasi[i] < '0' || dataList[data_ke]->Durasi[i] > '9') {
                durasi_valid = 0;
                break;
            }
        }
        if (durasi_valid == 1) break;
        cout << "Harus angka tidak boleh huruf\n";
    }

    while (true) {
        cout << "Skala Latihan (1 - 10) : ";
        getline(cin, dataList[data_ke]->Skala_Latihan);
        int skala_valid = 1;
        for (int i = 0; i < dataList[data_ke]->Skala_Latihan.length(); i++) {
            if (dataList[data_ke]->Skala_Latihan[i] < '0' || dataList[data_ke]->Skala_Latihan[i] > '9') {
                skala_valid = 0; 
                break;
            }
        }
        if (skala_valid == 1) {
            int skala = 0;
            for (int i = 0; i < dataList[data_ke]->Skala_Latihan.length(); i++) {
                skala = skala * 10 + (dataList[data_ke]->Skala_Latihan[i] - '0');
            }
            if (skala >= 1 && skala <= 10) break;
            else {
                cout << "Harus angka antara 1 - 10\n";
            }
        } else {
            cout << "Harus angka tidak boleh huruf\n";
        }
    }

    while (true) {
        cout << "\n 1 - Menurun";
        cout << "\n 2 - Tetap";
        cout << "\n 3 - Meningkat\n";
        cout << "\nProgress (1 - 3)     : ";
        getline(cin, dataList[data_ke]->Progress);
        int progress_valid = 1;
        for (int i = 0; i < dataList[data_ke]->Progress.length(); i++) {
            if (dataList[data_ke]->Progress[i] < '0' || dataList[data_ke]->Progress[i] > '9') {
                progress_valid = 0;
                break;
            }
        }
        if (progress_valid == 1) {
            int progress = 0;
            for (int i = 0; i < dataList[data_ke]->Progress.length(); i++) {
                progress = progress * 10 + (dataList[data_ke]->Progress[i] - '0');
            }
            if (progress >= 1 && progress <= 3) break;
            else {
                cout << "Harus angka antara 1 - 3.\n";
            }
        } else {
            cout << "Harus angka tidak boleh huruf\n";
        }
    }

    cout << "Catatan          : ";
    getline(cin, dataList[data_ke]->Catatan);

    data_ke++;
    saveToDatabase();
    cout << "Data berhasil ditambahkan.\n";
}

void edit()
{
    if (sesiRole != "PELATIH")
    {
        cout << "Hanya pelatih yang dapat mengedit data progress.\n";
        return;
    }

    string usernameToEdit, jenisLatihanToEdit;
    cout << "Masukkan username anggota yang ingin diedit: ";
    cin >> usernameToEdit;
    cin.ignore();

    int index = -1;
    for (int i = 0; i < data_ke; ++i)
    {
        if (dataList[i]->username == usernameToEdit)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Data progress untuk username dan jenis latihan tersebut tidak ditemukan.\n";
        return;
    }

    while (true) {
        cout << "Jenis Latihan    : ";
        getline(cin, dataList[index]->Jenis_Latihan);
        int valid = 1;
        for (int i = 0; i < dataList[index]->Jenis_Latihan.length(); ++i) {
            char karakter = dataList[index]->Jenis_Latihan[i];
            if (!((karakter >= 'A' && karakter <= 'Z') || (karakter >= 'a' && karakter <= 'z') || karakter == ' ')) {
                cout << "Harus huruf tidak boleh angka\n";
                valid = 0;
                break;
            }
        }
        if (valid == 1) break;
    }

    while (true) {
        cout << "Jumlah Set        : ";
        getline(cin, dataList[index]->Jumlah_Set);
        int valid = 1;
        for (int i = 0; i < dataList[index]->Jumlah_Set.length(); i++) {
            if (dataList[index]->Jumlah_Set[i] < '0' || dataList[index]->Jumlah_Set[i] > '9') {
                cout << "Harus angka tidak boleh huruf\n";
                valid = 0;
                break;
            }
        }
        if (valid == 1) break;
    }

    while (true) {
        cout << "Beban (kg)         : ";
        getline(cin, dataList[index]->Beban);
        int valid = 1;
        for (int i = 0; i < dataList[index]->Beban.length(); i++) {
            if (dataList[index]->Beban[i] < '0' || dataList[index]->Beban[i] > '9') {
                cout << "Harus angka tidak boleh huruf\n";
                valid = 0;
                break;
            }
        }
        if (valid == 1) break;
    }

    while (true) {
        cout << "Durasi (menit)       : ";
        getline(cin, dataList[index]->Durasi);
        int valid = 1;
        for (int i = 0; i < dataList[index]->Durasi.length(); i++) {
            if (dataList[index]->Durasi[i] < '0' || dataList[index]->Durasi[i] > '9') {
                cout << "Harus angka tidak boleh huruf\n";
                valid = 0;
                break;
            }
        }
        if (valid == 1) break;
    }

    while (true) {
        cout << "Skala Latihan (1 - 10) : ";
        getline(cin, dataList[index]->Skala_Latihan);
        int skala_valid = 1;
        for (int i = 0; i < dataList[index]->Skala_Latihan.length(); i++) {
            if (dataList[index]->Skala_Latihan[i] < '0' || dataList[index]->Skala_Latihan[i] > '9') {
                skala_valid = 0;
                break;
            }
        }
        if (skala_valid == 1) {
            int skala = 0;
            for (int i = 0; i < dataList[index]->Skala_Latihan.length(); i++) {
                skala = skala * 10 + (dataList[index]->Skala_Latihan[i] - '0');
            }
            if (skala >= 1 && skala <= 10) break;
            else cout << "Harus angka antara 1 - 10\n";
        } else {
            cout << "Harus angka tidak boleh huruf\n";
        }
    }

    while (true) {
        cout << "\n 1 - Menurun";
        cout << "\n 2 - Tetap";
        cout << "\n 3 - Meningkat\n";
        cout << "\nProgress (1 - 3)     : ";
        getline(cin, dataList[index]->Progress);
        int valid = 1;
        for (int i = 0; i < dataList[index]->Progress.length(); i++) {
            if (dataList[index]->Progress[i] < '0' || dataList[index]->Progress[i] > '9') {
                valid = 0;
                break;
            }
        }
        if (valid == 1) {
            int progress = 0;
            for (int i = 0; i < dataList[index]->Progress.length(); i++) {
                progress = progress * 10 + (dataList[index]->Progress[i] - '0');
            }
            if (progress >= 1 && progress <= 3) break;
            else cout << "Harus angka antara 1 - 3\n";
        } else {
            cout << "Harus angka tidak boleh huruf\n";
        }
    }

    cout << "Catatan          : ";
    getline(cin, dataList[index]->Catatan);

    saveToDatabase();
    cout << "Data berhasil diedit.\n";
}

void hapus()
{
    int index;
    cout << "Mau hapus data keberapa? ";
    cin >> index;
    if (index < 1 || index > data_ke)
    {
        cout << "Data tidak ditemukan.\n";
        return;
    }

    for (int i = index - 1; i < data_ke - 1; ++i)
    {
        dataList[i] = dataList[i + 1];
    }

    data_ke--;
    saveToDatabase(); // Save to database after deleting
    cout << "Data berhasil dihapus.\n";
}

void tampil()
{
    if (sesiRole == "ANGGOTA")
    {
        for (int i = 0; i < data_ke; ++i)
        {
            if (sesiUser == dataList[i]->username)
            {
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
    else
    {
        cout << "\n| " << setw(3) << "No"
             << " | " << setw(15) << "Username"
             << " | " << setw(15) << "Jenis Latihan"
             << " | " << setw(11) << "Jumlah Set"
             << " | " << setw(10) << "Beban (kg)"
             << " | " << setw(15) << "Durasi (menit)"
             << " | " << setw(14) << "Skala Latihan"
             << " | " << setw(8) << "Progress"
             << " | " << setw(10) << "Catatan" << " |\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------\n";

        for (int i = 0; i < data_ke; ++i)
        {
            if (dataList[i] == nullptr)
                continue;

            cout << "| " << setw(3) << i + 1
                 << " | " << setw(15) << dataList[i]->username
                 << " | " << setw(15) << dataList[i]->Jenis_Latihan
                 << " | " << setw(11) << dataList[i]->Jumlah_Set
                 << " | " << setw(10) << dataList[i]->Beban
                 << " | " << setw(15) << dataList[i]->Durasi
                 << " | " << setw(14) << dataList[i]->Skala_Latihan
                 << " | " << setw(8) << dataList[i]->Progress
                 << " | " << setw(10) << dataList[i]->Catatan << " |\n";
            cout << "--------------------------------------------------------------------------------------------------------------------------------\n";
        }
    }
}

void menuProgress()
{
    loadFromDatabase(); // Load data from database at the start
    int pilihan;

    while (true)
    {
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
        else if (pilihan == 2) {
            tampil();
            edit();
        }
        else if (pilihan == 3)
            tampil();
        else if (pilihan == 4) {
            tampil();
            hapus();
        }
        else if (pilihan == 5)
        {
            cout << "Keluar\n";
            break;
        }
        else
        {
            cout << "Pilih angka 1-5\n";
        }
    }
}