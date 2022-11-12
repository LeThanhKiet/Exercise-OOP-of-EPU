#include <bits/stdc++.h>
using namespace std;

class Nhanvien{
     private:
          string id, name;
          int age;
     public:
          Nhanvien(){
               id = name = "";
               age = 18;
          }
          ~Nhanvien(){}
          void Input();
          void Output();
          bool Vehuu();
};

void Nhanvien::Input(){
     cout << "--ID(Ma nhan vien): ";
     cin >> this->id;
     cout << "--Name(Ten): ";
     cin.ignore();
     getline(cin, this->name);
     cout << "--Age(tuoi): ";
     cin >> this->age;
}

void Nhanvien::Output(){
     cout << "ID(ma nhan vien): " << this->id << "   Name(Ten): " << this->name << "   Age(Tuoi): " << this->age;
}

bool Nhanvien::Vehuu(){ return this->age >= 60; }

class Canbo : public Nhanvien{
     private:
          float hsl, phucap;
          string trinhdo;
     public:
          Canbo(){
               hsl = phucap = 0;
               trinhdo = "";
          }
          ~Canbo(){}
          void Input();
          void Output();

          float tinhLuong();
};

void Canbo::Input(){
     Nhanvien::Input();
     cout << "--HLS(He so luong): ";
     cin >> this->hsl;
     cout << "--Phu cap: ";
     cin >> this->phucap;
     cin.ignore();
     do
     {
          cout << "--Trinh do: ";
          getline(cin, this->trinhdo);
     } while (this->trinhdo != "Dai hoc" && this->trinhdo != "Cao dang" && this->trinhdo != "Trung cap" && this->trinhdo != "Khac");
     
}

float Canbo::tinhLuong(){
     if(this->Vehuu() == false){
          return this->hsl * 1550 + this->phucap;
     }
     else
          return (this->hsl * 1550 + this->phucap) * 70 / 100;
}

void Canbo::Output(){
     Nhanvien::Output();
     cout << "   HSL(he so luong): " << this->hsl << "   Phu cap: " << this->phucap << "   Trinh do: " << this->trinhdo << "   Salary(Luong): " << (*this).tinhLuong() << endl;
}

void Chuavehuu(Canbo *a, int n){
     int cnt = 0;
     for (int i = 0; i < n; i++){
          if((*(a + i)).Vehuu() == false){
               cnt++;
               (*(a + i)).Output();
          }
     }
     if(cnt == 0) cout << "Tat ca can bo da nghi huu" << endl;
}

int main(){
     Nhanvien nv;
     cout << "Nhap thong tin nhan vien: " << endl;
     nv.Input();
     nv.Output();

     int n;
     cout << "\nNhap so luong can bo: ";
     cin >> n;

     Canbo *a = new Canbo[n];
     cout << "Nhap thong tin cho " << n << " can bo: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Input();
     }

     cout << "Danh sach " << n << " can bo: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Output();
     }

     cout << "Thong tin nhung can bo chua nghi huu: " << endl;
     Chuavehuu(a, n);

     delete[] a;
     return 0;
}