#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct 
{
    char nome[50];
    char dataNascimento[11];
    char CPF[12];
    int matricula;
    int status;
    char sexo[1];
}aluno;

typedef struct 
{
    char nome[50];
    char dataNascimento[11];
    char CPF[12];
    int matricula;
    int status;
    char sexo[1];
}professor;

typedef struct{
   char nome[100];
   int codigo;
   int semestre;
   professor prof;
   int status;
}disciplina;


void addAluno(aluno alunosCadastrados[], aluno novoAluno, int *nextMatAluno){
	
	int marcador = *nextMatAluno;
	
	alunosCadastrados[marcador].matricula = 1 + marcador;
    alunosCadastrados[marcador].status = 1; 
	strcpy(alunosCadastrados[marcador].CPF, novoAluno.CPF);
	strcpy(alunosCadastrados[marcador].nome, novoAluno.nome);
    strcpy(alunosCadastrados[marcador].dataNascimento, novoAluno.dataNascimento);
    strcpy(alunosCadastrados[marcador].sexo, novoAluno.sexo);
	
	printf("\nAluno adicionado.\n");
	marcador++;
	*nextMatAluno = marcador;
}

void attNomeAluno(aluno alunosCadastrados[], aluno attAluno, int matAluno){
	int i = matAluno-1;
	strcpy(alunosCadastrados[i].nome, attAluno.nome);
	printf("\nAluno atualizado.\n");}

void attSexoAluno(aluno alunosCadastrados[], aluno attAluno, int matAluno){
	int i = matAluno-1;
	strcpy(alunosCadastrados[i].sexo, attAluno.sexo);
	printf("\nAluno atualizado.\n");}

void listarAlunos(int nextMatAluno, aluno alunosCadastrados[]){
    int i = 0;
    for(i=0;i<nextMatAluno;i++){

        if(alunosCadastrados[i].status == 1){

            printf("\nNome: %s",alunosCadastrados[i].nome);
            printf("\nMatricula: %d",alunosCadastrados[i].matricula);
            printf("\nSexo: %s",alunosCadastrados[i].sexo);
            printf("\nData de nascimento: %s",alunosCadastrados[i].dataNascimento);
            printf("\nCPF: %s\n",alunosCadastrados[i].CPF);

        }
    }
}

int excluirAluno(aluno alunosCadastrados[], int nextMatAluno, int matAluno){
    int i,X;
    int atualiza = nextMatAluno;
    int opera= atualiza;
    for(i=0;i<opera;i++){

        if(alunosCadastrados[i].status == 1 && alunosCadastrados[i].matricula == matAluno){

            alunosCadastrados[i].status = 0;
            X++;
        }
    }
    if(X <= 0){
        return -1;}
	else{
		return 1;}
}

void primeiroAluno(aluno alunosCadastrados[]){
	
    alunosCadastrados[0].matricula = 1 ;
	strcpy(alunosCadastrados[0].nome,"Isello Silva");
    strcpy(alunosCadastrados[0].dataNascimento,"02/07/1991");
    strcpy(alunosCadastrados[0].sexo,"M");
    strcpy(alunosCadastrados[0].CPF,"58985882058");
    alunosCadastrados[0].status = 1;}  
	
void primeiroProfessor(professor professoresCadastrados[]){
	// 
	
    professoresCadastrados[0].matricula = 1 ;
	strcpy(professoresCadastrados[0].nome,"Renato Novais");
    strcpy(professoresCadastrados[0].dataNascimento,"04/09/1981");
    strcpy(professoresCadastrados[0].sexo,"M");
    strcpy(professoresCadastrados[0].CPF,"98985882052");
    professoresCadastrados[0].status = 1;}
	  
void addProfessor(professor professoresCadastrados[], professor novoProfessor, int *nextMatProfessor ){
	
	int marcador = *nextMatProfessor;
	int matInicial = 1;
	
	professoresCadastrados[marcador].matricula = matInicial + marcador;
    professoresCadastrados[marcador].status = 1; 
	strcpy(professoresCadastrados[marcador].CPF, novoProfessor.CPF);
	strcpy(professoresCadastrados[marcador].nome, novoProfessor.nome);
    strcpy(professoresCadastrados[marcador].dataNascimento, novoProfessor.dataNascimento);
    strcpy(professoresCadastrados[marcador].sexo, novoProfessor.sexo);
	
	printf("\nProfessor adicionado.\n");
	marcador++;
	*nextMatProfessor = marcador;
}

void attNomeProfessor(professor professoresCadastrados[], professor attProfessor, int matProfessor){
	int i = matProfessor-1;
	strcpy(professoresCadastrados[i].nome, attProfessor.nome);
	printf("\nProfessor atualizado.\n");}

