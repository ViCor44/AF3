#ifndef HEADER_H_
#define HEADER_H_

typedef struct sRets{
    	int x;
    	int y;
    	int l;
    	int h;
    	struct sRets *next ;
} Rets;


void init();
void Configtela();
void gotoxy(int x, int y);
void CriaLinha();
void CriarRetangulo(int x, int y, int l, int h, int modo);
void MoverEsquerda(int x, int y, int ml);
void MoverDireita(int x, int y, int mr);
void ApagarRetangulo(int x, int y);
void AnalisaTexto(char *comando);
void InserirComando();
void remove_scrollbar();
void gravity();
void release();

#endif /* HEADER_H_ */
