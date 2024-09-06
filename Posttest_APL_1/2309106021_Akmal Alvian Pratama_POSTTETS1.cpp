#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string nama, nim;
    int salah = 0;

    do {
        cout << "=== Program Konversi Mata Uang ===" << endl;
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama != "akmal_alvian_pratama" || nim != "2309106021") {
            salah++;
            if (salah == 3) {
                cout << "Anda telah salah memasukkan nama atau NIM sebanyak 3 kali. Program berhenti." << endl;
                break;
            }
            cout << "Nama atau NIM salah. Kesempatan mencoba: " << 3 - salah << endl;
            continue;
        }

        int menu;
        double nilai;
        
        do {
            cout << "\nMenu Konversi Mata Uang:" << endl;
            cout << "1. Konversi Rupiah ke Dollar, Euro, Yen" << endl;
            cout << "2. Konversi Dollar ke Rupiah, Euro, Yen" << endl;
            cout << "3. Konversi Euro ke Rupiah, Dollar, Yen" << endl;
            cout << "4. Konversi Yen ke Rupiah, Dollar, Euro" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilih menu: ";
            cin >> menu;

            switch(menu) {
                case 1:
                    cout << "Masukkan jumlah Rupiah: ";
                    cin >> nilai;
                    cout << "Konversi ke:" << endl;
                    cout << "Dollar: " << fixed << setprecision(2) << nilai / 15000 << endl;
                    cout << "Euro: " << fixed << setprecision(2) << nilai / 18000 << endl;
                    cout << "Yen: " << fixed << setprecision(2) << nilai / 140 << endl;
                    break;
                case 2:
                    cout << "Masukkan jumlah Dollar: ";
                    cin >> nilai;
                    cout << "Konversi ke:" << endl;
                    cout << "Rupiah: " << fixed << setprecision(2) << nilai * 15000 << endl;
                    cout << "Euro: " << fixed << setprecision(2) << nilai * 0.82 << endl;
                    cout << "Yen: " << fixed << setprecision(2) << nilai * 105 << endl;
                    break;
                case 3:
                    cout << "Masukkan jumlah Euro: ";
                    cin >> nilai;
                    cout << "Konversi ke:" << endl;
                    cout << "Rupiah: " << fixed << setprecision(2) << nilai * 18000 << endl;
                    cout << "Dollar: " << fixed << setprecision(2) << nilai * 1.22 << endl;
                    cout << "Yen: " << fixed << setprecision(2) << nilai * 126 << endl;
                    break;
                case 4:
                    cout << "Masukkan jumlah Yen: ";
                    cin >> nilai;
                    cout << "Konversi ke:" << endl;
                    cout << "Rupiah: " << fixed << setprecision(2) << nilai * 140 << endl;
                    cout << "Dollar: " << fixed << setprecision(2) << nilai * 0.0095 << endl;
                    cout << "Euro: " << fixed << setprecision(2) << nilai * 0.0079 << endl;
                    break;
                case 5:
                    cout << "Terima kasih telah menggunakan program konversi mata uang." << endl;
                    break;
                default:
                    cout << "Menu tidak valid." << endl;
            }
        } while (menu != 5);

    } while (true);

    return 0;
}