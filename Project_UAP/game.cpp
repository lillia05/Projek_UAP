#include <curses.h>
#include <windows.h>
#include <iostream>
using namespace std;
	
void instruction(){
	initscr();
	clear();
	mvprintw(7,50,"INSTRUKSI PERMAINAN");
	getch();
	endwin();
}

	
int main(){
	curs_set(0);
	int nlines =5; int ncols = 32; int y0 = 1; int x0=5;
	WINDOW *win = newwin(nlines, ncols, y0, x0);
	system("color E0");
	initscr();
	
	mvprintw(10,50,"--------------------");
	mvprintw(11,50,"|    GO GO DINO    |");
	mvprintw(12,50,"--------------------");
	refresh();
	Sleep(600);
	
	mvprintw(15,50," 1. Game start     ");
	refresh();
	Sleep(400);

	mvprintw(16,50," 2. Instruction    ");
	refresh();
	Sleep(400);
	
	mvprintw(17,50," 3. Exit        ");
	refresh();
	Sleep(400);
	
	mvprintw(19,50," select option :  ");
	refresh();
	Sleep(400);
	
	while (true)
	{
		char option = getch();
		if (option == '1')
		{
			endwin();
			system("go_go_dino");
			break;
		}
		else if (option == '2')
		{
			instruction();
			break;
		}
		else if (option == '3')
		{
			endwin();
			exit(0);
		}
	}
	endwin();
}
