#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//a. Viet ham nhap mang mot chieu cac so nguyen gom n phan tu (0<N<100)

void nhapmang(int *a, int &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%d",&n);
		if(n<=0 || n>99)
			printf("Nhap sai.Mang tu 0 den 99.Nhap lai");
	}while(n<=0 || n>99);
	for(int i = 0; i<n; i++){
		printf("Nhap gia tri phan tu thu %d: ",i);
		scanf("%d",a+i);
	}
}

//b. Xuat mang so nguyen n phan tu vua nhap
void xuatmang(int *a, int n){
	printf("\nCac ptu vua nhap vao mang: ");
	for(int i = 0; i<n; i++){
		printf("%5d",*(a+i));
	}
}

//c. Tinh tong cac phan tu co trong mang
void tongmang(int *a, int n){
	int tong = 0;
	for(int i = 0; i<n; i++){
		tong = tong + *a;
		a++;
	}
	printf("\nTong cac ptu trong mang: %d",tong);
}

//d. tong cac phan tu chan trong mang
//e. tong cac phan tu le co trong mang
void tongchanlemang(int *a, int n){
	int tongchan = 0, tongle = 0;
	for(int i = 0; i<n; i++){
		if(*(a+i) % 2 == 0){
			tongchan = tongchan + *(a+i);
		}else{
			tongle = tongle + *(a+i);
		}
	}
	printf("\nTong cac phan tu chan trong mang la: %d",tongchan);
	printf("\nTong cac phan tu le trong mang la: %d", tongle);
}

//f. Tinh tong cac phan tu nguyen to co trong mang
bool songuyento(int *a){
	if(*a < 2)
		return false;
	if(*a == 2)
		return true;
	for(int i = 2; i<*a; i++){
		if(*a%i == 0)
			return false;
	}
	return true;
}
int tongnguyento(int *a, int n){
	int tong = 0;
	for(int i = 0; i<n; i++){
		if(songuyento((a+i)) == true){
			tong += *(a+i);
		}
	}
	return tong;
}

//g. Tim phan tu chan dau tien co trong mang
void chandautien(int *a , int n){
	for(int i = 0; i<n; i++){
		if(*(a+i) % 2 == 0){
			printf("\nGia tri chan dau tien la %d tai vi tri %d.",*(a+i), i);
			break;
		}
	}
}

//h. Tim phan tu le dau tien co trong mang
void ledautien(int *a, int n){
	for(int i = 0; i<n; i++){
		if(*(a+i) % 2 != 0 ){
			printf("\nGia tri le dau tien la %d tai vi tri %d.",*(a+i), i);
			break;
		}
	}
}

//i. Tim phan tu nguyen to dau tien co trong mang
void songuyentodautien(int *a, int n){
	for(int i = 0; i<n; i++){
		if(songuyento((a+i)) == true){
			printf("\nSo nguyen to dau tien la %d tai vi tri %d.",*(a+i), i);
			break;
		}
	}
}

//j. Tim phan tu chan cuoi cung co trong mang
void chancuoicung(int *a, int n){
	for(int i = n-1; i>=0; i--){
		if(*(a+i) % 2 == 0){
			printf("\nGia tri chan cuoi cung la %d tai vi tri %d.",*(a+i), i);
			break;
		}
	}
}

//k. Tim phan tu chinh phuong cuoi cung co trong mang
void chinhphuongcuoicung(int *a, int n){
	int temp;
	for(int i = n-1; i>=0; i--){
		temp = sqrt(*(a+i));
		if(temp*temp == *(a+i)){
			printf("\nPhan tu so chinh phuong cuoi cung la %d tai vi tri %d.",*(a+i),i);
			break;
		}
	}
}

//l. Tim phan tu lon nhat co trong mang
int solonnhat(int *a, int n){
	int *max;
	max = &a[0];
	for(int i = 0; i<n; i++){
		if(*max < a[i]){
			max = &a[i];
		}
	}
	return *max;
}

