#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

/* 
10) Escreva uma função recursiva que determine quantas vezes um dígito K ocorre
em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.
*/

int conta_dig(int N, int K)
{
if ( N == 0 ) return 0;
return conta_dig(N/10,K) + (N%10==K);
}


int main (){   

	setlocale(LC_ALL, "Portuguese");
	
	int dig, nat;
	
	printf("Digite o dígito a ser procurado: ");
	scanf("%d", &dig);	
	printf("Digite o número natural: ");
	scanf("%d", &nat);
	
	
	
	int qtdDigs = conta_dig(nat, dig);
	
	printf ("Quantidade de ocorrências de %d em %d é igual a: %d \n",dig,nat, qtdDigs);
 
	getch();
	return 0;
}

