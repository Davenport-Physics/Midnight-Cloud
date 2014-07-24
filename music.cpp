/*
 * music.cpp
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


#include "music.h"

void *playerthread(void *n) {
	
	struct player_vars *data = (struct player_vars *)n;
	playerstart(data);
	
	pthread_exit(NULL);
}

void playerstart(struct player_vars *data) {
	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return;
		
	}
	int audio_rate = 22050;
	Uint16 audio_format = AUDIO_S16SYS;
	int audio_channels = 2;
	int audio_buffers = 4096;
 
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		
		fprintf(stderr, "Unable to initialize audio: %s\n", Mix_GetError());
		return;
		
	}

	Mix_Music *music;
	
	switch (data->x) {
		
		case -1: music = Mix_LoadMUS("Music/title1.ogg"); break;
		case 0: music = Mix_LoadMUS("Music/map1.ogg"); break;
		case 1: music = Mix_LoadMUS("Music/map2.ogg"); break;
		default: return; break;
		
	}
	if (music == NULL) {
		 
		printf("Unable to load Ogg file: %s\n", Mix_GetError()); 
		return;
		
	} 
	if (Mix_PlayMusic(music, 2) == -1) {
		
		 printf("Unable to play Ogg file: %s\n", Mix_GetError());
		 return;
		 
	}
	
	while (!data->done) {
		
		SDL_Delay(100);
	}
	
	Mix_HaltMusic();
	Mix_FreeMusic(music);
	Mix_CloseAudio(); 
	 
}
