#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

float soma(float x, float y)
{
    return x+y;
}
float main()
{
    float x, y;

    printf("Informe o primeiro valor: ");
    scanf("%f", &x);
    printf("Informe o segundo valor: ");
    scanf("%f", &y);
		
    printf("%f + %f = %f", x, y, soma(x, y));
    return 0;

}


