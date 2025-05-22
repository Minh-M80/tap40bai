#include<bits/stdc++.h>
using namespace std;

class NGUOI{
    private:
    string hoTen,GT;
    int namSinh;
    public:
    NGUOI();
    NGUOI(string,string,int);
    ~NGUOI();
    void nhap();
    void xuat();
    int tuoi(){
        return 2020-this->namSinh;
    }
};
class NHANVIEN:public NGUOI{
	private:
		float HSThamNien,mucLuong,tienAnCa;
	public:
		NHANVIEN();
		NHANVIEN(string,string,int,float,float,float);
		~NHANVIEN();
		void nhap();
		void xuat();
		bool nghiHuu(){
			return tuoi() >=60;
		}
		float luong(){
			if(nghiHuu()){
				return 0.75*mucLuong*HSThamNien;
			} else{
				return mucLuong*HSThamNien + tienAnCa;
			}
		}		
};


int main(){
	NGUOI a;
	
}