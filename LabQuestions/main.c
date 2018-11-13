#include<stdio.h>
#include<time.h>
#include<string.h>
#define BOYUT 15

//n size m shift sayısı

int shift_right (unsigned int i,unsigned int m){
	unsigned int ret;
	ret=i>>m;
	
	return ret;
	
}


int shift_left (unsigned int i,unsigned int m){
	unsigned int ret;
	ret=i<<m;
	
	return ret;
	
}



int* generic_shift(unsigned int*a,int n,int m,int (*fp)()){
	
	int *dizi1;
	int i;
	dizi1=(unsigned int *)malloc(n*sizeof(unsigned int));
	for (i=0;i<n;i++){
		dizi1[i]=fp(a[i],m);
		
	}
	
	return dizi1;
	
	
	
	
}



int main(){
int n,i,m,RLcontrol;
unsigned int *dizi;
int (*fp)();


	
printf("Dizinin eleman sayisini belirleyiniz.");scanf("%d",&n);

dizi=(unsigned int *)malloc(n*sizeof(unsigned int));

for (i=0;i<n;i++){
	printf("Dizinin %d inci elemanini giriniz.:",i+1);
	scanf("%hd",&dizi[i]);
	printf("\n");
}

//dizinin elemanları alındı.

printf("Her elemanin kaç adım shift edilecegini giriniz. ");scanf("%d",&m);

//kaç adım shift edileceği alındı.

printf("Shift edilme yonune karar verınız.\n Enter 1 to left \n Enter 0 to right");scanf("%d",&RLcontrol);
if (RLcontrol==1)
fp=shift_left;
else
fp=shift_right;

dizi=generic_shift(dizi,n,m,fp);

for (i=0;i<n;i++){
	printf("%3hd",dizi[i]);
}


	
	
	
	
	
	return 0;
}
