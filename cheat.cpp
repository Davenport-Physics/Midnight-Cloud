//      cheat.cpp
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


#include "cheat.h"

void cheat(struct variables *data,int *current_gold) {
	
	char cheater[10];
	
	cout << "> ";
	cin >> cheater;
	
	
	if (strcmp(cheater,"gold") == 0) {
		
		*current_gold += 1000;
		
	} else if (strcmp(cheater,"giveme") == 0) {
		
		data->player_health = data->max_health;
		
	} else if (strcmp(cheater,"mana") == 0) {
		
		data->max_mana += 10;
		data->mana = data->max_mana;
		
	} else if (strcmp(cheater,"damn") == 0) {
		
		data->attack += 100;
		
	}
	
}

