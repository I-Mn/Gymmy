#ifndef DATA_H
#define DATA_H
#include <string>
#include <fstream> // Untuk file handling
#include <sstream> // Untuk stringstream
using namespace std;

struct anggotaNode{
    int id;
    string nama;
    string telp;
    int umur;
    string paket;
    string jenisKelamin;
    string pelatih;
    anggotaNode* next;
};
anggotaNode *headAnggota;
anggotaNode *tailAnggota;

int countIdAnggota = 0;
int countIdPelatih = 0;

struct pelatihNode{
    int id;
    string nama;
    int umur;
    string keahlian;
    pelatihNode* next;
};

struct jadwalNode{
    int id;
    int idAnggota;
    int idPelatih;
    string hari;
    string jam;
    jadwalNode* next;
};

struct progresNode{
    string tanggal;
    int idAnggota;
    string latihan;
    int beratAngkat;
    int beratBadan;
    progresNode* next;
};

void loadAnggota(anggotaNode *&headAnggota, int id, string nama, string telp, int umur, string paket, string jenisKelamin, string pelatih){
    anggotaNode *newMember = new anggotaNode;
    anggotaNode *current = headAnggota;
    if (headAnggota != NULL){
        newMember->id = id;
        newMember->nama = nama;
        newMember->telp = telp;
        newMember->umur = umur;
        newMember->paket = paket;
        newMember->jenisKelamin = jenisKelamin;
        newMember->pelatih = pelatih;
        newMember->next = NULL;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newMember;
    } else {
        newMember->id = id;
        newMember->nama = nama;
        newMember->telp = telp;
        newMember->umur = umur;
        newMember->paket = paket;
        newMember->jenisKelamin = jenisKelamin;
        newMember->pelatih = pelatih;
        newMember->next = headAnggota;
        headAnggota = newMember;
    }
}

void saveToDatabase(){
    ofstream file("database.txt");
    if (!file.is_open()){
        cout << "Gagal membuka file database.txt" << endl;
        return;
    }

    anggotaNode *currentAnggota = headAnggota;
    while (currentAnggota != NULL){
        file <<"ANGGOTA,"<<currentAnggota->id << ","
             << currentAnggota->nama << ","
             << currentAnggota->telp << ","
             << currentAnggota->umur << ","
             << currentAnggota->paket << ","
             << currentAnggota->jenisKelamin << ","
             << currentAnggota->pelatih <<","<<countIdAnggota<< endl;
        currentAnggota = currentAnggota->next;
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
        string idStr, nama, telp, umurStr, paket, jenisKelamin, pelatih, countIDAnggotaSTR;

        getline(ss, idStr, ',');
        getline(ss, nama, ',');
        getline(ss, telp, ',');
        getline(ss, umurStr, ',');
        getline(ss, paket, ',');
        getline(ss, jenisKelamin, ',');
        getline(ss, pelatih, ',');
        getline(ss, countIDAnggotaSTR, ',');

        int id = stoi(idStr);
        int umur = stoi(umurStr);
        countIdAnggota = stoi(countIDAnggotaSTR);

        loadAnggota(headAnggota, id, nama, telp, umur, paket, jenisKelamin, pelatih);}
    }

    file.close();
}
#endif