#include <bits/stdc++.h>
using namespace std;
class Hanghoa{
	private:
		string id, name;
	public:
		Hanghoa(){ id = name = ""; }
		~Hanghoa(){}
		void Input();
		void Output();
};

void Hanghoa::Input(){
	cout << "--ID(Ma hang): ";
	cin >> this->id;
	cout << "--Name(Ten hang): ";
	cin.ignore();
	getline(cin, this->name);
}

void Hanghoa::Output(){
	cout << "ID: " << this->id << "   Name: " << this->name;
}

class Maytinh : public Hanghoa{
	private:
		string nhasx;
		int year;
		float price;
		static int km;
	public:
		Maytinh();
		~Maytinh();
		void Input();
		void Output();
		float tinhPrice();	
		string getNSX();
};

Maytinh::Maytinh(){
	nhasx = "";
	year = 2022;
	price = 0;
}

Maytinh::~Maytinh(){
	nhasx = "";
	year = 2022;
	price = 0;
}

int Maytinh::km = 50;

void Maytinh::Input(){
	Hanghoa::Input();
	cout << "--Nha SX: ";
	getline(cin, this->nhasx);
	cout << "--Year: ";
	cin >> this->year;
	cout << "--Price: ";
	cin >> this->price;
}

void Maytinh::Output(){
	Hanghoa::Output();
	cout << "   Nha SX: " << this->nhasx << "   Year: " << this->year << "   Price: " << this->price << endl;
}

float Maytinh::tinhPrice(){
     float price;
     price = this->price + (this->price * km / 100);

     return price;
}

string Maytinh::getNSX(){ 
	return this->nhasx; 
}

void Samsung(Maytinh *a, int n){
	cout << "Nhung may tinh cua nha san xuat SAMSUNG: " << endl;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if((*(a + i)).getNSX() == "SAMSUNG"){
			cnt++;
			(*(a + i)).Output();
		}
	}

	if(cnt == 0) cout << "Khong co may tinh nao cua nha san xuat SAMSUNG trong danh sach" << endl;
}

void minPrice(Maytinh *a, int n){
	float minPrice = (*(a + 0)).tinhPrice();
	int x = 0;
	for(int i = 1; i < n; i++){
		if((*(a + i)).tinhPrice() < minPrice) x = i;
	}
	cout << "May tinh co gia ban thuc te nho nhat: " << endl;
	for (int i = 0; i < n; i++){
		if((*(a + i)).tinhPrice() == (*(a + x)).tinhPrice()){
			(*(a + i)).Output();
		}
	}
	
}

int main(){
	Hanghoa h;
	cout << "Nhap thong tin cho hang hoa: " << endl;
	h.Input();
	h.Output();
	cout << endl;
	
	int n;
	cout << "Nhap so luong may tinh: ";
	cin >> n;
	
	Maytinh *a = new Maytinh[n];
	cout << "Nhap thong tin danh sach may tinh: " << endl;
	for(int i = 0; i < n; i++){
		cout << "Nhap may tinh thu " << i + 1 << ":" << endl;
		(*(a + i)).Input();
	}
	
	cout << "Danh sach may tinh: " << endl;
	for(int i = 0; i < n; i++){
		(*(a + i)).Output();
	}
	Samsung(a, n);
	minPrice(a, n);

	delete [] a;
	return 0;
}

