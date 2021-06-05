#include<stdio.h>
#include<stdlib.h>

// 1) Fa�a uma fun��o recursiva que calcule e retorne o fatorial de um n�mero inteiro N

double fatorial(int n) {
    if (n <= 1)
        return 1;
    else
        return (n * fatorial(n - 1));
}

int main(){
  int num;
  double f;
  
  do{
  	printf("Digite o numero que deseja calcular o fatorial: ");
  	scanf("%d",&num);
  } while(num<0);
  
  f = fatorial(num);
  
  printf("Fatorial de %d = %.0lf",num,f);
  
  getch();
  return 0;
}





