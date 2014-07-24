OBJS = Ascii.o combat.o enemies.o main.o Level.o mainmenu.o mygetch.o player.o Portrait.o Journal.o Merchant.o Gold.o cheat.o music.o systemtime.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -lpthread -lSDL2 -lSDL2_mixer $(DEBUG)

mc : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o mc

Ascii.o : Ascii.h Ascii.cpp combat.h mygetch.h Level.h player.h Journal.h Merchant.h Gold.h cheat.h music.h
	$(CC) $(CFLAGS) Ascii.cpp

combat.o : combat.h combat.cpp mygetch.h enemies.h player.h Portrait.h
	$(CC) $(CFLAGS) combat.cpp

enemies.o : enemies.h enemies.cpp Ascii.h systemtime.h
	$(CC) $(CFLAGS) enemies.cpp

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

Level.o : Level.h Level.cpp Ascii.h player.h
	$(CC) $(CFLAGS) Level.cpp

mainmenu.o : mainmenu.h mainmenu.cpp player.h mygetch.h music.h
	$(CC) $(CFLAGS) mainmenu.cpp

mygetch.o : mygetch.h mygetch.cpp
	$(CC) $(CFLAGS) mygetch.cpp

player.o : player.h player.cpp Level.h systemtime.h
	$(CC) $(CFLAGS) player.cpp

Portrait.o : Portrait.h Portrait.cpp 
	$(CC) $(CFLAGS) Portrait.cpp

Journal.o : Journal.h Journal.cpp
	$(CC) $(CFLAGS) Journal.cpp

Merchant.o : Merchant.h Merchant.cpp mygetch.h player.h
	$(CC) $(CFLAGS) Merchant.cpp

Gold.o : Gold.h Gold.cpp mygetch.h
	$(CC) $(CFLAGS) Gold.cpp

cheat.o : cheat.h cheat.cpp player.h
	$(CC) $(CFLAGS) cheat.cpp

music.o : music.h music.cpp
	$(CC) $(CFLAGS) music.cpp
	
systemtime.o : systemtime.h systemtime.cpp
	$(CC) $(CFLAGS) systemtime.cpp

clean:
	\rm *.o mc


