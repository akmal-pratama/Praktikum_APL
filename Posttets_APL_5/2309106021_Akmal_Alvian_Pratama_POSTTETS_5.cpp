#include <iostream>
#include <string>
#include <vector>
#include <limits> // Untuk membersihkan buffer

using namespace std;

// Struct untuk menyimpan data spesifikasi motor
struct Spesifikasi {
    string warna;
    int cc;
};

// Struct untuk menyimpan data motor Honda
struct DataMotor {
    string merk;
    string tipe;
    int tahun;
    Spesifikasi spesifikasi;
};

// Fungsi untuk membersihkan buffer
void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fungsi untuk membersihkan layar konsol
void clearScreen() {
    cout << "\033[2J\033[1;1H"; // ANSI escape code untuk membersihkan layar
}

// Fungsi untuk menampilkan menu
void displayMenu() {
    clearScreen();
    cout << "Menu:\n";
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
    getline(cin, motor.merk);
    cout << "Masukkan Tipe Motor: ";
    getline(cin, motor.tipe);
    cout << "Masukkan Tahun Produksi: ";
    while (!(cin >> motor.tahun)) {
        cout << "Input tahun tidak valid. Masukkan tahun kembali: ";
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int
    cout << "Masukkan Warna Motor: ";
    getline(cin, motor.spesifikasi.warna);
    cout << "Masukkan Kapasitas Mesin (cc): ";
    while (!(cin >> motor.spesifikasi.cc)) {
        cout << "Input kapasitas mesin tidak valid. Masukkan cc kembali: ";
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int
    dataMotor.push_back(motor);
    cout << "\nData motor berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan data motor yang ada dalam array
void lihatData(const vector<DataMotor>* dataMotorPtr) { // <--
    clearScreen();
    const vector<DataMotor>& dataMotor = *dataMotorPtr;
    if (dataMotor.empty()) {
        cout << "Tidak ada data motor.\n";
        return;
    }
    cout << "Data Motor Honda:\n";
    for (size_t i = 0; i < dataMotor.size(); ++i) {
        cout << "Data ke-" << i + 1 << ":\n";
        cout << "  Merk: " << dataMotor[i].merk << endl;
        cout << "  Tipe: " << dataMotor[i].tipe << endl;
        cout << "  Tahun: " << dataMotor[i].tahun << endl;
        cout << "  Spesifikasi:\n";
        cout << "    Warna: " << dataMotor[i].spesifikasi.warna << endl;
        cout << "    CC: " << dataMotor[i].spesifikasi.cc << endl;
    }
}

// Fungsi untuk mengedit data motor yang ada dalam array
void editData(vector<DataMotor>* dataMotorPtr) { // <--
    lihatData(dataMotorPtr);
    vector<DataMotor>& dataMotor = *dataMotorPtr;
    if (dataMotor.empty()) {
        cout << "Tidak ada data motor untuk diedit.\n";
        return;
    }
    int index;
    cout << "Masukkan nomor data motor yang ingin diedit: ";
    while (!(cin >> index) || index <= 0 || index > static_cast<int>(dataMotor.size())) {
        cout << "Nomor tidak valid. Masukkan nomor kembali: ";
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int

    DataMotor& motor = dataMotor[index - 1];
    cout << "Masukkan Merk Motor yang baru: ";
    getline(cin, motor.merk);
    cout << "Masukkan Tipe Motor yang baru: ";
    getline(cin, motor.tipe);
    cout << "Masukkan Tahun Produksi yang baru: ";
    while (!(cin >> motor.tahun)) {
        cout << "Input tahun tidak valid. Masukkan tahun kembali: ";
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int
    cout << "Masukkan Warna Motor yang baru: ";
    getline(cin, motor.spesifikasi.warna);
    cout << "Masukkan Kapasitas Mesin (cc) yang baru: ";
    while (!(cin >> motor.spesifikasi.cc)) {
        cout << "Input kapasitas mesin tidak valid. Masukkan cc kembali: ";
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int
    cout << "\nData motor berhasil diubah.\n";
}

// Fungsi untuk menghapus data motor dari array
void hapusData(vector<DataMotor>& dataMotor) { // <--
    lihatData(&dataMotor);
    if (dataMotor.empty()) {
        cout << "Tidak ada data motor untuk dihapus.\n";
        return;
    }
    int index;
    cout << "Masukkan nomor data motor yang ingin dihapus: ";
    while (!(cin >> index) || index <= 0 || index > static_cast<int>(dataMotor.size())) {
        cout << "Nomor tidak valid. Masukkan nomor kembali: ";
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int

    dataMotor.erase(dataMotor.begin() + index - 1);
    cout << "Data motor berhasil dihapus.\n";
}

int main() {
    vector<DataMotor> dataMotor;
    char opsi;

    // Menggunakan rekursi untuk login
    if (!login()) {
        return 1;
    }

    do {
        displayMenu();
        cout << "\nMasukkan pilihan: ";
        cin >> opsi;
        clearBuffer(); // Membersihkan buffer setelah menerima input char

        switch (opsi) {
            case '1':
                tambahData(dataMotor);
                break;
            case '2':
                lihatData(&dataMotor);
                break;
            case '3':
                editData(&dataMotor);
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
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.get(); // Menunggu sampai pengguna menekan Enter
    } while (opsi != '5');

    return 0;
    }