void attSexoProfessor(professor professoresCadastrados[], professor attProfessor, int matProfessor){
	int i = matProfessor-1;
	strcpy(professoresCadastrados[i].sexo, attProfessor.sexo);
	printf("\nProfessor atualizado.\n");}

void listarProfessores(professor professoresCadastrados[]){

    int i = 0;
    for(i=0;i<=999;i++){

        if(professoresCadastrados[i].status == 1){

            printf("\nNome: %s",professoresCadastrados[i].nome);
            printf("\nMatricula: %d",professoresCadastrados[i].matricula);
            printf("\nSexo: %s",professoresCadastrados[i].sexo);
            printf("\nData de nascimento: %s",professoresCadastrados[i].dataNascimento);
            printf("\nCPF: %s\n",professoresCadastrados[i].CPF);
        }
    }
}

int excluirProfessor(professor professoresCadastrados[], int nextMatProfessor, int matProfessor){
    int i,X;
    int atualiza = nextMatProfessor;
    int opera= atualiza;
    for(i=0;i<opera;i++){
        if(professoresCadastrados[i].status == 1 && professoresCadastrados[i].matricula == matProfessor){
            professoresCadastrados[i].status = 0;
            X++;
        }
    }
    if(X <= 0){
        return -1;}
	else{
		return 1;}
}
	  
void primeiraDisciplina(disciplina disciplinasCadastradas[]){

    disciplinasCadastradas[0].codigo = 1 ;
	strcpy(disciplinasCadastradas[0].nome,"Laboratorio de Programacao");
	disciplinasCadastradas[0].semestre = 2;
    disciplinasCadastradas[0].status = 1;
    strcpy(disciplinasCadastradas[0].prof.nome,"Renato Novais");
	disciplinasCadastradas[0].prof.matricula = 1;}
	
void listarDisciplinas(disciplina disciplinasCadastradas[]){
    int i = 0;
    for(i=0;i<999;i++){
        if(disciplinasCadastradas[i].status == 1){
        	printf("\nNome: %s",disciplinasCadastradas[i].nome);
            printf("\nCodigo: %d",disciplinasCadastradas[i].codigo);
            printf("\nSemestre: %d",disciplinasCadastradas[i].semestre);
            printf("\nNome do professor: %s",disciplinasCadastradas[i].prof.nome);
            printf("\nMatricula do professor: %d\n",disciplinasCadastradas[i].prof.matricula);}
    }
}	

void addDisciplina(disciplina novaDisciplina, disciplina disciplinasCadastradas[], int *nextCodDisciplina, professor professoresCadastrados[]){
	int e = novaDisciplina.prof.matricula;
	int i, x;
	int marcador = *nextCodDisciplina;
	int codInicial = 1;
	for (i=0 ; i<1000 ; i++){
		if (i == e){
		x = 1;
		break;}
		else{
		x=0;}}
	
	if(x==0){printf("Professor nao cadastrado.");}
	
	else{disciplinasCadastradas[marcador].codigo = codInicial + marcador;
		strcpy(disciplinasCadastradas[marcador].nome, novaDisciplina.nome);
		strcpy(disciplinasCadastradas[marcador].prof.nome, professoresCadastrados[e-1].nome);
		professoresCadastrados[1-i].status=1;
		disciplinasCadastradas[marcador].prof.matricula = i;
		disciplinasCadastradas[marcador].semestre = novaDisciplina.semestre;
		disciplinasCadastradas[marcador].status = 1;
		printf("\nDisciplina adicionada.\n");
		marcador++;
		*nextCodDisciplina = marcador;}
}

void attProfDisciplina(professor professoresCadastrados[], disciplina disciplinasCadastradas[], int codDisciplina, int matProfessor){
	int x=-1;
	int d = codDisciplina - 1;
	int i;
	
	for (i=0 ; i<1000 ; i++){
		if (professoresCadastrados[i].matricula == matProfessor){
		x = 1;
		break;}
		else{
		x=0;}}
	
	if(x==0){printf("Professor nao cadastrado.");}
	else{
		strcpy(disciplinasCadastradas[d].prof.nome, professoresCadastrados[matProfessor-1].nome);
		professoresCadastrados[1-i].status=1;
		disciplinasCadastradas[d].prof.matricula = matProfessor;
		disciplinasCadastradas[d].status = 1;
		printf("\nDisciplina atualizada.\n");
		}
}


int excluirDisciplina(disciplina disciplinasCadastradas[], int nextCodDisciplina, int codDisciplina){
    int i,X;
    int atualiza = nextCodDisciplina;
    int opera= atualiza;
    for(i=0;i<opera;i++){
        if(disciplinasCadastradas[i].status == 1 && disciplinasCadastradas[i].codigo == codDisciplina){
            disciplinasCadastradas[i].status = 0;
            X++;
        }
    }
    if(X <= 0){
        return -1;}
	else{
		return 1;}
}

