#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "header.h"

void InserirComando()
{
	char comando[16];
	CriaLinha();
    gotoxy(2, 2);
    printf(" Insira comando: ");
	gets(comando);
	AnalisaTexto(comando);
}

void AnalisaTexto(char *comando)
{
	int x, y, w, h;//, ml, mr;
	char *ordem;
	ordem = strdup(strtok(comando, " ,+"));
	x = atoi(strdup(strtok(NULL, " ,+")));
	y = atoi(strdup(strtok(NULL, " ,+")));
	w = atoi(strdup(strtok(NULL, " ,+")));
	h = atoi(strdup(strtok(NULL, " ,+")));

	if(strcmp(ordem, "create") == 0){
		if(x >=1 && (x+w) <= 80 && y >=1 && (y+h) <= 25){
			y = (40-y-h)+1;
			CriarRetangulo(x, y, w, h, 0);
		}else{
			printf("\n  Coordenadas inválidas!\n");
			printf("Eixo do X tem de ser entre 1 e 80. Eixo do Y tem de ser entre 1 e 25.");
			system("@cls||clear");
			InserirComando();
		}
	}
	else if(strcmp(ordem, "moveleft") == 0)
		MoverEsquerda(x, y, w);
	else if(strcmp(ordem, "moveright") == 0)
		MoverDireita(x, y, w);
	else if(strcmp(ordem, "delete") == 0)
		ApagarRetangulo(x, y);
	else if(strcmp(ordem, "gravity") == 0){
		gravity();
		InserirComando();
	}
	else if(strcmp(ordem, "exit") == 0)
			return;
	else
	{
		printf("\n  Comando invalido!\n");
		printf("  Comandos aceites: create, moveleft, moveright, delete, exit\n");
		printf("  Formato: 'comando' x,y+l,a");
		//sleep(3);
		system("@cls||clear");
		InserirComando();
	}
}
