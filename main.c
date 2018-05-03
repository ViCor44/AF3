#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

void configtela()//função q configura o tamanho da tela e do buffer
{
COORD outbuff;
outbuff.X = 150; // tem que ser 1 maior que o tamanho X
outbuff.Y = 45; // tem que ser 1 maior que o tamanho Y
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleScreenBufferSize(hConsole, outbuff);
Sleep(130);
SMALL_RECT windowSize = {0, 0, 149, 44}; 
SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void CriaLinha()
{
	int i;
	for(i= 1; i < 150; i++)
    {
		gotoxy(i, 44);
		printf("-");
	}    
}

void CriarRetangulo(int x, int y, int l, int h)
{	
	int i;
	system("@cls||clear");
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
    sleep(1);
}

int main(void){
	int i;
	int x, y, l, h;
	POINT p;
	
    configtela();
    CriaLinha();
    gotoxy(2, 45);
	scanf("%d %d %d %d", &x, &y, &l, &h);
	i = 0;
	//do
	//{
		//y = y + i;		
		CriarRetangulo(x, y, l, h);
		//i++;		  
	//}while(i < 5 || y + h <= 45);
	/*for(i = 0; i < 10000; i++)
	{
	GetCursorPos(&p);
	printf("%d / %d", p.x, p.y);
	system("@cls||clear");
	}*/
	
    system("pause >nul");
    return 0;
}
