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
	int x, y, w, h, ml, mr;
	char *ordem;
	ordem = strdup(strtok(comando, " ,+"));
	x = atoi(strdup(strtok(NULL, " ,+")));
	y = atoi(strdup(strtok(NULL, " ,+")));
	w = atoi(strdup(strtok(NULL, " ,+")));
	h = atoi(strdup(strtok(NULL, " ,+")));
	y = (40-y-h)+1;
	
	if(ordem != "create" || ordem != "moveleft" || ordem != "moveright" || ordem != "delete")
	{
		printf("\n  Comando invalido!\n");
		printf("  Comandos aceites: create, moveleft, moveright, delete\n");
		printf("  Formato: 'comando' x,y+l,a");
		sleep(3);
		system("@cls||clear");
		InserirComando();
	}
	if(strcmp(ordem, "create") == 0)
		CriarRetangulo(x, y, w, h);
	if(strcmp(ordem, "moveleft") == 0)
		MoverEsquerda(x, y, ml);
	if(strcmp(ordem, "moveright") == 0)
		MoverDireita(x, y, mr);
	if(strcmp(ordem, "delete") == 0)
		ApagarRetangulo(x, y);
}
