#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

/* 
8) O m�ximo divisor comum dos inteiros x e y � o maior inteiro que � divis�vel por x e y. 
Escreva uma fun��o recursiva mdc em C, que retorna o m�ximo divisor comum de x e y. 
O mdc de x e y � definido como segue: se y � igual a 0, ent�o mdc(x,y) � x; caso
contr�rio, mdc(x,y) � mdc (y, x%y), onde % � o operador resto.
*/
int MDC (int x, int y){
	
	if (x % y != 0)
	return MDC(y, x % y);
	else
	return y;
}

int main (){

	setlocale(LC_ALL, "Portuguese");
	
	int x, y;
	
	printf("Digite X: ");
	scanf("%d", &x);
	printf("Digite Y: ");
	scanf("%d", &y);
	
	int mdc = MDC(x, y);
	printf ("\nMDC de %d e %d � igual a: %d \n",x, y, mdc);
	
	getch();
	return 0;
}


