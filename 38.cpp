#include <bits/stdc++.h>
using namespace std;

typedef class PhuongTienGiaoThong{
     protected:
          string brand, name;
          int year;
          float maxspeed;
     public:
          PhuongTienGiaoThong(){
               brand = name = "";
               year = 2022;
               maxspeed = 0;
          }
          ~PhuongTienGiaoThong(){}
          void Input();
          void Output();

          string getBrand();
} PT;

void PT::Input(){
     cout << "--Brand (Hang san xuat): ";
     cin >> this->brand;
     cout << "--Name (Ten phuong tien): ";
     cin.ignore();
     getline(cin, this->name);
     do
     {
          cout << "--Nam san xuat: ";
          cin >> this->year;
     } while (this->year < 1990 || this->year > 2022);

     cout << "--Max speed (VTTD): ";
     cin >> this->maxspeed;
}

void PT::Output(){
     cout << "Hang: " << this->brand << "   Ten: " << this->name << "   NamSX: " << this->year
          << "   VTTD: " << fixed << setprecision(1) << this->maxspeed;
}

string PT::getBrand(){ return this->brand; }

class Oto : public PT{
     private:
          int sobanh;
          string kieudc;
     public:
          Oto(){
               sobanh = 0;
               kieudc = "";
          }
          ~Oto(){}
          friend istream& operator >> (istream&, Oto&);
          friend ostream& operator << (ostream&, Oto);
          float speedBase();
};

istream& operator >> (istream& in, Oto& another){
     another.Input();
     cout << "--So banh: ";
     in >> another.sobanh;
     cout << "--Kieu dong co: ";
     in.ignore();
     getline(in, another.kieudc);

     return in;
}

ostream& operator <<(ostream& out, Oto another){
     another.Output();
     out << "   So banh: " << another.sobanh << "   Kieu dong co: " << another.kieudc
         << "   Van toc co co: " << fixed << setprecision(1) << another.speedBase() << endl;
     return out;
}

float Oto::speedBase() { return this->maxspeed / this->sobanh; }

void Honda(Oto *a, int n){
     int cnt = 0;
     cout << "Danh sach o to cua hang Honda: " << endl;
     for(int i = 0; i < n; i++){
          if((*(a + i)).getBrand() == "Honda"){
               cout << *(a + i);
               cnt++;
          }
     }

     if(cnt == 0) cout << "Khong co o to nao cua hang Honda trong danh sach" << endl;
}
     
int main(){
     PT pt;
     cout << "Nhap thong tin cua ptgt: " << endl;
     pt.Input();
     cout << "Phuong tien:   ";
     pt.Output();

     int n;
     cout << "\nNhap so luong o to: ";
     cin >> n;

     Oto *a = new Oto[n];
     cout << "Nhap thong tin cua " << n << " o to: " << endl;
     for (int i = 0; i < n; i++){
          cout << "Nhap o to thu " << i + 1 << endl;
          cin >> *(a + i);
     }

     cout << "Danh sach " << n << " o to: " << endl;
     for (int i = 0; i < n; i++){
          cout << *(a + i);
     }

     Honda(a, n);

     delete[] a;
     return 0;
}