#include <bits/stdc++.h>
using namespace std;
class Hanghoa{
	private:
		string id, name;
	public:
		Hanghoa(){ id = name = " "; }
		~Hanghoa(){}
		void Input();
		void Output();
};

void Hanghoa::Input(){
	cout << "--ID: ";
	cin >> this->id;
	cout << "--Name: ";
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
		Maytinh(){
			nhasx = "";
			year = 2022;
			price = 0;
		}
		~Maytinh(){}
		void Input();
		void Output();
		float tinhPrice();	
		string getNSX();
};

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

float Maytinh::tinhPrice(){ return this->price + (this->price * km / 100); }

string Maytinh::getNSX() { return this->nhasx; }

void Samsung(Maytinh *a, int n){
	cout << "Nhung may tinh cua nha san xuat SAMSUNG: " << endl;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if((*(a + i)).getNSX().compare("SAMSUNG") == 0){
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
	for(int i = 0; i < n; i++){
		if((*(a + i)).tinhPrice() == (*(a + x)).tinhPrice()) {
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

	cout << endl;
	Samsung(a, n);
	cout << endl;

	minPrice(a, n);

	delete [] a;
	return 0;
}

