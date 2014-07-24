/*
 * controls.h
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

#ifndef CONTROLS_H
#define CONTROLS_H

#include <iostream>

#include "mygetch.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define HEAL 4
#define JOURNAL 5
#define QUIT 6
#define DEBUG 7
#define ENTER 8

struct player_controls {
	
	char controls[8];
	
};

int check_controls( char c );
void set_controls();
void init_controls();

#endif
