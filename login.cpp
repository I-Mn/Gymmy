#include <iostream>
#include <fstream>
#include <sstream>
#include "data.h"
#include "anggota.h"
using namespace std;

// Fungsi tambahAkun dikomentari karena tidak lagi digunakan
/*
void tambahAkun(string role, string username, string password) {
    AkunNode* baru = new AkunNode{role, username, password, nullptr};
    if (!akunHead) {
        akunHead = baru;
    } else {
        AkunNode* temp = akunHead;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
}
*/

// Fungsi loadAkun dikomentari karena tidak lagi digunakan
/*
void loadAkun() {
    ifstream file("akun.txt");
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string role, username, password;

        if (getline(ss, role, ',') && getline(ss, username, ',') && getline(ss, password, ',')) {
            cout << "Role: " << role << ", Username: " << username << ", Password: " << password << endl;

            tambahAkun(role, username, password);
        }
    }
    file.close();
}
*/


// Cek login
bool login(string role, string username, string password) {
    if (role == "ANGGOTA") {
        anggotaNode* temp = headAnggota;
        while (temp) {
            if (temp->username == username && temp->pass == password) {
                return true;
            }
            temp = temp->next;
        }
    }
    else if (role == "PELATIH") {
        for (int i = 0; i < jumlahpelatih; i++) {
            if (datapelatih[i].nama == username && datapelatih[i].notelp == password) {
                return true;
            }
        }
    }
    else if (role == "ADMIN"){
        if (username == "admin" && password == "admin#12345"){
            return true;
        }
    }
    return false;
}

// Menu login interaktif
void menuLogin() {
    loadFromDatabase(); // Load data anggota dari database
    int pilihan;
    string role, username, pass;

    cout << "\n=== MENU LOGIN ===\n";
    cout << "1. Login Anggota\n";
    cout << "2. Login Pelatih\n";
    cout << "3. Login Admin\n";
    cout << "0. Keluar\n";
    cout << "Pilih opsi: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: role = "ANGGOTA"; break;
        case 2: role = "PELATIH"; break;
        case 3: role = "ADMIN"; break;
        case 0: role = "-1"; return;
        default:
            cout << "Pilihan tidak valid!\n";
            role = "-1";
    return;
    }

    cout << "Username (ID): ";
    cin >> username;
    cout << "Password: ";
    cin >> pass;

    if (login(role, username, pass)) {
        cout << "Login berhasil sebagai " << role << "!\n";
        sesiRole = role; sesiUser = username;
        return;
    } else {
        cout << "Login gagal. Cek username/password.\n";
    }
}