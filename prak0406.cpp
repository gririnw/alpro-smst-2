#include <iostream>
using namespace std;

void geserKiriIteratif(int arr[], int n) {
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Array sebelum digeser: ";
    tampilkanArray(data, n);

    geserKiriIteratif(data, n);

    cout << "Array setelah digeser (iteratif): ";
    tampilkanArray(data, n);

    return 0;
}

