#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

// 6) Crie um programa em C, que contenha uma função recursiva que receba dois inteiros positivos k e n e calcule k^n. 
// Utilize apenas multiplicações. O programa principal deve solicitar ao usuário os valores de k e n e imprimir o resultado 
// da chamada da função.

int potencia(int k, int n) {
	
	if(n == 1) {
		return k;
	}
	
	return k*potencia(k, n - 1);
}

int main (){   

	setlocale(LC_ALL, "Portuguese");
	
	int k, n;
	
	printf("Digite K: ");
	scanf("%d", &k);
	printf("Digite N: ");
	scanf("%d", &n);	
	
	int resultado = potencia(k, n);
	
	printf ("\n%d elevado a %d é igual a: %d \n",k, n, resultado);
 
	getch();
	return 0;
}
