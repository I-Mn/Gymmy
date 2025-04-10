#ifndef DATA_H
#define DATA_H
#include <string>
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
anggotaNode *head;
anggotaNode *tail;

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
#endif