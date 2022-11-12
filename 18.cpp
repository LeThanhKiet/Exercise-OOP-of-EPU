#include <bits/stdc++.h>
using namespace std;
class Thisinh{
     protected:
          int sbd;
          string name, address;
          float duutien;
     public:
          Thisinh(){
               sbd = 0;
               name = address = "";
               duutien = 0;
          }

          ~Thisinh(){}
          void Nhap();
          void Xuat();
};

void Thisinh::Nhap(){
     cout << "--SBD: ";
     cin >> this->sbd;
     cout << "--Name(Ho ten): ";
     cin.ignore();
     getline(cin, this->name);
     cout << "--Address(Dia chi): ";
     getline(cin, this->address);
     cout << "--Diem uu tien: ";
     cin >> this->duutien;
}

void Thisinh::Xuat(){
     cout << "SBD: " << this->sbd << "   Ho ten: " << this->name << "   Dia chi: " << this->address
          << "   Diem uu tien: " << this->duutien;
}

class ThisinhkhoiA : public Thisinh{
     private:
          float dToan, dLy, dHoa;
     public:
          ThisinhkhoiA(){
               dToan = dLy = dHoa = 0;
          }

          ~ThisinhkhoiA(){}
          void Nhap();
          void Xuat();

          float tongDiem();
          bool operator>(ThisinhkhoiA another);
};

void ThisinhkhoiA::Nhap(){
     Thisinh::Nhap();
     do
     {
          cout << "--Diem toan: ";
          cin >> this->dToan;
     } while (dToan < 0 || dToan > 10);
     
     do
     {
          cout << "--Diem ly: ";
          cin >> this->dLy;
     } while (dLy < 0 || dLy > 10);
     
     do
     {
          cout << "--Diem hoa: ";
          cin >> this->dHoa;
     } while (dHoa < 0 || dHoa > 10);
     
}

void ThisinhkhoiA::Xuat(){
     Thisinh::Xuat();
     cout << "   Diem toan: " << this->dToan << "   Diem ly: " << this->dLy << "   Diem hoa: " << this->dHoa
          << "   Tong diem: " << (*this).tongDiem() << endl;
}

float ThisinhkhoiA::tongDiem(){ return this->dToan + this->dLy + this->dHoa + this->duutien; }


bool ThisinhkhoiA::operator>(ThisinhkhoiA another){
     return (*this).tongDiem() > another.tongDiem();
}

void sortbyDiem(ThisinhkhoiA *a, int n){
      for (int i = 0; i < n - 1; i++){
          int index = i;
          for (int j = i + 1; j < n; j++){
               if(*(a + j) > *(a + index))
                    index = j;
          }
          swap(*(a + i), *(a + index));
     }
}

int main(){
     Thisinh t;
     cout << "Nhap thi sinh: " << endl;
     t.Nhap();
     cout << "Thi sinh: " << endl;
     t.Xuat();

     int n;
     cout << "\nNhap so luong thi sinh khoi A: ";
     cin >> n;

     ThisinhkhoiA *a = new ThisinhkhoiA[n];
     cout << "Nhap thong tin cho danh sach thi sinh khoi A: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Nhap();
     }

     cout << "Danh sach " << n << " thi sinh khoi A: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Xuat();
     }

     cout << "Sap xep danh sach sinh vien giam dan theo tong diem: " << endl;
     sortbyDiem(a, n);
     for (int i = 0; i < n; i++){
          (*(a + i)).Xuat();
     }
     
     delete[] a;
     return 0;
}