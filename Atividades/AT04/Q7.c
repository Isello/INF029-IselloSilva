#include <stdio.h>
#include <stdlib.h>

palavras(char matriz[3][20]){
	int i;
	for(i=0;i<3;i++){
		scanf("%s", matriz[i]);
    }
}

int main(){
	
char matriz[3][20];
printf("Digite 3 palavras: \n");
palavras(matriz);

int i =0;
while(i<=2){
	printf("%s ", matriz[i]);
	i++;
}

return 0;

}
