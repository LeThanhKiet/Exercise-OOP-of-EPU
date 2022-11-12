#include <bits/stdc++.h>
using namespace std;
class Sach{
     protected:
		string id, name;
     public:
          Sach(){ id = name = ""; }
          ~Sach(){}
          void Input();
          void Output();
};

void Sach::Input(){
     cout << "--ID(Ma sach): ";
     cin >> this->id;
     cout << "--Name(Ten sach): ";
     cin.ignore();
     getline(cin, this->name);
}

void Sach::Output(){
     cout << "ID(Ma sach): " << this->id << "   Name(Ten sach): " << this->name;
}

class Muontra : public Sach{
     private:
          string idmember;
          int sl;
          static int phicuoc;
     public:
          Muontra(){
               idmember = "";
               sl = 0;
          }
          ~Muontra(){}
          void Input();
          void Output();
          int Money();
          int getSL();
          string getIDmember();
};

int Muontra::phicuoc = 50;

void Muontra::Input(){
     cout << "--ID Member: ";
     cin >> this->idmember;
     cout << "--ID Book: ";
     cin >> this->id;
     cout << "--So luong: ";
     cin >> this->sl;
}

void Muontra::Output(){
     cout << "ID member: " << this->idmember << "   ID book: " << this->id << "   So luong: " << this->sl << endl;
}

int Muontra::Money(){ return this->sl * phicuoc; }
int Muontra::getSL(){ return this->sl; }
string Muontra::getIDmember(){return this->idmember; }

void soluongLonhon10(Muontra *a, int n){
     int cnt = 0;
     cout << "Cac doc gia muon > 10 cuon sach: " << endl;
     for (int i = 0; i < n; i++){
          if((*(a + i)).getSL() > 10 ){
               cnt++;
               (*(a + i)).Output();
          }
     }
     if(cnt == 0) cout << "Khong co doc gia nao muon > 10 cuon sach" << endl;
}

void phicuocMax(Muontra *a, int n){
     int x = 0;
     int max = (*(a + 0)).Money();
     for (int i = 1; i < n; i++){
          if((*(a + 0)).Money() > max) x = i;
     }

     cout << "Ma cac doc gia so so tien cuoc nhieu nhat: ";
     for (int i = 0; i < n; i++){
          if((*(a + i)).Money() == (*(a + x)).Money()){
               cout << (*(a + i)).getIDmember() << " ";
          }
     }
     cout << endl;
}

int main(){
     Sach s;
     cout << "Nhap thong tin sach: " << endl;
     s.Input();
     s.Output();

     int n;
     cout << "\nNhap so luong: ";
     cin >> n;

     Muontra *a = new Muontra[n];
     cout << "Nhap thong tin danh sach muon tra: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Input();
     }

     cout << "Danh sach muon tra: " << endl;
     for (int i = 0; i < n; i++){
          (*(a + i)).Output();
     }

     soluongLonhon10(a, n);
     phicuocMax(a, n);

     delete[] a;
     return 0;
}


