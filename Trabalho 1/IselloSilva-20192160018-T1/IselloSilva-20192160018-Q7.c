#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char velha[3][3];
char p1[30], p2[30];

void preencherJogo() {
    int i,j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            velha[i][j] = ' ';
        }
    }
}

int checagemCarac(char letra) {
    if(letra == 'X' || letra == '0')
        return 1;
    else
        return 0;
}

int posicaoCheca(int x, int y) {
    if(x >= 0 && x < 3 && y >= 0 && y < 3 ) {
        return 1;
    }
    else{
    	printf("\nCoordenada invalida!\n");
    	printf("\nDigite uma coordenada valida: \n");
    	return 0;
	}
    
}

int coordenadaVazia(int x, int y) {	
    if(velha[x][y] != 'X' && velha[x][y] != '0')
        return 1;
    else{
    	printf("\nCoordenada preenchida!\n");
    	return 0;
	}   
}

int checaLines() {
    int i, j, igual = 1;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            if(checagemCarac(velha[i][j]) && velha[i][j] == velha[i][j+1])
                igual++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}

int checaColunas() {
    int i, j, igual = 1;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            if(checagemCarac(velha[j][i]) && velha[j][i] == velha[j+1][i])
                igual++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}

int primeiraDiagonal() {
    int i, igual = 1;
    for(i = 0; i < 2; i++) {
        if(checagemCarac(velha[i][i]) && velha[i][i] == velha[i+1][i+1])
            igual++;
    }
    if(igual == 3)
        return 1;
    else
        return 0;
}

int segundaDiagonal() {
    int i, igual = 1;
    for(i = 0; i < 2; i++) {
        if(checagemCarac(velha[i][3-i-1]) && velha[i][3-i-1] == velha[i+1][3-i-2])
            igual++;
    }
    if(igual == 3)
        return 1;
    else
        return 0;
}

void game() {
    int lin, col;

    printf("\n\t    1  2  3\n");
    for(lin = 0; lin < 3; lin++) {
    	if(lin==0){
    		printf("\tA ");}
    	if(lin==1){
    		printf("\tB ");}    	
    	if(lin==2){
    		printf("\tC ");} 
    		
        for(col = 0; col < 3; col++) {
            if(checagemCarac(velha[lin][col])) {
                if(col < 2)
                    printf(" %c |", velha[lin][col]);
                else
                    printf(" %c ", velha[lin][col]);
            } else {
                if(col < 2)
                    printf("   |");
                else
                    printf("      \n");
            }
        }
        if(lin < 2)
            printf("\n\t   ---------\n");
    }
}

void executa() {
    int x, y, valida, jogadas = 0, ganhou = 0, ordem = 1, vez = 0;
    char l;

    do {
        do {
            game();
            
            
            
            fflush(stdin);
            printf("\nDigite a linha que deseja preencher: ");
            scanf("%c", &l);
            
            switch (l){
            	case 'A':
            		x=1;
            		break;
            	case 'a':
            		x=1;
            		break;            		
            	case 'B':
            		x=2;
            		break;
            	case 'b':
            		x=2;
            		break;						
            	case 'C':
            		x=3;
            		break;
            	case 'c':
            		x=3;
            		break;            		
            	default:
            		x=10;													
			}
			
			fflush(stdin);           
            printf("\nDigite a coluna que deseja preencher: ");
            scanf("%d", &y);
            x = x-1;
            y= y-1;
            valida = posicaoCheca(x, y);
            if(valida == 1)
                valida = valida + coordenadaVazia(x, y);
        } while(valida != 2);
        if(ordem == 1)
            velha[x][y] = 'X';
        else
            velha[x][y] = '0';
        jogadas++;
        ordem++;
        if(ordem == 3)
            ordem = 1;
        ganhou += checaLines();
        ganhou += checaColunas();
        ganhou += primeiraDiagonal();
        ganhou += segundaDiagonal();
    } while(ganhou == 0 && jogadas < 9);

    if(ganhou != 0) {
        game();
        if(ordem - 1 == 1)
            printf("\nO ganhador foi: %s", p1);
        else
            printf("\nO ganhador foi: %s", p2);
    } else
        printf("\nNinguém ganhou.\n");
}

int main() {

    int op;

    printf("Digite o nome do jogador 1: ");
    fgets(p1, 30, stdin);
    printf("Digite o nome do jogador 2: ");
    fgets(p2, 30, stdin);
    
    do {
        preencherJogo();
        executa();
        printf("\nJogar novamente?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &op);
    } while(op == 1);

    return 0;
}
