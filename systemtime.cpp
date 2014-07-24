/*
 * systemtime.c
 * 
 * Copyright 2013 Michael Davenport <Michael@new-host-4.home>
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
 
 #include "systemtime.h"

struct timespec *hold;

void init_time() {
	
	hold = ( struct timespec * )malloc( sizeof( struct timespec ) );
	
}

void pause(int x) {
	
	hold->tv_sec = x/1000000000;
	hold->tv_nsec = x%1000000000;
	
	nanosleep( hold , NULL );
	

}
