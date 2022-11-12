#include <bits/stdc++.h>
using namespace std;

class Media{
     private:
          string name;
          float price;
     public:
          Media(){
               name = "";
               price = 0;
          }
          ~Media(){}
          void Nhap(){
               cout << "--Name(Ten goi): ";
               fflush(stdin);
               getline(cin, this->name);
               cout << "--Price(Gia ban): ";
               cin >> this->price;
          }

          void Xuat(){
               cout << "Name: " << this->name << "   Price: " << this->price;
          }

          string getName(){ return this->name; }
};

class Video : public Media{
     private:
          int timeRun;
     public:
          Video(){
               timeRun = 0;
          }
          ~Video(){}
          void Nhap(){
               Media::Nhap();
               cout << "--Thoi gian chay: ";
               cin >> this->timeRun;
          }

          void Xuat(){
               Media::Xuat();
               cout << "   Thoi gian chay: " << this->timeRun << endl;
          }
          int getTimerun(){ return this->timeRun; }
};

void Python(Video *a, int n){
     int cnt = 0;
     cout << "Video co ten Huong dan lap trinh Python co tren 10 don vi trong danh sach: " << endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).getName() == "Huong dan lap trinh Python" && (*(a + i)).getTimerun() > 10){
               cnt++;
               (*(a + i)).Xuat();
          }
     }

     if(cnt == 0) cout << "Khong co Huong dan lap trinh Python co tren 10 don vi trong danh sach" << endl;
}

int main(){

     Media m;
     cout << "Nhap thong tin phuong tien truyen thong media: " << endl;
     m.Nhap();
     cout << "Thong tin media: " << endl;
     m.Xuat();

     int n;
     cout << "\nNhap so luong video: ";
     cin >> n;

     Video *a = new Video[n];

     cout << "Nhap thong tin danh sach video: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Nhap();
     }

     cout << "Danh sach " << n << " video: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Xuat();
     }

     Python(a, n);

     delete[] a;
     return 0;
}
