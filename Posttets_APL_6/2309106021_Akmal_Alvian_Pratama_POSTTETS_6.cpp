#include <iostream>
#include <string>
#include <vector>
#include <limits> // Untuk membersihkan buffer
#include <algorithm> // Untuk std::sort

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
	system("cls");
}

// Fungsi untuk melakukan login
bool login() {
	clearScreen();
    string username, password;
    const string correct_username = "akmal_alvian_pratama";
    const string correct_password = "2309106021";
    const int max_attempts = 3;
    int attempts = 0;

    do {
        cout << "Masukkan Username: ";
        cin >> username;    
        cout << "Masukkan Password: ";
        cin >> password;

        if (username == correct_username && password == correct_password) {
            cout << "Login berhasil.\n";
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore(); // Menunggu sampai pengguna menekan Enter
            cin.get();
            return true;
        } else {
            cout << "Login gagal. Silakan coba lagi.\n";
            attempts++;
        }
    } while (attempts < max_attempts);

    cout << "Anda telah melebihi batas percobaan login. Program berhenti.\n";
    return false;
}

// Fungsi untuk menampilkan menu
void displayMenu() {
    clearScreen();
    cout << "Menu:\n";
    cout << "1. Tambah Data Motor\n";
    cout << "2. Lihat Data Motor\n";
    cout << "3. Edit Data Motor\n";
    cout << "4. Hapus Data Motor\n";
    cout << "5. Urutkan Data Motor (Ascending)\n";
    cout << "6. Bubble Sort Data Motor\n";
    cout << "7. Selection Sort Data Motor\n";
    cout << "8. Cari Data Motor Terurut (Ascending)\n";
    cout << "9. Cari Data Motor Terurut (Descending)\n";
    cout << "10. Keluar\n";
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
    cout << "Data motor berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan data motor yang ada dalam array
void lihatData(const vector<DataMotor>& dataMotor) {
    clearScreen();
    if (dataMotor.empty()) {
        cout << "Tidak ada data motor.\n";
        return;
    }
    cout << "Data Motor :\n";
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
void editData(vector<DataMotor>* dataMotor) {
    lihatData(*dataMotor);
    if (dataMotor->empty()) {
        cout << "Tidak ada data motor untuk diedit.\n";
        return;
    }
    int index;
    cout << "Masukkan nomor data motor yang ingin diedit: ";
    while (!(cin >> index) || index <= 0 || index > static_cast<int>(dataMotor->size())) {
        cout << "Nomor tidak valid. Masukkan nomor kembali: ";
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int

    DataMotor& motor = (*dataMotor)[index - 1];
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
    cout << "Data motor berhasil diubah.\n";
}

// Fungsi untuk menghapus data motor dari array
void hapusData(vector<DataMotor>* dataMotor) {
    lihatData(*dataMotor);
    if (dataMotor->empty()) {
        cout << "Tidak ada data motor untuk dihapus.\n";
        return;
    }
    int index;
    cout << "Masukkan nomor data motor yang ingin dihapus: ";
    while (!(cin >> index) || index <= 0 || index > static_cast<int>(dataMotor->size())) {
        cout << "Nomor tidak valid. Masukkan nomor kembali: ";
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int

    dataMotor->erase(dataMotor->begin() + index - 1);
    cout << "Data motor berhasil dihapus.\n";
}

// Fungsi untuk melakukan Bubble Sort
void bubbleSort(vector<DataMotor>& dataMotor) {
    int n = dataMotor.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (dataMotor[j].merk > dataMotor[j + 1].merk) {
                std::swap(dataMotor[j], dataMotor[j + 1]); // Memperbaiki pemanggilan swap
            }
        }
    }
    cout << "Data motor berhasil diurutkan menggunakan Bubble Sort.\n";
}

// Fungsi untuk melakukan Selection Sort
void selectionSort(vector<DataMotor>& dataMotor) {
    int n = dataMotor.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (dataMotor[j].merk < dataMotor[minIndex].merk) {
                minIndex = j;
            }
        }
        std::swap(dataMotor[i], dataMotor[minIndex]); // Memperbaiki pemanggilan swap
    }
    cout << "Data motor berhasil diurutkan menggunakan Selection Sort.\n";
}

// Fungsi untuk melakukan pencarian data terurut secara ascending
int searchAscending(const vector<DataMotor>& dataMotor, const string& target) {
    int left = 0;
    int right = dataMotor.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (dataMotor[mid].merk == target) {
            return mid; // Data ditemukan
        } else if (dataMotor[mid].merk < target) {
            left = mid + 1; // Cari di sebelah kanan
        } else {
            right = mid - 1; // Cari di sebelah kiri
        }
    }

    return -1; // Data tidak ditemukan
}

// Fungsi untuk melakukan pencarian data terurut secara descending
int searchDescending(const vector<DataMotor>& dataMotor, const string& target) {
    int left = 0;
    int right = dataMotor.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (dataMotor[mid].merk == target) {
            return mid; // Data ditemukan
        } else if (dataMotor[mid].merk > target) {
            left = mid + 1; // Cari di sebelah kanan
        } else {
            right = mid - 1; // Cari di sebelah kiri
        }
    }

    return -1; // Data tidak ditemukan
}
int searchDescendingSorted(const vector<DataMotor>& dataMotor, const string& target) {
    // Panggil algoritma pengurutan (misalnya bubbleSort atau selectionSort) di sini sebelum pencarian
    vector<DataMotor> sortedData = dataMotor;
    bubbleSort(sortedData); // Panggil fungsi bubbleSort untuk pengurutan
    // selectionSort(sortedData); // Panggil fungsi selectionSort untuk pengurutan

    // Lakukan pencarian biner pada data terurut secara descending
    return searchDescending(sortedData, target);
}

int main() {
    vector<DataMotor> dataMotor;
    char opsi;

    if (!login()) {
        return 1; // Keluar dari program jika login gagal
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
                lihatData(dataMotor);
                break;
            case '3':
                editData(&dataMotor);
                break;
            case '4':
                hapusData(&dataMotor);
                break;
            case '5':
                sort(dataMotor.begin(), dataMotor.end(), [](const DataMotor& a, const DataMotor& b) {
                    return a.merk < b.merk; // Sorting ascending berdasarkan merk
                });
                cout << "Data motor berhasil diurutkan secara ascending berdasarkan merk.\n";
                break;
            case '6':
                bubbleSort(dataMotor);
                break;
            case '7':
                selectionSort(dataMotor);
                break;
            case '8': {
                string target;
                cout << "Masukkan merk motor yang ingin dicari: ";
                cin >> target;
                int index = searchAscending(dataMotor, target);
                if (index != -1) {
                    cout << "Data ditemukan pada indeks: " << index + 1 << endl;
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            }
            case '9': {
                string target;
                cout << "Masukkan merk motor yang ingin dicari: ";
                cin >> target;
                int index = searchDescending(dataMotor, target);
                if (index != -1) {
                    cout << "Data ditemukan pada indeks: " << index + 1 << endl;
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            }
            case '10':
                cout << "Program berhenti.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.ignore(); // Menunggu sampai pengguna menekan Enter
        cin.get();
    } while (opsi != '10');

    return 0;
}