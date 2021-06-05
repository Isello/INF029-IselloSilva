#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

// 2) Fa�a uma fun��o recursiva que calcule e retorne o N-�simo termo da sequ�ncia
// Fibonacci. Alguns n�meros desta sequ�ncia s�o: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...

void fibonacci(int num){
	
   int x = num;
   
   int vetorAux[x];
   
   int i;
   
   vetorAux[0]= 0;
   
   for(i=1; i<x; i++){
   	
   	if(i==1 || i==2){ vetorAux[i] = 1;}
   	
   	else{
	    vetorAux[i] = vetorAux[i-1] + vetorAux[i-2];}
   }
   
   printf("%d\n", vetorAux[x-1]);
   
}

int main(){
   setlocale(LC_ALL, "Portuguese");
   int n, i;
   
  do{
  	printf("Digite a posi��o do elemento da sequ�ncia de Fibonacci que voc� deseja: ");
  	scanf("%d",&n);
  	
  	if(n<1){
  		printf("Digite um valor maior ou igual a 1.\n\n");
	  }
  	
  } while(n<1);
   

   printf("\nO elemento %d da sequ�ncia de Fibonacci �: ", n);
   fibonacci(n);
   
   getch();
   return 0;
}
