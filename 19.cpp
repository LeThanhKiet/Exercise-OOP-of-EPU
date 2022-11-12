#include <bits/stdc++.h>
using namespace std;

class Monhoc{
     protected:
          string maMH, tenMH;
     public:
          Monhoc(){
               maMH = tenMH = "";
          }
          ~Monhoc(){}
          void Nhap();
          void Xuat();
};

void Monhoc::Nhap(){
     cout << "--Ma MH: ";
     cin >> this->maMH;
     cout << "--Ten MH: ";
     cin.ignore();
     getline(cin, this->tenMH);
}

void Monhoc::Xuat(){
     cout << "Ma MH: " << this->maMH << "   Ten MH: " << this->tenMH << endl;
}

class Giangday : public Monhoc{
     private:
          string maGV, maLop;
          int soTC;
          static int soTietdagiangday;
     public:
          Giangday(){
               maGV = maLop = "";
               soTC = 0;
          }

          ~Giangday(){}
          void Nhap();
          void Xuat();
          int sotietconlai();        
          int getSOTC();
          string getMAGV();
};

int Giangday::soTietdagiangday = 10;

void Giangday::Nhap(){
     cout << "--Ma Giang vien: ";
     cin >> this->maGV;
     cout << "--Ma lop: ";
     cin >> this->maLop;
     cout << "--Ma mon hoc: ";
     cin >> this->maMH;
     cout << "--So tin chi: ";
     cin >> this->soTC;
}

void Giangday::Xuat(){
     cout << "Ma GV: " << this->maGV << "   Ma lop: " << this->maLop << "   Ma mon hoc: " << this->maMH << "   So tin chi: " << this->soTC
          << endl;
}
int Giangday::sotietconlai(){ return this->soTC * 15 - soTietdagiangday; }
int Giangday::getSOTC(){ return this->soTC; }
string Giangday::getMAGV(){ return this->maGV; }


void MH3TC(Giangday *a, int n){
     int cnt = 0;
     cout << "Nhung mon hoc co 3 tin chi: " << endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).getSOTC() == 3){
               cnt++;
               (*(a + i)).Xuat();
          }
     }

     if(cnt == 0) cout << "Khong co MH nao co 3 TC trong danh sach" << endl;
}

void MaGVcosotietMin(Giangday *a, int n){
     int x = 0;
     int min = (*(a + 0)).sotietconlai();
     for (int i = 1; i < n; i++){
          if((*(a + i)).sotietconlai() < min) x = i;
     }

     cout << "Ma giang vien co so tiet con lai phai giang day it nhat: ";
     for (int i = 0; i < n; i++){
          if((*(a + i)).sotietconlai() == (*(a + x)).sotietconlai()){
               cout << (*(a + i)).getMAGV() << " ";
          }
     }
     cout << endl;
}

int main(){
     Monhoc mh;
     cout << "Nhap thong tin cho mot mon hoc: " << endl;
     mh.Nhap();
     cout << "Mon hoc: "; mh.Xuat();

     int n;
     cout << "\nNhap so luong mon hoc giang day: ";
     cin >> n;

     Giangday *a = new Giangday[n];
     cout << "Nhap danh sach mon hoc giang day: " << endl;
     for (int i = 0; i < n; i++) (*(a + i)).Nhap();

     cout << "Danh sach " << n << " mon hoc giang day: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Xuat();
     }

     MH3TC(a, n);
     MaGVcosotietMin(a, n);
     delete[] a;
     return 0;
}