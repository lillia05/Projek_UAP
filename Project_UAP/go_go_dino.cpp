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

void DrawTree(int treeX)
{
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
	int x = 22;
	int y = 8;
	GotoXY(x, y);
	cout<<("===========================");
	GotoXY(x, y + 1);
	cout<<("======G A M E O V E R======");
	GotoXY(x, y + 2);	
	cout<<("===========================");
	GotoXY(x, y + 5);
	cout<<"Score Anda Adalah : "<<score;

	cout<<("\n\n\n\n\n\n\n\n\n");
	system("pause");
}
