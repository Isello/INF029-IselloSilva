#include <stdio.h>
#include <stdlib.h>

int numeros(int vetor[]){
	
	int i;
    for(i = 0; i <4 ; i++){
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i <4 ; i++){
	return  vetor[i];    
    }
    
}

int main(){

struct numbers {
  int vetor[4];
};
struct numbers x;
printf("Digite 4 numeros: \n");
numeros(x.vetor);
int i =0;
while(i<=3){
	printf("%d ", x.vetor[i]);
	i++;
}
return 0;
}
