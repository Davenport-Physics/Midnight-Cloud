//      player.cpp
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

#include "player.h"

void xp_int(struct variables *data) {
	
	data->xp[0]=0;
	data->xp[1]=50;
	data->xp[2]=100;
	data->xp[3]=200;
	data->xp[4]=400;
	data->xp[5]=750;
	data->xp[6]=1100;
	data->xp[7]=1400;
	
}
void controls() {
	
	cout << "Default Controls:" << endl;
	cout << "w,a,s,d - Movement" << endl;
	cout << "q - quit" << endl;
	cout << "h - heal" << endl;
	cout << "j - journal" << endl;
	cout << endl;
	cout << "Press enter to continue" << endl;
	
	cin.get();
	system("clear");

}
	
void file(bool newgame,string &load) {
		
	const int height = 9;
	const int width = 1;
	int game = 0;
	int xo,yo,oy;
	char command;
	ifstream *infile = new ifstream[3];
	string *line = new string[3];
	
	xo=0;
	yo=1;
	oy=yo;
	string Menu;
	
	char array[height][width] = {
		{' '},
		{' '},
		{' '},
		{' '},
		{' '},
		{' '},
		{' '},
		{' '},
		{' '}};
		
	infile[0].open( "Saves/Save0" , ios_base::in );
	if (!infile[0].is_open()) {
		
		line[0] = "Empty";
			
	} else {
		
		getline(infile[0],line[0]);
		
	}	
		
	infile[1].open( "Saves/Save1" , ios_base::in );
	if (!infile[1].is_open()) {
		
		line[1] = "Empty";
		
	} else {
		
		getline(infile[1],line[1]);
		
	}
	
	infile[2].open( "Saves/Save2" , ios_base::in );
	if ( !infile[2].is_open() ){
		
		line[2] = "Empty";
		
	} else {
		
		getline( infile[2] , line[2] );
		
	}
		
	//using the same menu for load game and new game. Using boolean
	if ( !newgame ) {
		
		Menu = "Choose a file to load";
		
	} else {
		
		Menu = "Choose a New game";
		
	}
		
	while ( game < 1 ) {
		
		array[yo][xo] = '>';
		cout << Menu << endl;
		for ( int y = 0;y < height;y++ ) {
			
			for ( int x = 0;x < width;x++ ) {
				
				cout << " " << array[y][x];
				
			}
			if ( y == 1 ) {
				
				cout << " <" << line[0] << ">";
				
			} else if ( y == 3 ) {
				
				cout << " <" << line[1] << ">";
				
			} else if ( y == 5 ) {
				
				cout << " <" << line[2] << ">";	
				
			}
			cout << endl;
			
		}
 		command = mygetch();
		switch ( command ) {
			case 's':
			
				yo += 2;
				
			break;
			case 'w':
			
				yo -= 2;
				
			break;
			case '\n':
			
				if ( yo == 1 ) {
					
					load = "Saves/Save0";
					
				} else if (yo == 3) {
					
					load = "Saves/Save1";	
					
				} else if (yo == 5) {
					
					load = "Saves/Save2";
					
				}
				game++;
				
			break;
		}
		if ( yo >= 7 || yo < 0 ) {
			
			yo = oy;
			
		} else {
			
			array[oy][xo] = ' ';
			oy = yo;
				
		}
		system("clear");
	}
	delete [] infile;
	delete [] line;
}
void Player_Health( void *n ) {
	
	struct variables *data;
	data = ( struct variables * )n;
	if ( data->level == 0 ) {
		
		data->max_health = 9;
		
	} else {
		
		data->max_health = ( 5 * data->level ) + 6;
		
	}
}
void name( string &load ) {
	controls();
	struct variables data;
	bool done = false;
	ifstream infile;
	
	cout << "Contacting Constuctor....." <<endl;
	pause(3000000000);
	system("clear");
	cout << "Contacting Constuctor.....Done" << endl;
	pause(2000000000);
	cout << "This is the Contructor, who is this? ";
	cin.getline(data.player_name,50); 
	cout << "Hello " << data.player_name << ", I need your help.....the destructor...he's coming." << endl;
	pause(3000000000);
	cout << "I'm Allocating you now." << endl;
	pause(2000000000);
		
	ofstream plna;
	plna.open( load.c_str() );
	//player Name
	plna << data.player_name <<endl;
	//Map or Level One
	plna << 0 << endl;
	//Player Level
	plna << 0 << endl;
	//Player current health
	plna << 9 <<endl; 
	//Player Max Health
	plna << 9 << endl;
	//mana
	plna << 3.0 << endl;
	//max mana
	plna << 3.0 << endl;
	//Exp;
	plna << 0 << endl;
	//x coordinate;
	plna << 1 << endl;
	//y coordinate;
	plna << 1 << endl;
	plna << 0.10 <<  endl;
	plna.close();
	
	data.player_health = 9;
	data.max_health = 9;
	data.mana = 3.0;
	data.max_mana = 3.0;
	data.level = 0;
	data.temporary_exp = 0;
	data.x = 1;
	data.y = 1;
	data.map = 0;
	data.mana_regen = 0.10;
	
	Player_Health(&data);
	xp_int(&data);
	system("clear");
			
	while ( !done ) {
		
		lvl( draw( data.map , &data ) , load , done , &data );
	}
}
void Loadgame( string &load )
{
	bool done = false;
	string line;
	ifstream infile;
	struct variables data;
	
	system("clear");
	
	//ios_base::in checks if there is a file, if there isn't it doesn't create one.
	infile.open( load.c_str() , ios_base::in );
	
	//if Saves isn't open prints empty
	if ( !infile.is_open() ) {
		
		cout << "File has nothing to load" << endl;
		pause(1000000000);
		cout << "Newgame Started" << endl;
		cin.get();
		system("clear");
		name(load);
		done = true;
		
	} else {
		
		infile >> data.player_name;
		infile >> data.map;
		infile >> data.level;
		infile >> data.player_health;
		infile >> data.max_health;
		infile >> data.mana;
		infile >> data.max_mana;
		infile >> data.temporary_exp;
		infile >> data.x;
		infile >> data.y;
		infile >> data.mana_regen;
		
	}
	Player_Health( &data );
	xp_int( &data );
			
	while ( !done ) {
		
		lvl(draw(data.map,&data),load,done,&data);
		
	}
}
void Savegame(string &load,struct variables *data) {
	char y;
	bool done = false;
	ofstream player_data;
	cout << "Are you Sure you want to save? y/n" << endl;
	while (!done) {
		
		y = mygetch();
		if (y =='y' || y == '\n') {
			
			system("clear");
			cout << "Saving....." << endl;
			pause(2000000000);
			player_data.open(load.c_str());
			player_data << data->player_name << endl;
			player_data << data->map << endl;
			player_data << data->level << endl;
			player_data << data->player_health << endl;
			player_data << data->max_health << endl;
			player_data << data->mana << endl;
			player_data << data->max_mana << endl;
			player_data << data->temporary_exp << endl;
			player_data << data->x << endl;
			player_data << data->y << endl;
			player_data << data->mana_regen;
			player_data.close();
			system("clear");
			cout << "Saving.....Done" << endl;
			cin.get();
			done = true;	
			
		} else if (y == 'n') {
			
			cout << "Bye! " << endl;
			cin.get();
			done = true;
			
		}
	}
}
	//Basic implementation for combat
int Player_Damage(struct variables *data) {
	
	int damage;
	int accuracy;
	srand(time(0));
	accuracy = (1+rand()%100);
	
	if (accuracy < 7 || accuracy > 92) {
		
		damage = (5+rand()%(15 + data->level + data->attack));
		
	} else {
		
		damage = (1+rand()%(5 + data->level + data->attack));
		
	}
	return damage;
}
int health_regeneration(struct variables *data) {
	
	int regen;
	srand(time(0));
	regen = (data->level + rand()%(7 + data->level));
	
	return regen;
}	
