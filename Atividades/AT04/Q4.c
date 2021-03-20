#include <stdio.h>
#include <stdlib.h>

int numeros(int vetor[]){
	
	int i;
    for(i = 0; i <= 2; i++){
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i <= 2; i++){
	return  vetor[i];    
    }
    
}

int main(){

int vetor[2];

printf("Digite 3 numeros: \n");
numeros(vetor);
int i =0;
while(i<=2){
	printf("%d ", vetor[i]);
	i++;
}
return 0;
}

