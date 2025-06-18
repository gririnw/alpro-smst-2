#include <iostream>
#include <string>

using namespace std;

const int MAX = 100; // Batas maksimum data mahasiswa

struct Mahasiswa {
    string NIM;
    string nama;
    string prodi;
    string no_telp;
};

void inputData(Mahasiswa data[], int& n) {
    char tambahLagi;
    do {
        if (n < MAX) {
            cout << "Masukkan NIM: ";
            cin >> data[n].NIM;
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, data[n].nama);
            cout << "Masukkan Prodi: ";
            getline(cin, data[n].prodi);
            cout << "Masukkan No. Telp: ";
            getline(cin, data[n].no_telp);
            n++;
            cout << "Tambah data lagi? (y/n): ";
            cin >> tambahLagi;
            
            cout << endl;
            
        } else {
            cout << "Data penuh!" << endl;
            break;
        }
    } while (tambahLagi == 'y' || tambahLagi == 'Y');
}

void tampilkanData(const Mahasiswa data[], int n) {
    for (int i = 0; i < n; i++) {
        cout << " NIM: " << data[i].NIM << endl;
		cout << " Nama: " << data[i].nama << endl; 
        cout << " Prodi: " << data[i].prodi <<endl;
		cout << " No. Telp: " << data[i].no_telp << endl;
    }
}

void bubbleSort(Mahasiswa data[], int n, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ascending ? (data[j].NIM > data[j + 1].NIM) : (data[j].NIM < data[j + 1].NIM)) {
                Mahasiswa temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    cout << "Data telah diurutkan." << endl;
}

void cariData(const Mahasiswa data[], int n, const string& nimCari) {
    for (int i = 0; i < n; i++) {
        if (data[i].NIM == nimCari) {
            cout << " NIM: " << data[i].NIM << endl;
			cout << " Nama: " << data[i].nama << endl; 
        	cout << " Prodi: " << data[i].prodi <<endl;
			cout << " No. Telp: " << data[i].no_telp << endl;
			cout << endl;
            return;
        }
    }
    cout << "Data dengan NIM " << nimCari << " tidak ditemukan." << endl;
}

int main() {
    Mahasiswa data[MAX];
    int n = 0;
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << " 1. Input Data\n";
        cout << " 2. Urutkan Data (Ascending/Descending)\n";
        cout << " 3. Cari Data\n";
        cout << " 4. Tampilkan Semua Data\n";
        cout << " 5. Keluar\n";
        cout << " Pilihan: ";
        cin >> pilihan;

		cout << endl;
		
        switch (pilihan) {
            case 1:
                inputData(data, n);
                break;
            case 2: {
                int urutan;
                cout << "Urutkan: " << endl;
				cout << " 1. Ascending" << endl;
				cout << " 2. Descending " << endl;
				cout << " pilih (1/2):";
                cin >> urutan;
                bubbleSort(data, n, urutan == 1);
                break;
            }
            case 3: {
                string nimCari;
                cout << "Masukkan NIM yang dicari: ";
                cin >> nimCari;
                cariData(data, n, nimCari);
                break;
            }
            case 4:
                tampilkanData(data, n);
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
