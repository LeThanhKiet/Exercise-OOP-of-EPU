#include <bits/stdc++.h>
using namespace std;

class Lophoc{
     protected:
          string maLop, tenLop;
     public:
          Lophoc(){
               maLop = tenLop = "";
          }
          ~Lophoc(){}
          void Nhap();
          void Xuat();
};

void Lophoc::Nhap(){
     cout << "--Ma Lop: ";
     cin >> this->maLop;
     cout << "--Ten Lop: ";
     cin.ignore();
     getline(cin, this->tenLop);
}

void Lophoc::Xuat(){
     cout << "Ma Lop: " << this->maLop << "   Ten MH: " << this->tenLop << endl;
}

class Giangday : public Lophoc{
     private:
          string maGV;
          string maMH;
          int soTC;
          static int soTietdagiangday;
     public:
          Giangday(){
               maGV = maMH = "";
               soTC = 0;
          }

          ~Giangday(){}
          void Nhap();
          void Xuat();
          int sotietconlai(){
               return this->soTC * 15 - soTietdagiangday;
          }

          int getSOTC(){
               return this->soTC;
          }

          string getMAGV(){
               return this->maGV;
          }
};

int Giangday::soTietdagiangday = 10;

void Giangday::Nhap(){
     cout << "--Ma Giang vien: ";
     cin >> this->maGV;
     cout << "--Ma mon hoc: ";
     cin >> this->maMH;
     cout << "--Ma lop hoc: ";
     cin >> this->maLop;
     cout << "--So tin chi: ";
     cin >> this->soTC;
}

void Giangday::Xuat(){
     cout << "Ma GV: " << this->maGV << "   Ma mon hoc: " << this->maMH << "   Ma lop: " << this->maLop << "   So tin chi: " << this->soTC
          << endl;
}

void MH3TC(Giangday *a, int n){
     int cnt = 0;
     cout << "Nhung lop hoc co 3 tin chi: " << endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).getSOTC() == 3){
               cnt++;
               (*(a + i)).Xuat();
          }
     }

     if(cnt == 0) cout << "Khong co lop nao co 3 TC trong danh sach" << endl;
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
     Lophoc lh;
     cout << "Nhap thong tin cho mot lop hoc: " << endl;
     lh.Nhap();
     cout << "Lop hoc: " << endl;
     lh.Xuat();

     int n;
     cout << "Nhap so luong giang day: ";
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