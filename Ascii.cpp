//      Ascii.cpp
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
//      
//      
#include "Ascii.h"

using namespace std;

void lvl(string map,string &load,bool &done,struct variables *data) {
	
	const int width = 40;
	const int height = 20;
	int game = 0;
	int xo = data->x;
	int yo = data->y;
	char command;
	int current_gold = 0;
	
	struct info Thread;
	pthread_t thread;
	
	struct player_vars music;
	pthread_t musicthread;
	music.done = false;
	music.x = data->map;
	
	//I'm not sure how I want the attack variable to be used at this moment
	//At it's current state, you can increase it. It is not saved, and
	//movement across maps sets it back to 0.
	data->attack = 0;
	Thread.done = false;
	Thread.halt = false;
	
	//Reads from text file to draw map. 40x20 must be taken up.
	//char array[height][width];
    ifstream myfile(map.c_str());
    int a = 0;
    int b = 0;
    if(!myfile) {
		
        cout << "File cannot be found"<<endl;
		cin.get();
        done = true;
        return;
        
    }
    while(!myfile.eof()) {
		
      myfile >> Thread.map[b][a];
      if(a == 39) {
		  
           a = 0;
           b++;
           myfile >> Thread.map[b][a];
           
      }
      a++;
      
    }
    pthread_create( &thread , NULL , movement , (void *)&Thread );
    pthread_create( &musicthread , NULL , playerthread , (void *)&music );
    
	while (game < 1) {
		
		Thread.map[data->y][data->x] = '@';
		//Makes the game grid
		for( int row = 0;row < height; row++ ) {
			
			for( int column = 0; column < width; column++ ) {
				
				if (Thread.map[row][column] == 'X') {
					
					cout << "  ";
				
				} else {
					
					cout << " " << Thread.map[row][column];
					
				}
				
			}
			cout << endl;
			
		}
	
		cout << "Level: " << data->level << " Exp: "<< data->temporary_exp << " HP: " << data->player_health 
		<< " Mana " << data->mana << " Gold: " << current_gold << endl;
	
		command = mygetch();
		Thread.halt = true;
		
		switch ( check_controls(command) ) {
			case UP:
			
				data->y--;
				
			break;
			case LEFT:
			
				data->x--;
				
			break;
			case DOWN:
			
				data->y++;
				
			break;
			case RIGHT:
			
				data->x++;
				
			break;
			case JOURNAL:
			
				display();
				
			break;
			case QUIT:
			
				stop( done );
				if ( done ) {
					
					game++;
					
				}
				
			break;
			case DEBUG:
			
				cheat( data , &current_gold );
				
			break;
			case '\n':
			
				data->mana -= .10;
				
			break;
			case HEAL:
				//Adds Healing option to grid.
				if (data->player_health < data->max_health && data->mana >= 1.5) {
					
					data->player_health += health_regeneration( data );
					cout << "+" << health_regeneration(data) << " HP" << endl;
					cin.get();
					data->mana -= 1.5;
					
					if ( data->player_health > data->max_health ) {
						
						data->player_health = data->max_health;
						
					}
					
				} else if ( data->mana <= 1.4 ) {
					
					cout << "Not enough mana" << endl;
					cin.get();
					
				} else {
					
					cout << "You already have full health" << endl;
					data->mana-=.10;
					cin.get();
					
				}
			break;
		}
		//collision detection
		switch (Thread.map[data->y][data->x]) {
			case '#':
			
				data->x = xo;
				data->y = yo;
				data->mana -= data->mana_regen;
				
			break;
			case '>':
			
				data->map++;
				game++;
				
			break;
			case '<':
			
				data->map--;
				game++;
				
			break;
			case '.':
			
				Thread.map[yo][xo] = '.';
				xo=data->x;
				yo=data->y;
				
			break;
			case 's':
			
				data->x = xo;
				data->y = yo;
				system("clear");
				Savegame(load,data);
				
			break;
			case 'm':
			
				data->x = xo;
				data->y = yo;
				system("clear");
				display(data, current_gold);
				
			break;
			case '+':
			
				Thread.map[yo][xo] = '.';
				xo = data->x;
				yo = data->y;
				current_gold += gold();
				
			break;
			default:
			
				check(Thread.map[data->y][data->x],load,game,done,data);
				Thread.map[data->y][data->x] = '.';
				data->y = yo;
				data->x = xo;
				
			break;
		}
		Thread.halt = false;
		if ( data->mana < data->max_mana ) {
			
			data->mana += data->mana_regen;
			if ( data->mana > data->max_mana ) {
				
				data->mana = data->max_mana;
				
			}
			
		}
		system("clear");
	}
	
	Thread.halt = true;
	Thread.done = true;
	music.done = true;
	pthread_join( thread , NULL );
	pthread_join( musicthread , NULL );
	system("clear");
	
}



void check(char x,string &load, int &game,bool &done,struct variables *data)
{
	char enemies[3] = {'d','b','D'};
	bool is = false;
	
	//Checks to see if you stepped into a enemy.
	for ( int a = 0;a < 3;a++ ) {
		
		if ( x == enemies[a] ) {
			
			is = true;
			
		}
			
	}
	
	if ( is ) {
		
		system("clear");
		fight( x , load , done , data );
		
	}	     
    if ( done ) {
		
		game++;
		
	}	  
}
