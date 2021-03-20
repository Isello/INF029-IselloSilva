#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
    char nome[30];
    char dataNascimento[11];
    char CPF[11];
    char sexo;
}cliente;

int validarNome(cliente X){
	int x = strlen(X.nome);
	if(x <= 20) {
	    return 1;
	} else {
	    return -1;
	}
}

int validarData(cliente X){
	int x = strlen(X.dataNascimento);
    char *dia, *mes, *ano;
    dia = strtok(X.dataNascimento, "/");
    mes = strtok(NULL, "/");
    ano = strtok(NULL, " ");
    	
    int dd, mm, aa;
    dd = atol(dia);
    mm = atol(mes);
    aa = atol(ano);
    
    int i=0;
    int j;

    if (aa >= 1900 && aa <= 2021)
    {
        if (mm >= 1 && mm <= 12)
        {
            if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)){
            	j++;
			}
            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11)){
            	j++;
			}
            else if ((dd >= 1 && dd <= 28) && (mm == 2)){
            	j++;
			}
            else if (dd == 29 && mm == 2 && (aa % 400 == 0 || (aa % 4 == 0 && aa % 100 != 0))){
            	j++;
			}
            else{
			i=1;} 
        }
        else{
            i=1;}
    }
    else{
        i=1;}
    if (i==0){
    	return 1;}
	else{
		return -1;}    
}

int validarCPF(char *cpf) //Return 1 Se for válido e -1 Se for inválido
{
    int d1 = 0, d2 = 0, i, j;
    
    if(strlen(cpf) != 11)
        return -1;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return -1; 
    else
    {
        ///Verificação do primeiro dígito verificador
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de d1
            d1 += (cpf[i]-48) * j;
        d1 %= 11;
        if(d1 < 2)
            d1 = 0;
        else
            d1 = 11 - d1;
        if((cpf[9]-48) != d1)
            return -1; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///Verificação do segundo dígito verificador
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de d2
                    d2 += (cpf[i]-48) * j;
        d2 %= 11;
        if(d2 < 2)
            d2 = 0;
        else
            d2 = 11 - d2;
        if((cpf[10]-48) != d2)
            return -1; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}

int validarSexo(char X) {

	if(X =='F' || X == 'M' || X == 'O' || X =='f' || X == 'm' || X == 'o') {
	    return 1;
	} else {
	    return -1;
	}
	
}

int cadastrarCliente(cliente user){
	
	cliente val;
	int n=0;
	
	strcpy(val.nome, user.nome);
	strcpy(val.dataNascimento, user.dataNascimento);
	char cpf[10];
	strcpy(cpf, user.CPF);
	char sex = user.sexo;
	
	// Validando nome
	int nomeValido = validarNome(val);
	if (nomeValido == -1){
		n= n+1;}
	
	// Validando data
	int dataNascimentoValida = validarData(val);
	if (dataNascimentoValida == -1){
		n= n+10;}		
	
	// Validando CPF
	int cpfInvalido = validarCPF(cpf);
	if (cpfInvalido == -1){
		n= n+100;}
		
	// Validando sexo
	int sexoInvalido = validarSexo(sex);
	if (sexoInvalido == -1){
		n= n+1000;
	}
	
	return n;	
			
}

int main() {

    cliente user;

	printf("--- Cadastro Cliente ---\n");
	
	printf("\nInforme o nome do cliente:\n");
	scanf("%s", &user.nome);
	printf("\nInforme a data de nascimento do cliente (formato Dia/Mes/Ano):\n");
	scanf("%s", &user.dataNascimento);
	printf("\nInforme o CPF do cliente:\n");
	scanf("%s", &user.CPF);
	
	printf("\nInforme o sexo do cliente (opções: m e M para masculino; f e F para feminino, o e O para outro):\n");
	scanf("%s", &user.sexo);
	
	char sex = user.sexo;

	
	int x = cadastrarCliente(user);
	
	switch (x){
		
   case 1:
     printf("\nNome invalido.");
   break;

   case 10:
     printf("\nData invalida.");
   break;
   
   case 11:
     printf("\nNome e data invalidos.");
   break;   
   
   case 100:
     printf("\nCPF invalido.");
   break;  
   
   case 101:
     printf("\nNome e CPF invalidos.");
   break;  
   
   case 110:
     printf("\nData e CPF invalidos.");
   break;     
   
   case 111:
     printf("\nNome, data e CPF invalidos.");
   break; 
   
   case 1000:
     printf("\nSexo invalido.");
   break; 
   
   case 1001:
     printf("\nNome e sexo invalidos.");
   break;  
   
   case 1010:
     printf("\nData e sexo invalidos.");
   break; 
   
   case 1011:
     printf("\nNome, data e sexo invalidos.");
   break;    
   
   case 1100:
     printf("\nCPF e sexo invalidos.");
   break;
   
   case 1101:
     printf("\nNome, CPF e sexo invalidos.");
   break;
   
   case 1110:
     printf("\nData, CPF e sexo invalidos.");
   break;   
        
   case 1111:
   printf("\nNome, data, CPF e sexo invalidos.");
   break;
   
   default:
     printf("\nCadastro realizado!");
   }
		
return 0;
}

