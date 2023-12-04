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

void game_start(){
	initscr();
	clear();
	while (true)
	{
		mvprintw(8,45," _                          _");
		mvprintw(9,45,"| |------------------------| |");
		mvprintw(10,45,"| |      SELECT LEVEL      | |");
		mvprintw(11,45,"| |                        | |");
		mvprintw(12,45,"| |    1. easy             | |");
		mvprintw(13,45,"| |    2. medium           | |");
		mvprintw(14,45,"| |    3. hard             | |");
		mvprintw(15,45,"| |    4. extreme          | |");
		mvprintw(16,45,"|_|------------------------|_|");
		refresh();
		
		mvprintw(19,54,"  select :  ");
		refresh();
		Sleep(400);
	
		char select = getch();
		if (select == '1')
		{
			endwin();
			system("easy");
			break;
		}
		else if (select == '2')
		{
			endwin();
			system("medium");
			break;
		}
		else if (select == '3')
		{
			endwin();
			system("hard");
			break;
		}
		else if (select == '4')
		{
			endwin();
			system("extreme");
			break;
		}
	}
	getch();
	endwin();
}

	
int main(){
	curs_set(0);
	int nlines =5; int ncols = 32; int y0 = 1; int x0=5;
	WINDOW *win = newwin(nlines, ncols, y0, x0);
	system("color E0");
	initscr();
	
//	mvprintw(7,20,"  _____  ____        _____  ____       _____ _____ _   _  ____  ");
//	mvprintw(8,20," / ____|/ __ \      / ____|/ __ \     |  __ \_   _| \ | |/ __ \ ");
//	mvprintw(9,20,"| |  __| |  | |    | |  __| |  | |    | |  | || | |  \| | |  | |");
//	mvprintw(10,20,"| | |_ | |  | |    | | |_ | |  | |    | |  | || | | . ` | |  | |");
//	mvprintw(11,20,"| |__| | |__| |    | |__| | |__| |    | |__| || |_| |\  | |__| |");
//	mvprintw(12,20," \_____|\____/      \_____|\____/     |_____/_____|_| \_|\____/ ");
//	refresh();
//	Sleep(600);
	
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
			
			game_start();
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
