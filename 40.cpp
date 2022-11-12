#include <bits/stdc++.h>
using namespace std;

class SV{
     private:
		string idSV, nameSV;
     public:
          SV(){ idSV = nameSV = ""; }
          ~SV(){}
          void Nhap();
          void Xuat();
};

void SV::Nhap(){
     cout << "--ID(Ma sinh vien): ";
     cin >> this->idSV;
     cout << "--Name(Ho ten SV): ";
     cin.ignore();
     getline(cin, this->nameSV);
}

void SV::Xuat(){
     cout << "ID: " << this->idSV << "   Name: " << this->nameSV;
}

class SVTMDT : public SV{
     private:
          float score;
     public:
          SVTMDT(){ score = 0; }
          ~SVTMDT(){}
          void Nhap();
          void Xuat();
          bool operator< (SVTMDT);
};

void SVTMDT::Nhap(){
     SV::Nhap();
     cout << "--Score(Diem mon kinh doanh online): ";
     cin >> this->score;
}

void SVTMDT::Xuat(){
     SV::Xuat();
     cout << "   Diem mon Kinh doanh online: " << this->score << endl;
}

void Nhap(SVTMDT *a, int n){
     cout << "Nhap danh sach " << n << " sinh vien TMDT: " << endl;
     for(int i = 0; i < n; i++){
          cout << "Nhap sinh vien thu " << i + 1 << " :" << endl;
          (*(a + i)).Nhap();
     }
}

void Xuat(SVTMDT *a, int n){
     cout << "Danh sach sinh vien TMDT: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Xuat();
     }
     
}

bool SVTMDT::operator<(SVTMDT another){ return this->score < another.score; }

void sortbyScore(SVTMDT *a, int n){
          for (int i = 0; i < n - 1; i++){
          int index = i;
          for (int j = i + 1; j < n; j++){
               if(*(a + index) < *(a + j)) index = j;
          }
          swap(*(a + i), *(a + index));
     }
}

int main(){
     SV s;
     cout << "Nhap thong tin sinh vien: " << endl;
     s.Nhap();
     cout << "Thong tin sinh vien: " << endl;
     s.Xuat();

     int n;
     cout << "\nNhap so luong sinh vien TMDT: ";
     cin >> n;

     SVTMDT *a = new SVTMDT[n];
	Nhap(a, n);
	Xuat(a, n);
     
     cout << "Sap xep " << n << " sinh vien TMDT theo diem giam dan: " << endl;
     sortbyScore(a, n);
     Xuat(a, n);
     delete[] a;
     return 0;
}