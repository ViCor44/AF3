#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* Função q configura o tamanho da tela e do buffer*/
void Configtela()
{
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
    	InserirComando();
}
