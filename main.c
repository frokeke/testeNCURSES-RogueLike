#include <ncurses/ncurses.h>
#include <stdlib.h>

typedef struct
{
	int yPos;
	int xPos;
	int height;
	int width;
	
	/*
	Enemy** enemy;			Funcionalidades ainda não implementadas.
	Item** items;
	*/
} Room
typedef struct
{
	int xPos;
	int yPos;
	int health;
} Player;

/*	Campo para declaração de funções */
int screenSetup();

Room** mapSetup();

Room** createRoom(int y, int x, int height, int width);

Player* playerSetup();

int handleInput(int input, Player* user);

int playerMove(int y, int x, Player* user);

int checkPosition(int newY, int newX, Player* user);
/* Fim do campo de declaração de funções */

int main() 
{
	Player* user;
	int ch;
	
	screenSetup();
	mapSetup();
	user = playerSetup();
	
	/*	
	*	Game Loop	
	*/
	while((ch = getch()) != 'q')
	{
		handleInput(ch, user);
	}
	
	endwin();
	
	return 0;
}

int screenSetup()
{
	initscr();
	printw("Teste");
	noecho();
	refresh();
	
	return 0;
}

Room** mapSetup()
{
	mvprintw(13, 13, "--------");
	mvprintw(14, 13, "|......|");
	mvprintw(15, 13, "|......|");
	mvprintw(16, 13, "|......|");
	mvprintw(17, 13, "|......|");
	mvprintw(18, 13, "--------");
	
	createRoom();
	
	mvprintw(2, 40, "--------");
	mvprintw(3, 40, "|......|");
	mvprintw(4, 40, "|......|");
	mvprintw(5, 40, "|......|");
	mvprintw(6, 40, "|......|");
	mvprintw(7, 40, "--------");
	
	mvprintw(10, 40, "--------");
	mvprintw(11, 40, "|......|");
	mvprintw(12, 40, "|......|");
	mvprintw(13, 40, "|......|");
	mvprintw(14, 40, "|......|");
	mvprintw(15, 40, "--------");
}
Player* playerSetup()
{
	Player* newPlayer;
	newPlayer = malloc(sizeof(Player));
	newPlayer->xPos = 14;
	newPlayer->yPos = 14;
	newPlayer->health = 20;
	
	playerMove(newPlayer->yPos, newPlayer->xPos, newPlayer);
	
	return newPlayer;
	
}

int handleInput(int input, Player* user)
{
	int newY;
	int newX;
		
	switch(input)
	{	
		/* mover para cima */
		case 'w':
		case 'W':
		
			newY = user->yPos - 1;
			newX = user->xPos;
			break;
			
		/* mover para baixo */
		case 's':
		case 'S':
		
			newY = user->yPos + 1;
			newX = user->xPos;
			break;
			
		/* mover para esquerda */
		case 'a':
		case 'A':
		
			newY = user->yPos;
			newX = user->xPos - 1;
			break;
			
		/* mover para direita */
		case 'd':
		case 'D':
		
			newY = user->yPos;
			newX = user->xPos + 1;
			break;
			
		default:
			break;
	}
	
	checkPosition(newY, newX, user);
}

/*	Faz a checagem do que está na proxima posição */
int checkPosition(int newY, int newX, Player* user)
{
	int space;
	switch(mvinch(newY, newX))
	{
		case '.':
			playerMove(newY, newX, user);
			break;
		default:
			move(user->yPos, user->xPos);
			break;
	}
}
int playerMove(int y, int x, Player* user)
{
	mvprintw(user->yPos, user->xPos, ".");
	
	user->xPos = x;
	user->yPos = y;
	
	mvprintw(user->yPos, user->xPos, "@");
	move(user->yPos, user->xPos);
} 

Room** createRoom(int y, int x, int height, int width)
{
	
}