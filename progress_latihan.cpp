#include <iostream>
#include <string>
#include "data.h" // Include data.h for shared structures and functions
using namespace std;

void tambah()
{
    dataList[data_ke] = new progress_latihan;

    cout << "=== Tambah Progress Latihan ===" << endl;

    cin.ignore();
    cout << "Tanggal (DD/MM/YYYY) : ";
    getline(cin, dataList[data_ke]->Tanggal);
    cout << "Nama Pelatih         : ";
    getline(cin, dataList[data_ke]->Nama_Pelatih);
    cout << "Nama Anggota         : ";
    getline(cin, dataList[data_ke]->Nama_Anggota);
    cout << "Jenis Latihan        : ";
    getline(cin, dataList[data_ke]->Jenis_Latihan);
    cout << "Jumlah Set           : ";
    getline(cin, dataList[data_ke]->Jumlah_Set);
    cout << "Beban (kg)           : ";
    getline(cin, dataList[data_ke]->Beban);
    cout << "Durasi (menit)       : ";
    getline(cin, dataList[data_ke]->Durasi);
    cout << "Skala Latihan        : ";
    getline(cin, dataList[data_ke]->Skala_Latihan);
    cout << "Progress             : ";
    getline(cin, dataList[data_ke]->Progress);
    cout << "Catatan              : ";
    getline(cin, dataList[data_ke]->Catatan);

    data_ke++;
    cout << "Data berhasil ditambahkan.\n";
}

void edit()
{
    string Nama_Anggota;
    cout << "Masukkan nama anggota yang ingin diedit: ";
    cin.ignore();
    getline(cin, Nama_Anggota);

    for (int i = 0; i < data_ke; ++i)
    {
        if (dataList[i]->Nama_Anggota == Nama_Anggota)
        {
            cout << "=== Edit Progress Latihan ===" << endl;
            cout << "\nData Anggota: " << Nama_Anggota << "\n";

            cout << "Tanggal (DD/MM/YYYY) : ";
            getline(cin, dataList[i]->Tanggal);
            cout << "Nama Pelatih         : ";
            getline(cin, dataList[i]->Nama_Pelatih);
            cout << "Nama Anggota         : ";
            getline(cin, dataList[i]->Nama_Anggota);
            cout << "Jenis Latihan        : ";
            getline(cin, dataList[i]->Jenis_Latihan);
            cout << "Jumlah Set           : ";
            getline(cin, dataList[i]->Jumlah_Set);
            cout << "Beban (kg)           : ";
            getline(cin, dataList[i]->Beban);
            cout << "Durasi (menit)       : ";
            getline(cin, dataList[i]->Durasi);
            cout << "Skala Latihan        : ";
            getline(cin, dataList[i]->Skala_Latihan);
            cout << "Progress             : ";
            getline(cin, dataList[i]->Progress);
            cout << "Catatan              : ";
            getline(cin, dataList[i]->Catatan);

            cout << "Data berhasil diedit.\n";

        } else {
            cout << "Nama anggota tidak ditemukan.\n";
        }
    }
}

void hapus()
{
    string Nama_Anggota;
    cout << "Masukkan nama anggota yang progressnya ingin dihapus: ";
    cin.ignore();
    getline(cin, Nama_Anggota);

    for (int i = 0; i < data_ke; ++i)
    {
        if (dataList[i]->Nama_Anggota == Nama_Anggota)
        {
            for (int j = i; j < data_ke - 1; ++j)
            {
                dataList[j] = dataList[j + 1];
            }
            data_ke--;
            cout << "Progress anggota " << Nama_Anggota << " berhasil dihapus.\n";
            break;
        } else {
            cout << "Nama anggota tidak ditemukan.\n";
        }
    }
}

void tampil()
{
    for (int i = 0; i < data_ke; ++i)
    {
        cout << "\nData ke-" << i + 1 << ":\n";
        cout << "\n=== Data Progress Latihan ===\n";
        cout << "Tanggal          : " << dataList[i]->Tanggal << endl;
        cout << "Nama Pelatih     : " << dataList[i]->Nama_Pelatih << endl;
        cout << "Nama Anggota     : " << dataList[i]->Nama_Anggota << endl;
        cout << "Jenis Latihan    : " << dataList[i]->Jenis_Latihan << endl;
        cout << "Jumlah Set       : " << dataList[i]->Jumlah_Set << endl;
        cout << "Beban (kg)       : " << dataList[i]->Beban << endl;
        cout << "Durasi (menit)   : " << dataList[i]->Durasi << endl;
        cout << "Skala Latihan    : " << dataList[i]->Skala_Latihan << endl;
        cout << "Progress         : " << dataList[i]->Progress << endl;
        cout << "Catatan          : " << dataList[i]->Catatan << endl;
    }
}

int main()
{
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
        else if (pilihan == 2)
            edit();
        else if (pilihan == 3)
            tampil();
        else if (pilihan == 4)
            hapus();
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