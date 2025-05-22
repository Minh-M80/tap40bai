#include<bits/stdc++.h>
using namespace std;

class SV{
	private:
	string ma,hoTen;
	public:
		SV();
		~SV();
		void nhap();
		void xuat();	
};
void SV::nhap(){
	cout<<"Nhap ma sinh vien:";
	getline(cin,this->ma);
	cout<<"Nhap ho ten:";
	getline(cin,this->hoTen);
}
void SV::xuat(){
	cout<<endl;
	cout<<this->ma<<"\t\t\t"
	<<this->hoTen;
}
SV::SV(){
};
SV::~SV(){
	ma="";
	hoTen="";
}
class SVTMDT:public SV{
	private:
		float diem;
	public:
		SVTMDT();
		~SVTMDT();
		void nhap();
		void xuat();
		float getDiem() const{
			return this->diem;
		};
};
void SVTMDT::nhap(){
	cout<<endl;
	SV::nhap();
	cout<<"Nhap diem:";
	cin>>this->diem;
	cin.ignore();
	cout<<endl;
	
}
void SVTMDT::xuat(){
	
	SV::xuat();
	cout<<"\t\t"<<this->diem;
}
bool operator < (const SVTMDT &a,const SVTMDT &b ){
	return a.getDiem() < b.getDiem();
}
SVTMDT::SVTMDT(){
};
SVTMDT::~SVTMDT(){
};

int main(){
	SV a;
	cout<<"Nhap thong tin 1 sinh vien:";
	cout<<endl;
	a.nhap();
	cout<<endl;
	cout<<"Hien thi thong tin sinh vien vua nhap:";
	cout<<endl;
	cout<<"Ma sinh vien"<<"\t\t"<<"Ho ten";
	a.xuat();
	cout<<endl;
	int n;
	cout<<"Nhap so doi tuong sinh vien chuyen nganh he thong tmdt:";
	cin>>n;
	cin.ignore();
	SVTMDT b[n];
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin sinh vien thu"<<i+1;
		b[i].nhap();
	}
	cout<<endl;
	cout<<"Thong tin sinh vien chuyen nganh he thong thuong mai dien tu:";
	cout<<endl;
	cout<<"Ma sinh vien\t\t"<<"Ho ten\t\t"<<"Diem\t\t";
	
		for(int i=0;i<n;i++){
		b[i].xuat();
	}
	cout<<endl;
	cout<<"Sap xep cac sinh vien theo diem giam dan:";
	cout<<endl;
//	sort(b,b+n);
for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
        if(b[i] < b[j]){
             SVTMDT temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
    }
}

		cout<<"Ma sinh vien\t\t"<<"Ho ten\t\t"<<"Diem\t\t";
	
		for(int i=0;i<n;i++){
		b[i].xuat();
	}
}
	
