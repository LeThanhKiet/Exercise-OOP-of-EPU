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

class SVCNPM : public SV{
     private:
          float dtb;
     public:
          SVCNPM(){ dtb = 0; }
          ~SVCNPM(){}
          void Nhap();
          void Xuat();
          float getDTB();
};

void SVCNPM::Nhap(){
     SV::Nhap();
     cout << "--DTB: ";
     cin >> this->dtb;
}

void SVCNPM::Xuat(){
     SV::Xuat();
     cout << "   DTB: " << this->dtb << endl;
}

float SVCNPM::getDTB(){ return this->dtb; }

void Input(SVCNPM *a, int n){
	cout << "Nhap thong tin cho danh sach SVCNPM: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Nhap();
     }
}

void Output(SVCNPM *a, int n){
	cout << "Danh sach " << n << " SVCNPM: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Xuat();
     }
}

void DTB(SVCNPM *a, int n){
     int cnt = 0;
     cout << "Nhung sinh vien co DTB >= 8,5: " << endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).getDTB() >= 8.5){
               cnt++;
               (*(a + i)).Xuat();
          }
     }
     if(cnt == 0) cout << "Khong co sinh vien nao co diem Tb >= 8,5" << endl;
}

int main(){
     SV s;
     cout << "Nhap thong tin sinh vien: " << endl;
     s.Nhap();
     cout << "Thong tin sinh vien: " << endl;
     s.Xuat();

     int n;
     cout << "\nNhap so luong sinh vien CNPM: ";
     cin >> n;

     SVCNPM *a = new SVCNPM[n];
	Input(a, n);
	Output(a, n);
     DTB(a, n);

     delete[] a;
     return 0;
}