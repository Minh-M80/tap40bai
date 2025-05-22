#include<bits/stdc++.h>
using namespace std;


class DATE {
	private:
		int ngay,thang,nam;
	public:
		DATE();
		~DATE();
		DATE(int,int,int);
		void nhap();
		void xuat();
};
DATE::DATE(){
};
DATE::DATE(int ngay,int thang,int nam){
	this->ngay=ngay;
	this->thang=thang;
	this->nam=nam;
};
DATE::~DATE(){
	ngay=thang=nam=0;	
}
void DATE::nhap(){
	cout<<"Nhap ngay:";
	cin>>this->ngay;
	cin.ignore();
	cout<<"Nhap thang:";
	cin>>this->thang;
	cin.ignore();
	cout<<"Nhap nam:";
	cin>>this->nam;
	cin.ignore();
}
void DATE::xuat(){
	cout<<left<<setw(15)<<this->ngay
	<<left<<setw(15)<<this->thang
	<<left<<setw(15)<<this->nam;
}

class MAYTINH:public DATE{
	private:
		string ma,ten;
		float giaNiemY;
		static float rate;
	public:
		MAYTINH();
		~MAYTINH();
		MAYTINH(int,int,int,string,string,float);
		void nhap();
		void xuat();
		float giaTT();
		string getTen(){
			return this->ten;
		}	
};
MAYTINH::MAYTINH(){
};
MAYTINH::~MAYTINH(){
	ma=ten="";
	giaNiemY=0;
};
float MAYTINH::rate=0.1;
void MAYTINH::nhap(){
	DATE::nhap();
	cout<<"Nhap ma may tinh:";
	getline(cin,this->ma);
	cout<<"Nhap ten may tinh:";
	getline(cin,this->ten);
	cout<<"Nhap gia niem yet:";
	cin>>this->giaNiemY;
	cin.ignore();
	cout<<endl;
}

void MAYTINH::xuat(){
	
	DATE::xuat();
	cout<<left<<setw(15)<<this->ma<<left<<setw(15)<<this->ten<<left<<setw(15)
	<<this->giaNiemY<<endl;
}
float MAYTINH::giaTT(){
	return this->giaNiemY-this->giaNiemY*this->rate;
}

int toNumber(string temp){
	stringstream ss;
	ss<<temp;
	int a;
	ss>>a;
	return a;
}
bool checkInput(string temp,string name){
	stringstream ss(temp);
	string token;
	if(name=="chu"){
		while(ss>>token){
			for(char x:token){
				if(!isalpha(x)){
					return true;
				}
			}
		}
	} else if(name=="so"){
		int a=toNumber(temp);
		if(a<=0){
			return true;
		}
		for(char x:temp){
			if(!isdigit(x)){
				return true;
			}
		}
	}
	return false;
}

void mayTinhTenASUS(MAYTINH b[],int n){
	int check=0;
	for(int i=0;i<n;i++){
		if(b[i].getTen()=="ASUS"){
			b[i].xuat();
			check=1;
		}
	}
	if(check==0){
		cout<<"Khong co may tinh ten ASUS";
		cout<<endl;
	}
}

void giaThcTeMin(MAYTINH b[],int n){
	float min=b[0].giaTT();
	for(int i=0;i<n;i++){
		if(b[i].giaTT()<=min){
			min=b[i].giaTT();
		}
	}
	for(int i=0;i<n;i++){
		if(b[i].giaTT()==min){
			b[i].xuat();
		}
	}
}

int main() {
	DATE a;
	cout<<"Nhap mot doi tuong DATE:\n";
	a.nhap();
	cout<<"Thong tin doi tuong DATE vua nhap la:\n";
	cout<<left<<setw(15)<<"Ngay"<<setw(15)<<"Thang"<<setw(15)<<"Nam";
	cout<<endl;
	a.xuat();
	cout<<endl;
	int n;
	string temp;
	do{
		cout<<"Nhap so doi tuong MAYTINH:";
		getline(cin,temp);
	}while(checkInput(temp,"so"));
	n=toNumber(temp);
	MAYTINH b[n];
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin may tinh thu "<<i+1<<":"<<endl;
		b[i].nhap();
	}
	cout<<endl;
	cout<<"Thong tin may tinh vua nhap la:\n";
	cout<<left<<setw(15)<<"Ngay"<<setw(15)<<"Thang"<<setw(15)<<"Nam"
	<<setw(15)<<"Ma may"<<setw(15)<<"Ten may"<<setw(15)<<"Gia niem yet";
	cout<<endl;
	for(int i=0;i<n;i++){
		b[i].xuat();
	}
	cout<<endl;
	cout<<"Thong tin may tinh ten ASUS la:";
	cout<<endl;
	cout<<left<<setw(15)<<"Ngay"<<setw(15)<<"Thang"<<setw(15)<<"Nam"
	<<setw(15)<<"Ma may"<<setw(15)<<"Ten may"<<setw(15)<<"Gia niem yet";
	cout<<endl;
	mayTinhTenASUS(b,n);
	cout<<endl;
	cout<<"Thong tin may tinh co gia thuc te nho nhat:";
	cout<<endl;
	cout<<left<<setw(15)<<"Ngay"<<setw(15)<<"Thang"<<setw(15)<<"Nam"
	<<setw(15)<<"Ma may"<<setw(15)<<"Ten may"<<setw(15)<<"Gia niem yet";
	cout<<endl;
	giaThcTeMin(b,n);
}