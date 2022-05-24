#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Sinhvien{
	char ten[50], lop[7];
	int maSo,ngay, thang, nam, gt;
	float toan, ly, tin, tong;
};
void menu(){
	printf("\n1. Xuat danh sach sinh vien.");
	printf("\n2. Xuat thong tin bang nhap ma sinh vien");
	printf("\n3. Danh sach sinh vien CNTT");
	printf("\n4. Danh sach sinh vien nu CNTT");
	printf("\n5. Danh sach sinh vien theo ten");
	printf("\n6. Danh sach sinh vien theo mssv");
	printf("\n7. Danh sach sinh vien theo diem toan");
}
void nhapngaysinh(int &ngay, int &thang, int &nam){
	do{
		printf("\t Nhap nam: ");
		scanf("%d",&nam );
		if(nam <=0)
			printf("Nhap sai, nhap lai");
	}while(nam<=0);
	
	do{
		printf("\t Nhap thang: ");
		scanf("%d",&thang );
		if(thang <1 || thang > 12){
			printf("Nhap sai, nhap lai");
		}
	}while(thang < 1 || thang >12);
	bool test = true;
	do{
		printf("\t Nhap ngay: ");
		scanf("%d",&ngay );
		if(thang ==4 || thang == 6|| thang == 9 || thang ==11){
			if(ngay <1 || ngay>30){
				printf("Nhap sai, nhap lai");
				test = false;
			}else{
				test = true;
			}
		}else if(thang == 2){
			if(nam%4 == 0 && nam%100!=0 || nam%400 ==0){
				if(ngay<1 || ngay>29){
					printf("Nhap sai, nhap lai");
					test = false;
				}
				else{
					test = true;
				}
			}else{  
				if(ngay<1 || ngay>28){
					printf("Nhap sai, nhap lai");
					test = false;
				}else{
					test = true;
				}
				
			}
		}else{
			if(ngay<1 || ngay>31){
				printf("Nhap sai, nhap lai");
				test = false;
			}else{
					test = true;
			}
		}
	}while(test == false);
}
void nhapdiem(float &a){
	do{
		scanf("%f",&a);
		if(a<0 || a>10){
			printf("Nhap sai, nhap lai ");
		}
	}while(a<0 || a>10);
}
void nhap1sinhvien(Sinhvien *a){
	fflush(stdin);
	printf("\n - Nhap ten: ");
	gets(a->ten );
	printf(" - Nhap mssv: ");
	scanf("%d",&a->maSo );
	printf(" - Nhap ngay, thang, nam sinh: \n");
	nhapngaysinh(a->ngay, a->thang, a->nam);
	do{
		printf(" - Nhap gioi tinh (Nam nhap 0, nu nhap 1): ");
		scanf("%d",&a->gt );
		if(a->gt<0 || a->gt>1){
			printf("Nhap sai, nhap lai");
		}
	}while(a->gt<0 || a->gt>1);
	printf("Nhap lop hoc: ");
	scanf("%s",&a->lop);
	printf("Nhap diem toan: ");
	nhapdiem(a->toan);
	printf("Nhap diem ly: ");
	nhapdiem(a->ly);
	printf("Nhap diem tin: ");
	nhapdiem(a->tin );
}
void xuat1sinhvien(Sinhvien *a){
	printf("\nHo va ten: %30s",a->ten);
	printf("\nMSSV: %4d ",a->maSo);
	printf("Nam sinh: %d / %d / %d",a->ngay, a->thang, a->nam);
	if(a->gt == 0){
		printf("\nGT: Nam");
	}else{
		printf("\nGT: Nu");
	}
	
	printf("\nLop: %7s",a->lop );
	printf("\nDiem toan: %.2f",a->toan );
	printf("\nDiem ly: %.2f",a->ly );
	printf("\nDiem tin: %.2f",a->tin );
	
}
void nhapdanhsachsinhvien(Sinhvien *a, int &n){
	printf("\nNhap so luong sinh vien: ");
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		printf("\nSinh vien thu %d: \n",i);
		nhap1sinhvien((a+i));
	}
}
void xuatdanhsachsinhvien(Sinhvien *a, int n){ 
	for(int i = 0; i<n; i++){
		printf("\nThong tin sinh vien thu %d: \n",i);
		xuat1sinhvien((a+i));
	}
}
void xuatmasosinhvien(Sinhvien *a, int n){
	int ms;
	printf("\nNhap ma so sinh vien can lay thong tin: ");
	scanf("%d",&ms);
	for(int i = 0; i<n; i++){
		if((a+i)->maSo == ms)
			xuat1sinhvien((a+i));
	}
}
void sapxeptheoten(Sinhvien *a, int n){
	for(int i = 0; i<n-1; i++){
		for(int j = i+1; j<n; j++){
			if(strcmpi((((a+i))->ten), ((a+j)->ten))> 0){
				Sinhvien temp = *(a+i);
				*(a+i) = *(a+j);
				*(a+j) = temp;
			}
		}xuatdanhsachsinhvien(a,n);
	}
}
void sapxeptheomaso(Sinhvien *a, int n){
	for(int i = 0; i<n-1; i++){
		for(int j = i+1; j<n; j++){
			if((a+i)->maSo > (a+j)->maSo){
				Sinhvien temp = *(a+i);
				*(a+i) = *(a+j);
				*(a+j) = temp;
			}
		}xuatdanhsachsinhvien(a,n);
	}
}
void sapxeptheodiemtoan(Sinhvien *a, int n){
	for(int i = 0; i<n-1; i++){
		for(int j = i+1; j<n; j++){
			if((a+i)->toan > (a+j)->toan){
				Sinhvien temp = *(a+i);
				*(a+i) = *(a+j);
				*(a+j) = temp;
			}
		}xuatdanhsachsinhvien(a,n);
	}
}
int main(){
	Sinhvien *a;
	int n;
	a = (Sinhvien*)malloc(1000);
	nhapdanhsachsinhvien(a,n);
	xuatdanhsachsinhvien(a,n);
	xuatmasosinhvien(a,n);
	printf("\nXuat theo ten sinh vien: \n");
	sapxeptheoten(a,n);
	printf("\nXuat theo ma so sinh vien: \n");
	sapxeptheomaso(a,n);
	printf("\nXuat theo diem toan cua sinh vien: \n");
	sapxeptheodiemtoan(a,n);
	free(a);
	return 0;
}
