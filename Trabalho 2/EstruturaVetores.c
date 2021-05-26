#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int ***estruturaPrincipal;

void dobrar(int *x)
{

    *x = *x * 2;
}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Retorno (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho){

	int x = tamanho + 1;
	if(posicao<1 || posicao>10){
		return POSICAO_INVALIDA;
	}
	else{
		if (estruturaPrincipal[posicao]!=NULL){
			return JA_TEM_ESTRUTURA_AUXILIAR;
		}
		else{
			if (tamanho<1){
				return TAMANHO_INVALIDO;
			}
			else{
				estruturaPrincipal[posicao] = malloc(x*sizeof(int *));
				int i;
				for (i = 0; i < x; i++){
					estruturaPrincipal[posicao][i] = NULL;
				}
				if (estruturaPrincipal[posicao]==NULL){
					return SEM_ESPACO_DE_MEMORIA;
				}
				else{
					estruturaPrincipal[posicao][0] = malloc(sizeof(int));
					*estruturaPrincipal[posicao][0] = x-1;
					return SUCESSO;
				}
			}
		}
	}
}


/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/


int inserirNumeroEmEstrutura(int posicao, int valor){
	
	if(posicao<1 || posicao>10){
		return POSICAO_INVALIDA;}
	
	else if(estruturaPrincipal[posicao] == NULL){
		return SEM_ESTRUTURA_AUXILIAR;}

	for (int i = 1; i <= *(estruturaPrincipal[posicao][0]); i += 1) {
        if (estruturaPrincipal[posicao][i] == NULL) {
            estruturaPrincipal[posicao][i] = malloc(sizeof(int));
            *(estruturaPrincipal[posicao][i]) = valor;
            return SUCESSO;}
    }
    return SEM_ESPACO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Retorno (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
	
	if(posicao<1 || posicao>10){
		return POSICAO_INVALIDA;}
	
	else if(estruturaPrincipal[posicao] == NULL){
		return SEM_ESTRUTURA_AUXILIAR;}
		
	int i;	
    for (i = *(estruturaPrincipal[posicao][0]); i >= 1; i--) {
        if (estruturaPrincipal[posicao][i] != NULL) {
        	estruturaPrincipal[posicao][i] = NULL;
            return SUCESSO;}
    }
    
    return ESTRUTURA_AUXILIAR_VAZIA;
}


/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
	
	int contou = 0;
    int achou = 0; 
    
	if(posicao<1 || posicao>10){
		return POSICAO_INVALIDA;
	}
    
    else if (estruturaPrincipal[posicao]==NULL){
            return SEM_ESTRUTURA_AUXILIAR;
    }
	

    else{
    	int i;
    	for (i = 1; *estruturaPrincipal[posicao][0] >= i ; i++){
    		if (estruturaPrincipal[posicao][i] != NULL){
    			contou = 1;
    			if (*estruturaPrincipal[posicao][i] == valor){
                    achou++;
                    estruturaPrincipal[posicao][i] = NULL;
                    return SUCESSO;
                    break;
                }
            }
        }
    }
	
    if (contou == 0){
    	return ESTRUTURA_AUXILIAR_VAZIA;
    }
    if (achou==0){
    	return NUMERO_INEXISTENTE;
    }       
}


// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
	if (posicao < 0 || posicao > TAM)
	    return POSICAO_INVALIDA;
	else
	    return SUCESSO;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

/*
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	
	if(posicao<1 || posicao>10){
		return POSICAO_INVALIDA;}
    
    else if (estruturaPrincipal[posicao]==NULL){
        return SEM_ESTRUTURA_AUXILIAR;}
     
	int i;
	int j=0; 
	int x=0;
	
	for( i=0; estruturaPrincipal[posicao][i] != NULL; i++){
		x++;
	} 
	
	for ( i=0; i<=x; i++) {
        vetorAux[j] = *(estruturaPrincipal[posicao][i]);
        j++;
    }

    return SUCESSO;
}*/

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	
	if(posicao<1 || posicao>10){
		return POSICAO_INVALIDA;}
    
    else if (estruturaPrincipal[posicao]==NULL){
        return SEM_ESTRUTURA_AUXILIAR;}
     
	int i;
	int j=0; 
	int x=0;
	
	for( i=0; estruturaPrincipal[posicao][i] != NULL; i++){
		x++;
	} 
	
	x=x-1;
	
	//(i = 1; j < x && i <= *(estruturaPrincipal[posicao][0]) && estruturaPrincipal[posicao][i]; i++)
	
    for(i = 1; j < x; i++){
        vetorAux[j] = *(estruturaPrincipal[posicao][i]);
        j++;
    }

    return SUCESSO;
}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	
	if(posicao<1 || posicao>10){
		return POSICAO_INVALIDA;}
    
    else if (estruturaPrincipal[posicao]==NULL){
        return SEM_ESTRUTURA_AUXILIAR;}
     
	int i;
	int j=0; 
	int x=0;
	
	for( i=0; estruturaPrincipal[posicao][i] != NULL; i++){
		x++;} 
	
	x=x-1;

    for(i = 1; j < x; i++){
        vetorAux[j] = *(estruturaPrincipal[posicao][i]);
        j++;}

    int aux;
    
    for(i=0; i<x; i++){
    	for(j=i+1; j<x; j++){
    		if(vetorAux[i]>vetorAux[j]){
    			aux=vetorAux[i];
    			vetorAux[i]=vetorAux[j];
    			vetorAux[j]=aux;
			}
		}
	}
    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
	int tamVetor = 2;
    int j = 0;
    for (int i = 1; j < tamVetor && i <= TAM; i += 1) {
        if (estruturaPrincipal[i]) {
            for (int k = 1; j < tamVetor && k <= *(estruturaPrincipal[i][0]) && estruturaPrincipal[i][k]; k += 1) {
                vetorAux[j] = *(estruturaPrincipal[i][k]);
                j += 1;
            }
        }
    }
    return j > 0 ? SUCESSO : TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
}

/*
Objetivo: retorna os n�meros ordenados de todas as estruturas auxiliares.
os n�meros devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posi��o 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - N�o tem estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
}



/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
	if(posicao<1 || posicao>10){
		return POSICAO_INVALIDA;}
    
    else if (estruturaPrincipal[posicao]==NULL){
        return SEM_ESTRUTURA_AUXILIAR;}
	//
}


/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
	if(posicao<1 || posicao>10){
		return POSICAO_INVALIDA;}
    
    else if (estruturaPrincipal[posicao]==NULL){
        return SEM_ESTRUTURA_AUXILIAR;}
	//
}


/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote(){

}


/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]){

}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio){

}


// Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

void inicializar(){
	estruturaPrincipal = malloc(TAM*sizeof(int **));
	int i;
	for(i = 0; i < TAM;i++){
		estruturaPrincipal[i] = NULL;
	}	
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar(){}

