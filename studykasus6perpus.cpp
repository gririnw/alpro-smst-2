#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Buku {
    string judul;
    string penulis;
    int jumlah;
};

vector<Buku> inventaris;

void tambahBuku() {
    int banyakBuku;
    cout << "Berapa jumlah buku yang ingin anda input? ";
    cin >> banyakBuku;
    cin.ignore();

    for (int i = 0; i < banyakBuku; ++i) {
        Buku buku;
        cout << "\nData Buku ke-" << i + 1 << endl;
        cout << "Masukkan judul buku: ";
        getline(cin, buku.judul);
        cout << "Masukkan nama penulis: ";
        getline(cin, buku.penulis);
        cout << "Masukkan jumlah stok: ";
        cin >> buku.jumlah;
        cin.ignore(); 
        inventaris.push_back(buku);
    }

    cout << "\n" << banyakBuku << " buku berhasil ditambahkan ke inventaris!\n";
}

void hapusBuku() {
    string judul;
    cin.ignore(); 
    cout << "Masukkan judul buku yang ingin dihapus: ";
    getline(cin, judul);

    bool ditemukan = false;
    vector<Buku>::iterator it;
    for (it = inventaris.begin(); it != inventaris.end(); ++it) {
        if (it->judul == judul) {
            inventaris.erase(it);
            cout << "Buku berhasil dihapus!\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Buku tidak ditemukan!\n";
    }
}

void tampilkanInventaris() {
    if (inventaris.empty()) {
        cout << "Inventaris kosong.\n";
        return;
    }

    cout << "\nDaftar Buku:\n";
    cout << "\n======================\n";
    vector<Buku>::const_iterator it;
    for (it = inventaris.begin(); it != inventaris.end(); ++it) {
        cout << "Judul: " << it->judul << "\n";
        cout << "Penulis: " << it->penulis << "\n";
        cout << "Stok: " << it->jumlah << "\n";
        cout << "--------------------------\n";
    }
}

void totalStok() {
    int total = 0;
    vector<Buku>::const_iterator it;
    for (it = inventaris.begin(); it != inventaris.end(); ++it) {
        total += it->jumlah;
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
                tambahBuku();
                break;
            case 2:
                hapusBuku();
                break;
            case 3:
                tampilkanInventaris();
                break;
            case 4:
                totalStok();
                break;
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}

