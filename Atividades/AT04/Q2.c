#include <stdio.h>
#include <stdlib.h>

float subtrai(float x, float y, float z)
{
    return x-y-z;
}
float main()
{
    float x, y, z;

    printf("Informe o primeiro valor: ");
    scanf("%f", &x);
    printf("Informe o segundo valor: ");
    scanf("%f", &y);
    printf("Informe o terceiro valor: ");
    scanf("%f", &z);		
    printf("%f - %f - %f = %f", x, y, z, subtrai(x, y,z));
    return 0;

}
