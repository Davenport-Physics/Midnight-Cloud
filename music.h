/*
 * music.h
 * 
 * Copyright 2012 Michael Davenport
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


#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <pthread.h>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
using std::string;

struct player_vars {
	
	bool done;
	int x;
	
};
void *playerthread(void *n);
void playerstart(struct player_vars *data);

#endif
