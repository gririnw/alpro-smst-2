#include <iostream>
using namespace std;

class Sorting{
	friend istream& operator>>(istream& in, Sorting& a);
	friend ostream& operator<<(ostream& out, Sorting& a);
public:
	void bubble_sort();
	int pencarianLinear();
private:
	void tukar(int&, int&);
	int data[10], n;
};
void Sorting::tukar(int &a,int &b){
	int temp = a;
	a=b;
	b=temp;
}
void Sorting::bubble_sort(){
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n-1;j++){
			if(data[j]>data[j+1]){
				tukar(data[j],data[j+1]);
			}
		}
	}
}

int Sorting::pencarianLinear(){
	int kunciPencarian;
	cout<<"Masukkan nilai yang ingin dicari : ";
	cin>>kunciPencarian;
	for(int i = 0;i<n;i++){
		if(data[i]==kunciPencarian)
			return i;
	}
	return -1;
}
istream& operator>>(istream& in, Sorting& a){
	cout<<"Masukkan jumlah data(max 10): ";
	in>>a.n;
	for(int i = 0;i<a.n;i++){
		cout<<"Data ke- "<<i+1<<" : ";
		in>>a.data[i];
	}
	return in;
}
ostream& operator<<(ostream& out,Sorting& a){
	out<<"Data : ";
	for(int i = 0;i<a.n;i++){
		out<<a.data[i]<<" ";
	}
	out<<endl;
	return out;
}
int main(){
	Sorting s;
	cin>>s;
	
	cout<<"\nData sebelum disorting:\n";
	cout<<s;
	
	s.bubble_sort();
	
	cout<<"\nData setelah di sorting : \n";
	cout<<s;
	
	int hasil = s.pencarianLinear();
	if(hasil != -1)
		cout<<"Data ditemukan pada indeks ke-"<<hasil<<endl;
	else
		cout<<"Data tidak di temukan."<<endl;
		return 0;
	}

