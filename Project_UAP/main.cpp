#include <curses.h>
#include <windows.h>
#include <iostream>
#include <unistd.h>
using namespace std;

void utama();
	
void instruction(){
	initscr();
	clear();
	mvprintw(6,45,"-----------------------");
	mvprintw(7,45,"| INSTRUKSI PERMAINAN |");
	mvprintw(8,45,"-----------------------");
	mvprintw(11,33,"Go Go Dino adalah permainan yang seru dan mendebarkan.");
    mvprintw(13,20,"Pemain mengendalikan dinosaurus dengan menekan tombol 'w' pada keyboard untuk melompat. ");
	mvprintw(15,10,"Bersiaplah untuk melibatkan diri dalam petualangan dinosaurus yang penuh energi dan menjadi juara Go Go Dino!");
    mvprintw(20,35, "        Apakah Anda Sudah mengerti? ");
    mvprintw(22,34," ===============================================");
    mvprintw(25,35,"1. Ya, Mengerti");
    mvprintw(25,60,"2. Tidak Mengerti");
    
    while (true)
	{
		char pilih = getch();
		if (pilih == '1')
		{
			endwin();
			utama();
			break;
		}
		else if (pilih == '2')
		{
			endwin();
			instruction();
			exit(0);
		}
		endwin();
	}
}

void utama(){
	clear();
	curs_set(0);
	int nlines =5; int ncols = 32; int y0 = 1; int x0=5;
	WINDOW *win = newwin(nlines, ncols, y0, x0);
	initscr();
	
	Sleep(500);
	mvprintw(7,25,"  _____   ____        _____   ____       _____  _______ _   _   ____  ");
	mvprintw(8,25," / ____| / __ \\      / ____| / __ \\     |  __ \\ |_   _|| \\ | | / __ \\ ");
	mvprintw(9,25,"| |  __ | |  | |    | |  __ | |  | |    | |  | |  | |  |  \\| || |  | |");
	mvprintw(10,25,"| | |_ || |  | |    | | |_ || |  | |    | |  | |  | |  | . ` || |  | |");
	mvprintw(11,25,"| |__| || |__| |    | |__| || |__| |    | |__| | _| |_ | |\\  || |__| |");
	mvprintw(12,25," \\_____| \\____/      \\_____| \\____/     |_____/ |_____||_| \\_| \\____/ ");
	refresh();
	Sleep(600);
	
	mvprintw(15,50," 1. Game start     ");
	refresh();

	mvprintw(16,50," 2. Instruction    ");
	refresh();
	
	mvprintw(17,50," 3. Exit        ");
	refresh();
	
	mvprintw(19,50," select option :  ");
	refresh();
	
	while (true)
	{
		char option = getch();
		if (option == '1')
		{
			endwin();
			system("level_game");
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
	getch();
	endwin();
}

int main(){
	curs_set(0);
	utama();
}
