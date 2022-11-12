#include <bits/stdc++.h>
using namespace std;

class Lophoc{
     protected: 
          string maLop, tenLop;
     public:
          Lophoc(){ maLop = tenLop = ""; }
          ~Lophoc(){}
          friend istream& operator >> (istream&, Lophoc&);
          friend ostream& operator << (ostream&, Lophoc);
};

istream& operator >> (istream& in, Lophoc& another){
     cout << "--Ma lop: ";
     in >> another.maLop;
     cout << "--Ten lop: ";
     fflush(stdin);
     getline(in, another.tenLop);

     return in;
}

ostream& operator << (ostream& out, Lophoc another){
     cout << "Ma lop: " << another.maLop << "   Ten lop: " << another.tenLop << endl;

     return out; 
}

class Giangday : public Lophoc{
     private:
          string maGV, maMH;
          int soTC;
          static int sotietdaday;
     public:
          Giangday(){
               maGV = maMH = "";
               soTC = 0;
          }
          ~Giangday(){}
          friend istream& operator >> (istream&, Giangday&);
          friend ostream& operator << (ostream&, Giangday);
          float tietConlai();
          int getSOTC();
          string getMaGV();
};

istream& operator >> (istream& in, Giangday& another){
     cout << "--Ma giang vien: ";
     in >> another.maGV;
     cout << "--Ma mon hoc: ";
     in >> another.maMH;
     cout << "--Ma lop: ";
     in >> another.maLop;
     cout << "--So tin chi: ";
     in >> another.soTC;

     return in;
}

ostream& operator << (ostream& out, Giangday another){
     out << "MaGv: " << another.maGV << "   MaMH: " << another.maMH << "   MaLop: " << another.maLop
         << "   So tin chi: " << another.soTC << endl;

     return out;
}

int Giangday::sotietdaday = 10;
float Giangday::tietConlai(){ return this->soTC * 15 - sotietdaday; }
int Giangday::getSOTC(){ return this->soTC; }
string Giangday::getMaGV(){ return this->maGV; }

void LH3TC(Giangday *a, int n){
     int cnt = 0;
     cout << "Nhung lop hoc co 3 tin chi: " << endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).getSOTC() == 3){
               cnt++;
               cout << *(a + i);
          }
     }

     if(cnt == 0) cout << "Khong co MH nao co 3 TC trong danh sach" << endl;
}

void MaGVcosotietMin(Giangday *a, int n){
     int x = 0;
     int min = (*(a + 0)).tietConlai();
     for (int i = 1; i < n; i++){
          if((*(a + i)).tietConlai() < min) x = i;
     }

     cout << "Ma giang vien co so tiet con lai phai giang day it nhat: ";
     for (int i = 0; i < n; i++){
          if((*(a + i)).tietConlai() == (*(a + x)).tietConlai()){
               cout << (*(a + i)).getMaGV() << " ";
          }
     }
     cout << endl;
}


int main(){
     Lophoc l;
     cout << "Nhap thon tin lop hoc: " << endl;
     cin >> l;
     cout << "Lop hoc: " << l;

     int n;
     cout << "Nhap so luong giang day: ";
     cin >> n;

     Giangday *a = new Giangday[n];
     cout << "Nhap " << n << " giang day: " << endl;
     for (int i = 0; i < n; i++){
          cout << "Nhap thong tin thu " << i + 1 << " :" << endl;
          cin >> *(a + i);
     }

     cout << "Thong tin " << n << " doi tuong giang day: " << endl;
     for (int i = 0; i < n; i++){
          cout << *(a + i);
     }

     LH3TC(a, n);
     MaGVcosotietMin(a, n);
     delete[] a;
     return 0;
}