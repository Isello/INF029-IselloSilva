#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

/* 
11) A multiplicação de dois números inteiros pode ser feita através de somas
sucessivas. Proponha um algoritmo recursivo Multip_Rec(n1,n2) que calcule a
multiplicação de dois inteiros.
*/

int Multip_Rec(int n1, int n2) {
	if(n1 == 0 || n2 == 0) {
		return 0;
	}
	if(n2 == 1) {
		return n1;
	}
	return n1 + Multip_Rec(n1, n2 - 1);
}


int main (){   

	setlocale(LC_ALL, "Portuguese");
	
	int n1, n2;
	
	printf("Digite o primeiro número: ");
	scanf("%d", &n1);	
	printf("Digite o segundo número: ");
	scanf("%d", &n2);

	int resultado = Multip_Rec(n1, n2);
	
	printf ("O produto é igual a: %d \n",resultado);
 
	getch();
	return 0;
}