void attSemestreDisciplina(disciplina disciplinasCadastradas[], int codDisciplina, int sd){
	int i = codDisciplina-1;
	disciplinasCadastradas[i].semestre= sd;
	printf("\nDisciplina atualizada.\n");}

main(){
	int menu1=-1;
	
	aluno novoAluno;
	aluno attAluno;
	int menuAluno=-1;
	aluno alunosCadastrados[10000];
	primeiroAluno(alunosCadastrados);
	int nextMatAluno = 1;
	int matAluno;
	
	
	professor professoresCadastrados[9999];
	primeiroProfessor(professoresCadastrados);
	professor novoProfessor;
	professor attProfessor;
	int menuProfessor=-1;
	int nextMatProfessor = 1;
	int matProfessor;
	
	
	int menuDisciplina=-1;
	disciplina disciplinasCadastradas[999];
	disciplina novaDisciplina;
	disciplina attDisciplina;
	primeiraDisciplina(disciplinasCadastradas);
	int nextCodDisciplina= 1;
	int codDisciplina;

    
	while(menu1 != 0){
		printf("\n### Projeto Escola ###\n");
		printf("\nDigite 1 para gerenciar Alunos\n");
		printf("Digite 2 para gerenciar Professores\n");
		printf("Digite 3 para gerenciar Disciplinas\n");
		printf("Digite 9 para limpar a tela do programa\n");
		printf("Digite 0 para sair do programa\n");
		scanf("%d",&menu1);
		
		switch(menu1){
		
		case 1:  
				printf("\nDigite 1 para inserir um aluno\n");
		        printf("Digite 2 para excluir um aluno\n");
	      	    printf("Digite 3 para para atualizar um aluno\n");
	      	    printf("Digite 4 para listar os alunos\n");
		        printf("Digite 0 para voltar\n");
		        scanf("%d",&menuAluno);
		        
		        if(menuAluno==1){ // Adicionar alunos
		        	printf("\nDigite o nome do aluno: ");
					fflush(stdin);
					scanf("%[^\n]", novoAluno.nome);
					
		        	printf("\nDigite o sexo do aluno: ");
					scanf("%s", novoAluno.sexo);		
					
		        	printf("\nDigite a data de nascimento do aluno (Dia/Mes/Ano): ");
					scanf("%s", novoAluno.dataNascimento);
					
					printf("\nDigite o CPF do aluno: ");	
					scanf("%s", novoAluno.CPF);	
					
					addAluno(alunosCadastrados, novoAluno, &nextMatAluno);}
				
				else if(menuAluno==2){ // Excluir alunos
					printf("\nDigite a matricula do aluno que deseja excluir: ");
                    scanf("%d", &matAluno);
                    
                    int checaExclusaoAluno = excluirAluno(alunosCadastrados, nextMatAluno, matAluno);
                    
                    switch(checaExclusaoAluno){
                    case 1:
                    	printf("\nAluno removido.\n");
                    break;
                    	
                    default:
						printf("\nMatricula nao localizada.\n");
					break;
                    }
                }
                
                else if(menuAluno==3){
                	
                	printf("Digite a matricula do aluno que deseja atualizar:");
                	scanf("%d", &matAluno);
                	
                	int nomeOUsexoAluno;
                	printf("Digite 1 para atualizar o nome ou 2 para atualizar o sexo do aluno: \n");
                	scanf("%d", &nomeOUsexoAluno);
                	
                    switch(nomeOUsexoAluno){
                    	
                    case 1:
		        	printf("\nDigite o nome atualizado do aluno: ");
					fflush(stdin);
					scanf("%[^\n]", attAluno.nome);
                    attNomeAluno(alunosCadastrados, attAluno, matAluno);
                    break;
                    	
                    case 2:
		        	printf("\nDigite o sexo atualizado do aluno: ");
					fflush(stdin);
					scanf("%s", &attAluno.sexo);
                    attSexoAluno(alunosCadastrados, attAluno, matAluno);						
					break;
                    }                	
				}
                
				else if(menuAluno==4){  // Listar alunos
					listarAlunos(nextMatAluno, alunosCadastrados);
				}				
		break;
		
		case 2:
				printf("\nDigite 1 para inserir um professor\n");
		        printf("Digite 2 para excluir um professor\n");
	      	    printf("Digite 3 para para atualizar um professor\n");
	      	    printf("Digite 4 para listar os professores\n");
		        printf("Digite 0 para voltar\n");
		        scanf("%d",&menuProfessor);
	
		        if(menuProfessor==1){ // Adicionar professores
		        	printf("\nDigite o nome do professor: ");
					fflush(stdin);
					scanf("%[^\n]", novoProfessor.nome);
					
		        	printf("\nDigite o sexo do professor: ");
					scanf("%s", novoProfessor.sexo);		
					
		        	printf("\nDigite a data de nascimento do professor (Dia/Mes/Ano): ");
					scanf("%s", novoProfessor.dataNascimento);
					
					printf("\nDigite o CPF do professor: ");	
					scanf("%s", novoProfessor.CPF);	
					
					addProfessor(professoresCadastrados, novoProfessor, &nextMatProfessor);}
				
				else if(menuProfessor==2){ // Excluir professores
					printf("\nDigite a matricula do professor que deseja excluir: ");
                    scanf("%d", &matProfessor);
                    
                    int checaExclusaoProfessor = excluirProfessor(professoresCadastrados, nextMatProfessor, matProfessor);
                    
                    switch(checaExclusaoProfessor){
                    case 1:
                    	printf("\nProfessor removido.\n");
                    break;
                    	
                    default:
						printf("\nMatricula nao localizada.\n");
					break;
                    }
                }
                
                else if(menuProfessor==3){
                	
                	printf("Digite a matricula do professor que deseja atualizar:");
                	scanf("%d", &matProfessor);
                	
                	int nomeOUsexoProfessor;
                	printf("Digite 1 para atualizar o nome ou 2 para atualizar o sexo do professor: \n");
                	scanf("%d", &nomeOUsexoProfessor);
                	
                    switch(nomeOUsexoProfessor){
                    	
                    case 1:
		        	printf("\nDigite o nome atualizado do professor: ");
					fflush(stdin);
					scanf("%[^\n]", attProfessor.nome);
                    attNomeProfessor(professoresCadastrados, attProfessor, matProfessor);
                    break;
                    	
                    case 2:
		        	printf("\nDigite o sexo atualizado do professor: ");
					fflush(stdin);
					scanf("%s", &attProfessor.sexo);
                    attSexoProfessor(professoresCadastrados, attProfessor, matProfessor);						
					break;
                    }                	
				}
                
				else if(menuProfessor==4){  // Listar professores
					listarProfessores(professoresCadastrados);}						
		break;
		
		case 3: 
				printf("\nDigite 1 para inserir disciplina\n");
		        printf("Digite 2 para excluir disciplina\n");
	      	    printf("Digite 3 para para atualizar disciplina\n");
	      	    printf("Digite 4 para para listar disciplinas\n");
		        printf("Digite 0 para sair\n");
		        scanf("%d",&menuDisciplina);
		        
				if(menuDisciplina==1){ // Adicionar disciplinas
				
					printf("\nDigite o nome da disciplina: ");
					fflush(stdin);
					scanf("%[^\n]", novaDisciplina.nome);
					
		        	printf("\nDigite o semestre da disciplina: ");
					scanf("%d", &novaDisciplina.semestre);		
					
					printf("\nDigite a matricula do professor da disciplina: \n");
					scanf("%d", &novaDisciplina.prof.matricula);
					
					addDisciplina(novaDisciplina, disciplinasCadastradas, &nextCodDisciplina, professoresCadastrados);
				}
				
				else if(menuDisciplina==2){ // Excluir disciplinas
				
					printf("\nDigite o codigo da disciplina que deseja excluir: ");
                    scanf("%d", &codDisciplina);
                    
                    int checaExclusaoDisciplina = excluirDisciplina(disciplinasCadastradas, nextCodDisciplina, codDisciplina);
                    
                    switch(checaExclusaoDisciplina){
                    case 1:
                    	printf("\nDisciplina removida.\n");
                    break;
                    	
                    default:
						printf("\nCodigo nao localizado.\n");
					break;
                    }
                }
                
				else if(menuDisciplina==3){
					printf("Digite o codigo da disciplina que deseja atualizar: \n");
                	scanf("%d", &codDisciplina);
                	int sd;
                	int semestreOUprofessor=-1;
                	printf("Digite 1 para atualizar o semestre da disciplina ou digite 2 para atualizar o professor da disciplina: \n");
                	scanf("%d", &semestreOUprofessor);

                    switch(semestreOUprofessor){
                    	
                    case 1:
		        	printf("\nDigite o semestre atualizado da disciplina: \n");
					scanf("%d", &sd);
                    attSemestreDisciplina(disciplinasCadastradas, codDisciplina, sd);
                    break;
                    	
                    case 2:
		        	printf("\nDigite a matricula do novo professor da disciplina: \n");
					scanf("%d", &matProfessor);
                    attProfDisciplina(professoresCadastrados, disciplinasCadastradas, codDisciplina, matProfessor);						
					break;
                    }                	
                	
				}             
				
				else if(menuDisciplina==4){ // Listar disciplinas
					listarDisciplinas(disciplinasCadastradas);}
					
				
					        
		break;
		
		case 9: 
				system("cls");	        
		break;		
    	}  
	}	
return 0;
}





