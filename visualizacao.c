#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

/* Função q configura o tamanho da tela e do buffer*/
void Configtela()
{
COORD outbuff;
outbuff.X = 150;
outbuff.Y = 45;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleScreenBufferSize(hConsole, outbuff);
Sleep(130);
SMALL_RECT windowSize = {0, 0, 149, 44}; 
SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
/* Cria uma linha para separar a insercao de comandos*/
void CriaLinha()
{
	int i;
	for(i= 1; i < 150; i++)
    {
		gotoxy(i, 3);
		printf("-");
	}    
}

/* Funcao para criar retangulos*/
void CriarRetangulo(int x, int y, int l, int h)
{	
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
}
