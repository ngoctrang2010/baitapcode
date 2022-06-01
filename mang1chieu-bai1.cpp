#include <stdio.h>
#define max 100
#include <math.h>

const int GIA_TRI_NHO_NHAT_MANG = 1;
const int GIA_TRI_LON_NHAT_MANG = 100;

void NhapSL(int &n)
{
	do{
		printf("Nhap so luong phan tu trong mang: ");
		scanf("%d",&n);
		
		if(n<GIA_TRI_NHO_NHAT_MANG||n>GIA_TRI_LON_NHAT_MANG)printf("Ban nhap sai so luong phan tu trong mang, 0<sl<=100.Nhap lai!");
		
	}while(n<GIA_TRI_NHO_NHAT_MANG||n>GIA_TRI_LON_NHAT_MANG);
}

void NhapXuatMang(int a[], int n)
{

	for(int i=0; i<n; i++)
	{
		printf("a[%d]=", i);
		scanf("%d",&a[i]);
	}
	
	printf("\nMang ban vua nhap la:");
	for(int j=0; j<n; j++)
	{
		printf("\t%d", a[j]);
	}
}

int KtraSNT( int n)
{
	int dem = 0;
		
	for(int j=2; j<=sqrt(n); j++)
		{
			if( n%j==0)dem++;
		}
	if(dem == 0 )return 1;
	else return 0;
}

int SNTmin(int a[], int n, int min)
{
	for(int i=0; i<n; i++)
	{
		if( KtraSNT(a[i]) == 1)
		{
			min = a[i];
			break;	
		}
		if( KtraSNT(a[i]) == 1 && min > a[i])
			min = a[i];	
	}
	return min;
}

void NhapX(float &x)
{
	do{
		printf("\nNhap gia tri cua X: ");
		scanf("%f", &x);
		
		if(x<0)printf("\nBan nhap sai gia tri x, x lon hon 0.Nhap lai!");
	}while(x<0);
}

void SNTlessX(int a[], int n, float x)
{
	NhapX(x);
	int DEM=0;
	
	for(int i=0; i<n; i++)
	{
		if(KtraSNT(a[i])==1 && a[i]<x) DEM++;
	}
	
	if(DEM == 0 )printf("\nTrong mang khong co so nguyen to nao nho hon %.1f", x);
	else printf("\nTrong mang co %d so nguyen to nho hon %.1f",DEM,x);
}
void tong(int a[], int n)
{
	int Sum=0;
	
	for(int i=0; i<n; i++)
	{
		Sum=Sum+a[i];
	}
	printf("\nTong cac phan tu trong mang la %d",Sum);
}
int main()
{
	int a[max], n, min;
	float x;
	 
	NhapSL(n);
	NhapXuatMang(a,n);
	
	printf("\nGia tri so nguyen to nho nhat la:%d",SNTmin(a,n, min));
	SNTlessX(a,n,x);
	
	tong(a,n);
	
	return 0;
}
