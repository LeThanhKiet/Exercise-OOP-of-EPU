#include <bits/stdc++.h>
using namespace std;

class Nguoi{
     private:
          string name, gt;
          int year;
     public:
          Nguoi(){
               name = gt = "";
               year = 2022;
          }

          ~Nguoi(){}
          void Input();
          void Output();
          int Age();
};

void Nguoi::Input(){
     cout << "--Name(Ho ten): ";
     fflush(stdin);
     getline(cin, this->name);

     do{
          cout << "--Gender(Gioi tinh): ";
          cin >> this->gt;
     } while (this->gt != "Nam" && this->gt != "Nu" && this->gt != "Khac");

     do{
          cout << "--Year(Nam sinh): ";
          cin >> this->year;
     } while (this->year < 1900 || this->year > 2022);
}

int Nguoi::Age(){ return 2022 - this->year; }

void Nguoi::Output(){
     cout << "Ho ten: " << this->name << "   Gioi tinh: " << this->gt << "   Nam sinh: " << this->year << "   Tuoi: " << (*this).Age();
}

class Nhanvien : public Nguoi{
     private:
          float hsThamnien, mucLuong, anCa;
     public:
          Nhanvien(){ hsThamnien = mucLuong = anCa = 0; }
          ~Nhanvien(){}
          void Input();
          void Output();
          bool nghiHuu();
          float Luong();
};

void Nhanvien::Input(){
     Nguoi::Input();
     cout << "--HS tham nien: ";
     cin >> this->hsThamnien;
     cout << "--Muc luong: ";
     cin >> this->mucLuong;
     cout << "--Tien an ca: ";
     cin >> this->anCa;
}

bool Nhanvien::nghiHuu(){ return (*this).Age() >= 60; }

float Nhanvien::Luong(){
     if((*this).nghiHuu()){
          return 0.75 * this->mucLuong * this->hsThamnien;
     }else return this->mucLuong * this->hsThamnien + this->anCa;
}

void Nhanvien::Output(){
     Nguoi::Output();
     cout << "   HS tham nien: " << this->hsThamnien << "   Muc luong: " << this->mucLuong 
          << "   Tien an ca: " << this->anCa << "   Luong: " << (*this).Luong() << endl;
}

void Nghihuu(Nhanvien *a, int n){
     int cnt = 0;
     cout << "Nhung nhan vien den tuoi nghi huu: " << endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).Age() == 60){
               cnt++;
               (*(a + i)).Output();
          }
     }

     if(cnt == 0) cout << "Khong co nhan vien nao den tuoi nghi huu" << endl;
}

int main(){
     Nguoi ng;
     cout << "Nhap thong tin nguoi: " << endl;
     ng.Input();
     cout << "Thon tin cua nguoi: " << endl;
     ng.Output();

     int n;
     cout << "\nNhap so luong nhan vien: ";
     cin >> n;

     Nhanvien *a = new Nhanvien[n];
     cout << "Nhap danh sach sinh vien: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Input();
     }

     cout << "Danh sach " << n << " nhan vien: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Output();
     }

     Nghihuu(a, n);

     delete[] a;
     return 0;
}