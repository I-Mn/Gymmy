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

struct anggotaNode{
    string nama;
    string telp;
    int umur;
    string paket;
    string jenisKelamin;
    string pelatih;
    string pass;
    string username; // Add username field
    anggotaNode* next;
};
anggotaNode *headAnggota;
anggotaNode *tailAnggota;

int countIdAnggota = 0;
int countIdPelatih = 0;

struct progress_latihan {
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
        currentAnggota = currentAnggota->next;
    }

    // Save progress data
    for (int i = 0; i < data_ke; ++i) {
        file << "PROGRESS," << dataList[i]->Jenis_Latihan << ","
             << dataList[i]->Jumlah_Set << ","
             << dataList[i]->Beban << ","
             << dataList[i]->Durasi << ","
             << dataList[i]->Skala_Latihan << ","
             << dataList[i]->Progress << ","
             << dataList[i]->Catatan << endl;
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
            dataList[data_ke] = new progress_latihan;
            getline(ss, dataList[data_ke]->Jenis_Latihan, ',');
            getline(ss, dataList[data_ke]->Jumlah_Set, ',');
            getline(ss, dataList[data_ke]->Beban, ',');
            getline(ss, dataList[data_ke]->Durasi, ',');
            getline(ss, dataList[data_ke]->Skala_Latihan, ',');
            getline(ss, dataList[data_ke]->Progress, ',');
            getline(ss, dataList[data_ke]->Catatan, ',');
            data_ke++;
        }
    }

    file.close();
}
#endif