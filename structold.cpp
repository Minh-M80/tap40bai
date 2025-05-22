#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct NN{
	int ngay;
	int thang;
	int nam;
};
typedef struct NN NN;

struct TB{
	int matb;
	char tentb[20];
	NN ngaynhap;
	int khauhao;
	float giaban;
	int sl;
};

typedef struct TB TB;

void nhapTB(TB *a,int n){
	for(int k=0;k<n;k++){
		printf("nhap ma tb thu %d:",k+1);scanf("%d",&(a+k)->matb);
		printf("nhap tentb thu %d:",k+1);fflush(stdin);gets((a+k)->tentb);
		printf("nhap ngay nhap tb thu %d:",k+1);scanf("%d",&(a+k)->ngaynhap.ngay);
		printf("nhap thang nhap tb thu %d:",k+1);scanf("%d",&(a+k)->ngaynhap.thang);
		printf("nhap nam nhap tb thu %d:",k+1);scanf("%d",&(a+k)->ngaynhap.nam);
		printf("nhap khauhao tb thu %d:",k+1);scanf("%d",&(a+k)->khauhao);
		printf("nhap gia ban tb thu %d:",k+1);scanf("%f",&(a+k)->giaban);
		printf("nhap so luong tb thu %d:",k+1);scanf("%d",&(a+k)->sl);
	}
}
void hienTB(TB *a,int n){
	printf("\n\t\tDANH SACH THIET BI\n");
	printf("\n%10s|%20s|%10s/%10s/%10s|%10s|%10s|%10s|","matb","tentb","ngay","thang","nam","khauhao","giaban","sl");

	for (int i = 0; i <n ; i++)
	{
		printf("\n%10d|%20s|%10d/%10d/%10d|%10d|%10.2f|%10d|",(a+i)->matb,(a+i)->tentb,(a+i)->ngaynhap.ngay,(a+i)->ngaynhap.thang,(a+i)->ngaynhap.nam,(a+i)->khauhao,(a+i)->giaban,(a+i)->sl);

	}
}


void hienthikhauhaolonhon5andnhaptrongnam2017(TB *a,int n){
	printf("\n\t\tTHIET BI KHAU HAO LON HON 5 VA NHAP TRONG NAM 2017\n");
    printf("\n%10s|%20s|%10s/%10s/%10s|%10s|%10s|%10s|","matb","tentb","ngay","thang","nam","khauhao","giaban","sl");

    for (int i = 0; i <n; i++)
	{
		if(((a+i)->khauhao)>5 && (a+i)->ngaynhap.nam==2017){
				printf("\n%10d|%20s|%10d/%10d/%10d|%10d|%10f|%10d|",(a+i)->matb,(a+i)->tentb,(a+i)->ngaynhap.ngay,(a+i)->ngaynhap.thang,(a+i)->ngaynhap.nam,(a+i)->khauhao,(a+i)->giaban,(a+i)->sl);
		}
	}
	
}
void thietbivanconkhauhao(TB *a,int n){
	int count=0;
	printf("Thiet bi van con khau hao tinh den ngay 20/11/2023");
	printf("\n%10s|%20s|%10s/%10s/%10s|%10s|%10s|%10s|","matb","tentb","ngay","thang","nam","khauhao","giaban","sl");
	for (int i = 0; i <=n; i++)
	{
		if(2023-(a+i)->khauhao>(a+i)->ngaynhap.nam){
			count++;
			printf("\n%10d|%20s|%10d/%10d/%10d|%10d|%10f|%10d|",(a+i)->matb,(a+i)->tentb,(a+i)->ngaynhap.ngay,(a+i)->ngaynhap.thang,(a+i)->ngaynhap.nam,(a+i)->khauhao,(a+i)->giaban,(a+i)->sl);
		}
		else if (2023-(a+i)->khauhao==(a+i)->ngaynhap.nam)
		{
			if((a+i)->ngaynhap.thang<11){
				count++;
                printf("\n%10d|%20s|%10d/%10d/%10d|%10d|%10f|%10d|",(a+i)->matb,(a+i)->tentb,(a+i)->ngaynhap.ngay,(a+i)->ngaynhap.thang,(a+i)->ngaynhap.nam,(a+i)->khauhao,(a+i)->giaban,(a+i)->sl);
			}
		}
		else if ((a+i)->ngaynhap.thang==11)
		{
			if((a+i)->ngaynhap.ngay<20){
                count++;
                printf("\n%10d|%20s|%10d/%10d/%10d|%10d|%10f|%10d|",(a+i)->matb,(a+i)->tentb,(a+i)->ngaynhap.ngay,(a+i)->ngaynhap.thang,(a+i)->ngaynhap.nam,(a+i)->khauhao,(a+i)->giaban,(a+i)->sl);
            }
		}
		if(count == 0){
			printf("khong co thiet bi nao van con khau hao tinh den ngay 20/11/2023");
		}
		
		
	}
	
}



int main(){
	int m;//so tb
	do
	{
		printf("nhap so thiet bi can nhap:");scanf("%d",&m);
	} while (m<=0);
	TB *a=(TB*)malloc(m*sizeof(TB));

	nhapTB(a,m);
	hienTB(a,m);
	hienthikhauhaolonhon5andnhaptrongnam2017(a,m);
//	thietbivanconkhauhao(a,m);
}