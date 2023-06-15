#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <locale.h>

#define ORDER 3

void someoneWon(int board[ORDER][ORDER]);
void showBoard(int board[ORDER][ORDER]);
void loading();
void close();
void textcolor(int color);
void gotoxy(int x, int y);
void cursor (int x);

int main() {
	setlocale(LC_ALL, "Portuguese");

	int board[ORDER][ORDER] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
	};

	loading();

	do {
		showBoard(board)
		
		// Obter jogada
		// Validar jogada
	} while(! someoneWon(board)); // Retornar se partida acabou e printar mensagem de quem venceu 


	close();

    return 0;
}

void someoneWon(int board[ORDER][ORDER])
{
	
}

void showBoard(int board[ORDER][ORDER])
{
	system("cls");

    for (int i = 0; i < ORDER; i++) {
        gotoxy(57, 8 + i); 
        printf("| ");
        for (int j = 0; j < ORDER; j++) {
        	if(board[i][j] == 1) {
        		printf("X ");

        		continue;
			}
			
			if(board[i][j] == -1) {
				printf("O ");

        		continue;
			}

            printf("_ ");
        }
        
        printf("|\n");
    }

    cursor(0);

    int input;

    do {
    	fflush(stdin);
    	
        input = getch();
    } while (input != 13);

    return;
}

void loading()
{
	system("cls");
	
	cursor(0);

	gotoxy(60, 15); 
	for(int i = 0; i < 3; i++) {
		printf(". ");
		Sleep(500);
	}
}

void close()
{
	system("cls");

	cursor(0);

	gotoxy(43, 12); printf("Obrigado por utilizar nosso programa!");
	
	textcolor(0); gotoxy(80, 34);
	
	exit(1);
}

void textcolor(int color)
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0xf0) | color);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void cursor (int show)
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
