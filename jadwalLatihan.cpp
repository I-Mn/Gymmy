#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "data.h"
#include <iomanip>

using namespace std;

void inputJadwal() {
    JadwalLatihan jadwalBaru;

    int pilih;

    cout << "Masukkan Username Anggota: ";
    cin >> jadwalBaru.username;

    cout << "Masukkan Nama Pelatih: ";
    cin.ignore(); 
    getline(cin, jadwalBaru.Pelatih);

    cout << "Jumlah Anggota: ";
    cin >> jadwalBaru.JumlahAnggota;

    cout << "Hari: ";
    cin >> jadwalBaru.HariLatihan.hari;
    cout << "Tanggal: ";
    cin >> jadwalBaru.HariLatihan.tanggal;
    cout << "Bulan: ";
    cin >> jadwalBaru.HariLatihan.bulan;
    cout << "Tahun: ";
    cin >> jadwalBaru.HariLatihan.tahun;

    cout << "Jenis Latihan: ";
    cin >> jadwalBaru.JenisLatihan;

    cout << "Durasi (menit): ";
    cin >> jadwalBaru.Durasi;

    daftarJadwal.push_back(jadwalBaru);
}

void tampilkanJadwal() {
    cout << left << setw(15) << "Nama"
    << setw(15) << "Username"
    << setw(8)  << "Jumlah"
    << setw(15) << "Tanggal"
    << setw(18) << "Jenis Latihan"
    << setw(10) << "Durasi"
    << setw(15) << "Pelatih" << endl;
cout << string(96, '-') << endl;

for (const auto& jadwal : daftarJadwal) {
    if (sesiRole == "ANGGOTA" && sesiUser != jadwal.username) {
        continue; 
    }
    string tanggal = jadwal.HariLatihan.hari + ", " +
                         to_string(jadwal.HariLatihan.tanggal) + "-" +
                         to_string(jadwal.HariLatihan.bulan) + "-" +
                         to_string(jadwal.HariLatihan.tahun);
     cout << left << setw(15) << jadwal.NamaAnggota
             << setw(15) << jadwal.username
             << setw(8)  << jadwal.JumlahAnggota
             << setw(15) << tanggal
             << setw(18) << jadwal.JenisLatihan
             << setw(10) << jadwal.Durasi
             << setw(15) << jadwal.Pelatih << endl;
}
cout << endl;
}

void editJadwal() {
    int index;
    cout << "\nPilih nomor jadwal yang ingin diedit:\n";
    for (int i = 0; i < daftarJadwal.size(); ++i) {
        cout << i + 1 << ". " << daftarJadwal[i].NamaAnggota << " - " 
             << daftarJadwal[i].JenisLatihan << endl;
    }
    cout << "Masukkan nomor jadwal: ";
    cin >> index;

    if (index < 1 || index > daftarJadwal.size()) {
        cout << "Nomor jadwal tidak valid.\n";
        return;
    }

    JadwalLatihan &jadwal = daftarJadwal[index - 1];

    cout << "Edit Nama Anggota (" << jadwal.NamaAnggota << "): ";
    cin.ignore();
    getline(cin, jadwal.NamaAnggota);

    cout << "Edit Username Anggota (" << jadwal.username << "): ";
    getline(cin, jadwal.username);

    cout << "Edit Jumlah Anggota (" << jadwal.JumlahAnggota << "): ";
    cin >> jadwal.JumlahAnggota;

    cout << "Edit Hari (" << jadwal.HariLatihan.hari << "): ";
    cin >> jadwal.HariLatihan.hari;
    cout << "Edit Tanggal (" << jadwal.HariLatihan.tanggal << "): ";
    cin >> jadwal.HariLatihan.tanggal;
    cout << "Edit Bulan (" << jadwal.HariLatihan.bulan << "): ";
    cin >> jadwal.HariLatihan.bulan;
    cout << "Edit Tahun (" << jadwal.HariLatihan.tahun << "): ";
    cin >> jadwal.HariLatihan.tahun;

    cout << "Edit Jenis Latihan (" << jadwal.JenisLatihan << "): ";
    cin.ignore();
    getline(cin, jadwal.JenisLatihan);

    cout << "Edit Durasi (" << jadwal.Durasi << " menit): ";
    cin >> jadwal.Durasi;

    cout << "Edit Pelatih (" << jadwal.Pelatih << "): ";
    cin.ignore();
    getline(cin, jadwal.Pelatih);

    cout << "Jadwal berhasil diedit.\n";
}

void hapusJadwal() {
    int index;
    cout << "\nPilih nomor jadwal yang ingin dihapus:\n";
    for (int i = 0; i < daftarJadwal.size(); ++i) {
        cout << i + 1 << ". " << daftarJadwal[i].NamaAnggota << " - " 
             << daftarJadwal[i].JenisLatihan << endl;
    }
    cout << "Masukkan nomor jadwal: ";
    cin >> index;

    if (index < 1 || index > daftarJadwal.size()) {
        cout << "Nomor jadwal tidak valid.\n";
        return;
    }

    daftarJadwal.erase(daftarJadwal.begin() + (index - 1));
    cout << "Jadwal berhasil dihapus.\n";
}

void menuJadwal() {
    int pilihan=0;

    do {
        pilihan = 0;
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Input Jadwal Latihan\n";
        cout << "2. Tampilkan Jadwal\n";
        cout << "3. Edit Jadwal\n";
        cout << "4. Hapus Jadwal\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1:
                inputJadwal();
                saveToDatabase();
                break;
            case 2:
                tampilkanJadwal();
                break;
            case 3:
                editJadwal();
                saveToDatabase();
                break;
            case 4:
                hapusJadwal();
                saveToDatabase();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);
}
