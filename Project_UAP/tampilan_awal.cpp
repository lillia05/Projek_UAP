#include <curses.h>
#include <windows.h>
#include <iostream>
using namespace std;
	

int main(){
	int nlines =5; int ncols = 32; int y0 = 1; int x0=5;
	WINDOW *win = newwin(nlines, ncols, y0, x0);
	system("color E0");
	initscr();
	mvprintw(10,50,"--------------------");
	mvprintw(11,50,"|    GO GO DINO    |");
	mvprintw(12,50,"--------------------");
	refresh();
	Sleep(700);
	
	mvprintw(15,50," 1. Game start     ");
	refresh();
	Sleep(500);

	mvprintw(16,50," 2. Instruction    ");
	refresh();
	Sleep(500);
	
	mvprintw(17,50," 3. quit        ");
	refresh();
	Sleep(500);
	
	mvprintw(19,50," select option :  ");
	refresh();
	Sleep(500);
		
	wrefresh(win);
	int ch = wgetch(win);
	delwin(win);
		
	getch();
	endwin();
}
