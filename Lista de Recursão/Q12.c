#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

/* 
12) Faça uma função recursiva que receba um número inteiro positivo N e imprima
todos os números naturais de 0 até N em ordem crescente.
*/

int naturais(int n, int y){

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

