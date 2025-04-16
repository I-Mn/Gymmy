#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "data.cpp"

using namespace std;

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
    JadwalLatihan jadwalBaru; // buat jadwal baru

    int pilih;

    cout << "\nDaftar Anggota:\n";
    for (int i = 0; i < daftarAnggota.size(); ++i) {
        cout << i + 1 << ". " << daftarAnggota[i] << endl;
    }
    cout << "Pilih nomor anggota: ";
    cin >> pilih;
    jadwalBaru.NamaAnggota = daftarAnggota[pilih - 1];

    cout << "Masukkan Username Anggota: ";
    cin >> jadwalBaru.username; // tambahkan input untuk username

    cout << "\nDaftar Pelatih:\n";
    for (int i = 0; i < daftarPelatih.size(); ++i) {
        cout << i + 1 << ". " << daftarPelatih[i] << endl;
    }
    cout << "Pilih nomor pelatih: ";
    cin >> pilih;
    jadwalBaru.Pelatih = daftarPelatih[pilih - 1];

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

    daftarJadwal.push_back(jadwalBaru); // tambahkan ke daftar jadwal
}

void tampilkanJadwal() {
    cout << "\nData Jadwal Latihan:\n";
    if (sesiRole == "ANGGOTA") {
        for (const auto& jadwal : daftarJadwal) {
            if (sesiUser == jadwal.username) { // Akses username dari elemen jadwal
                cout << "Nama: " << jadwal.NamaAnggota << endl;
                cout << "Username: " << jadwal.username << endl;
                cout << "Jumlah: " << jadwal.JumlahAnggota << endl;
                cout << "Tanggal: " << jadwal.HariLatihan.hari << ", "
                     << jadwal.HariLatihan.tanggal << "-" << jadwal.HariLatihan.bulan << "-" << jadwal.HariLatihan.tahun << endl;
                cout << "Jenis Latihan: " << jadwal.JenisLatihan << endl;
                cout << "Durasi: " << jadwal.Durasi << " menit" << endl;
                cout << "Pelatih: " << jadwal.Pelatih << endl;
                cout << "--------------------------\n";
            }
        }
    }
    for (const auto& jadwal : daftarJadwal) {
        cout << "Nama: " << jadwal.NamaAnggota << endl;
        cout << "Username: " << jadwal.username << endl; // tampilkan username
        cout << "Jumlah: " << jadwal.JumlahAnggota << endl;
        cout << "Tanggal: " << jadwal.HariLatihan.hari << ", "
             << jadwal.HariLatihan.tanggal << "-" << jadwal.HariLatihan.bulan << "-" << jadwal.HariLatihan.tahun << endl;
        cout << "Jenis Latihan: " << jadwal.JenisLatihan << endl;
        cout << "Durasi: " << jadwal.Durasi << " menit" << endl;
        cout << "Pelatih: " << jadwal.Pelatih << endl;
        cout << "--------------------------\n";
    }
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
    int pilihan;

    bacaData();

    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Input Jadwal Latihan\n";
        cout << "2. Tampilkan Jadwal\n";
        cout << "3. Edit Jadwal\n";
        cout << "4. Hapus Jadwal\n";
        cout << "5. Keluar\n";
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
