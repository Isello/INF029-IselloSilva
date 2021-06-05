#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

// 4) Faça uma função recursiva que permita somar os elementos de um vetor de inteiros.

int soma (int vet[], int tam){
	
	if(1 == tam){
		return vet [0];
	}
    
    else{
    	return vet [tam-1]+soma(vet, tam-1);
	}
}

int main (){   

	setlocale(LC_ALL, "Portuguese");
	
	int vet []= {1, 2, 3, 4, 5}; 

    int len = sizeof(vet)/sizeof(vet[0]);

    int resultado= soma (vet,len);
  
    printf ("Soma do vetor é igual a: %d \n",resultado);
 
	getch();
	return 0;
}
