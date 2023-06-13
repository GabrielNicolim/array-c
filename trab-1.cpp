#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <locale.h>

int mat[9999][9999], order;

void initArray();
void initMenu();
int navegateMenu(int start, int end, int p);
void showMat();
void swapRowForLine();
void swapRowForColumn();
void swapPrimaryForSecondary();
void verifySymmetric();
void close();
void loading();
void textcolor(int color);
void gotoxy(int x, int y);
void cursor (int x);

int main() {
	setlocale(LC_ALL, "Portuguese");

	initArray();

    initMenu();

    return 0;
}

void initArray()
{
	gotoxy(30, 8); printf("Digite qual ordem sua matriz deve ter: ");
	scanf("%d", &order);
	
	for(int i = 0; i < order; i++) {
		system("cls");

		for(int j = 0; j < order; j++) {
			gotoxy(30, 8 + (j * 2)); printf("Elemento [%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
}

void initMenu()
{
	int option;

	do {
		system("cls");

	    gotoxy(30, 8);  printf("Mostrar os elementos");
	    gotoxy(30, 10); printf("Trocar os elementos da linha X pela linha Y");
	    gotoxy(30, 12); printf("Trocar os elementos da coluna X pela coluna Y");
	    gotoxy(30, 14); printf("Troque os elementos da diagonal principal com a diagonal secund�ria");
	    gotoxy(30, 16); printf("Verificar se uma matriz � sim�trica");
	    gotoxy(30, 18); printf("Verificar se uma matriz � um quadrado m�gico");
	    gotoxy(30, 20); printf("Verificar se uma matriz � quadrado latino");
	    gotoxy(30, 22); printf("Verificar se uma matriz � matriz de permuta��o");
	    gotoxy(30, 24); printf("Sair");

		option = navegateMenu(8, 24, 28);
	
		cursor(1);

	    switch(option) {
	        case 0:
                 showMat();
	            break;
	        case 1:
	        	swapRowForLine();
	            break;
	        case 2:
	        	swapRowForColumn();
	            break;
	        case 3:
	        	swapPrimaryForSecondary();
	            break;
	        case 4:
	        	verifySymmetric();
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
	    
	} while(option != 8);

    return;
    
}

int navegateMenu(int start, int end, int p)
{
    cursor(0);

    int aux = start;
    int input;

    do{
        gotoxy(p, aux); printf("%c", 62);

        fflush(stdin);

        input = getch();

        gotoxy(p,aux); printf(" ");

        switch(input){
            case 72:
                aux -= 2;

                if(aux < start) aux  = end;

                gotoxy(p, aux); printf("%c", 62);

                break;
            case 80:
                aux+=2;

                if(aux > end) aux = start;

                gotoxy(p,aux); printf("%c", 62);

                break;
            case 13:
                return (aux - start) / 2;

                break;
        }
    } while (input != 13);
}

void showMat()
{
    system("cls");

    for (int i = 0; i < order; i++) {
        gotoxy(30, 8 + i); 
        printf("| ");
        for (int j = 0; j < order; j++) {
            printf("%d ", mat[i][j]);
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

void swapRowForLine()
{
	int x, y;
	
	do {
		system("cls");
	
		gotoxy(30, 8); printf("Digite a linha a ser trocada: ");
		scanf("%d", &x);
		gotoxy(30, 10); printf("Digite a linha a ser trocada: ");
		scanf("%d", &y);
	} while(x >= order || y >= order);

	int aux;
	for(int i = 0; i < order; i ++) {
		aux = mat[x][i];
		mat[x][i] = mat[y][i];
		mat[y][i] = aux;
	}

	return;
}

void swapRowForColumn()
{
	int x, y;

	do {
		system("cls");

		gotoxy(30, 8); printf("Digite a coluna a ser trocada: ");
		scanf("%d", &x);
		gotoxy(30, 10); printf("Digite a coluna a ser trocada: ");
		scanf("%d", &y);	
	} while(x >= order || y >= order);


	int aux;
	for(int i = 0; i < order; i ++) {
		aux = mat[i][x];
		mat[i][x] = mat[i][y];
		mat[i][y] = aux;
	}

	return;
}

void swapPrimaryForSecondary()
{
	int aux, line = 0, column = (order - 1);  

	for(int i = 0; i < order; i++) {
		aux = mat[i][i];
		mat[i][i] = mat[line][column];
		mat[line][column] = aux;
		
		column--;
		line++;
	}

	loading();

	return;
}

int isSymmetric (int mat[][9999]) {
	for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            if (mat[i][j] != mat[j][i]) {
                return 0;
            } 
        }
    }
    
    return 1;
}

void verifySymmetric() 
{
	int symmetric = isSymmetric(mat);
	
	system("cls");

    if (symmetric == 1) {
        gotoxy(30, 8); printf("A matriz � sim�trica.");
    } else {
        gotoxy(30, 8); printf("A matriz n�o � sim�trica.");
    }

    int input;
    cursor(0);

    do {
        fflush(stdin);
        input = getch();
    } while (input != 13);

    return;
}

void close()
{
	system("cls");

	cursor(0);

	gotoxy(43, 12); printf("Obrigado por utilizar nosso programa!");
	
	textcolor(0); gotoxy(80, 34);
	
	exit(1);
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
