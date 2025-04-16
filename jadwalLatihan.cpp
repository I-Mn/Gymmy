#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "data.h"

using namespace std;

struct Tanggal {
    string hari;
    int bulan;
    int tahun;
    int tanggal;
};

struct JadwalLatihan {
    string NamaAnggota;
    int JumlahAnggota;
    Tanggal HariLatihan;
    string JenisLatihan;
    int Durasi;
    string Pelatih;
};

vector<string> daftarAnggota;
vector<string> daftarPelatih;
JadwalLatihan jadwal; // satu data untuk contoh

void bacaData() {
    ifstream file("database.txt");
    string baris;

    while (getline(file, baris)) {
        stringstream ss(baris);
        string tipe, nama;
        getline(ss, tipe, ',');
        getline(ss, nama);

        if (tipe == "ANGGOTA") {
            daftarAnggota.push_back(nama);
        } else if (tipe == "PELATIH") {
            daftarPelatih.push_back(nama);
        }
    }
    file.close();
}

void inputJadwal() {
    int pilih;

    cout << "\nDaftar Anggota:\n";
    for (int i = 0; i < daftarAnggota.size(); ++i) {
        cout << i + 1 << ". " << daftarAnggota[i] << endl;
    }
    cout << "Pilih nomor anggota: ";
    cin >> pilih;
    jadwal.NamaAnggota = daftarAnggota[pilih - 1];

    cout << "\nDaftar Pelatih:\n";
    for (int i = 0; i < daftarPelatih.size(); ++i) {
        cout << i + 1 << ". " << daftarPelatih[i] << endl;
    }
    cout << "Pilih nomor pelatih: ";
    cin >> pilih;
    jadwal.Pelatih = daftarPelatih[pilih - 1];

    cout << "Jumlah Anggota: ";
    cin >> jadwal.JumlahAnggota;

    cout << "Hari: ";
    cin >> jadwal.HariLatihan.hari;
    cout << "Tanggal: ";
    cin >> jadwal.HariLatihan.tanggal;
    cout << "Bulan: ";
    cin >> jadwal.HariLatihan.bulan;
    cout << "Tahun: ";
    cin >> jadwal.HariLatihan.tahun;

    cout << "Jenis Latihan: ";
    cin >> jadwal.JenisLatihan;

    cout << "Durasi (menit): ";
    cin >> jadwal.Durasi;
}

void tampilkanJadwal() {
    cout << "\nData Jadwal Latihan:\n";
    cout << "Nama: " << jadwal.NamaAnggota << endl;
    cout << "Jumlah: " << jadwal.JumlahAnggota << endl;
    cout << "Tanggal: " << jadwal.HariLatihan.hari << ", "
         << jadwal.HariLatihan.tanggal << "-" << jadwal.HariLatihan.bulan << "-" << jadwal.HariLatihan.tahun << endl;
    cout << "Jenis Latihan: " << jadwal.JenisLatihan << endl;
    cout << "Durasi: " << jadwal.Durasi << " menit" << endl;
    cout << "Pelatih: " << jadwal.Pelatih << endl;
}

void menuUtama() {
    int pilihan;

    bacaData();

    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Input Jadwal Latihan\n";
        cout << "2. Tampilkan Jadwal\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputJadwal();
                saveToDatabase();
                break;
            case 2:
                tampilkanJadwal();
                break;
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 3);
}

int main() {
    menuUtama();
    return 0;
}
