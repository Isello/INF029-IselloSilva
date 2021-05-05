// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de AnÃ¡lise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - LaboratÃ³rio de ProgramaÃ§Ã£o
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- OrientaÃ§Ãµes gerais -----
//  DescriÃ§Ã£o: esse arquivo deve conter as questÃµes do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questÃµes do trabalho

//  ----- Dados do Aluno -----
//  Nome: Isello Silva
//  email: isellovinicius@gmail.com
//  Matrícula: 20192160018
//  Semestre: 2021.1

//  Copyright Â© 2016 Renato Novais. All rights reserved.
// Ãšltima atualizaÃ§Ã£o: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>


/*
## funÃ§Ã£o utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## funÃ§Ã£o utilizada para testes  ##

 fatorial = fatorial de um nÃºmero
@objetivo
    calcular o fatorial de um nÃºmero
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //funÃ§Ã£o utilizada para testes
    int fat = 1;
    return fat;
}

int separarData(char *data, int vetor[]){
 	
	int mes, mes1;
	char vetMes[2];
	int contaMes=0;
	
	int ano, ano1;
	char vetAno[2];
	int contaAno=0;
	
	int dia, dia1;
	int i, j;
	char vetDia[2];
	int contaDias = 0;
	
	// Dia
	for(i = 0; data[i] != '/'; i++){
		vetDia[i] = data[i];
		contaDias++;}
		
	if(contaDias > 2 || contaDias <= 0){
		return 0;}
		
	char dias[contaDias];
	
	for(i = 0; i < contaDias; i++){
		dias[i] = vetDia[i];}	
		
	dia1 = atoi(dias);
	dia = dia1;
	
	// Mês
	j=0;
	for(i = contaDias+1; data[i] != '/'; i++){
		vetMes[j] = data[i];
		j++;
		contaMes++;}
		
	if(contaMes > 2 || contaMes <= 0){
		return 0;}
		
	char meses[contaMes];
	
	for(i = 0; i < contaMes; i++){
		meses[i] = vetMes[i];}	
		
	mes1 = atoi(meses);
	mes = mes1;	
	//printf("%d", mes);
	
	// Ano
	j=0;
	for(i = contaDias + contaMes +2; data[i] != '\0'; i++){
		vetAno[j] = data[i];
		j++;
		contaAno++;}
		
	if(contaAno > 4){
		return 0;}
		
	char anos[contaAno];
	
	for(i = 0; i < contaAno; i++){
		anos[i] = vetAno[i];}	
		
	ano1 = atoi(anos);
	ano = ano1;
	
	vetor[0]= dia;	
	vetor[1]= mes;
	vetor[2]= ano;	
 }

int q1(char *data){
	
	int mes, mes1;
	char vetMes[2];
	int contaMes=0;
	
	int ano, ano1;
	char vetAno[2];
	int contaAno=0;
	
	int dia, dia1;
	int i, j;
	char vetDia[2];
	int contaDias = 0;
	
	// Dia
	for(i = 0; data[i] != '/'; i++){
		vetDia[i] = data[i];
		contaDias++;}
		
	if(contaDias > 2 || contaDias <= 0){
		return 0;}
		
	char dias[contaDias];
	
	for(i = 0; i < contaDias; i++){
		dias[i] = vetDia[i];}	
		
	dia1 = atoi(dias);
	dia = dia1;
	
	// Mês
	j=0;
	for(i = contaDias+1; data[i] != '/'; i++){
		vetMes[j] = data[i];
		j++;
		contaMes++;}
		
	if(contaMes > 2 || contaMes <= 0){
		return 0;}
		
	char meses[contaMes];
	
	for(i = 0; i < contaMes; i++){
		meses[i] = vetMes[i];}	
		
	mes1 = atoi(meses);
	mes = mes1;	
	//printf("%d", mes);
	
	// Ano
	j=0;
	for(i = contaDias + contaMes +2; data[i] != '\0'; i++){
		vetAno[j] = data[i];
		j++;
		contaAno++;}
		
	if(contaAno > 4){
		return 0;}
		
	char anos[contaAno];
	
	for(i = 0; i < contaAno; i++){
		anos[i] = vetAno[i];}	
		
	ano1 = atoi(anos);
	ano = ano1;	
	//printf("%d", ano);	
	
	// Verificação se as datas sao validas
	if(ano>=1 && ano<=9999){
        if(mes>=1 && mes<=12){
            if((dia>=1 && dia<=31) && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12))
                return 1;
            else if((dia>=1 && dia<=30) && (mes==4 || mes==6 || mes==9 || mes==11))
                return 1;
            else if((dia>=1 && dia<=28) && (mes==2))
                return 1;
            else if(dia==29 && mes==2 && (ano%400==0 ||(ano%4==0 && ano%100!=0)))
                return 1;
            else
                return 0;
        }
        else{
            return 0;}
    }
    else{
        return 0;}  
}

int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{
	int vetorInicio[3];
	int vetorFinal[3];
	separarData( datainicial, vetorInicio);
	separarData( datafinal, vetorFinal);

	int diaInicial = vetorInicio[0];
	int mesInicial = vetorInicio[1];
	int anoInicial = vetorInicio[2];
	
	int diaFinal = vetorFinal[0];
	int mesFinal = vetorFinal[1];
	int anoFinal = vetorFinal[2];
	//printf("%d/%d/%d\n",diaFinal, mesFinal, anoFinal);
	
	if(anoInicial > anoFinal){
		return 4;}
	if(anoInicial == anoFinal && mesInicial>mesFinal){
		return 4;}	
	if(anoInicial == anoFinal && mesInicial == mesFinal && diaInicial>diaFinal){
		return 4;}	
		
    if (q1(datainicial) == 0)
        return 2;
    if (q1(datafinal) == 0)
        return 3;  
		
	int nDiasInicial=0;	
	int nDiasFinal=0;
		
	switch(mesInicial){
		case 1:
			nDiasInicial = diaInicial;
			break;
			
		case 2:
			nDiasInicial = 31 + diaInicial;
			break;
			
		case 3:
			if(anoInicial%400==0 ||(anoInicial%4==0 && anoInicial%100!=0)){
				nDiasInicial = 31 + 29 + diaInicial;
				break;
			}else{
				nDiasInicial = 31 + 28 + diaInicial;
				break;
			}
			
		case 4:
			if(anoInicial%400==0 ||(anoInicial%4==0 && anoInicial%100!=0)){
				nDiasInicial = 31 + 29 + 31 + diaInicial;
				break;
			}else{
				nDiasInicial = 31 + 28 + 31 + diaInicial;
				break;
			}
			
		case 5:
			if(anoInicial%400==0 ||(anoInicial%4==0 && anoInicial%100!=0)){
				nDiasInicial = 31 + 29 + 31 + 30 + diaInicial;
				break;
			}else{
				nDiasInicial = 31 + 28 + 31 + 30 + diaInicial;
				break;
			}
			
		case 6:
			if(anoInicial%400==0 ||(anoInicial%4==0 && anoInicial%100!=0)){
				nDiasInicial = 31 + 29 + 31 + 30 + 31 + diaInicial;
				break;
			}else{
				nDiasInicial = 31 + 28 + 31 + 30 + 31 + diaInicial;
				break;
			}	
			
		case 7:
			if(anoInicial%400==0 ||(anoInicial%4==0 && anoInicial%100!=0)){
				nDiasInicial = 31 + 29 + 31 + 30 + 31 + 30 + diaInicial;
				break;
			}else{
				nDiasInicial = 31 + 28 + 31 + 30 + 31 + 30 + diaInicial;
				break;
			}
			
		case 8:
			if(anoInicial%400==0 ||(anoInicial%4==0 && anoInicial%100!=0)){
				nDiasInicial = 31 + 29 + 31 + 30 + 31 + 30 + 31 + diaInicial;
				break;
			}else{
				nDiasInicial = 31 + 28 + 31 + 30 + 31 + 30 + 31 + diaInicial;
				break;
			}
			
		case 9:
			if(anoInicial%400==0 ||(anoInicial%4==0 && anoInicial%100!=0)){
				nDiasInicial = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + diaInicial;
				break;
			}else{
				nDiasInicial = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + diaInicial;
				break;
			}		
			
		case 10:
			if(anoInicial%400==0 ||(anoInicial%4==0 && anoInicial%100!=0)){
				nDiasInicial = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + diaInicial;
				break;
			}else{
				nDiasInicial = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + diaInicial;
				break;
			}
			
		case 11:
			if(anoInicial%400==0 ||(anoInicial%4==0 && anoInicial%100!=0)){
				nDiasInicial = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + diaInicial;
				break;
			}else{
				nDiasInicial = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + diaInicial;
				break;
			}
			
		case 12:
			if(anoInicial%400==0 ||(anoInicial%4==0 && anoInicial%100!=0)){
				nDiasInicial = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + diaInicial;
				break;
			}else{
				nDiasInicial = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + diaInicial;
				break;
			}						
	}
	
	switch(mesFinal){
		case 1:
			nDiasFinal = diaFinal;
			break;
			
		case 2:
			nDiasFinal = 31 + diaFinal;
			break;
			
		case 3:
			if(anoFinal%400==0 ||(anoFinal%4==0 && anoFinal%100!=0)){
				nDiasFinal = 31 + 29 + diaFinal;
				break;
			}else{
				nDiasFinal = 31 + 28 + diaFinal;
				break;
			}
			
		case 4:
			if(anoFinal%400==0 ||(anoFinal%4==0 && anoFinal%100!=0)){
				nDiasFinal = 31 + 29 + 31 + diaFinal;
				break;
			}else{
				nDiasFinal = 31 + 28 + 31 + diaFinal;
				break;
			}
			
		case 5:
			if(anoFinal%400==0 ||(anoFinal%4==0 && anoFinal%100!=0)){
				nDiasFinal = 31 + 29 + 31 + 30 + diaFinal;
				break;
			}else{
				nDiasFinal = 31 + 28 + 31 + 30 + diaFinal;
				break;
			}
			
		case 6:
			if(anoFinal%400==0 ||(anoFinal%4==0 && anoFinal%100!=0)){
				nDiasFinal = 31 + 29 + 31 + 30 + 31 + diaFinal;
				break;
			}else{
				nDiasFinal = 31 + 28 + 31 + 30 + 31 + diaFinal;
				break;
			}	
			
		case 7:
			if(anoFinal%400==0 ||(anoFinal%4==0 && anoFinal%100!=0)){
				nDiasFinal = 31 + 29 + 31 + 30 + 31 + 30 + diaFinal;
				break;
			}else{
				nDiasFinal = 31 + 28 + 31 + 30 + 31 + 30 + diaFinal;
				break;
			}
			
		case 8:
			if(anoFinal%400==0 ||(anoFinal%4==0 && anoFinal%100!=0)){
				nDiasFinal = 31 + 29 + 31 + 30 + 31 + 30 + 31 + diaFinal;
				break;
			}else{
				nDiasFinal = 31 + 28 + 31 + 30 + 31 + 30 + 31 + diaFinal;
				break;
			}
			
		case 9:
			if(anoFinal%400==0 ||(anoFinal%4==0 && anoFinal%100!=0)){
				nDiasFinal = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + diaFinal;
				break;
			}else{
				nDiasFinal = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + diaFinal;
				break;
			}		
			
		case 10:
			if(anoFinal%400==0 ||(anoFinal%4==0 && anoFinal%100!=0)){
				nDiasFinal = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + diaFinal;
				break;
			}else{
				nDiasFinal = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + diaFinal;
				break;
			}
			
		case 11:
			if(anoFinal%400==0 ||(anoFinal%4==0 && anoFinal%100!=0)){
				nDiasFinal = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + diaFinal;
				break;
			}else{
				nDiasFinal = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + diaFinal;
				break;
			}
			
		case 12:
			if(anoFinal%400==0 ||(anoFinal%4==0 && anoFinal%100!=0)){
				nDiasFinal = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + diaFinal;
				break;
			}else{
				nDiasFinal = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + diaFinal;
				break;
			}						
	}
	
	//printf("%d\n", nDiasInicial);
	//printf("%d\n", nDiasFinal);
	
	//calcule os dados e armazene nas trÃªs variÃ¡veis a seguir
    int nDias, nMeses, nAnos;
	nDias = 99;
    nMeses = 99;
    nAnos = 99;
	
	//printf("%d/%d/%d\n", diaInicial, mesInicial, anoInicial);	
	//printf("%d/%d/%d\n", diaFinal, mesFinal, anoFinal);
	
	int k = nDiasFinal-nDiasInicial;
	//printf("%d\n", k);
	
	if(diaFinal >= diaInicial && mesFinal>=mesInicial){
		nMeses = mesFinal-mesInicial;
		nDias = diaFinal-diaInicial;
		nAnos = anoFinal-anoInicial;}
		
	else if( k==30 && (mesInicial == 1 || mesInicial == 3 || mesInicial == 5 || mesInicial == 1 || mesInicial == 7 || mesInicial == 8 || mesInicial == 10 || mesInicial == 12)) {
		
		nMeses = mesFinal-mesInicial -1;
		nDias = k;
		nAnos = anoFinal-anoInicial;}	
		
	else if (k>30){
		nMeses = k/30;
		nDias = k%30;
		nAnos = anoFinal-anoInicial;}
		
	else if( mesInicial==2 && diaInicial==29 && mesFinal<=2 && mesInicial==2 && ((anoFinal%400==0 ||(anoFinal%4==0 && anoFinal%100!=0)))){

		nAnos = anoFinal-anoInicial-1;
		nDias = 31-abs(k);
		nMeses =11;
	}		
		
	else if( mesInicial==2 && diaInicial==29 && mesFinal<=2){
		nMeses = 0;
		nDias = k+1;
		nAnos = anoFinal-anoInicial;}	
				
	else{
		nMeses = 0;
		nDias = k;
		nAnos = anoFinal-anoInicial;}
		
	//printf("%d/%d/%d", nDias, nMeses, nAnos);

    /*mantenha o cÃ³digo abaixo, para salvar os dados em 
    nos parÃ¢metros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;
    //printf("%d\n", qtdAnos);
    //coloque o retorno correto
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se Ã© uma pesquisa Case Sensitive ou nÃ£o. Se isCaseSensitive = 1, a pesquisa deve considerar diferenÃ§as entre maiÃºsculos e minÃºsculos.
        Se isCaseSensitive != 1, a pesquisa nÃ£o deve  considerar diferenÃ§as entre maiÃºsculos e minÃºsculos.
 @saida
    Um nÃºmero n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = 0;
    int k, i, j, t=0;
    
    char vogalSem[]="aaaaaeeeeiiiiooooouuuuuAAAAAEEEEIIIIOOOOOUUUUU", vogalCom[]="áâãàäéêèëíîìïóõôòöúûùüÁÂÃÀÄÉÊÈËÍÎÌÏÓÕÔÒÖÚÛÙÜ"; 

    for (i=0;texto[i]!='\0';i++){
        for(j=0;j<sizeof(vogalCom);j++){
            if(vogalCom[j]==texto[i]) texto[i]=vogalSem[j];}
    }

    for(k = 0; texto[k] != '\0'; k++)
    	t++;

    if (isCaseSensitive != 1){
        for(i = 0; i < t; i++)
            if (texto[i] == c || texto[i] == tolower(c) || texto[i] == toupper(c))
                qtdOcorrencias++;}

    if (isCaseSensitive == 1){
        for (i = 0; i < t; i++)
            if (texto[i] == c)
                qtdOcorrencias++;}

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrÃªncias de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irÃ¡ guardar as posiÃ§Ãµes de inÃ­cio e fim de cada ocorrÃªncia da palavra (strBusca) no texto base (texto).
 @saida
    Um nÃºmero n >= 0 correspondente a quantidade de ocorrÃªncias encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saÃ­da correspondente. Por exemplo, se tiver uma Ãºnica ocorrÃªncia, a posiÃ§Ã£o 0 do vetor deve ser preenchido com o Ã­ndice de inÃ­cio do texto, e na posiÃ§Ã£o 1, deve ser preenchido com o Ã­ndice de fim da ocorrencias. Se tiver duas ocorrÃªncias, a segunda ocorrÃªncia serÃ¡ amazenado nas posiÃ§Ãµes 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como hÃ¡ uma ocorrÃªncia da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o Ã­ndice da posiÃ§Ã£o no texto deve comeÃ§ar ser contado a partir de 1.
        O retorno da funÃ§Ã£o, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	int qtdOcorrencias=0;
	int i=0;
	int j=0;
	int x=0;
	int tamTexto=0;
	int tamBusca=0;
	int conta=0;
	
	for(i = 0; i < 30; i++){
		posicoes[i]= -1; }
		
	for(i = 0; strTexto[i] != '\0'; i++){
	    tamTexto++;}
    for(i = 0; strBusca[i] != '\0'; i++){
    	tamBusca++;}
	for(i = 0; i < tamTexto; i++){
		conta=0;
		j=0;
	    while(strTexto[i] == strBusca[j]){
			conta++;
			j++;
			i++;
			if(conta==tamBusca){
				j=0;
				break;}
		}
		if(conta==tamBusca){
		    qtdOcorrencias++;
			posicoes[x]= i - (tamBusca-1);
			x++;
			posicoes[x]= i;
			x++;
			conta=0;}		
	}
	
    return qtdOcorrencias;
}

/*
 Q5 = inverte nÃºmero
 @objetivo
    Inverter nÃºmero inteiro
 @entrada
    uma int num.
 @saida
    NÃºmero invertido
 */

int q5(int num){
   int x=0;
   int i=1;
   
   while(i<=num){
       x*=10;
       x+=(num%(i*10)-num%i)/i;
       i*=10;
   }
   return x;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
	int qtdOcorrencias=0;
    int x;
    int base;
    x = numerobusca;
    base = 1;
    do{ base *= 10;
	} while ( x /= 10 );
    qtdOcorrencias = 0;
    do{ qtdOcorrencias += numerobusca == numerobase % base; 
	}while( numerobase /= 10 );
	return qtdOcorrencias;
}
