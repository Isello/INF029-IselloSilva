#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

// 7) Crie um programa em C que receba um vetor de números reais com 100 elementos.
// Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor.

void inverteVetor(int v[], int ini, int fim){
    int aux;
    if(ini < fim){
        aux = v[ini];
        v[ini] = v[fim];
        v[fim] = aux;
        inverteVetor(v, ini + 1, fim - 1);
    }
}

int main (){

	setlocale(LC_ALL, "Portuguese");
	int i;
	
	int vet[100];
    int len = sizeof(vet)/sizeof(vet[0]);
    vet[0]=1;
    
    for( i = 1; i<len; i++){
    	vet[i] = vet[i-1]  + 1 ;
	}

    inverteVetor(vet, 0, len-1);
		
    for( i=0; i<len; i++ ){
    	printf ("V[%d]: %d \n",i,vet[i]);
	} 	
	
	getch();
	return 0;
}


