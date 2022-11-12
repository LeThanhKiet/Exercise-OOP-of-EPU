#include <bits/stdc++.h>
using namespace std;

class Media{
     private:
          string name;
          float price;
     public:
          Media(){ name = "";  price = 0; }
          ~Media(){}
          void Input(){
               cout << "--Name(Ten goi): ";
               fflush(stdin);
               getline(cin, this->name);
               cout << "--Price(Gia ban): ";
               cin >> this->price;
          }

          void Output(){
               cout << "Name: " << this->name << "   Price: " << this->price; 
          }
          string getName(){ return this->name; }
};

class Book : public Media{
     private:
          int sotrang;
          string author;
     public:
          Book(){
               sotrang = 0;
               author = "";
          }
          ~Book(){}
          friend void operator>> (istream& in, Book& b){
               b.Input();
               cout << "--So trang: ";
               in >> b.sotrang;
               cout << "--Author(Tac gia): ";
               fflush(stdin);
               getline(in, b.author);
          }

          friend void operator<< (ostream& out, Book b){
               b.Output();
               out << "   So trang: " << b.sotrang << "   Tacgia: " << b.author << endl;
          }

          string getAuthor(){ return this->author; }
};

void Input(Book *a, int n){
     cout << "Nhap danh sach " << n << " sach: " << endl;
     for(int i = 0 ; i < n; i++){
          cout << "Nhap sach thu " << i + 1 << " :" << endl;
          cin >> *(a + i);
     }
}

void Output(Book *a, int n){
     cout << "Danh sach " << n << " sach: " << endl;
     for(int i = 0; i < n; i++) cout << *(a + i);
}

void BookofAuthor(Book *a, int n){
     int cnt = 0;
     cout << "Sach Lap trinh C++ cua Nguyen Thanh Thuy: " << endl;
     for(int i = 0 ; i < n; i++){
          if((*(a + i)).getName() == "Lap trinh C++" && (*(a + i)).getAuthor() == "Nguyen Thanh Thuy"){
               cnt++;
               cout << *(a + i);
          }
     }
     if(cnt == 0) cout << "Khong co sach lap trinh C++ cua Nguyen Thanh Thuy trong danh sach" << endl;
}

int main(){

     Media m;
     cout << "Nhap thong tin phuong tien truyen thong media: " << endl;
     m.Input();
     cout << "Thong tin media: " << endl;
     m.Output();

     int n;
     cout << "\nNhap so luong book: ";
     cin >> n;

     Book *a = new Book[n];
     Input(a, n);
     Output(a, n);
     BookofAuthor(a, n);

     delete[] a;
     return 0;
}
