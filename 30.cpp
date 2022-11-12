#include <bits/stdc++.h>
using namespace std;

class MonHoc{
     private:
          string maMH, tenMH;
          double dtb;
          int soTC;
     public:
          MonHoc(){
               maMH = tenMH = "";
               dtb = soTC = 0;
          }
          ~MonHoc(){}
          friend istream& operator>> (istream&, MonHoc&);
          friend ostream& operator<< (ostream&, MonHoc);
          int getSOTC();
          double getDTB();
};

istream& operator >> (istream& in, MonHoc& another){
     cout << "--Ma mon hoc: ";
     in >> another.maMH;
     cout << "--Ten mon hoc: ";
     fflush(stdin);
     getline(in, another.tenMH);
     cout << "--Diem trung binh: ";
     in >> another.dtb;
     cout << "--So tin chi: ";
     in >> another.soTC;

     return in;
}

ostream& operator << (ostream& out, MonHoc another){
     out << "MaMH: " << another.maMH << "    TenMH: " << another.tenMH 
         << "   Diem TB: " << fixed << setprecision(2) << another.dtb
         << "   So tin chi: " << another.soTC << endl;
     
     return out;
}

int MonHoc::getSOTC(){ return this->soTC; }
double MonHoc::getDTB(){ return this->dtb; }

class SinhVien{
     private:
          string maSV, tenSV;
          int soMH;
          MonHoc mh[100];
     public:
          SinhVien(){
               maSV = tenSV = "";
               soMH = 1;
          }
          ~SinhVien(){}
          friend istream& operator>> (istream&, SinhVien&);
          friend ostream& operator<< (ostream&, SinhVien);     
          double DTK();
};   

istream& operator>> (istream& in, SinhVien& another){
     cout << "--Ma sinh vien: ";
     in >> another.maSV;
     cout << "--Ten sinh vien: ";
     in.ignore();
     getline(in, another.tenSV);
     cout << "--So mon hoc: ";
     in >> another.soMH;
     cout << "--Nhap thong tin mon hoc cua sinh vien: " << endl;
     for(int i = 0; i < another.soMH; i++){
          in >> *(another.mh + i);
     }

     return in;
}

ostream& operator << (ostream& out, SinhVien another){
     out << "MaSV: " << another.maSV << "   TenSV: " << another.tenSV << "   SoMH: " << another.soMH << endl;
     out << "Thong tin mon hoc sinh vien: " << endl;
     for(int i = 0 ; i < another.soMH; i++){
          out << *(another.mh + i);
     }
     out << "===> Diem trung binh sinh vien: " << fixed << setprecision(2) << another.DTK() << endl;

     return out;
}

void Input(SinhVien *a, int n){
     cout << "Nhap danh sach " << n << " sinh vien: " << endl;
     for(int i = 0; i < n; i++){
          cout << "Nhap sinh vien thu " << i + 1 << " :" << endl;
          cin >> *(a + i);
     } 
}

void Output(SinhVien *a, int n){
     cout << "Danh sach " << n << " sinh vien: " << endl;
     for(int i = 0; i < n; i++){
          cout << "----------------------------------------------------" << endl;
          cout << *(a + i);
     }
     cout << "----------------------------------------------------" << endl;
}

double SinhVien::DTK(){
     double tu, mau;
     for(int i = 0 ; i < this->soMH; i++){
          tu += this->mh[i].getSOTC() * this->mh[i].getDTB();
          mau += this->mh[i].getSOTC();
     }

     return tu / mau;
}

int HocLai(SinhVien *a, int n){
     int cnt = 0;
     for (int i = 0; i < n; i++){
          if((*(a + i)).DTK() < 4) cnt++;
     }

     return cnt;   
}

int main(){
     MonHoc mh;
     cout << "Nhap thong tin mon hoc: " << endl;
     cin >> mh;
     cout << "Thong tin mon hoc: " << mh << endl;

     int n;
     cout << "Nhap so luong sinh vien: ";
     cin >> n;

     SinhVien *a = new SinhVien[n];
     Input(a, n);
     Output(a, n);
     
     if(HocLai) cout << "Co " << HocLai << " sinh vien hoc lai" << endl;
     else cout << "Khong co sinh vien hoc lai" << endl;

     delete[] a;
     return 0;
}