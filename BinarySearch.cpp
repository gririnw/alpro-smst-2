#include <iostream>
using namespace std;

class Searching {
    friend istream& operator>>(istream& in, Searching& a);
    friend ostream& operator<<(ostream& out, Searching& a);
public:
    int binarySearch(); // pencarian biner tanpa sorting
private:
    int data[10], n;
};

// Fungsi pencarian biner
int Searching::binarySearch() {
    int low = 0;
    int high = n - 1;
    int middle;
    int kunciPencarian;

    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> kunciPencarian;

    while (low <= high) {
        middle = (low + high) / 2;
        cout << "Low: " << low << ", Middle: " << middle << ", High: " << high << endl;

        if (kunciPencarian == data[middle])
            return middle;
        else if (kunciPencarian < data[middle])
            high = middle - 1;
        else
            low = middle + 1;
    }

    return -1;
}

// Input data
istream& operator>>(istream& in, Searching& a) {
    cout << "Masukkan jumlah data (maksimal 10): ";
    in >> a.n;
    cout << "Masukkan data yang sudah terurut dari kecil ke besar:\n";
    for (int i = 0; i < a.n; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        in >> a.data[i];
    }
    return in;
}

// Output data
ostream& operator<<(ostream& out, Searching& a) {
    out << "Data: ";
    for (int i = 0; i < a.n; i++) {
        out << a.data[i] << " ";
    }
    out << endl;
    return out;
}

// Fungsi utama
int main() {
    Searching s;
    cin >> s;

    cout << "\nData yang dimasukkan:\n";
    cout << s;

    int hasil = s.binarySearch();

    if (hasil != -1)
        cout << "Data ditemukan pada indeks ke-" << hasil << endl;
    else
        cout << "Data tidak ditemukan." << endl;

    return 0;
}

