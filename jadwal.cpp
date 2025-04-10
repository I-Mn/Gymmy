#include <iostream>
#include <string>
#include <ctime>
using namespace std;


struct JadwalLatihan {
    tm HariTanggal;
    string JenisLatihan;
    string Pelatih;
    int jumlahAnggota;
    int durasi;
    string Metode;
    string NotePelatih;
};

int main() {
    JadwalLatihan jadwal;

    cout << "Masukkan tahun: ";
    cin >> jadwal.HariTanggal.tm_year;
    jadwal.HariTanggal.tm_year -= 1900; 

    cout << "Masukkan bulan (1-12): ";
    cin >> jadwal.HariTanggal.tm_mon;
    jadwal.HariTanggal.tm_mon -= 1; 

    cout << "Masukkan hari: ";
    cin >> jadwal.HariTanggal.tm_mday;

    cin.ignore(); // Clear the input buffer
    cout << "Masukkan jenis latihan: ";
    getline(cin, jadwal.JenisLatihan);

    cout << "Masukkan nama pelatih: ";
    getline(cin, jadwal.Pelatih);

    cout << "Masukkan jumlah anggota: ";
    cin >> jadwal.jumlahAnggota;

    cout << "Masukkan durasi (dalam menit): ";
    cin >> jadwal.durasi;

    cin.ignore(); // Clear the input buffer
    cout << "Masukkan metode latihan: ";
    getline(cin, jadwal.Metode);

    cout << "Masukkan catatan pelatih: ";
    getline(cin, jadwal.NotePelatih);

    // Output the data to verify
    cout << "\nData Jadwal Latihan:\n";
    cout << "Tanggal: " << jadwal.HariTanggal.tm_mday << "/"
         << jadwal.HariTanggal.tm_mon + 1 << "/"
         << jadwal.HariTanggal.tm_year + 1900 << endl;
    cout << "Jenis Latihan: " << jadwal.JenisLatihan << endl;
    cout << "Pelatih: " << jadwal.Pelatih << endl;
    cout << "Jumlah Anggota: " << jadwal.jumlahAnggota << endl;
    cout << "Durasi: " << jadwal.durasi << " menit" << endl;
    cout << "Metode: " << jadwal.Metode << endl;
    cout << "Catatan Pelatih: " << jadwal.NotePelatih << endl;

    return 0;

}