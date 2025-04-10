#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct JadwalLatihan {
    string Bulan;
    string NamaPeserta;
    string DaftarLatihan[99]={};
    struct DataLatihan;
};

struct DataLatihan {
    tm HariTanggal;
    string JenisLatihan;
    string Pelatih;
    int jumlahAnggota;
    int durasi;
    string Metode;
    string NotePelatih;
};

int main() {
    DataLatihan latihan;

    cout << "Masukkan tahun: ";
    cin >> latihan.HariTanggal.tm_year;
    latihan.HariTanggal.tm_year -= 1900; 

    cout << "Masukkan bulan (1-12): ";
    cin >> latihan.HariTanggal.tm_mon;
    latihan.HariTanggal.tm_mon -= 1; 

    cout << "Masukkan hari: ";
    cin >> latihan.HariTanggal.tm_mday;

    cin.ignore(); 
    cout << "Masukkan jenis latihan: ";
    getline(cin, latihan.JenisLatihan);

    cout << "Masukkan nama pelatih: ";
    getline(cin, latihan.Pelatih);

    cout << "Masukkan jumlah anggota: ";
    cin >> latihan.jumlahAnggota;

    cout << "Masukkan durasi (dalam menit): ";
    cin >> latihan.durasi;

    cin.ignore(); // Clear the input buffer
    cout << "Masukkan metode latihan: ";
    getline(cin, latihan.Metode);

    cout << "Masukkan catatan pelatih: ";
    getline(cin, latihan.NotePelatih);

    // Output the data to verify
    cout << "\nData Jadwal Latihan:\n";
    cout << "Tanggal: " << latihan.HariTanggal.tm_mday << "/"
         << latihan.HariTanggal.tm_mon + 1 << "/"
         << latihan.HariTanggal.tm_year + 1900 << endl;
    cout << "Jenis Latihan: " << latihan.JenisLatihan << endl;
    cout << "Pelatih: " << latihan.Pelatih << endl;
    cout << "Jumlah Anggota: " << latihan.jumlahAnggota << endl;
    cout << "Durasi: " << latihan.durasi << " menit" << endl;
    cout << "Metode: " << latihan.Metode << endl;
    cout << "Catatan Pelatih: " << latihan.NotePelatih << endl;

    return 0;

}