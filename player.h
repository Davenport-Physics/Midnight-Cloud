//      player.h
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
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "systemtime.h"
#include "Level.h"
#include "Ascii.h"
#include "cheat.h"

using namespace std;

struct variables {
	
	int player_health;
	int max_health;
	int level;
	int temporary_exp;
	int x,y;
	int map;
	int xp[30];
	int attack;
	char player_name[50];
	float mana;
	float max_mana;
	float mana_regen;
		
};

void xp_int( struct variables *data );
void controls();
void file( bool newgame , string &load );
void name( string &load );
void Loadgame( string &load );
void Savegame( string &load , struct variables *data );
void Player_Health( void *n );
int Player_Damage( struct variables *data );
int health_regeneration( struct variables *data );
#endif

