#include <bits/stdc++.h>
using namespace std;

class Nguoi{
     private:
          string name, gender;
          int year;
     public:
          Nguoi(){
               name = gender = "";
               year = 2022;
          }
          ~Nguoi(){}
          void Input();
          void Output();
          int Age();
};

void Nguoi::Input(){
     cout << "--Name: ";
     fflush(stdin);
     getline(cin, this->name);

     do {
          cout << "--Gender(Gioi tinh): ";
          cin >> this->gender;
     } while( this->gender != "Nam" && this->gender != "Nu" && this->gender != "Khac" );

     do {
          cout << "--Year(Nam sinh): ";
          cin >> this->year;
     } while( this->year < 1900 || this->year > 2022 );
}

void Nguoi::Output(){
     cout << "Name: " << this->name << "   Gender(GT): " << this->gender << "   Year(Nam sinh): " << this->year
          << "   Age(Tuoi): " << this->Age();
}

int Nguoi::Age() { return 2022 - this->year; }

class NhanVien: public Nguoi{
     private:
          double hs, salary, tienan;
     public:
          NhanVien(){ hs = salary = tienan = 0; }
          ~NhanVien(){}
          friend istream& operator >> (istream&, NhanVien&);
          friend ostream& operator << (ostream&, NhanVien);
          bool NghiHuu();
          double Salary();

};

istream& operator >> (istream& in, NhanVien& another){
     another.Input();
     cout << "--HS tham nien: ";
     in >> another.hs;
     cout << "--Salary(Muc luong): ";
     in >> another.salary;
     cout << "--Tien An ca: ";
     in >> another.tienan;

     return in;
}

ostream& operator << (ostream& out, NhanVien another){
     another.Output();
     out << "   HS tham nien: " << fixed << setprecision(2) << another.hs
         << "   Salary(Muc luong): " << fixed << setprecision(2) << another.salary
         << "   Tien an ca: " << fixed << setprecision(2) << another.tienan
         << "   Luong: " << fixed << setprecision(2) << another.Salary()
         << endl;

     return out; 
}

void Input(NhanVien *a, int n){
     cout << "Nhap danh sach " << n << " nhan vien: " << endl;
     for(int i = 0; i < n; i++){
          cout << "Nhap thon tin cua nhan vien thu " << i + 1 << " : " << endl;
          cin >> *(a + i);
     }
}

void Output(NhanVien *a, int n){
     cout << "Danh sach " << n << " nhan vien cung voi luong: " << endl;
     for (int i = 0; i < n; i++) cout << *(a + i); 
}

bool NhanVien::NghiHuu(){ return this->Age() >= 60; }

double NhanVien::Salary(){
     if(this->NghiHuu()) return 0.75 * this->salary * this->hs;
     else return this->salary * this->hs + this->tienan;
}

void NghiHuu(NhanVien* a, int n){
     int cnt = 0;
     cout << "Danh sach nhung nhan vien den tuoi nghi huu: " << endl;
     for(int i = 0; i < n; i++){
          if((*(a + i)).Age() == 60){
               cnt++;
               cout << *(a + i);
          }
     }

     if(cnt == 0) cout << "Khong co nhan vien den tuoi nghi huu" << endl;
}


int main(){
     Nguoi ng;
     cout << "Nhap thong tin cua nguoi: " << endl;
     ng.Input();
     cout << "Thong tin:    "; ng.Output();

     int n;
     cout << "\nNhap so luong nhan vien: ";
     cin >> n;

     NhanVien *a = new NhanVien[n];
     Input(a, n);
     Output(a, n);
     NghiHuu(a, n);

     delete[] a;
     return 0;
}