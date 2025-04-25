#include <iostream>
#include <string>
#include <utility>
#include "anggota.cpp"
#include <limits>
#include "login.cpp"
#include "jadwalLatihan.cpp"
#include "manajemn_pelatih.cpp"
#include "progress_latihan.cpp"
#include "data.h"
#include <limits>
using namespace std;

int main(){
    int menu;
    menu = 0;
    menuLogin();
    while (true){
        loadFromDatabase();
        if (sesiRole == "ADMIN"){
            cout << "--------------------" << endl;
            cout << "GYMMY" << endl;
            cout << "--------------------" << endl;
            cout << "Main Menu" << endl;
            cout << "1. Manajemen Anggota" << endl;
            cout << "2. Manajemen Pelatih" << endl;
            cout << "3. Manajemen Jadwal" << endl;
            cout << "0. Keluar" << endl;
            cout << "Pilih menu: ";
            cin >> menu;

            if (cin.fail() || menu < 0 || menu > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Menu tidak valid. Silakan coba lagi." << endl;
                continue;
            }

            cin.ignore();
            if (menu != 0){
                if (menu == 1){
                    menuAnggota();
                    continue;
                } 
                else if (menu == 2){
                    menupelatih();
                }
                else if (menu == 3){
                    menuJadwal();
                }
            } else {
                cout << "Terima kasih telah menggunakan Gymmy!" << endl;
                break;
            }
        }
        else if (sesiRole == "ANGGOTA"){
            cout << "--------------------" << endl;
            cout << "GYMMY" << endl;
            cout << "--------------------" << endl;
            cout << "Main Menu" << endl;
            cout << "1. Lihat Jadwal Latihan" << endl;
            cout << "2. Lihat Progress Latihan" << endl; // Perbaikan typo
            cout << "0. Keluar" << endl;
            cout << "Pilih menu: ";
            cin >> menu;

            if (cin.fail() || menu < 0 || menu > 2) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Menu tidak valid. Silakan coba lagi." << endl;
                continue;
            }

            cin.ignore();
            if (menu != 0){
                if (menu == 1){
                    tampilkanJadwal();
                }
                else if (menu == 2){
                    tampil();
                }
            } else {
                cout << "Terima kasih telah menggunakan Gymmy!" << endl;
                break;
            }
        }
        else if (sesiRole == "PELATIH"){
            cout << "--------------------" << endl;
            cout << "GYMMY" << endl;
            cout << "--------------------" << endl;
            cout << "Main Menu" << endl;
            cout << "1. Menu Progress Latihan" << endl; 
            cout << "0. Keluar" << endl;
            cout << "Pilih menu: ";
            cin >> menu;

            if (cin.fail() || menu < 0 || menu > 1) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Menu tidak valid. Silakan coba lagi." << endl;
                continue;
            }

            cin.ignore();
            if (menu != 0){
                if (menu == 1){
                    menuProgress();
                }
            } else {
                cout << "Terima kasih telah menggunakan Gymmy!" << endl;
                break;
            }
        }
        else {
            cout << "Role tidak dikenali. Silakan login ulang." << endl;
            break;
        }
    }
}