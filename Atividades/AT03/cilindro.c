#include <stdio.h>
#include <stdlib.h>
#include "volumeCilindro.h"


float main(){

    float raio, altura, volume;
    
    printf("Informe o raio do cilindro: \n");
    scanf("%f",&raio);
            
    printf("Informe a altura do cilindro: \n");
    scanf("%f",&altura);

    volume = volumeCilindro(raio,altura);

    printf("Volume do cilindro: %.2f",volume);


    return 0;
}
