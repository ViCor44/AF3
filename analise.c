#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

void AnalisaTexto(char *comando)
{
	int x, y, w, h;
	char *ordem;
	ordem = strdup(strtok(comando, " ,+"));
	x = atoi(strdup(strtok(NULL, " ,+")));
	y = atoi(strdup(strtok(NULL, " ,+")));
	w = atoi(strdup(strtok(NULL, " ,+")));
	h = atoi(strdup(strtok(NULL, " ,+")));
	
	if(strcmp(ordem, "create") == 0)
		CriarRetangulo(x, y, w, h);
}
