//      enemies.h
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

#ifndef ENEMIES_H
#define ENEMIES_H

#include <iostream>
#include <cstdlib>
#include <pthread.h>

#include "Ascii.h"
#include "systemtime.h"

int attack(char x);
int health(char x);
int experience(char x);
int damageGive(int minRange,int maxRange,int Acc1,int Acc2);

void *movement(void *n);
void calculate_movement(struct info *data);
int getplayer_y(struct info *data);
int getplayer_x(int y,struct info *data);
bool closer(int py,int px,int ey,int ex,int tempy,int tempx);
bool check_place(char character);

#endif

