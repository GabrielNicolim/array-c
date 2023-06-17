#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <locale.h>

#define ORDER 3

void * getInput(int board[ORDER][ORDER], int * playerNumber);
int someoneWon(int board[ORDER][ORDER]);
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

	int playerNumber = 1;

	do {
		showBoard(board);
		
		getInput(board, &playerNumber);

		// Validar jogada
	} while(! someoneWon(board)); // Retornar se partida acabou e printar mensagem de quem venceu 


	close();

    return 0;
}

void * getInput(int board[ORDER][ORDER], int * playerNumber)
{
	cursor(1);

	int column, line;

    do {
    	for(int i = 0; i < 10; i++) {
    		gotoxy(72 + i, 18); printf(" ");
		}

		for(int i = 0; i < 10; i++) {
    		gotoxy(72 + i, 20); printf(" ");
		}

    	gotoxy(43, 18); printf("%s - Linha (1 - 3): ", * playerNumber == 1 ? "Jogador [1]" : "Jogador [2]");
    	scanf("%d", &line);

		gotoxy(43, 20); printf("%s - Coluna (1 - 3): ", * playerNumber == 1 ? "Jogador [1]" : "Jogador [2]");
		scanf("%d", &column);
		
		if((line < 1 || line > 3) || (column < 1 || column > 3)) {
			for(int i = 0; i < 40; i++) {
	    		gotoxy(43 + i, 22); printf(" ");
			}

			gotoxy(43, 22); printf("Digite valores entre 1 e 3");
			
			continue;
		}
		
		if(board[line - 1][column - 1] != 0) {
			for(int i = 0; i < 40; i++) {
	    		gotoxy(43 + i, 22); printf(" ");
			}

			gotoxy(43, 22); printf("Escolha uma posição não ocupada");

			continue;
		}
    } while (((line < 1 || line > 3) || (column < 1 || column > 3)) || (board[line - 1][column - 1] != 0));

	board[line - 1][column - 1] = * playerNumber;

	if(* playerNumber == 1) {
		* playerNumber = -1;	
	} else {
		* playerNumber = 1;
	}
}

int someoneWon(int board[ORDER][ORDER])
{
	return 0;
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
