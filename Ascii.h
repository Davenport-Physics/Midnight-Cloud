//      Ascii.h
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



#ifndef ASCII_H
#define ASCII_H

#include <iostream>
#include <cstdlib>
#include <pthread.h>

#include "combat.h"
#include "mygetch.h"
#include "Level.h"
#include "Journal.h"
#include "Merchant.h"
#include "Gold.h"
#include "enemies.h"
#include "music.h"
#include "controls.h"

struct info {
	
	char map[20][40];
	bool done;
	bool halt;
};

void lvl(string map,string &load,bool &done,struct variables *data);
void check(char x,string &load,int &game,bool &done,struct variables *data);

#endif



