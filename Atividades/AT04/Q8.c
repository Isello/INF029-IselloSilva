#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nome[30];
    char dataNascimento[11];
    char cpf[12];
    char sexo[1];
}cliente;

cliente cadastrarCliente(cliente user){
	scanf("%s", user.nome);
    scanf("%s", user.dataNascimento);
    scanf("%s", user.cpf);
    scanf("%s", user.sexo);
    return user;
}

int main(){
	cliente user;
	printf("Informe o nome, a data de nascimento, o cpf e o sexo:\n");
	user = cadastrarCliente(user);

	
	printf("Nome: %s\n", user.nome);
    printf("Data de nascimento: %s\n", user.dataNascimento);
    printf("CPF: %s\n", user.cpf);
    printf("Sexo: %s\n", user.sexo);
 
    return 0;
}


