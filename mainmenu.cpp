//      MainMenu.cpp
//      
//      Copyright 2011 Michael Davenport
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.



#include "mainmenu.h"

	
void show(bool *cont) {
	
	const int height = 10;
	const int width = 22;
	char command;
	int game = 0;
	int x = 3;
	int ox = x;
	int y = 5;
	int oy = y;
	string load = "";
	
	struct player_controls *pc = new struct player_controls[1];
	pc->up = 'w';
	pc->down = 's';
	pc->left = 'a';
	pc->right = 'd';
	pc->quit = 'q';
	pc->heal = 'h';
	pc->journal = 'j';
	pc->debug = 'c';
	
	pthread_t title;
	struct player_vars data;
	data.done = false;
	data.x = -1;
	
	pthread_create(&title,NULL,playerthread,(void *)&data);
	
	
	char array[height][width] = {
{' ','/','\\','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','/','\\',' '},
{'<','(',')','{','M','i','d','n','i','g','h','t',' ','C','l','o','u','d','}','(',')','>'},
{' ',' ','\\','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',' ',' ',' '},
{' ',' ',' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ','\\',' ',' ',' ','_','_','_','_','_','_','_','_',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ','}','\\','_','/','N','e','w',' ','G','a','m','e',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ','\\',' ',' ',' ','_','_','_','_','_','_','_','_','_',' ',' ',' '},
{' ',' ',' ',' ',' ',' ','}','\\','_','/','L','o','a','d',' ','G','a','m','e',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ','\\',' ',' ',' ','_','_','_','_','_','_','_',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ','}','\\','_','/','O','p','t','i','o','n','s',' ',' ',' '}};

	system("clear");
	
	while (game < 1) {
		
		array[y][x] = '>';
		for (int row = 0;row < height;row++) {
		
			for (int column = 0;column < width;column++) {
			
				std::cout << " " << array[row][column];
	
			}
			std::cout << std::endl;
		
		}
		command = mygetch();
		if ( command == pc->up ) {
			
			y -=2;
			x -=2;
			
		} else if ( command == pc->down ) {
			
			y+=2;
			x+=2;
			
		} else if ( command == pc->quit ) {
			
			cout << "Goodbye!" << endl;
			*cont = true;
			return;
			
		} else if ( command == '\n' ) {
				
			if ( oy == 5 && ox == 3 ) {
				
				data.done = true;
				system("clear");
				
				game++;
				file( true , load );
				pthread_join( title , NULL );
				name( load );
				
				//Buffer isn't cleared, assumes the player choose new game again.
				std::cin.get();
				
			} else if ( oy == 7 && ox == 5 ) {
				
				system("clear");
				game++;
				
				data.done = true;
				file(false,load);
				pthread_join(title,NULL);
				Loadgame(load);
				
			} else {
				
				options(pc);
				
			}
			
		}
		if (y <= 3 || y >= 10) {
			
			x = ox;
			y = oy;
			
		} else {
			
			array[oy][ox] = ' ';
			ox = x;
			oy = y;
			
		}
		system("clear");	
	}
	delete pc;
}
void options(struct player_controls *pc) {
	
	system("clear");

	char array[5][10] = {{' ','C','o','n','t','r','o','l','s',' '},
						 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
						 {' ','C','r','e','d','i','t','s',' ',' '},
						 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
						 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
	int x = 0;
	int y = 0;
	int yo = y;
	bool done = false;
	char command;
	
	while ( !done ) {
		array[y][x] = '>';
		for ( int row = 0;row < 5;row++ ) {
			for ( int column = 0;column < 10;column++ ) {
					std::cout << array[row][column];
			}
			std::cout << std::endl;
		}
		
		command = mygetch();
		
		if (command == '\n') {
			if ( y == 0 ) {
				change_controls( pc );
			} else if ( y == 2 ) {
				
				system("clear");
				std::cout << "Credits" << std::endl;
				std::cout << "LP-Michael Davenport" << std::endl;
				std::cout << "HP-Alex Fatum" << std::endl;
				std::cout << "SAG-Max Mitchell" << std::endl;
				std::cout << std::endl;
				std::cout << "Special thanks to:" << std::endl;
				std::cout << "James Thomas" << std::endl;
				std::cout << "Linteg" << std::endl;
				std::cout << "Music by:" << std::endl;
				std::cout << "Title1 - Max Mitchell" << std::endl;
				std::cout << "map2 - MIdnight cloud - Max Mitchell" << std::endl;
				std::cout << "map1 - Waltz into the moonlight - tryad" << std::endl;
				std::cin.get();
				
			}
		}
		else if ( command == pc->up ) {
			
			y-=2;
			
		} else if ( command == pc->down ) {
			y+=2;
		} else if ( command == pc->quit ) {
			done = true;
		}
		if (y < 0 || y > 2 ) {
			y=yo;
		} else {
			array[yo][x] = ' ';
			yo=y;
		}
		system("clear");
	}
}
void change_controls( struct player_controls *pc )  {
	
	bool check = true;
	bool done = false;
	
	while (!done) {
	
		std::cout << "Press key for up" << endl;
		pc->up = mygetch();
	
		std::cout << "Press key for down" << endl;
		pc->down = mygetch();
		if ( pc->down == pc->up ) {
			check = false;
		}
	
		std::cout << "Press key for left" << endl;
		pc->left = mygetch();
		if (( pc->left == pc->down ) || ( pc->left == pc->up )) {
			check = false;
		}
	
		std::cout << "Press key for right" << endl;
		pc->right = mygetch();
		if (( pc->right == pc->left ) || ( pc->right == pc->down ) 
									||	( pc->right == pc->up )) {
				check = false;
		}
	
		std::cout << "Press key for heal" << endl;
		pc->heal = mygetch();
		if ((pc->heal == pc->right) || (pc->heal == pc->left) 
			|| (pc->heal == pc->down) || (pc->heal == pc->up)) {
			check = false;	
		}
	
		std::cout << "Press key for journal" << endl;
		pc->journal = mygetch();
		if ((pc->journal == pc->heal) || (pc->journal == pc->right) 
			|| (pc->journal == pc->left) || (pc->journal == pc->down) 
										|| (pc->journal == pc->down)) {
			check = false;	
		}
	
		std::cout << "Press key for quit" << endl;
		pc->quit = mygetch();
		if ((pc->quit == pc->journal) || (pc->quit == pc->heal) 
			|| (pc->quit == pc->right) || (pc->quit == pc->left) 
			|| (pc->quit == pc->down) || (pc->quit == pc->up)) {
			check = false;	
		}
	
		std::cout << "Press key for debug" << endl;
		pc->debug = mygetch();
		if ((pc->debug == pc->quit) || (pc->debug == pc->journal) 
			|| (pc->debug == pc->heal) || (pc->debug == pc->right) 
			|| (pc->debug == pc->left) || (pc->debug == pc->down)
									|| (pc->debug == pc->up)) {
			check = false;								
		}
		if (check == true) {
			
			done = true;
			std::cout << "No duplicate key found, have fun." << std::endl;
			std::cin.get();
			
		} else {
			
			std::cout << "One of your key are used twice. Try again" << std::endl;
			pause(1000000000);
			system("clear");
			
		}
	}
	
}
