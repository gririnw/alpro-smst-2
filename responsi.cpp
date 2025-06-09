#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Struct Dosen
struct Dosen {
    string nama;
    string jadwal;
};

// Array dosen
const int JUMLAH_DOSEN = 5;
Dosen daftarDosen[JUMLAH_DOSEN] = {
    {"Dr. Ahmad Fikri", "Senin & Rabu, 08:00 - 10:00"},
    {"Rina Sari", "Selasa & Kamis, 09:00 - 11:00"},
    {"Dr. Budi Santoso", "Senin & Kamis, 10:00 - 12:00"},
    {"Sri Wulandari", "Rabu & Jumat, 07:30 - 09:30"},
    {"James Hartono", "Selasa & Jumat, 13:00 - 15:00"}
};

// Fungsi cari dosen
void tampilkanjadwaldosen() {
    string namadosen;
    cout << "\n===== Daftar Dosen =====" << endl;
    cout << "Nama Dosen: ";
    getline(cin >> ws, namadosen);  // baca input dengan spasi

    // Ubah input menjadi huruf kecil untuk pencarian fleksibel
    string inputLower = namadosen;
    transform(inputLower.begin(), inputLower.end(), inputLower.begin(), ::tolower);

    bool ditemukan = false;
    for (int i = 0; i < JUMLAH_DOSEN; i++) {
        string namaLower = daftarDosen[i].nama;
        transform(namaLower.begin(), namaLower.end(), namaLower.begin(), ::tolower);
        if (namaLower.find(inputLower) != string::npos) {
            cout << "\n>> Dosen ditemukan!" << endl;
            cout << "Nama   : " << daftarDosen[i].nama << endl;
            cout << "Jadwal : " << daftarDosen[i].jadwal << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "\n>> Dosen dengan nama \"" << namadosen << "\" tidak ditemukan." << endl;
    }
}

// Fungsi pilih prodi setelah fakultas
void tampilkanJadwalProdi() {
    int fakultas, prodi;

    // Pilih fakultas
    cout << "\n===== Pilih Fakultas =====" << endl;
    cout << "1. Fakultas Teknologi Industri" << endl;
    cout << "2. Fakultas Ekonomi dan Bisnis" << endl;
    cout << "3. Fakultas Keguruan dan Ilmu Pendidikan" << endl;
    cout << "Pilihan Fakultas (1-3): ";
    cin >> fakultas;

    // Pilih prodi
    cout << "\n===== Pilih Program Studi =====" << endl;
    cout << "1. Teknik Informatika" << endl;
    cout << "2. Sistem Informasi" << endl;
    cout << "3. Manajemen" << endl;
    cout << "4. Pendidikan Matematika" << endl;
    cout << "5. Pendidikan Bahasa Inggris" << endl;
    cout << "Pilihan Prodi (1-5): ";
    cin >> prodi;

    cout << "\n>> Menampilkan Jadwal untuk: ";
    switch (prodi) {
        case 1:
            cout << "Teknik Informatika\nSenin & Rabu, 08:00 - 10:00" << endl;
            break;
        case 2:
            cout << "Sistem Informasi\nSelasa & Kamis, 09:00 - 11:00" << endl;
            break;
        case 3:
            cout << "Manajemen\nSenin & Kamis, 10:00 - 12:00" << endl;
            break;
        case 4:
            cout << "Pendidikan Matematika\nRabu & Jumat, 07:30 - 09:30" << endl;
            break;
        case 5:
            cout << "Pendidikan Bahasa Inggris\nSelasa & Jumat, 13:00 - 15:00" << endl;
            break;
        default:
            cout << "Pilihan prodi tidak valid." << endl;
    }
}

// Submenu Jadwal Kuliah Baru
void tampilkanSubmenuJadwalKuliah() {
    int subpilihan;
    do {
        cout << "\n===== Jadwal Kuliah Baru =====" << endl;
        cout << "1. Jadwal Program Studi" << endl;
        cout << "2. Jadwal Dosen" << endl;
        cout << "3. Jadwal Ruang" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "-------------------------------" << endl;
        cout << "Pilihan Anda: ";
        cin >> subpilihan;

        switch (subpilihan) {
            case 1:
                tampilkanJadwalProdi();
                break;
            case 2:
                tampilkanjadwaldosen();
                break;
            case 3:
                cout << ">> Menampilkan Jadwal Ruang..." << endl;
                break;
            case 4:
                cout << ">> Kembali ke Menu Utama." << endl;
                break;
            default:
                cout << ">> Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (subpilihan != 4);
}

// Menu Utama
void tampilkanMenuUtama() {
    int pilihan;
    do {
        cout << "\n==============================================" << endl;
        cout << "      Sistem Informasi Manajemen Ruang        " << endl;
        cout << "==============================================" << endl;
        cout << "Login sebagai: Mahasiswa\n" << endl;

        cout << "Menu Utama:" << endl;
        cout << "1. Jadwal Kuliah Baru" << endl;
        cout << "2. Jadwal Program Studi" << endl;
        cout << "3. Jadwal Dosen" << endl;
        cout << "4. Jadwal Ruang" << endl;
        cout << "5. Logout" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanSubmenuJadwalKuliah();
                break;
            case 2:
                tampilkanJadwalProdi();
                break;
            case 3:
                tampilkanjadwaldosen();
                break;
            case 4:
                cout << ">> Menampilkan Jadwal Ruang..." << endl;
                break;
            case 5:
                cout << ">> Logout berhasil. Terima kasih!" << endl;
                break;
            default:
                cout << ">> Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);
}

// Program utama
int main() {
    string username, password;

    cout << "==============================================" << endl;
    cout << "           Universitas Ahmad Dahlan           " << endl;
    cout << "==============================================" << endl;
    cout << "         Sistem Informasi Manajemen Ruang     " << endl;
    cout << "----------------------------------------------" << endl;

    cout << "Username : ";
    getline(cin, username);

    cout << "Password : ";
    getline(cin, password);

    if (username == "mhs" && password == "mhs") {
        cout << "\nLogin berhasil! Selamat datang, " << username << "." << endl;
        tampilkanMenuUtama();
    } else {
        cout << "\nLogin gagal! Username atau password salah." << endl;
    }

    return 0;
}

