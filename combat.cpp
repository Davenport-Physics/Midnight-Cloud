//      Enemies.cpp
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


#include "combat.h"

using namespace std;

void fight(char x,string &load,bool &done,struct variables *data)
{
     
     int Monster_Health;
     int Monster_Damage;
     int PlayerDamage;
     int heal;
     int game = 0;
     int xo = 0;
     int yo = 2;
     int x1 = xo;
     int y1 = yo;
     int xp_gained = experience(x);
     bool life = false;
     bool level_gain;
     
     char check;
	 const int height = 7;
     const int width = 7;
     
     //sets health and damage to each monsters assigned variables
      Monster_Health = health(x);        
            
     char array[width][height]={
     {' ',' ',' ',' ',' ',' ',' '},
     {' ',' ',' ',' ',' ',' ',' '},
     {' ','A','t','t','a','c','k'},
     {' ',' ',' ',' ',' ',' ',' '},
     {' ',' ',' ',' ',' ',' ',' '},
     {' ','H','e','a','l',' ',' '},
     {' ',' ',' ',' ',' ',' ',' '}};
     while (game<1) {
		 
		 array[yo][xo] = '>';
		 
		 Monster_Damage = attack(x);
		 PlayerDamage = Player_Damage(data);
		 cout << "HP: " << data->player_health << endl;
		 //modular design, also very useful =D
		 portrait(x);
		 
		 //draws user options
		for (int a = 0;a < height;a++) {
			
			for (int b = 0;b < width;b++) {
				
				cout << " " << array[a][b];
				
			} 
			cout << endl;
			
		 }
		 
		check = mygetch();
		switch (check_controls(check)) {
			case UP:
			
				yo -= 3;
				
			break;
			case DOWN:
			
				yo += 3;
				
			break;
			case ENTER:
				//checks where the user pressed enter.
				if (array[yo][xo] == array[2][0]) {
					
					Monster_Health -= PlayerDamage;
					cout << "Dealt " << PlayerDamage << " damage" << endl;
					cin.get();
			 
					if (Monster_Health <= 0) {
						
						cout << "Enemy Defeated" << endl;
						cout << "Gained " << xp_gained << " Exp" << endl;
						data->temporary_exp += xp_gained;
						level_gain = level_check(data);
			 
						if (level_gain) {
							
							cout << "You have gained a level! " << endl;
							cin.get();
							data->level++;
							Player_Health(data);
							
						}
						game++;
						
					} else {
						
						data->player_health -= Monster_Damage;
						cout << "Took " << Monster_Damage << " damage" << endl;
						cin.get();
				
						if (data->player_health <= 0) {
							
							life = true;
							
						}
							
					}
					
				} else {
					
					heal = (2+rand()%7);
					srand(time(0));
			
					if (data->player_health < data->max_health && data->mana >= 0.0) {
						
						data->player_health += heal;
						data->mana -= 1.0;
						cout << "Used 1 mana" << endl;
						cin.get();
			
						if (data->player_health >= data->max_health) {
							
							data->player_health = data->max_health;
							cout << "Gained " << heal << " HP" << endl;
							cout << "Max Health Reached" << endl;
							
						} else {
							
							cout << "Gained " << heal << " HP" << endl;
							
						}
						cin.get();
						
					} else if (data->mana < 1) {
						
						cout << "Not enough mana" << endl;
						cin.get();
						
					} else {
						
						cout << "Can't do that right now" << endl;
						cin.get();
						
					}
					
					if (data->player_health>0) {
						
						Monster_Damage = attack(x);
						data->player_health -= Monster_Damage;
						cout << "Took " << Monster_Damage << " damage" << endl;
						cin.get();
					
						if (data->player_health <= 0) {
							
							life = true;
							
						}
							
					}
					
				}
				
			}
			//needed or the player will crash the game.
			if (array[yo][xo] == array[2][0] || array[yo][xo] == array[5][0]) {
				
				array[y1][x1] = ' ';
				y1 = yo;
				x1 = xo;
				
			} else {
				yo = y1;
				xo = x1;
			}
			//checks if player has died. Player Health Made 1 for testing
			if (life == true) {
				
				cout << "You have Died, Press enter" << endl;
				cin.get();
				done = true;
				break;
				
			}
			//Mana regeneration so healing isn't abused. 
			if (data->mana < data->max_mana) {
				
				data->mana += .15;
				if (data->mana > data->max_mana) {
					
					data->mana = data->max_mana;
					
				}
				
			}
			system("clear");
	 }
}
	
bool level_check(struct variables *data) {
	
	int y = data->level;
	y++;
	if (data->temporary_exp < data->xp[y]) {
		
		return false;
		
	} else {
		
		return true;
		
	}
}
