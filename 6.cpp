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
		friend istream& operator >> (istream&, Maytinh&);
		friend ostream& operator << (ostream&, Maytinh);
		float PriceThucTe();
		bool operator>(Maytinh);
};

int Maytinh::km = 50;

istream& operator >> (istream& in, Maytinh& another){
	another.Input();
	cout << "--Nha sx: ";
	in >> another.nhasx;
	do {
		cout << "--Nam sx: ";
		in >> another.year;
	} while(another.year < 1900 || another.year > 2022);
	cout << "--Gia ban: ";
	in >> another.price;

	return in;
}

ostream& operator << (ostream& out, Maytinh another){
	another.Output();
	out << "   NhaSX: " << another.nhasx << "   NamSX: " << another.year << "   Gia ban: " << another.price
	    << "   Gia ban thuc te: " << fixed << setprecision(2) << another.PriceThucTe() << endl;

	return out;
}

float Maytinh::PriceThucTe(){ return this->price - (this->price * 50/100); }

bool Maytinh::operator>(Maytinh another){ return this->PriceThucTe() > another.PriceThucTe(); }

void sortbyPrice(Maytinh *a, int n){
     for (int i = 0; i < n - 1; i++){
          int index = i;
          for (int j = i + 1; j < n; j++){
               if(*(a + j) > *(a + index)) index = j;
          }
          swap(*(a + i), *(a + index));
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
		cin >> *(a + i);
	}
	
	cout << "Danh sach may tinh: " << endl;
	for(int i = 0; i < n; i++){
		cout << *(a + i);
	}

	cout << "Sap xep " << n << " may tinh giam dan theo gia ban thuc te: " << endl;
	sortbyPrice(a, n);
	for(int i = 0; i < n; i++)
		cout << *(a + i);

	delete[] a;
	return 0;
}