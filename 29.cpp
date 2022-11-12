#include <bits/stdc++.h>
using namespace std;

class Nhanvien{
     protected:
          string id, name;
          int age;
     public:
          Nhanvien(){
               id = name = "";
               age = 18;
          }
          ~Nhanvien(){}
          void Nhap();
          void Xuat();
          bool Vehuu();
};

void Nhanvien::Nhap(){
     cout << "--ID(Ma nhan vien): ";
     cin >> this->id;
     cout << "--Name(Ten): ";
     cin.ignore();
     getline(cin, this->name);
     cout << "--Age(tuoi): ";
     cin >> this->age;
}

void Nhanvien::Xuat(){
     cout << "ID(ma nhan vien): " << this->id << "   Name(Ten): " << this->name << "   Age(Tuoi): " << this->age;
}

bool Nhanvien::Vehuu(){
     return this->age >= 60;
}

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
          void Nhap();
          void Xuat();
          float tinhLuong();
          float getHS(){
               return this->hsl;
          }
};

void Canbo::Nhap(){
     Nhanvien::Nhap();
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
     if(this->age < 60){
          return this->hsl * 1550 + this->phucap;
     }
     else
          return (this->hsl * 1550 + this->phucap) * 70 / 100;
}

void Canbo::Xuat(){
     Nhanvien::Xuat();
     cout << "   HSL(he so luong): " << this->hsl << "   Phu cap: " << this->phucap << "   Trinh do: " << this->trinhdo << "   Salary(Luong): " << (*this).tinhLuong() << endl;
}

void Chuavehuu(Canbo *a, int n){
     int cnt = 0;
     for (int i = 0; i < n; i++){
          if((*(a + i)).Vehuu() == false && (*(a + i)).getHS() > 7.0){
               cnt++;
               (*(a + i)).Xuat();
          }
     }
     if(cnt == 0) cout << "Tat ca can bo da nghi huu" << endl;
}

int main(){
     Nhanvien nv;
     cout << "Nhap thong tin nhan vien: " << endl;
     nv.Nhap();
     nv.Xuat();

     int n;
     cout << "\nNhap so luong can bo: ";
     cin >> n;

     Canbo *a = new Canbo[n];
     cout << "Nhap thong tin cho " << n << " can bo: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Nhap();
     }

     cout << "Danh sach " << n << " can bo: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Xuat();
     }

     cout << "Thong tin nhung can bo chua nghi huu co he so luong > 7.0: " << endl;
     Chuavehuu(a, n);

     delete[] a;
     return 0;
}