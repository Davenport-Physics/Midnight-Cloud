//      Portrait.cpp
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
#include "Portrait.h"

void portrait(char x){
	
	switch (x) {
		case 'd':
		
			cout << "      __                 " << endl;
			cout << "     (..)                " << endl;
			cout << "      /_\\               " << endl;
			cout << "                         " << endl;
			
		break;
		case 'b':
		
			cout << "   /\\\\ " << endl;
			cout << "  //.\\\\" << endl;
			cout << "  \\\\.//    " << endl;
			cout << "  /_\\/_\\    " << endl;
			cout << "  \\ | /" << endl;
			cout << "   \\|/" << endl;
			
		break;
		case 'D':
		
			cout << "  ____" << endl;
			cout << "  |. .|" << endl;
			cout << "  | - |" << endl;
			cout << "--|   |--" << endl;
			cout << "|||\\/ |||" << endl;
			cout << "|||   |||" << endl;
			cout << "8 |   |8" << endl;
			cout << "  -----" << endl;
			cout << "  ^ ^ ^" << endl;
			
		break;
	}	
	
}

