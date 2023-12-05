#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
using namespace std;


void SetConsoleView(){
	system("mode con:cols=150 lines=150");
}


void GotoXY(int x, int y){
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


int GetKeyDown(){
	if (_kbhit() != 0){
		return _getch();
	}
	return 0;
}

void DrawDino(int dinoY){
	GotoXY(0, dinoY);
	static bool legFlag = true;
	cout<<("        $$$$$$$ \n");
	cout<<("       $$ $$$$$$\n");
	cout<<("       $$$$$$$$$\n");
	cout<<("$      $$$      \n");
	cout<<("$$     $$$$$$$  \n");
	cout<<("$$$   $$$$$     \n");
	cout<<(" $$  $$$$$$$$$$ \n");
	cout<<(" $$$$$$$$$$$    \n");
	cout<<("  $$$$$$$$$$    \n");
	cout<<("    $$$$$$$$    \n");
	cout<<("     $$$$$$     \n");
	if (legFlag){
		cout<<("     $    $$$    \n");
		cout<<("     $$          ");
		legFlag = false;
	}
	else{
		cout<<("     $$$  $     \n");
		cout<<("          $$    ");
		legFlag = true;
	}
}

void DrawTree(int treeX){
	GotoXY(treeX, TREE_BOTTOM_Y);
	cout<<("####");
	GotoXY(treeX, TREE_BOTTOM_Y + 1);
	cout<<(" ## ");
	GotoXY(treeX, TREE_BOTTOM_Y + 2);
	cout<<(" ## ");
	GotoXY(treeX, TREE_BOTTOM_Y + 3);
	cout<<(" ## ");
	GotoXY(treeX, TREE_BOTTOM_Y + 4);
	cout<<(" ## ");
}

void DrawGameOver(const int score){
	system("cls");
	int x = 20;
	int y = 6;
	GotoXY(x, y);
	cout<<("   ____      _      __  __  U _____ u    ");
	GotoXY(x, y + 1);
	cout<<("U /'___|uU  /'\\  uU|' \\/ '|u\\| ___'|/    ");
	GotoXY(x, y + 2);	
	cout<<("\\| |  _ / \\/ _ \\/ \\| |\\/| |/ |  _|'      ");
	GotoXY(x, y + 3);	
	cout<<(" | |_| |  / ___ \\  | |  | |  | |___      ");
	GotoXY(x, y + 4);	
	cout<<("  \\____| /_/   \\_\\ |_|  |_|  |_____|     ");
	GotoXY(x, y + 5);	
	cout<<("  _)(|_   \\\\    >><<,-,,-.   <<   >>     ");
	GotoXY(x, y + 6);	
	cout<<(" (__)__) (__)  (__)(./  \\.) (__) (__)    ");
	GotoXY(x, y + 7);	
	cout<<("   U  ___ u__     __ U _____ u   ____    ");
	GotoXY(x, y + 8);
	cout<<("    \\/'_ \\/\\ \\   /'/u\\| ___'|/U |  _'\\ u ");
	GotoXY(x, y + 9);	
	cout<<("    | | | | \\ \\ / //  |  _|'   \\| |_) |/ ");
	GotoXY(x, y + 10);	
	cout<<(".-,_| |_| | /\\ V /_,-.| |___    |  _ <   ");
	GotoXY(x, y + 11);	
	cout<<(" \\_)-\\___/ U  \\_/-(_/ |_____|   |_| \\_\\  ");
	GotoXY(x, y + 12);	
	cout<<("      \\\\     //       <<   >>   //   \\\\_ ");
	GotoXY(x, y + 13);	
	cout<<("     (__)   (__)     (__) (__) (__)  (__)");
	GotoXY(x + 5, y + 16);
	cout<<"Score Anda Adalah : "<<score;

	cout<<("\n\n\n\n\n\n\n\n\n");
	system("pause");
}

bool isCollision(const int treeX, const int dinoY){
	GotoXY(0, 0);
	cout<<("treeX : %d, dinoY : %d", treeX, dinoY); 
	if (treeX <= 8 && treeX >= 4 &&
		dinoY > 8)
	{
		return true;
	}
	return false;
}


void game(int level){
	SetConsoleView();

	while (true)		
	{
		bool isJumping = false;
		bool isBottom = true;
		const int gravity = 3;
		
		int dinoY = DINO_BOTTOM_Y;
		int treeX = TREE_BOTTOM_X;
		
		int score = 0;
		clock_t start, curr;	
		start = clock();	

		while (true){
			if(isCollision(treeX, dinoY))
				break;

			if (GetKeyDown() == 'w' && isBottom){
				isJumping = true;
				isBottom = false;
			}
			if (isJumping){
				dinoY -= gravity;
			}
			else{
				dinoY += gravity;
			}
			if (dinoY >= DINO_BOTTOM_Y){
				dinoY = DINO_BOTTOM_Y;
				isBottom = true;
			}

			treeX -= 2;
			if (treeX <= 0){
				treeX = TREE_BOTTOM_X;
			}

			if (dinoY <= 3){
				isJumping = false;
			}

			DrawDino(dinoY);	
			DrawTree(treeX);	

			curr = clock();			
			if (((curr - start) / CLOCKS_PER_SEC) >= 1)	{
				score++;	
				start = clock();	
			}
			Sleep(level);
			system("cls");	

			GotoXY(25, 0);	
			cout<<"Score : "<<score;
		}
		DrawGameOver(score);
	}
}

void game_start(){
	//clear();
	while (true)
	{int x = 23;
	int y = 8;
	GotoXY(x, y);
	cout<<(" _                          _");
	GotoXY(x, y + 1);
	cout<<("| |------------------------| |");
	GotoXY(x, y + 2);
	cout<<("| |      SELECT LEVEL      | |");
	GotoXY(x, y + 3);
	cout<<("| |                        | |");
	GotoXY(x, y + 4);
	cout<<("| |    1. easy             | |");
	GotoXY(x, y + 5);
	cout<<("| |    2. medium           | |");
	GotoXY(x, y + 6);
	cout<<("| |    3. hard             | |");
	GotoXY(x, y + 7);
	cout<<("| |    4. extreme          | |");
	GotoXY(x, y + 8);
	cout<<("|_|------------------------|_|");
		
	GotoXY(x + 3, y + 10);
	cout<<("  select :  ");
	Sleep(400);
	
		char select = getch();
		cin>>select;
		if (select == '1')
		{
			game(100);
			break;
		}
		else if (select == '2')
		{

			game(70);
			break;
		}
		else if (select == '3')
		{
			game(40);
			break;
		}
		else if (select == '4')
		{
			game(20);
			break;
		}
	}
}

int main(){
	game_start();
}

