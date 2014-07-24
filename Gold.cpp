//      Gold.cpp
//      
//      Copyright 2011 Unknown <ghost@Arch>
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

#include "Gold.h"

int gold()
{
	srand(time(NULL));
	int gold;
	int moregold = (1+rand()%100);
	int jackpot = (1+rand()%100);
	
	if (jackpot > 95 || jackpot < 5) {
		
		if (moregold > 95 || moregold < 5) {
			
			gold = (65+rand()%20);
			
		} else {
			
			gold = (45+rand()%15);
			
		}
		std::cout << "Gained " << gold << " Gold" << "  Jackpot!!" << std::endl;
		
	} else {
		
		if (moregold > 95 || moregold < 5) {
			
			gold = (10+rand()%20);
			
		} else {
			
			gold = (1+rand()%10);
			
		}
		std::cout << "Gained " << gold << " Gold" << std::endl;
		
	}
	mygetch();
	
	return gold;
}

