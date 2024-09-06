#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Struct untuk menyimpan data motor Honda
struct DataMotor {
    string merk;
    string tipe;
    int tahun;
};

// ANSI escape codes untuk warna teks
const string GREEN = "\033[1;32m";
const string RED = "\033[1;31m";
const string RESET = "\033[0m";

// Fungsi untuk login, mengembalikan true jika login berhasil, dan false jika gagal
bool login() {
    string username, password;
    int attempt = 0;
    const string correct_username = "akmal_alvian_pratama";
    const string correct_password = "2309106021";

    while (attempt < 3) {
        cout << RESET << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        if (username == correct_username && password == correct_password) {
            cout << GREEN << "Login berhasil.\n";
            return true;
        } else {
            cout << RED << "Login gagal. Silakan coba lagi.\n";
            attempt++;
        }
    }

    cout <<RESET<< "Anda telah melebihi batas percobaan login. Program berhenti.\n";
    return false;
}

// Fungsi untuk menampilkan menu
void displayMenu() {
    cout << RESET << "\nMenu:\n";
    cout << "1. Tambah Data Motor\n";
    cout << "2. Lihat Data Motor\n";
    cout << "3. Edit Data Motor\n";
    cout << "4. Hapus Data Motor\n";
    cout << "5. Keluar\n";
}

// Fungsi untuk menambah data motor ke dalam array
void tambahData(vector<DataMotor>& dataMotor) {
    DataMotor motor;
    cout << "Masukkan Merk Motor: ";
    cin >> motor.merk;
    cout << "Masukkan Tipe Motor: ";
    cin >> motor.tipe;
    cout << "Masukkan Tahun Produksi: ";
    cin >> motor.tahun;
    dataMotor.push_back(motor);
    cout << "Data motor berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan data motor yang ada dalam array
void lihatData(const vector<DataMotor>& dataMotor) {
    if (dataMotor.empty()) {
        cout << " Merk: Vario, Tipe:Matic, Tahun:2024\n";
        return;
    }
    cout << "Data Motor Honda:\n";
    for (size_t i = 0; i < dataMotor.size(); ++i) {
        cout << i + 1 << ". Merk: " << dataMotor[i].merk << ", Tipe: " << dataMotor[i].tipe << ", Tahun: " << dataMotor[i].tahun << endl;
    }
}

// Fungsi untuk mengedit data motor yang ada dalam array
void editData(vector<DataMotor>& dataMotor) {
    lihatData(dataMotor);
    if (dataMotor.empty()) {
        return;
    }
    int index;
    cout << "Masukkan nomor data motor yang ingin diedit: ";
    cin >> index;
    if (index <= 0 || index > static_cast<int>(dataMotor.size())) {
        cout << "Nomor tidak valid.\n";
        return;
    }
    cout << "Masukkan Merk Motor yang baru: ";
    cin >> dataMotor[index - 1].merk;
    cout << "Masukkan Tipe Motor yang baru: ";
    cin >> dataMotor[index - 1].tipe;
    cout << "Masukkan Tahun Produksi yang baru: ";
    cin >> dataMotor[index - 1].tahun;
    cout << "Data motor berhasil diubah.\n";
}

// Fungsi untuk menghapus data motor dari array
void hapusData(vector<DataMotor>& dataMotor) {
    lihatData(dataMotor);
    if (dataMotor.empty()) {
        return;
    }
    int index;
    cout << "Masukkan nomor data motor yang ingin dihapus: ";
    cin >> index;
    if (index <= 0 || index > static_cast<int>(dataMotor.size())) {
        cout << "Nomor tidak valid.\n";
        return;
    }
    dataMotor.erase(dataMotor.begin() + index - 1);
    cout << "Data motor berhasil dihapus.\n";
}

int main() {
    vector<DataMotor> dataMotor;
    char opsi;
    bool loggedIn = false;

    do {
        if (!loggedIn) {
            loggedIn = login();
            if (!loggedIn) {
                return 1;
            }
        }

        displayMenu();
        cout << "Masukkan pilihan: ";
        cin >> opsi;

        switch (opsi) {
            case '1':
                tambahData(dataMotor);
                break;
            case '2':
                lihatData(dataMotor);
                break;
            case '3':
                editData(dataMotor);
                break;
            case '4':
                hapusData(dataMotor);
                break;
            case '5':
                cout << "Program berhenti.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (opsi != '5');

    return 0;
}