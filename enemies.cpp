//      enemies.c++
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

#include "enemies.h"

int attack(char x) {
		
		int damage;
		
		switch (x) {
			//Rusty Android
			case 'd': damage = damageGive(1,3,85,15); break;
			//Blue Android
			case 'b': damage = damageGive(1,5,90,10); break;
			//Maniac
			case 'D': damage = damageGive(1,10,95,5); break;
		}
	return damage;
}
int damageGive(int minRange,int maxRange,int Acc1,int Acc2) {
	
	srand(time(0));
	int damage = (minRange+rand()%maxRange);
	int accuracy = (1+rand()%100);
	
	if (accuracy > Acc1 || accuracy < Acc2) {
		
		damage = 0;
		
	}
	
	return damage;
}
int health(char x) {
	
	int bot_health;

	switch (x) {
		//Rusty Andriod
		case 'd': bot_health = 5; break;
		//blue anrdoid
		case 'b': bot_health = 7; break;
		//maniac android
		case 'D': bot_health = 20; break;	
	}		
    return bot_health;
}

int experience(char x) {
	
	int exp = 0;
	switch (x) {
		case 'd': exp=5; break;
		case 'b': exp=10; break;
		case 'D': exp=20; break;
	}
	return exp;
}
void *movement(void *n) {
	
	struct info *data  = (struct info *)n;
	
	while (!data->done) {
		
		while (!data->halt) {
			
			calculate_movement(data);
			
			pause(50000000);
		}
		pause(50000000);
	}
	
	
	data = NULL;
	 
	pthread_exit(NULL);
}
bool check_place(char character) {
	
	const char constants[9] = {'@','.','#','s','>','<','m','+','X'};
	bool found = true;
	
	for (int z = 0;z < 9;z++) {
						
		if (character == constants[z]) {
							
			found = false;
							
		}
						
	}
	
	
	return found;
}
void calculate_movement(struct info *data) {
	
	int y = getplayer_y(data);
	int x = getplayer_x(y,data);
	
	int tempx = 0;
	int tempy = 0;
	
	bool found = false;
	
	if ((x > 2 && x < 38) && (y > 2 && y < 18)) {
		
		for (int b = (y-2);b < (y+2);b++) {
			for (int a = (x-2);a < (x+2);a++) {
				
				found = check_place(data->map[b][a]);
				
				if (found) {
					
					tempy = b;
					tempx = a;
					
					break;
				
				}
			}
			if (found) {
				
				break;
			
			}
		}
		
		if (found) {
			
			bool moved = false;
			
			for (int b = (y-1);b < (y+1);b++) {
				
				for (int a = (x-1);a < (x+1);a++) {
					
					if (data->map[b][a] == '.' && closer(y,x,b,a,tempy,tempx)) {
						
						data->map[b][a] = data->map[tempy][tempx];
						data->map[tempy][tempx] = '.';
						moved = true;
						break;
						
					}
				}
				if (moved) {
					
					break;
					
				}
				
			}
			
		}
		
	}
	
}
bool closer(int py,int px,int ey,int ex,int tempy,int tempx) {
	
	if ((tempy > ey && ey > py) || (tempx > ex && ex > px) 
		|| (tempy < ey && ey < py) || (tempx < ex && ex < px)) {
	
		return true;
	}
	
	return false;
}
int getplayer_y(struct info *data) {
	
	int temp = 0;
	
	for (int y = 0;y < 20;y++) {
				
		for (int x = 0;x < 40;x++) {
			
			if (data->map[y][x] == '@') {
				temp = y;
				break;
			}
		}
		if (temp != 0) {
			
			break;
			
		}	
	}
	
	return temp;
}
int getplayer_x(int y,struct info *data) {
	
	int temp = 0;
				
	for (int x = 0;x < 40;x++) {
			
		if (data->map[y][x] == '@') {
			
			temp = x;
			break;
			
		}	
					
	}
	return temp;			
} 
