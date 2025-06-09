#include <iostream>
#include <string>

using namespace std;

struct Buku {
    string judul;
    string penulis;
    int jumlah;
};

const int MAKS_BUKU = 100;
Buku inventaris[MAKS_BUKU];
int jumlahdata = 0; 

void tambahbuku() {
    int banyak;
    cout << "Berapa jumlah buku yang ingin anda input? ";
    cin >> banyak;
    cin.ignore(); 

    if (jumlahdata + banyak > MAKS_BUKU) {
        cout << "Maaf, data melebihi kapasitas maksimal (" << MAKS_BUKU << " buku).\n";
        return;
    }

    for (int i = 0; i < banyak; ++i) {
        cout << "\nData Buku ke-" << (jumlahdata + 1) << endl;
        cout << "Masukkan judul buku: ";
        getline(cin, inventaris[jumlahdata].judul);
        cout << "Masukkan nama penulis: ";
        getline(cin, inventaris[jumlahdata].penulis);
        cout << "Masukkan jumlah stok: ";
        cin >> inventaris[jumlahdata].jumlah;
        cin.ignore(); 

        jumlahdata++;
    }

    cout << banyak << " buku berhasil ditambahkan!\n";
}

void hapusbuku() {
    string judul;
    cin.ignore();
    cout << "Masukkan judul buku yang ingin dihapus: ";
    getline(cin, judul);

    bool ditemukan = false;

    for (int i = 0; i < jumlahdata; ++i) {
        if (inventaris[i].judul == judul) {

            for (int j = i; j < jumlahdata - 1; ++j) {
                inventaris[j] = inventaris[j + 1];
            }
            jumlahdata--;
            ditemukan = true;
            cout << "Buku berhasil dihapus!\n";
            break;
        }
    }

    if (!ditemukan) {
        cout << "Buku tidak ditemukan!\n";
    }
}

void tampilkaninventaris() {
    if (jumlahdata == 0) {
        cout << "Inventaris kosong.\n";
        return;
    }

    cout << "\nDaftar Buku:\n";
    cout << "\n======================\n";
    for (int i = 0; i < jumlahdata; ++i) {
        cout << "Judul: " << inventaris[i].judul << endl;
        cout << "Penulis: " << inventaris[i].penulis << endl;
        cout << "Stok: " << inventaris[i].jumlah << endl;
        cout << "--------------------------\n";
    }
}

void totalstok() {
    int total = 0;
    for (int i = 0; i < jumlahdata; ++i) {
        total += inventaris[i].jumlah;
    }
    cout << "Total stok semua buku: " << total << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\n=== Menu Inventaris Toko Buku ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Hapus Buku\n";
        cout << "3. Tampilkan Semua Buku\n";
        cout << "4. Hitung Total Stok\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahbuku();
                break;
            case 2:
                hapusbuku();
                break;
            case 3:
                tampilkaninventaris();
                break;
            case 4:
                totalstok();
                break;
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
