#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

/* 
14) Fa�a uma fun��o recursiva que receba um n�mero inteiro positivo par N e imprima
todos os n�meros pares de 0 at� N em ordem crescente.
*/

int naturais(int n, int y){
	
	if( y%2 == 0)
    printf("%d\n", y);

    if (n>y){

        return naturais(n, y+1);}

    else{

        return 0 ;}
}


int main (){   

	setlocale(LC_ALL, "Portuguese");
	
   int n, y=0;

   printf("Digite um numero\n");

   scanf("%d", &n);

   naturais(n, y);
 
	getch();
	return 0;
}
