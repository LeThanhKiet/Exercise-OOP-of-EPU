#include <bits/stdc++.h>
class Date{
     private:
          int day, month, year;
     public:
          Date(){
               day = month = 1;
               year = 1900;
          }
          ~Date(){}
          void Input();
          void Output();

          int getYear(){
               return this->year;
          }
};

void Date::Input(){
     std::cout << "--Day: ";
     std::cin >> this->day;
     std::cout << "--Month: ";
     std::cin >> this->month;
     std::cout << "--Year: ";
     std::cin >> this->year;
}

void Date::Output(){
     std::cout << "Date: " << this->day << "/" << this->month << "/" << this->year;
}

class Muontra : public Date{
     private:
          std::string idmember, idbook;
          int sl;
          static int phicuoc;

     public:
          Muontra(){
               idmember = idbook = "";
               sl = 0;
          }
          ~Muontra(){}
          void Input();
          void Output();
          int Money();
          bool operator<(Muontra another);
};

int Muontra::phicuoc = 1000;

void Muontra::Input(){
     std::cout << "--ID member: ";
     std::cin >> this->idmember;
     std::cout << "--ID book: ";
     std::cin >> this->idbook;
     Date::Input();
     std::cout << "--So luong: ";
     std::cin >> this->sl;
}

void Muontra::Output(){
     std::cout << "ID member: " << this->idmember << " ID book: " << this->idbook << " ";
     Date::Output();
     std::cout << " So luong: " << this->sl << "   Tien cuoc: " << (*this).Money() << std::endl;
}

int Muontra::Money(){ return this->sl * phicuoc; }

bool Muontra::operator<(Muontra another){
     return (*this).Money() < another.Money();
}

void sortbyMoney(Muontra *a, int n){
     for (int i = 0; i < n - 1; i++){
          int index = i;
          for (int j = i + 1; j < n; j++){
               if(*(a + j) < *(a + index) == false) index = j;
          }
          Muontra temp = *(a + i);
          *(a + i) = *(a + index);
          *(a + index) = temp;
     }
}

int main(){
     Date d;
     std::cout << "Nhap ngay thang nam: " << std::endl;
     d.Input();
     d.Output();

     int n;
     std::cout << "\nNhap so luong muon tra: ";
     std::cin >> n;
     Muontra *a = new Muontra[n];

     std::cout << "Nhap danh sach muon tra: " << std::endl;
     for (int i = 0; i < n; i++){
          std::cout << "Nhap thong tin thu " << i + 1 << std::endl;
          (*(a + i)).Input();
     }

     std::cout << "Danh sach: " << std::endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Output();
     }

     std::cout << "Sap xep danh sach muon tra giam dan theo tien cuoc: " << std::endl;
     sortbyMoney(a, n);
     for (int i = 0; i < n; i++){
          (*(a + i)).Output();
     }
     delete[] a;
     return 0;
}