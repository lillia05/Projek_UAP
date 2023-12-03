#include <curses.h>
#include <windows.h>
#include <iostream>
using namespace std;

void instruction(){
	initscr();
	system("cls");
	mvprintw(20,50,"INSTRUKSI PERMAINAN");
	getch();
	endwin();
	
	}

for (int f = 0; f < 20; f++){
			mvprintw(10,50+f,"-");
			refresh();
			Sleep(50);
		}
//	mvprintw(10,50,"--------------------");

	mvprintw(11,50,"|");
	refresh();
	Sleep(50);
	mvprintw(11,51," ");
	refresh();
	Sleep(50);
	mvprintw(11,52," ");
	refresh();
	Sleep(50);
	mvprintw(11,53," ");
	refresh();
	Sleep(50);
	mvprintw(11,54," ");
	refresh();
	Sleep(50);
	mvprintw(11,55,"G");
	refresh();
	Sleep(50);
	mvprintw(11,56,"O");
	refresh();
	Sleep(50);
	mvprintw(11,57," ");
	refresh();
	Sleep(50);
	mvprintw(11,58,"G");
	refresh();
	Sleep(50);
	mvprintw(11,59,"O");
	refresh();
	Sleep(50);
	mvprintw(11,60," ");
	refresh();
	Sleep(50);
	mvprintw(11,61,"D");
	refresh();
	Sleep(50);
	mvprintw(11,62,"I");
	refresh();
	Sleep(50);
	mvprintw(11,63,"N");
	refresh();
	Sleep(50);
	mvprintw(11,64,"O");
	refresh();
	Sleep(50);
	mvprintw(11,65," ");
	refresh();
	Sleep(50);
	mvprintw(11,66," ");
	refresh();
	Sleep(50);
	mvprintw(11,67," ");
	refresh();
	Sleep(50);
	mvprintw(11,68," ");
	refresh();
	Sleep(50);
	mvprintw(11,69,"|");
	refresh();
	Sleep(50);
	
	for (int f = 0; f < 20; f++){
			mvprintw(12,50+f,"-");
			refresh();
			Sleep(50);
		}
//	mvprintw(12,50,"--------------------");
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
