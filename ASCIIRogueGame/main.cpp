#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include "Player.h"
#include "GameManager.h"


using namespace std;

bool SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	// Get handle of the standard output 
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (Handle == NULL)
	{
		cout << "Failure in getting the handle\n" << GetLastError();
		return FALSE;
	}

	// Set screen buffer size to that specified in coord 
	if (!SetConsoleScreenBufferSize(Handle, coord))
	{
		cout << "Failure in setting buffer size\n" << GetLastError();
		return FALSE;
	}

	// Set the window size to that specified in Rect 
	if (!SetConsoleWindowInfo(Handle, TRUE, &Rect))
	{
		cout << "Failure in setting window size\n" << GetLastError();
		return FALSE;
	}

	return TRUE;
}

ostream& operator<<(ostream &strm, const Player &p) {
	return strm << "Player data = [pos(" << p.getPosition().getXCoord() << "," << p.getPosition().getYCoord() << ")]\n"
		        << "            = [Lvl: " << p.getLevel() << "]\n"
				<< "            = [Att: " << p.getAttack() << "]\n"
				<< "            = [Def: " << p.getDefence() << "]\n"
				<< "            = [Exp: " << p.getExperience() << "]\n";
}

int main(){

	if (SetWindow(130, 30))
	{
		cout << "Success\n";
	}

	GameManager gameManager("level1.txt");
	gameManager.startGame();
	return 0;
}