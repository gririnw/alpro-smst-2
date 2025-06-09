#include <iostream>
#include <iomanip>
using namespace std;

int hitung_total_SKS(int sks[], int n){
		if (n == 0) return 0;
			return sks[n-1] + hitung_total_SKS(sks, n -1);
}

int main(){
	string nim, nama;
	string matkul[50];
	int sks[50];
	int jumlah_matkul;
	
		cout << "Masukan NIM: ";
		getline(cin, nim);
		cout << "Masukan Nama Mahasiswa: ";
		getline(cin, nama);
	
		cout << "Masukan Jumlah Mata Kuliah: ";
		cin >> jumlah_matkul;
		cin.ignore();
					cout << endl;
			for (int i=0; i<jumlah_matkul; i++){
				cout << "Masukan nama mata kuliah ke-" << i + 1 << ": ";
				getline(cin, matkul[i]);
				cout << "Masukan sks untuk " << matkul[i] << ": ";
				cin >> sks[i];
				cin.ignore();
			}
	
	int totalSKS = hitung_total_SKS(sks, jumlah_matkul);
	int totalbiaya = totalSKS * 125000;
	double diskon = 0.15 * totalbiaya;
	double totalbayar = totalbiaya -  diskon;
	
		cout << "\n=== DATA PEMBAYARAN MAHASISWA ===\n";
		cout << "NIM\t: " << nim << endl;
		cout << "Nama\t: " << nama << endl;
		cout << "Daftar mata kuliah:\n";
			for (int i = 0; i<jumlah_matkul; i++){
				cout << " - " << matkul[i] << " (" << sks[i] << "SKS)" << endl;
			}
		cout << "Total SKS\t: " << totalSKS << endl;
		cout << "Total biaya\t: Rp" << (int)totalbiaya << endl;
		cout << "Diskon 15%\t: Rp" << (int)diskon << endl;
		cout << "Total bayar\t: Rp" << (int)totalbayar << endl;
		
		return 0;
}

