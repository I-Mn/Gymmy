#ifndef DATA_H
#define DATA_H
#include <string>
#include <fstream> // Untuk file handling
#include <sstream> // Untuk stringstream
#include <ctime> // Tambahkan header untuk time()
using namespace std;
#include <cstdlib>

void initializeRandomSeed() {
    srand(static_cast<unsigned int>(time(0))); // Inisialisasi seed dengan waktu saat ini
}

char randomLetter(){
    int random = rand() % 36;
    char randChar;
    if (random >= 0 && random <= 9) {
        randChar = '0' + random; // Karakter angka (0-9)
    } else {
        randChar = 'A' + (random - 10); // Karakter huruf (A-Z)
    }

    return randChar;
}

struct progress_latihan
{
    string username;
    string Tanggal;
    string Nama_Pelatih;
    string Nama_Anggota;
    string Jenis_Latihan;
    string Jumlah_Set;
    string Beban;
    string Durasi;
    string Skala_Latihan;
    string Progress;
    string Catatan;
};

progress_latihan **dataList = new progress_latihan *[100];
int data_ke = 0;

struct anggotaNode {
    string nama;
    string telp;
    int umur;
    string paket;
    string jenisKelamin;
    string pelatih;
    string pass;
    string username;
    anggotaNode *next;
};

anggotaNode *headAnggota;
anggotaNode *tailAnggota;

int countIdAnggota = 0;
int countIdPelatih = 0;

const int MAX = 100;

struct pelatih {
    string nama;
    string notelp;
    int umur;
    string jeniskelamin;
    string spesialis;
    string username; // Add username field
    string password; // Add password field
};

pelatih datapelatih[MAX];
int jumlahpelatih = 0;

string sesiRole;
string sesiUser;

void loadAnggota(anggotaNode *&headAnggota, string nama, string telp, int umur, string paket, string jenisKelamin, string pelatih, string passAnggota, string username){
    anggotaNode *newMember = new anggotaNode;
    anggotaNode *current = headAnggota;
    if (headAnggota != NULL){
        newMember->nama = nama;
        newMember->telp = telp;
        newMember->umur = umur;
        newMember->paket = paket;
        newMember->jenisKelamin = jenisKelamin;
        newMember->pelatih = pelatih;
        newMember->pass = passAnggota;
        newMember->username = username; // Set username
        newMember->next = NULL;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newMember;
        tailAnggota = newMember;
    } else {
        newMember->nama = nama;
        newMember->telp = telp;
        newMember->umur = umur;
        newMember->paket = paket;
        newMember->jenisKelamin = jenisKelamin;
        newMember->pelatih = pelatih;
        newMember->next = headAnggota;
        newMember->pass = passAnggota;
        newMember->username = username; // Set username
        headAnggota = newMember;
        tailAnggota = newMember;
    }
}

void saveToDatabase(){
    ofstream file("database.txt");
    if (!file.is_open()){
        cout << "Gagal membuka file database.txt" << endl;
        return;
    }

    // Save anggota data
    anggotaNode *currentAnggota = headAnggota;
    while (currentAnggota != NULL){
        file <<"ANGGOTA,"<<currentAnggota->nama << ","
             << currentAnggota->telp << ","
             << currentAnggota->umur << ","
             << currentAnggota->paket << ","
             << currentAnggota->jenisKelamin << ","
             << currentAnggota->pelatih <<","
             <<currentAnggota->pass<<","
             <<currentAnggota->username<< endl;

        // Save progress data specific to this anggotaNode
        for (int i = 0; i < data_ke; ++i) {
            if (dataList[i]->username == currentAnggota->username) {
                file << "PROGRESS," << dataList[i]->Jenis_Latihan << ","
                     << dataList[i]->Jumlah_Set << ","
                     << dataList[i]->Beban << ","
                     << dataList[i]->Durasi << ","
                     << dataList[i]->Skala_Latihan << ","
                     << dataList[i]->Progress << ","
                     << dataList[i]->Catatan << endl;
            }
        }

        currentAnggota = currentAnggota->next;
    }

    // Save pelatih data
    for (int i = 0; i < jumlahpelatih; i++) {
        file << "PELATIH," << datapelatih[i].nama << ","
             << datapelatih[i].notelp << ","
             << datapelatih[i].umur << ","
             << datapelatih[i].jeniskelamin << ","
             << datapelatih[i].spesialis << ","
             << datapelatih[i].username << ","
             << datapelatih[i].password << endl;
    }

    file.close();
}

void loadFromDatabase(){
    ifstream file("database.txt");
    if (!file.is_open()){
        cout << "Gagal membuka file database.txt" << endl;
        return;
    }

    string line;
    while (getline(file, line)){
        stringstream ss(line);
        string type;
        getline(ss, type, ',');
        if (type == "ANGGOTA"){
            string nama, telp, umurStr, paket, jenisKelamin, pelatih, pass, username;

            getline(ss, nama, ',');
            getline(ss, telp, ',');
            getline(ss, umurStr, ',');
            getline(ss, paket, ',');
            getline(ss, jenisKelamin, ',');
            getline(ss, pelatih, ',');
            getline(ss, pass, ',');
            getline(ss, username, ',');

            int umur = stoi(umurStr);

            loadAnggota(headAnggota, nama, telp, umur, paket, jenisKelamin, pelatih, pass, username);
        } else if (type == "PROGRESS") {
            string username, Jenis_Latihan, Jumlah_Set, Beban, Durasi, Skala_Latihan, Progress, Catatan;

            getline(ss, username, ',');
            getline(ss, Jenis_Latihan, ',');
            getline(ss, Jumlah_Set, ',');
            getline(ss, Beban, ',');
            getline(ss, Durasi, ',');
            getline(ss, Skala_Latihan, ',');
            getline(ss, Progress, ',');
            getline(ss, Catatan, ',');

            progress_latihan *newProgress = new progress_latihan;
            newProgress->username = username;
            newProgress->Jenis_Latihan = Jenis_Latihan;
            newProgress->Jumlah_Set = Jumlah_Set;
            newProgress->Beban = Beban;
            newProgress->Durasi = Durasi;
            newProgress->Skala_Latihan = Skala_Latihan;
            newProgress->Progress = Progress;
            newProgress->Catatan = Catatan;

            dataList[data_ke++] = newProgress;
        } else if (type == "PELATIH") {
            string nama, notelp, umurStr, jeniskelamin, spesialis, username, password;

            getline(ss, nama, ',');
            getline(ss, notelp, ',');
            getline(ss, umurStr, ',');
            getline(ss, jeniskelamin, ',');
            getline(ss, spesialis, ',');
            getline(ss, username, ',');
            getline(ss, password, ',');

            int umur = stoi(umurStr);

            pelatih *p = &datapelatih[jumlahpelatih++];
            p->nama = nama;
            p->notelp = notelp;
            p->umur = umur;
            p->jeniskelamin = jeniskelamin;
            p->spesialis = spesialis;
            p->username = username;
            p->password = password;
        }
    }

    file.close();
}
#endif