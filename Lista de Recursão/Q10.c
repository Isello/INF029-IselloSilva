#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

/* 
10) Escreva uma fun��o recursiva que determine quantas vezes um d�gito K ocorre
em um n�mero natural N. Por exemplo, o d�gito 2 ocorre 3 vezes em 762021192.
*/

int conta_dig(int N, int K)
{
if ( N == 0 ) return 0;
return conta_dig(N/10,K) + (N%10==K);
}


int main (){   

	setlocale(LC_ALL, "Portuguese");
	
	int dig, nat;
	
	printf("Digite o d�gito a ser procurado: ");
	scanf("%d", &dig);	
	printf("Digite o n�mero natural: ");
	scanf("%d", &nat);
	
	
	
	int qtdDigs = conta_dig(nat, dig);
	
	printf ("Quantidade de ocorr�ncias de %d em %d � igual a: %d \n",dig,nat, qtdDigs);
 
	getch();
	return 0;
}

