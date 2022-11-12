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

class SVSDH : public SV{
     private:
          float hocphi;
     public:
          SVSDH(){ hocphi = 0; }
          ~SVSDH(){}
          void Nhap();
          void Xuat();

          float getHocphi();
};
void SVSDH::Nhap(){
     SV::Nhap();
     cout << "--Hoc phi: ";
     cin >> this->hocphi;
}

void SVSDH::Xuat(){
     SV::Xuat();
     cout << "   Hoc phi: " << this->hocphi << endl;
}

float SVSDH::getHocphi(){ return this->hocphi; }

void Hocphi(SVSDH *a, int n){
     int cnt = 0;
     cout << "Nhung sinh vien co hoc phi > 9000: " << endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).getHocphi() > 9000){
               cnt++;
               (*(a + i)).Xuat();
          }
     }
     if(cnt == 0) cout << "Khong co sinh vien nao co hoc phi > 9000" << endl;
}

int main(){
     SV s;
     cout << "Nhap thong tin sinh vien: " << endl;
     s.Nhap();
     cout << "Thong tin sinh vien: " << endl;
     s.Xuat();

     int n;
     cout << "\nNhap so luong SCSDH: ";
     cin >> n;

     SVSDH *a = new SVSDH[n];
     cout << "Nhap thong tin cho danh sach SVSDH: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Nhap();
     }

     cout << "Danh sach " << n << " SVSDH: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Xuat();
     }

     Hocphi(a, n);

     delete[] a;
     return 0;
}