#include <bits/stdc++.h>
using namespace std;

class SV{
    private:
        string maSV, tenSV;
    public:
        SV(){ maSV = tenSV = ""; }
        ~SV(){}

        void Input();
        void Output();
};

void SV::Input(){
    cout << "--Ma Sinh vien: ";
    cin >> this->maSV;
    cout << "--Ten sinh vien: ";
    cin.ignore();
    getline(cin, this->tenSV);
}

void SV::Output(){
    cout << "Ma Sinh vien: " << this->maSV << "   Ten sinh vien: " << this->tenSV;
}

class SVAI : public SV{
    private:
        float dtb;
    public:
        SVAI(){ dtb = 0; }
        ~SVAI(){}
        friend istream& operator>> (istream&, SVAI&);
        friend ostream& operator<< (ostream&, SVAI);
        bool operator<(SVAI);
};

istream& operator>> (istream& in, SVAI& another){
    another.Input();
    cout << "--Diem trung binh: ";
    in >> another.dtb;

    return in;
}

ostream& operator<< (ostream& out, SVAI another){
    another.Output();
    out << "   DTB: " << another.dtb << endl;

    return out;
}

void Input(SVAI *a, int n){
    cout << "Nhap danh sach sinh vien AI: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Nhap sinh vien AI thu " << i + 1 << " :" << endl;
        cin >> *(a + i);
    }
}

void Output(SVAI *a, int n){
    cout << "Danh sach " << n << " sinh vien AI: " << endl;
    for(int i = 0; i < n; i++){
        cout << *(a + i);
    }
}
bool SVAI::operator<(SVAI another){
    return this->dtb < another.dtb;
}

void sortbyDTB(SVAI *a, int n){
    for(int i = 0; i < n - 1; i++){
        int index = i;
        for(int j = i + 1; j < n; j++){
            if(*(a + index) < *(a + j)) index = j;
        }
        swap(*(a + i), *(a + index));
    }
}

int main(){
    SV sv;
    cout << "Nhap thong tin cua mot sinh vien: " << endl;
    sv.Input();
    cout << "Thong tin sinh vien: " << endl;
    sv.Output();

    int n;
    cout << "\nNhap so luong sinh vien AI: ";
    cin >> n;

    SVAI *a = new SVAI[n];
    Input(a, n);
    Output(a, n);

    cout << "Danh sach " << n << " sinh vien sap xep giam dan theo dtb: " << endl;
    sortbyDTB(a, n);
    Output(a, n);

    delete[] a;
    return 0;
}