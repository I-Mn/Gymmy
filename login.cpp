#include <iostream>
#include <fstream>
#include <sstream>
#include "data.h"
#include <conio.h> // Untuk getch()
#include "anggota.cpp"

using namespace std;

// Fungsi untuk memverifikasi login
bool login(string role, string username, string password) {
    if (role == "ANGGOTA") {
        anggotaNode* temp = headAnggota;
        while (temp) {
            if (temp->username == username && temp->pass == password) {
                return true;
            }
            temp = temp->next;
        }
    } else if (role == "PELATIH") {
        for (int i = 0; i < jumlahpelatih; i++) {
            if (datapelatih[i].username == username && datapelatih[i].password == password) {
                return true;
            }
        }
    } else if (role == "ADMIN") {
        if (username == "admin" && password == "admin#12345") {
            return true;
        }
    }
    return false;
}

// Fungsi untuk membaca password tanpa menampilkannya di layar
string readPassword() {
    string password;
    char ch;
    while (true) {
        ch = getch();
        if (ch == '\r') { // Enter ditekan
            break;
        }
        else if (ch == '\b') { // Backspace
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else if (isprint(ch)) { // Hanya karakter yang bisa dicetak
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

// Fungsi untuk menampilkan menu login
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
    cin.ignore(); // Membersihkan karakter newline dari buffer

    switch (pilihan) {
        case 1: role = "ANGGOTA"; break;
        case 2: role = "PELATIH"; break;
        case 3: role = "ADMIN"; break;
        case 0: return;
        default:
            cout << "Pilihan tidak valid!\n";
            return;
    }

    // Input Username
    while (true) {
        cout << "Username (ID): ";
        getline(cin, username);

        // Validasi username kosong
        if (username.empty() || username.find_first_not_of(" \t\n\v\f\r") == string::npos) {
            cout << "Username tidak boleh kosong. Silakan masukkan kembali.\n";
        } else {
            break;
        }
    }

    // Input Password
    while (true) {
        cout << "Password: ";
        pass = readPassword();

        // Validasi password kosong
        if (pass.empty() || pass.find_first_not_of(" \t\n\v\f\r") == string::npos) {
            cout << "Password tidak boleh kosong. Silakan masukkan kembali.\n";
        } else {
            break;
        }
    }

    if (login(role, username, pass)) {
        cout << "Login berhasil sebagai " << role << ".\n";
        sesiRole = role;
        sesiUser = username;
    } else {
        cout << "Login gagal. Cek username atau password.\n";
    }
}
