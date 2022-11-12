#include <bits/stdc++.h>
using namespace std;

class Date{
	protected:
		int day, month, year;
	public:
		Date(){
			day = month = 1;
			year = 2022;
		}
		~Date(){}
		void Input();
		void Output();
};

void Date::Input(){
	do{
		cout << "--Day: ";
		cin >> this->day;
	}while(this->day < 1 || this->day > 31);
	
	do{
		cout << "--Month: ";
		cin >> this->month;
	}while(this->month < 1 || this->month > 12);
	
	do{
		cout << "--Year: ";
		cin >> this->year;
	}while(this->year < 1900 || this->year > 2022);
}

void Date::Output(){
	cout << "Day/Month/Year: " << this->day << "/" << this->month << "/" << this->year;
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
		~Canbo(){}
		void Input();
		void Output();
		float Salary();
		string getName();
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

float Canbo::Salary(){ return this->salary + tienphucap; }

void Canbo::Output(){
	cout << "Ma can bo: " << this->id << "   Ho ten: " << this->name
		<< "   ";
	Date::Output();
	cout << "   Luong co ban: " << this->Salary() << "$" << endl;
}

string Canbo::getName() { return this->name; }

void minSalary(Canbo *a, int n){
	int x = 0;
	float minSalary = (*(a + 0)).Salary();
	for(int i = 1; i < n; i++){
		if((*(a + i)).Salary() < minSalary) x = i;
	}
	
	cout << "Ho ten can bo co luong thap nhat: " << endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).Salary() == (*(a + x)).Salary())
               cout << (*(a + i)).getName() << endl;
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
		cout << "Nhap thong tin cho can bo thu " << i + 1 << " :" << endl;
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
