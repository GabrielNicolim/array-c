#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <locale.h>

void init_menu();
int navegate_menu(int start, int end, int p);
void close();
void textcolor(int color);
void gotoxy(int x, int y);
void cursor (int x);


int main() {
	setlocale(LC_ALL, "Portuguese");

    init_menu();

    return 0;
}

void init_menu()
{
    gotoxy(30, 8);  printf("Mostrar os elementos");
    gotoxy(30, 10); printf("Trocar os elementos da linha X pela linha Y");
    gotoxy(30, 12); printf("Trocar os elementos da coluna X pela coluna Y");
    gotoxy(30, 14); printf("Troque os elementos da diagonal principal com a diagonal secundária");
    gotoxy(30, 16); printf("Verificar se uma matriz é simétrica");
    gotoxy(30, 18); printf("Verificar se uma matriz é um quadrado mágico");
    gotoxy(30, 20); printf("Verificar se uma matriz é quadrado latino");
    gotoxy(30, 22); printf("Verificar se uma matriz é matriz de permutação");
    gotoxy(30, 24); printf("Sair");

    int escolha = navegate_menu(8, 24, 28);

    switch(escolha){
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
        	close();
            break;
    }

    return;
}

int navegate_menu(int start, int end, int p)
{
    cursor(0);

    int aux = start;
    int input;

    do{
        gotoxy(p,aux); printf("%c", 62);	//posição inicial da seta

        fflush(stdin);

        input = getch();

        gotoxy(p,aux); printf(" ");

        switch(input){
            case 72: // Seta para cima
                aux -= 2;

                if(aux < start) aux  = end;

                gotoxy(p,aux);printf("%c", 62);
                break;

            case 80: // Seta para baixo
                aux+=2;

                if(aux > end) aux = start;

                gotoxy(p,aux);printf("%c", 62);
                break;
            case 13:
                return (aux - start)/2; // Retorna o valor da opção seleciona => inicia em 0
                break;
        }
    }while(1);
}

void close() // Finaliza a execução do programa
{
	system("cls");

	gotoxy(45, 15); printf("Obrigado por utilizar nosso programa!");
	
	textcolor(0); gotoxy(80, 34); // Esconde mensagem de encerramento
	
	exit(1);
}

void textcolor(int color) // Define a cor do texto
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0xf0) | color);
}

void gotoxy(int x, int y)   // Move o cursor para a coluna e linha desejada
{
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void cursor (int show) // Define se o cursor ira aparecer sim(1) ou não(0)
{
    switch (show) {
        case 0: {
            CONSOLE_CURSOR_INFO cursor = {1, FALSE};
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
            break;
        }
        case 1: {
            CONSOLE_CURSOR_INFO cursor = {1, TRUE};
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
            break;
        }
    }
}
