#include <bits/stdc++.h>
class Date{
     protected:
          int day, month, year;
     public:
          Date(){
               day = month = 1;
               year = 1900;
          }
          ~Date(){}
          void Input();
          void Output();
          int getYear();
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

int Date::getYear(){ return this->year; }

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
          std::string getIDmember();
};

int Muontra::phicuoc = 50;

void Muontra::Input(){
     std::cout << "ID member: ";
     std::cin >> this->idmember;
     std::cout << "ID book: ";
     std::cin >> this->idbook;
     Date::Input();
     std::cout << "So luong: ";
     std::cin >> this->sl;
}

void Muontra::Output(){
     std::cout << "ID member: " << this->idmember << " ID book: " << this->idbook << " ";
     Date::Output();
     std::cout << " So luong: " << this->sl << std::endl;
}

int Muontra::Money(){ return this->sl * phicuoc; }
std::string Muontra::getIDmember() { return this->idmember; }

void muonTruoc(Muontra *a, int n){
     int cnt = 0;
     std::cout << "Cac doc gia muon sach truoc ngay 1/1/2020: " << std::endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).getYear() < 2020){
               cnt++;
               (*(a + i)).Output();
          }
     }
     if(cnt == 0) std::cout << "Khong co doc gia nao muon truoc ngay 1/1/2020" << std::endl;
}

void maxPhicuoc(Muontra *a, int n){
     int x = 0;
     int max = (*(a + 0)).Money();
     for (int i = 1; i < n; i++){
          if((*(a + i)).Money() > max) x = i;
     }

     std::cout << "Ma cac doc gia co so tien cuoc nhieu nhat: ";
     for (int i = 0; i < n; i++){
          if((*(a + i)).Money() == (*(a + x)).Money()) std::cout << (*(a + i)).getIDmember() << " ";
     }
     std::cout << std::endl;
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

     muonTruoc(a, n);
     maxPhicuoc(a, n);

     delete[] a;
     return 0;
}