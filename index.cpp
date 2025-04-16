#include <iostream>
#include <string>
#include <utility>
#include "anggota.h"
#include "login.cpp"
#include "jadwalLatihan.cpp"
#include "manajemn_pelatih.cpp"
#include "progress_latihan.cpp"
#include "data.h"
using namespace std;

int main(){
    int menu;
    menu = 0;
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
            else {
                cout << "Menu tidak valid. Silakan coba lagi." << endl;
                continue;
            }
        }
    }
    if (sesiRole == "ANGGOTA"){
        cout << "--------------------" << endl;
        cout << "GYMMY" << endl;
        cout << "--------------------" << endl;
        cout << "Main Menu" << endl;
        cout << "1. Lihat Jadwal Latihan" << endl;
        cout << "2. Lihat Progress Latiha" << endl;
        cout << "0. Keluar"<< endl;
        cout << "Pilih menu: ";
        cin >> menu;
        cin.ignore();
        if (menu != 0){
            if (menu == 1){

            }
            else if (menu == 2){
                tampil();
            }
        }
    }
    if (sesiRole == "PELATIH"){
        cout << "--------------------" << endl;
        cout << "GYMMY" << endl;
        cout << "--------------------" << endl;
        cout << "Main Menu" << endl;
        cout << "1. Lihat Jadwal Latihan" << endl;
        cout << "2. Lihat Progress Latiha" << endl;
        cout << "0. Keluar"<< endl;
        cout << "Pilih menu: ";
        cin >> menu;
        cin.ignore();
        if (menu != 0){
            if (menu == 1){
                menuProgress();
            }
            
            }
        }
    cout << "Terima kasih telah menggunakan Gymmy!" << endl;
    break;
 }}