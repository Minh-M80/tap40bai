#include<bits/stdc++.h>
using namespace std;

class NGUOI{
	private:
	string ma,hoTen;
	public:
		NGUOI();
		NGUOI(string ma,string hoTen);
		~NGUOI();
		void nhap();
		void xuat();	
};
NGUOI::NGUOI(){
};
NGUOI::NGUOI(string ma,string hoTen){
	this->ma=ma;
	this->hoTen=hoTen;
};
NGUOI::~NGUOI(){
	ma="";
	hoTen="";
};
void NGUOI::nhap(){
	cout<<endl;
	cout<<"Nhap ma dinh danh:";
	getline(cin,this->ma);
	cout<<"Nhap ho ten:";
	getline(cin,this->hoTen);
}
void NGUOI::xuat(){
	cout << endl;
	cout << left << setw(15) << this->ma
	     << left << setw(25) << this->hoTen;
}

class NHANVIEN:public NGUOI{
	private:
		int nam;
		float heSo;
		static float phuCap;
	public:
		void nhap();
		void xuat();
		NHANVIEN();
		NHANVIEN(string ma,string hoTen,int nam,float heSo);
		~NHANVIEN();
		float setLuong() const{
			return (this->heSo*1550 + this->phuCap);
		};
		bool operator < (const NHANVIEN &other){
			return this->setLuong()<other.setLuong();
		};
};

NHANVIEN::NHANVIEN(){
};
NHANVIEN::~NHANVIEN(){
};
NHANVIEN::NHANVIEN(string ma,string hoTen,int nam,float heSo):NGUOI(ma,hoTen){
	this->nam=nam;
	this->heSo=heSo;
};

float NHANVIEN::phuCap=2000;
void NHANVIEN::nhap(){
	NGUOI::nhap();
	cout<<"Nhap nam sinh:";
	cin>>this->nam;
	cin.ignore();
	cout<<"Nhap he so luong:";
	cin>>this->heSo;
	cin.ignore();
}
void NHANVIEN::xuat(){
	NGUOI::xuat();
	cout << left << setw(15) << this->nam
	     
	     << left << setw(10) << this->setLuong();
}



int main(){
	NGUOI a;
	cout<<"Nhap thong tin mot nguoi:";
	a.nhap();
	cout<<"Hien thi thong tin nguoi vua nhap:";
	cout<<endl;
	cout<<"Ma dinh danh\t"<<"Ho ten";
	a.xuat();
	cout<<endl;
	int n;
	cout<<"Nhap so doi tuong nhan vien:";
	cin>>n;
	cin.ignore();
	NHANVIEN b[n];
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin nhan vien thu "<<i+1;
		b[i].nhap();
	}
	cout<<"Thong tin n nhan vien sau khi nhap:";
	cout<<endl;
	cout << left << setw(15) << "Ma dinh danh"
     << left << setw(25) << "Ho ten"
     << left << setw(15) << "Nam sinh"
     << left << setw(10) << "Luong";

		for(int i=0;i<n;i++){
		b[i].xuat();
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(b[i]<b[j]){
				NHANVIEN temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	cout<<endl;
	cout<<"Thong tin sau khi sap xep:\n";
	cout << left << setw(15) << "Ma dinh danh"
     << left << setw(25) << "Ho ten"
     << left << setw(15) << "Nam sinh"
     << left << setw(10) << "Luong";

		for(int i=0;i<n;i++){
		b[i].xuat();
	}
	
}