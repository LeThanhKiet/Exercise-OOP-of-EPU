#include <bits/stdc++.h>
using namespace std;

class Nguoi{
     private:
          string id, name;
     public:
          Nguoi(){ id = name = ""; }    
          ~Nguoi(){}
          void Nhap();
          void Xuat();
};

void Nguoi::Nhap(){
     cout << "--ID(ma dinh danh): ";
     cin >> this->id;
     cout << "--Name(Ho ten): ";
     cin.ignore();
     getline(cin, this->name);
}

void Nguoi::Xuat(){
     cout << "ID(ma dinh danh): " << this->id << "   Name(Ho ten): " << this->name;
}

class Nhanvien : public Nguoi{
     private:
          int year;
          float hs;
          static float tienpc;
     public:
          Nhanvien(){
               year = 0;
               hs = 0;
          }
          ~Nhanvien(){}
          friend istream& operator>>(istream&, Nhanvien&);
          friend ostream& operator<<(ostream&, Nhanvien);
          float salary();
          bool operator>(Nhanvien);
};

istream& operator>>(istream& in, Nhanvien& another){
     another.Nhap();
     do {
          cout << "--Year(Nam sinh): ";
          in >> another.year;
     } while (another.year < 1900 || another.year > 2022);
     cout << "--He so luong: ";
     in >> another.hs;

     return in;
}

ostream& operator<<(ostream& out, Nhanvien another){
     another.Xuat();
     out << "   Year(Nam sinh): " << another.year << "   He So Luong: " << another.hs 
         << "   Salary(Luong): " << fixed << setprecision(2) << another.salary() << "$" << endl;

     return out;
}

float Nhanvien::salary() { return this->hs * 1550 + tienpc; }

bool Nhanvien::operator>(Nhanvien another) { return this->hs > another.hs; }

void sortbyHSL(Nhanvien *a, int n){
     for(int i = 1; i < n; i++){
          Nhanvien res = *(a + i);
          int pos = i - 1;
          while(pos >= 0 && res > *(a + pos)){
               *(a + pos + 1) = *(a + pos);
               pos--;
          }
          *(a + pos + 1) = res;
     }
}

float Nhanvien::tienpc = 1000;

int main(){
     Nguoi ng;
     cout << "Nhap thong tin nguoi: " << endl;
     ng.Nhap();
     cout << "Thong tin nguoi vua nhap: " << endl;
     ng.Xuat();

     int n;
     cout << "\nNhap so luong nhan vien: ";
     cin >> n;

     Nhanvien *a = new Nhanvien[n];
     for(int i = 0; i < n; i++){
          cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
          cin >> *(a + i);
     }

     cout << "Danh sach " << n << " nhan vien vua nhap: " << endl;
     for (int i = 0; i < n; i++){
          cout << *(a + i);
     }
     cout << "Danh sach " << n << " nhan vien sap xep giam dan theo HSL: " << endl;
     sortbyHSL(a, n);
     for (int i = 0; i < n; i++){
          cout << *(a + i);
     }

     delete[] a;
     return 0;
}