#ifndef HEADER_H_
#define HEADER_H_

void Configtela();
void gotoxy(int x, int y);
void CriaLinha();
void CriarRetangulo(int x, int y, int l, int h);
void MoverEsquerda(int x, int y, int ml);
void MoverDireita(int x, int y, int mr);
void ApagarRetangulo(int x, int y);
void AnalisaTexto(char *comando);
void InserirComando();
void remove_scrollbar();

#endif /* HEADER_H_ */
