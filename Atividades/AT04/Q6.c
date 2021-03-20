#include <stdio.h>
#include <stdlib.h>

palavra(char vetor[]){
	scanf("%[^\n]s",  vetor);
}

int main(){
char vetor[2];
printf("Digite 3 letras: \n");
palavra(vetor);
printf("%s", vetor);
return 0;
}




