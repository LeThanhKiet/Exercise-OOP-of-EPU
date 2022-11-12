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
          bool operator < (Oto);
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

bool Oto::operator<(Oto another) { return this->speedBase() < another.speedBase(); }

void sortbySpeed(Oto *a, int n){
     for (int i = 0; i < n - 1; i++){
          int index = i;
          for (int j = i + 1; j < n; j++){
               if(*(a + index) < *(a + j)) index = j;
          }
          swap(*(a + i), *(a + index));
     }
     
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

     cout << "Sap xep " << n << " o to theo thu tu giam dan cua van toc co so: " << endl;
     sortbySpeed(a, n);
     for (int i = 0; i < n; i++){
          cout << (*(a + i));
     }

     delete[] a;
     return 0;
}