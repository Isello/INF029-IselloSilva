#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

/* 
9) Crie uma fun��o recursiva que receba um n�mero inteiro positivo N e calcule o somat�rio dos n�meros de 1 a N.
*/

int soma(int x){
	
    if(x == 0){
        return 0;
    }
    
	else{
        return x + soma(x -1);
    }
}

int main (){   

	setlocale(LC_ALL, "Portuguese");
	
	int num;
	
	printf("Digite o numero:\n");
	scanf("%d", &num);
	
	int resultado = soma(num);
	
	printf ("Soma de %d at� 1 � igual a: %d \n",num, resultado);
 
	getch();
	return 0;
}

