#include <bits/stdc++.h>
using namespace std;

class Date{
     private:
          int ngay, thang, nam;
     public:
          Date(){
               ngay = thang = 1;
               nam = 2022;
          }
          ~Date(){}
          void Nhap(){
               do{
                    cout << "--Day: ";
                    cin >> this->ngay;
               } while (this->ngay < 1 || this->ngay > 31);

               do{
                    cout << "--Month: ";
                    cin >> this->thang;
               } while (this->thang < 1 || this->thang > 12);

               do{
                    cout << "--Year: ";
                    cin >> this->nam;
               } while (this->nam < 1990 || this->nam > 2022);
          }

          void Xuat(){
               cout << "Ngay/Thang/Nam: " << this->ngay << "/" << this->thang << "/" << this->nam;
          }
};

class Maytinh : public Date{
     private:
          string ma, ten;
          float gianiemyet;
          static float km;
     public:  
          Maytinh(){
               ma = ten = "";
               gianiemyet = 0;
          }
          ~Maytinh(){}
          void Nhap(){
               cout << "--Ma may: ";
               cin >> this->ma;
               cout << "--Ten may: ";
               cin.ignore();
               getline(cin, this->ten);
               Date::Nhap();
               cout << "--Gia ban niem yet: ";
               cin >> this->gianiemyet;
          }

          void Xuat(){
               cout << "Ma may: " << this->ma << "   Ten may: " << this->ten << "   ";
               Date::Xuat();
               cout << "   Gia ban niem yet: " << fixed << setprecision(2) << this->gianiemyet 
                    << "   Gia ban thuc: " << fixed << setprecision(2) << this->Giabanthuc() << endl;
          }

          float Giabanthuc(){ return this->gianiemyet - this->gianiemyet * km; }

          string getTen(){ return this->ten; }

};

float Maytinh::km = 0.5;

void Asus(Maytinh *a, int n){
     int cnt = 0;
     cout << "May tinh cua hang Asus: " << endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).getTen() == "ASUS"){
               cnt++;
               (*(a + i)).Xuat();
          }
     }

     if(cnt == 0) cout << "Khong co may tinh nao cua ASUS trong danh sach" << endl;
}

void GiabanthucMin(Maytinh *a, int n){
     int x = 0;
     float min = (*(a + 0)).Giabanthuc();
     for (int i = 1; i < n; i++){
          if((*(a + i)).Giabanthuc() < min) x = i;
     }

     cout << "Thong tin nhung may tinh co gia ban thuc te nho nhat: " << endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).Giabanthuc() == (*(a + x)).Giabanthuc()) (*(a + i)).Xuat();
     }
}

int main(){
     Date d;
     cout << "Nhap thong tin ngay thang: " << endl;
     d.Nhap();
     d.Xuat();

     int n;
     cout << "\nNhap so luong may tinh: ";
     cin >> n;

     Maytinh *a = new Maytinh[n];
     cout << "Nhap thong tin " << n << " may tinh: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Nhap();
     }

     cout << "Thong tin " << n << " may tinh: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Xuat();
     }
     Asus(a, n);
     GiabanthucMin(a, n);
     return 0;
}