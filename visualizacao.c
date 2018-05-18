#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

static Rets *retangulos;

void init(){
	retangulos = NULL;
}

/* Função q configura o tamanho da tela e do buffer*/
void Configtela()
{
	system("CLS");

    HANDLE hConsoleOutput;
    COORD coord;
    CONSOLE_SCREEN_BUFFER_INFO  ConsoleInfo;
    HWND console = GetConsoleWindow();

    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOutput, &ConsoleInfo);
    coord.X = 10;
    coord.Y = 10;
    SetConsoleScreenBufferSize(hConsoleOutput, coord);

    MoveWindow(console, 1, 10, 1200, 600, TRUE);
    system("CLS");
} /* setScreenSize */

void remove_scrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
/* Cria uma linha para separar a insercao de comandos*/
void CriaLinha()
{
     int i;
     for(i= 1; i < 80; i++)
     {
    	 gotoxy(i, 3);
    	 printf("-");
     }
}

/* Funcao para adicionar props.retangulo na lista */
Rets* adicionaRet(int x, int y, int l, int h, Rets* rets){
	Rets *rets_aux = (Rets*)malloc(sizeof(Rets));
	rets_aux->x = x;
	rets_aux->y = y;
	rets_aux->l = l;
	rets_aux->h = h;
	rets_aux->next = rets;
	return rets_aux;
}


/* Funcao para criar retangulos*/
void CriarRetangulo(int x, int y, int l, int h, int modo)
{
	// Se em modo ADD - adicionar retangulo na lista
	if(modo == 0){
		int y0 = y;
		y = (40 - y - h) +1;
		retangulos = adicionaRet(x,y,l,h,retangulos);
		y = y0;
	}
    int i;
    gotoxy(x,y);
    printf("+");
    for(i= 1; i < l - 1; i++)
    {
    	gotoxy(x + i,y);
		printf("-");
    }
    gotoxy(x + l - 1,y);
    printf("+");
    for(i= 1; i < h - 1; i++)
    {
    	gotoxy(x + l -1, y + i);
    	printf("|");
    }
    gotoxy(x,y + h - 1);
    printf("+");
    for(i= 1; i < l - 1; i++)
    {
    	gotoxy(x + i, y + h -1);
    	printf("-");
    }
	for(i= 1; i < h - 1; i++)
    {
		gotoxy(x, y + i);
    	printf("|");
    }
	gotoxy(x + l - 1,y + h - 1);
    printf("+\n");
    // Se em modo ADD - funcao InserirComando
    if(modo == 0){
    	InserirComando();
    }
}

Rets* removeRets(int x, int y, int modo, Rets* rets){
	Rets *original = rets;
	Rets *rets_aux = NULL;
	while(rets != NULL){
		rets_aux = rets->next;
		int x_min = rets->x;
		int x_max = rets->x + rets->l;
		int y_min = rets->y;
		int y_max = rets->y + rets->h;
		if((x >= x_min) && (x <= x_max) && (y >= y_min) && (y <= y_max)){
			y_min = (40-y_min-(rets->h))+1;
			/* Remove ou substitui os chars do retangulo por blanks*/
			int i;
			gotoxy(x_min,y_min);
			printf(" ");
			for(i= 1; i < (rets->l) - 1; i++)
			{
				gotoxy(x_min + i,y_min);
				printf(" ");
			}
			gotoxy(x_min + (rets->l) - 1,y_min);
			printf(" ");
			for(i= 1; i < (rets->h) - 1; i++)
			{
				gotoxy(x_min + (rets->l) -1, y_min + i);
				printf(" ");
			}
			gotoxy(x_min,y_min + (rets->h) - 1);
			printf(" ");
			for(i= 1; i < (rets->l) - 1; i++)
			{
				gotoxy(x_min + i, y_min + (rets->h) -1);
				printf(" ");
			}
			for(i= 1; i < (rets->h) - 1; i++)
			{
				gotoxy(x_min, y_min + i);
				printf(" ");
			}
			gotoxy(x_min + (rets->l) - 1,y_min + (rets->h) - 1);
			printf(" \n");
			/* Se modo Delete, apaga retangulo da lista */
			if(modo == 1){
				rets->next = rets_aux->next;
			}
			break;
		}
		rets = rets_aux;
	}
	return original;
}

Rets* moverXRets(int x, int y, int v, int dir, Rets* rets){
	Rets *original = rets;
	Rets *rets_aux = NULL;
	while(rets != NULL){
		rets_aux = rets->next;
		int x_min = rets->x;
		int x_max = rets->x + rets->l;
		int y_min = rets->y;
		int y_max = rets->y + rets->h;
		int x_novo;
		if((x >= x_min) && (x <= x_max) && (y >= y_min) && (y <= y_max)){
			/* Primeiro apagsa o antigo */
			rets = removeRets(x_min, y_min, 0, rets);

			// Se Mover para Direita
			if(dir == 2){
				x_novo = x_min + v;
				// Limitar move p/direita no eixo do X maximo de 80 (X+largura)
				if((x_novo + rets->l) > 80){
					x_novo = (80 - rets->l);
				}
			}
			// Se Mover para Esquerda
			if(dir == 1){
				x_novo = x_min - v;
				// Limitar move p/esquerda no eixo do X maximo de 1
				if(x_novo < 1){
					x_novo = 1;
				}
			}
			rets->x = x_novo;

			/* Desenha */
			y_min = (40-y_min-(rets->h))+1;
			printf("x=%d y=%d l=%d h=%d",(x_novo),(y_min),(rets->l),(rets->h));
			CriarRetangulo(x_novo, y_min, rets->l, rets->h, 1);

			break;
		}
		rets = rets_aux;
	}
	return original;
}


void MoverEsquerda(int x, int y, int ml)
{
	retangulos = moverXRets(x, y, ml, 1,retangulos);
	InserirComando();
}

void MoverDireita(int x, int y, int mr)
{
	retangulos = moverXRets(x, y, mr, 2,retangulos);
	InserirComando();
}

void ApagarRetangulo(int x, int y)
{
	retangulos = removeRets(x, y, 1, retangulos);
	InserirComando();
}

void aplicarGravidade(Rets* rets){
	Rets *rets_aux = NULL;
	while(rets != NULL){
		rets_aux = rets->next;
		/* Primeiro apaga o antigo */
		rets = removeRets(rets->x, rets->y, 0, rets);
		// Mover p/baixo 1 posicao ate ground-zero ou Y=1
		if((rets->y)-1 >= 1){
			rets->y = rets->y - 1;
		}else{
			rets->y = 1;
		}
		/* Desenha */
		int y = (40-(rets->y)-(rets->h))+1;
		CriarRetangulo(rets->x, y, rets->l, rets->h, 1);

		rets = rets_aux;
	}
}

void gravity(){
	aplicarGravidade(retangulos);
}

void release(){
	free(retangulos);
}
