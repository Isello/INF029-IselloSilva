#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

// 3) Fa�a uma fun��o recursiva que permita inverter um n�mero inteiro N. Ex: 123 - 321

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
	printf("Digite um n�mero:");
	scanf("%d",&num);
	invert(num);
	
	getch();
	return 0;
}
