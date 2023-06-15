#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

    return 0;
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
