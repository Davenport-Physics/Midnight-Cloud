/*
 * controls.cpp
 * 
 * Copyright 2014 Michael Davenport <Davenport.physics@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "controls.h"

using std::cout;

static struct player_controls pc;

int check_controls( char c ) {
	
	for ( int x = 0; x < 9; x++ ) {
	
		if ( c == pc.controls[x] ) {
		
			return x;
			
		}
		
	}

	return -1;
}

void set_controls() {

	bool done = false;
	
	while (done == false) {

		for ( int x = 0; x < 8; x++ ) {
	
			switch (x) {
			
				case 0: cout << "Up: "; break;
				case 1: cout << "Down: "; break;
				case 2: cout << "Left: "; break;
				case 3: cout << "Right: "; break;
				case 4: cout << "Heal: "; break;
				case 5: cout << "Journal: "; break;
				case 6: cout << "Quit: "; break;
				case 7: cout << "Debug: "; break;
		
			}
			pc.controls[x] = mygetch();
			cout << '\n';
		
		}
		done = true;
		for (int y = 0; y < 7; y++) {
			
			if (done == false) {
			
				break;
				
			}
			
			for ( int x = (y+1); x < 8; x++ ) {
			
				if ( pc.controls[y] == pc.controls[x] ) {
				
					cout << "Found a duplicate, please enter unique controls";
					
					done = false;
					break;	
			
				}
		
			}
		}
		
	}

}

void init_controls() {
	
	pc.controls[0] = 'w';
	pc.controls[1] = 's';
	pc.controls[2] = 'a';
	pc.controls[3] = 'd';
	pc.controls[4] = 'h';
	pc.controls[5] = 'j';
	pc.controls[6] = 'q';
	pc.controls[7] = 'c';
	pc.controls[8] = '\n';

}
