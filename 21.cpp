#include <bits/stdc++.h>
using namespace std;

class Date{
	protected:
		int ngay, thang, nam;
	public:
		Date(){
			ngay = thang = 1;
			nam = 2022;
		}
		~Date(){}
		void Input();
		void Output();
};

void Date::Input(){
	do{
		cout << "--Day: ";
		cin >> this->ngay;
	}while(this->ngay < 1 || this->ngay > 31);
	
	do{
		cout << "--Month: ";
		cin >> this->thang;
	}while(this->thang < 1 || this->thang > 12);
	
	do{
		cout << "--Year: ";
		cin >> this->nam;
	}while(this->nam < 1900 || this->nam > 2022);
}

void Date::Output(){
	cout << "Day/Month/Year: " << this->ngay << "/" << this->thang << "/" << this->nam;
}

class Canbo : public Date{
	private:
		string id,name;
		float salary;
		static float tienphucap;
	public:
		Canbo(){
			id = name = "";
			salary = 0;
		}
		~Canbo();
		void Input();
		void Output();
		float tinhluong();
};

float Canbo::tienphucap = 2000;

void Canbo::Input(){
	cout << "--ID: ";
	cin >> this->id;
	cout << "--Name: ";
	cin.ignore();
	getline(cin, this->name);
	Date::Input();
	cout << "--Luong co ban: ";
	cin >> this->salary;
}

float Canbo::tinhluong(){
	return this->salary + tienphucap;
}

void Canbo::Output(){
	cout << "Ma can bo: " << this->id << "   Ho ten: " << this->name << "   ";
	Date::Output();
	cout << "   Luong co ban: " << this->salary << "$"
		<< "   Luong thuc the: "<< (*this).tinhluong() << "$" << endl;
}

void minSalary(Canbo *a, int n){
	int x = 0;
	float minSalary = (*(a + 0)).tinhluong();
	for(int i = 1; i < n; i++){
		if((*(a + i)).tinhluong() < minSalary) x = i;
	}
	
	cout << "Can bo co luong nho nhat: " << endl;
	for(int i = 0; i < n; i++){
		if((*(a + i)).tinhluong() == (*(a + x)).tinhluong()){
			(*(a + i)).Output();
		}
	}
}

int main(){
	cout << "Nhap ngay thang nam: " << endl;
	Date d;
	d.Input();
	d.Output();
	
	int n;
	cout << "\nNhap so luong can bo: ";
	cin >> n;
	
	Canbo *a = new Canbo[n];
	cout << "Nhap thong tin cho danh sach can bo: " << endl;
	for(int i = 0; i < n; i++){
		cout << "Nhap thong tin cho can bo thu" << i + 1 << ":" << endl;
		(*(a + i)).Input();
	}
	
	cout << "Danh sach can bo vua nhap: " << endl;
	for(int i = 0; i < n; i++){
		(*(a + i)).Output();
	}
	minSalary(a, n);

	delete [] a;
	return 0;
}
