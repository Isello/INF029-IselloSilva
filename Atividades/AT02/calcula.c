#include <stdio.h>
#include <stdlib.h>
int main()
{
float n1, n2, r1;
int X;
int L=1;
    
while (L != 0){
		
	printf("Insira 0 - Sair, 1 - Somar, 2 - Subtrair, 3 - Multiplicar, 4 - Dividir.\n");
    scanf("%d", &X);
    while ((X<0) || (X>4)){
    	printf("\nComando invalido.\n");
    	printf("\nInsira 0 - Sair, 1 - Somar, 2 - Subtrair, 3 - Multiplicar, 4 - Dividir.\n");
		scanf("%d", &X);
	}
    if(X == 0){
	printf("Tchau!");
	break;}
	
    printf("Primeiro valor:\n");
    scanf("%f", &n1);
    printf("Segundo valor:\n");
    scanf("%f", &n2);
    
    if(X == 0){
	printf("\nTchau!");
	break;}
			
	if(X == 1){
	r1 = n1 + n2;
	printf("\nResultado= %.2f\n", r1);}
			
	else if(X == 2){
	r1 = n1 - n2;
	printf("\nResultado= %.2f\n", r1);}
			
	else if(X == 3){
	r1 = n1 * n2;
	printf("\nResultado= %.2f\n", r1);}
	
	else{
	r1 = n1 /n2;
	printf("\nResultado= %.2f\n", r1);}
		
	printf("\nSair da calculadora?\n 0 - SIM / 1 - NAO \n");
	scanf("%d", &L);
	}
return 0;	
}
    
