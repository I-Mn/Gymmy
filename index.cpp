#include <iostream>
#include <string>
#include "anggota.h"
using namespace std;

int main(){
    int menu;
    menu = 0;
    while (true){
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
        } else {
            cout << "Menu tidak valid. Silakan coba lagi." << endl;
            continue;
        }
    }
    cout << "Terima kasih telah menggunakan Gymmy!" << endl;
    break;
 }}