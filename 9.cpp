#include <bits/stdc++.h>
using namespace std;

typedef class DichVu{
     private:
          string idDV, nameDV;
          double price;
     public:
          DichVu(){
               idDV = nameDV = "";
               price = 0;
          }
          ~DichVu(){}
          friend istream& operator>> (istream&, DichVu&);
          friend ostream& operator<< (ostream&, DichVu);
          double getPrice();
} DV;

istream& operator>> (istream& in, DichVu& another){
     cout << "--ID(Ma dich vu): ";
     in >> another.idDV;
     cout << "--Name(Ten dich vu): ";
     fflush(stdin);
     getline(in, another.nameDV);
     cout << "--Price(Gia cuoc): ";
     in >> another.price;

     return in;
}

ostream& operator<< (ostream& out, DichVu another){
     cout << "--ID: " << another.idDV << "   Name: " << another.nameDV << "   Price(Gia cuoc): " 
          << fixed << setprecision(2) <<  another.price << endl;

     return out;
}

double DV::getPrice(){ return this->price; }

class Nguoi{
     private:
          string name, address, sdt;
     public:
          Nguoi(){ name = address = sdt = ""; }
          ~Nguoi(){}
          void Input();
          void Output();
}; 

void Nguoi::Input(){
     cout << "--Name(Ho ten): ";
     fflush(stdin);
     getline(cin, this->name);
     cout << "--Address(Dia chi): ";
     getline(cin, this->address);
     cout << "--Phone Number(SDT): ";
     cin >> this->sdt;
}

void Nguoi::Output(){
     cout << "Ho ten: " << this->name << "   Dia chi: " << this->address << "   SDT: " << this->sdt;
}
 
typedef class KhachHang : public Nguoi{
     private:
          int sldv;
          DV dv[100];
     public:
          KhachHang(){ sldv = 1; }
          ~KhachHang(){}
          void Input();
          void Output();
          double TongCuoc();

} KH;

void KH::Input(){
     Nguoi::Input();
     cout << "--SL dich vu: ";
     cin >> this->sldv;
     cout <<"--Nhap thong tin dich vu cua khach hang: " << endl;
     for (int i = 0; i < this->sldv; i++){
          cin >> this->dv[i];
     }
     
}

void KH::Output(){
     Nguoi::Output();
     cout << "   SL dich vu: " << this->sldv << endl;
     cout << "Thong tin dich vu cua khach hang: " << endl;
     for(int i = 0; i < this->sldv; i++){
          cout << this->dv[i];
     }
}

double KH::TongCuoc(){
     double sum;
     for(int i = 0; i < this->sldv; i++){
          sum += this->dv[i].getPrice();
     }
}

int main(){
     Nguoi ng;
     cout << "Nhap thong tin nguoi: " << endl;
     ng.Input();
     cout << "Thong tin nguoi: " << endl;
     ng.Output();

     KH kh;
     cout << "Nhap thong tin khach hang: " << endl;
     kh.Input();
     cout << "Thong tin khach hang: " << endl;
     kh.Output();

     cout << "Tong gia cuoc khach hang: " << kh.TongCuoc() << endl;
     return 0;
}




