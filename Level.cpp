//      Level.cpp
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
#include "Level.h"

string draw(int x,struct variables *data){
	
	string list[30];
	list[0] = "Maps/Map0";
	list[1] = "Maps/Map1";
	list[2] = "Maps/Map2";
	
	return list[x];
	
}
void stop(bool &done) {
	char check;
	
	cout << "Do you want to stop? y/n" << endl;
	check = cin.get();
	
	if (check == 'y') {
		
		done = true;
		
	} else {
		
		done = false;
		
	}
}
