#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

// 3) Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321

int invert(int n){
	
    if(n==0)
    return n;
    
    else{
     printf("%d", n % 10);
     n=n / 10;
     return invert(n);
    }
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int num;
	printf("Digite um número:");
	scanf("%d",&num);
	invert(num);
	
	getch();
	return 0;
}
