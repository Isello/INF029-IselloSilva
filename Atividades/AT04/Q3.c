#include <stdio.h>
#include <stdlib.h>

int fat(int x) {
    if (x >= 0) {
        int i = 1;
        while (x > 0) {
            i = i*x;
            x--;
        }
        return i;
    } else {
        return -1;
    }
}


int main(){
	int x;
    printf("Informe o numero para calcular o fatorial: \n");
    scanf("%d", &x);
	
	if(fat(x)==-1){
		printf("Nao e possivel calcular o fatorial desse numero");
	}
	else{
		printf("o fatorial do numero e: %d", fat(x));
	}
return 0;
}




