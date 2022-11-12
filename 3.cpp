#include <bits/stdc++.h>
using namespace std;

class Nguoi{
     private:
          string id, name;
     public:
          Nguoi(){ id = name = ""; }
          ~Nguoi(){}
          void Input(){
               cout << "--ID(Ma dinh danh): ";
               cin >> this->id;
               cout << "--Name(Ho ten): ";
               cin.ignore();
               getline(cin, this->name);
          }
          void Output(){
               cout << "ID(Ma dinh danh): " << this->id << "   Name(Ho ten): " << this->name;
          }

          string getName(){
               return this->name;
          }
};

class Nhanvien : public Nguoi{
     private:
          int year;
          float heso;
          static int tienphucap;

     public:
          Nhanvien(){
               year = 2022;
               heso = 0;
          }

          ~Nhanvien(){}
          void Input(){
               Nguoi::Input();
               do
               {
                    cout << "--Year(Nam sinh): ";
                    cin >> this->year;
               } while (this->year < 1900 || this->year > 2022);

               cout << "--He so luong: ";
               cin >> this->heso;
          }

          void Output(){
               Nguoi::Output();
               cout << "   Nam sinh: " << this->year << "   He so luong: " << this->heso
                    << "   Salary(Luong): " << this->salary() << endl;
          }

          float salary(){
               return this->heso * 1550 + tienphucap;
          }
};

int Nhanvien::tienphucap = 2000;

void Maxluong(Nhanvien *a, int n){
     int x = 0;
     float max = (*(a + 0)).salary();
     for (int i = 1; i < n; i++){
          if((*(a + i)).salary() > max) x = i;
     }

     cout << "Ho ten nhan vien co luong cao nhat: " << endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).salary() == (*(a + x)).salary())
               cout << (*(a + i)).getName() << endl;
     }
}

int main(){
     Nguoi ng;
     cout << "Nhap thong tin nguoi: " << endl;
     ng.Input();
     cout << "Thong tin nguoi: " << endl;
     ng.Output();

     int n;
     cout << "\nNhap so luong nhan vien: ";
     cin >> n;

     Nhanvien *a = new Nhanvien[n];
     cout << "Nhap danh sach " << n << " nhan vien: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Input();
     }

     cout << "Danh sach " << n << " nhan vien: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Output();
     }
     Maxluong(a, n);

     delete[] a;
     return 0;
}