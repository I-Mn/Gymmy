#include <iostream>
#include <fstream>
#include <sstream>
#include "anggota.h"
using namespace std;

struct AkunNode {
    string role;
    string username;
    string password;
    AkunNode* next;
};

AkunNode* akunHead = nullptr;

// Tambah node akun ke linked list
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

// Load akun dari akun.txt
void loadAkun() {
    ifstream file("akun.txt");
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string role, username, password;

        // Membaca role, username, dan password dari file
        if (getline(ss, role, ',') && getline(ss, username, ',') && getline(ss, password, ',')) {
            cout << "Role: " << role << ", Username: " << username << ", Password: " << password << endl;

            tambahAkun(role, username, password);
        }
    }
    file.close();
}


// Cek login
bool login(string role, string username, string password) {
    AkunNode* temp = akunHead;
    while (temp) {
        if (temp->role == role && temp->username == username && temp->password == password) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Menu login interaktif
void menuLogin() {
    loadAkun();
    int pilihan;
    string role, uname, pass;

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
        case 0: return;
        default:
            cout << "Pilihan tidak valid!\n";
            return;
    }

    cout << "Username: ";
    cin >> uname;
    cout << "Password: ";
    cin >> pass;

    if (login(role, uname, pass)) {
        cout << "Login berhasil sebagai " << role << "!\n";
        if (role == "ANGGOTA") {
            menuAnggota();
        } else if (role == "PELATIH") {
        } else if (role == "ADMIN") {
        }
    } else {
        cout << "Login gagal. Cek username/password.\n";
    }
}