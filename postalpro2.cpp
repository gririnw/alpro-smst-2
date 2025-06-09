#include <iostream>
using namespace std;

void MODULUS(int n) {
    if (n % 5 == 0 && n % 7 == 0) {
        cout << n << " ";
    }
}

int main() {
    int x = 1;
    int batas = 100;

    cout << "Hasil bilangan yang habis dibagi 5 dan 7 adalah: ";
    while (x <= batas) {
        MODULUS(x);
        x = x + 1;
    }
    cout << endl;

    return 0;
}
