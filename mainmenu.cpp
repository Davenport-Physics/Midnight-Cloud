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
	
	init_controls();
	
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
		if ( check_controls(command) == UP ) {
			
			y -=2;
			x -=2;
			
		} else if ( check_controls(command) == DOWN ) {
			
			y+=2;
			x+=2;
			
		} else if ( check_controls(command) == QUIT ) {
			
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
				
				options();
				
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
	
}
void options() {
	
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
				
				set_controls();
				
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
		else if ( check_controls( command ) == UP ) {
			
			y -= 2;
			
		} else if ( check_controls( command ) == DOWN ) {
			
			y += 2;
			
		} else if ( check_controls( command ) == QUIT ) {
			
			done = true;
			
		}
		if (y < 0 || y > 2 ) {
			
			y = yo;
			
		} else {
			
			array[yo][x] = ' ';
			yo = y;
			
		}
		
		system("clear");
		
	}
	
}
