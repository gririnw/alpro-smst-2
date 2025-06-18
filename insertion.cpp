#include <iostream>
using namespace std;

class Sorting {
    friend istream& operator>>(istream& in, Sorting& a);
    friend ostream& operator<<(ostream& out, Sorting& a);
public:
    void selection_sort();
    int pencarianLinear(); // ganti jadi linear search
private:
    void minimum(int, int, int&);
    void tukar(int&, int&);
    int data[10], n;
};

void Sorting::minimum(int dari, int n, int &tempat) {
    int min = data[dari];
    tempat = dari;
    for (int i = dari + 1; i < n; i++) {
        if (data[i] < min) {
            min = data[i];
            tempat = i;
        }
    }
}

void Sorting::tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Sorting::selection_sort() {
    int t;
    for (int i = 0; i < n; i++) {
        minimum(i, n, t);
        tukar(data[i], data[t]);
    }
}

// Fungsi pencarian linear tanpa variabel low, high, middle
int Sorting::pencarianLinear() {
    int kunciPencarian;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> kunciPencarian;

    for (int i = 0; i < n; i++) {
        if (data[i] == kunciPencarian)
            return i;
    }
    return -1;
}

istream& operator>>(istream& in, Sorting& a) {
    cout << "Masukkan jumlah data (maksimal 10): ";
    in >> a.n;
    for (int i = 0; i < a.n; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        in >> a.data[i];
    }
    return in;
}

ostream& operator<<(ostream& out, Sorting& a) {
    out << "Data: ";
    for (int i = 0; i < a.n; i++) {
        out << a.data[i] << " ";
    }
    out << endl;
    return out;
}

int main() {
    Sorting s;
    cin >> s;

    cout << "\nData sebelum disorting:\n";
    cout << s;

    s.selection_sort();

    cout << "\nData setelah disorting:\n";
    cout << s;

    int hasil = s.pencarianLinear();

    if (hasil != -1)
        cout << "Data ditemukan pada indeks ke-" << hasil << endl;
    else
        cout << "Data tidak ditemukan." << endl;

    return 0;
}