//m. Dem phan tu chan co trong mang
void demphantuchan(int *a, int n){
	int dem = 0;
	for(int i = 0; i < n; i++){
		if(*(a+i) % 2 == 0)	dem++;
	}
	printf("\nSo phan tu chan co trong mang la %d.",dem);
}

//n. Dem so phan tu lon nhat trong mang
void demmax(int *a, int n){
	int demmax = 0;
	for(int i = 0; i<n; i++){
		if(solonnhat(a,n) == *(a+i)){
			demmax++;
		}
	}
	printf("\nSo luong phan tu lon nhat la %d.",demmax);
}

//o. In vi tri phan tu lon nhat dau tien co trong mang.
void vitrimaxdautien(int *a, int n){
	for(int i = 0; i<n; i++){
		if(solonnhat(a,n) == *(a+i)){
			printf("\nVi tri phan tu lon nhat dau tien la %d.",i);
			break;
		}
	}
}

//p. Them phan tu vao dau mang
void themdaumang(int *a, int &n){
	int x;
	printf("\nNhap gia tri can them vao dau mang: ");
	scanf("%d",&x);
	
	for(int i = n; i>0; i--){
		*(a+i) = *(a+(i-1));
	}
	
	++n;
	a[0] = x;
}

//q. Them phan tu voa vi tri x trong mang
void themphantu(int *a, int &n){
	int x,k;
	printf("\nNhap gia tri can them: ");
	scanf("%d", &x);
	printf("\nNhao vi tri can them: ");
	scanf("%d", &k);
	for(int i = n; i>k; i--){
		*(a+i) = *(a+(i-1));
	}
	
	++n;
	a[k] = x;
}

//s. Xoa phan tu chan dau tien

int vitrichandau(int *a, int n){
	for(int i = 0; i<n; i++){
		if(*(a+i) % 2 == 0)
			return i;
	}
}
void xoachandau(int *a, int &n){
	int k = vitrichandau(a,n);
	for(int i = k; i<n; i++){
		*(a+i) = *(a + (i + 1));
	}
	--n;
}

//t. Xoa tat ca phan tu lon nhat trong mang
void xoaphantulonnhat(int *a, int &n ){
	int z = solonnhat(a,n);
	for(int i = 0; i<n; i++){
		if(z == *(a+i)){
			for(int j = i; j<n; j++){
				*(a+j) = *(a+ (j+1));
			}
			--n;
		}
	}
}

//u. Sap xep mang tang dan

void hoanvi(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void mangtangdan(int *a, int n){
	for(int  i = 0; i<n-1; i++){
		for(int j = i+1; j<n; j++){
			if(a[i] > a[j])
				hoanvi(a[i],a[j]);
		}
	}
}

int main(){
	
	int n;
	int *a = (int*)malloc(100);
	nhapmang(a,n);
	
	xuatmang(a,n);
	
	tongmang(a,n);
	
	tongchanlemang(a,n);
	
	printf("\nTong cac so nguyen to: %d",tongnguyento(a,n));
	
	chandautien(a,n);
	
	ledautien(a,n);
	
	songuyentodautien(a,n);
	
	chinhphuongcuoicung(a,n);
	
	printf("\nGia tri phan tu lon nhat la %d.",solonnhat(a,n));
	
	demphantuchan(a,n);
	
	demmax(a,n);
	
	vitrimaxdautien(a,n);
	
	printf("\nThem phan tu vao dau mang:");
	themdaumang(a,n);
	xuatmang(a,n);
	
	printf("\nThem phan tu vao vi tri cho truoc:");
	themphantu(a,n);
	xuatmang(a,n);
	
	printf("\nXoa phan tu chan dau tien:");
	xoachandau(a,n);
	xuatmang(a,n);
	
	printf("\nXoa cac phan tu lon nhat: ");
	xoaphantulonnhat(a,n);
	xuatmang(a,n);
	
	printf("\nMang sau khi sap xep: ");
	mangtangdan(a,n);
	xuatmang(a,n);
	return 0;
}
