#include<bits/stdc++.h>
using namespace std;
int toNumber(string temp){
	stringstream ss;
	ss << temp;
	int a;
	ss >> a;
	return a;
}
bool checkInput(string temp,string name){
	stringstream ss(temp);
	string token;
	if(name == "chu"){
		while(ss >> token){
			for(char x:token){
				if(!isalpha(x)){
					return true;
				}	
			}
		}
	}else if(name == "so"){
		int a = toNumber(temp);
		if(a <= 0){
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
class PhuongTienGiaoThong{
	private:
		string hang,tenPhgTien;
		int namsx;
		float vmax;
	public:
		PhuongTienGiaoThong();
		PhuongTienGiaoThong(string,string,int,float);
		~PhuongTienGiaoThong();
		void nhap();
		void xuat();
		float getVmax(){
			return this->vmax;
		}
		string getHang(){
			return this->hang;
		}
};
PhuongTienGiaoThong::PhuongTienGiaoThong(){
};
PhuongTienGiaoThong::~PhuongTienGiaoThong(){
	hang="";
	tenPhgTien="";
	namsx=0;
	vmax=0;
};
PhuongTienGiaoThong::PhuongTienGiaoThong(string hang,string tenPhgTien,int namsx,float vmax){
	this->hang=hang;
	this->tenPhgTien=tenPhgTien;
	this->namsx=namsx;
	this->vmax=vmax;
};
void PhuongTienGiaoThong::nhap(){
	cout<<"Nhap hang sx:";
	getline(cin,this->hang);
	cout<<"Nhap ten phg tien:";
	getline(cin,this->tenPhgTien);
	cout<<"Nhap nam sx:";
	cin>>this->namsx;
	cin.ignore();
	cout<<"Nhap v toc max:";
	cin>>this->vmax;
	cin.ignore();
}
void PhuongTienGiaoThong::xuat(){
	cout<<left<<setw(10)<<this->hang
	<<left<<setw(18)<<this->tenPhgTien
	<<left<<setw(10)<<this->namsx
	<<left<<setw(25)<<this->vmax;
}

class Oto:public PhuongTienGiaoThong{
	private:
		int soCho;
		string kieuDC;
	public:
		Oto();
		Oto(string,string,int,float,int,string);
		~Oto();
		void nhap();
		void xuat();
		float setVTCS(){
			return this->getVmax()/4;
		}
	
		
};
Oto::Oto(){
};
Oto::Oto(string hang,string tenPhgTien,int namsx,float vmax,int soCho,string kieuDC):PhuongTienGiaoThong( hang, tenPhgTien, namsx, vmax){
	this->soCho=soCho;
	this->kieuDC=kieuDC;
}
Oto::~Oto(){
};
void Oto::nhap(){
	PhuongTienGiaoThong::nhap();
	cout<<"Nhap so cho:";
	cin>>this->soCho;
	cin.ignore();
	cout<<"Nhap kieu dong co:";
	getline(cin,this->kieuDC);
}
void Oto::xuat(){
	PhuongTienGiaoThong::xuat();
	cout<<left<<setw(10)<<this->soCho
	<<left<<setw(20)<<this->kieuDC
	<<left<<setw(25)<<this->setVTCS();
	
}

void inHangHonda(Oto a[],int n){
	int check=0;
	for(int i=0;i<n;i++){
		if(a[i].getHang()=="Honda"){
			a[i].xuat();
			check=1;
			cout<<endl;
		}
	}
	if(check==0){
		cout<<"Khong co o to hang Honda\n";
	}
}

int main(){
	PhuongTienGiaoThong a;
	cout<<"Nhap mot phuong tien giao thong:";
	cout<<endl;
	a.nhap();
	cout<<"Hien thi thong tin phg tien vua nhap:";
	cout<<endl;
	cout<<left<<setw(10)<<"Hang sx"<<
	left<<setw(18)<<"Ten phuong tien"
	<<left<<setw(10)<<"Nam sx"
	<<left<<setw(25)<<"Van toc toi da"<<endl;
	a.xuat();
	cout<<endl;
	int n;
	cout<<"Nhap so doi tuong o to:";
	cin>>n;
	cin.ignore();
	Oto b[n];
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin o to thu "<<i+1<<"\n";
		b[i].nhap();
	}
	cout<<"Hien thi thong tin o to vua nhap:\n";
		cout<<left<<setw(10)<<"Hang sx"<<
	left<<setw(18)<<"Ten phuong tien"
	<<left<<setw(10)<<"Nam sx"
	<<left<<setw(25)<<"Van toc toi da"
	<<left<<setw(10)<<"So cho"
	<<left<<setw(20)<<"Kieu dong co"
	<<left<<setw(25)<<"Van toc co so"<<endl;
	for(int i=0;i<n;i++){
		b[i].xuat();
		cout<<endl;
	}
	cout<<endl;
	inHangHonda(b,n);
	
}