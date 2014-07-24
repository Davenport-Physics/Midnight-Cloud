//      Merchant.cpp
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
      
#include "Merchant.h"

void display(struct variables *data,int &current_gold)
{
	bool done = false;
	int x = 0;
	int y = 1;
	int yo = y;
	char command;
	char array[4][1] = {
	{' '},
	{' '},
	{' '},
	{' '}};
	
	while (!done) {
		
		array[y][x] = '>';
		cout << " ----" << endl;
		cout << " |  |" << endl;
		cout << "------" << endl;
		cout << " |..|" << endl;
		cout << " | >|" << endl;
		cout << " ----" << endl;
		cout << endl;
		cout << "What can i help you with? " << endl;
	
		for (int row = 0;row < 4;row++) {
			
			for (int column = 0;column < 1;column++) {
				
				cout << array[row][column];
				
			}
			switch (row) {
				case 1:
				
					cout << "Buy" << endl;
					
				break;
				case 3:
				
					cout << "Sell" << endl;
					
				break;
			}
			cout << endl;
			
		}
		command = mygetch();
		
		switch (command) {
			case 's':
			
				y += 2;
				if (y > 3) {
					
					y -= 2;
					
				} else {
					
					array[yo][x] = ' ';
					yo = y;
					
				}
				
			break;
			case 'w':
			
				y -= 2;
				if (y < 0) {
					
					y += 2;
					
				} else {
					
					array[yo][x] = ' ';
					yo = y;
					
				}
				
			break;
			case '\n':
			
				switch (y) {
					case 1:
				
						buy(data,current_gold);
					
					break;
					case 3:
				
						sell();
					
					break;	
				}
			break;
			case 'q':
			case 'Q':
			
				cout << "Goodbye!" << endl;
				std::cin.get();
				done = true;
				
			break;
		}
		
	system("clear");
	
	}
	
}
void buy(struct variables *data, int &current_gold) {
	
	system("clear");
	bool done = false;
	char command;
	int x = 0;
	int y = 0;
	int yo = y;
	char array[5][1] = {
	{' '},
	{' '},
	{' '},
	{' '},
	{' '}};
	string *objects = new string[3];
	int *ID = new int[3];
	
	itemName(objects,ID);
	
	while (!done) {
		
		cout << "Well what would you like to buy? " << endl;
		cout << endl;
		array[y][x] = '>';
		for (int row = 0;row < 5;row++) {
			
			for (int column = 0;column < 1;column++) {
				
				cout << array[row][column];
				switch (row) {
					case 0:
					
						cout << objects[0] << " selling for " << itemCost(ID[0]) << " Gold." << endl;
						
					break;
					case 2:
					
						cout << objects[1] << " selling for " << itemCost(ID[1]) << " Gold." << endl;
						
					break;
					case 4:
					
						cout << objects[2] << " selling for " << itemCost(ID[2]) << " Gold." << endl;
						
					break;
				}
				
			}
			cout << endl;
			
		}
		command = mygetch();
		switch (command) {
			case 's':
			
				y += 2;
				if (y > 4) {
					
					y = yo;
					
				} else {
					
					array[yo][x] = ' ';
					yo = y;
					
				}
			
			break;
			case 'w':
			
				y -= 2;
				if (y < 0) {
					
					y = yo;
					
				} else {
					
					array[yo][x] = ' ';
					yo = y;
					
				}
				
			break;
			case '\n':
			
				switch (y) {
				case 0:
				
					item(ID[0],data,current_gold);
					
				break;
				case 2:
				
					item(ID[1],data,current_gold);
					
				break;
				case 4:
				
					item(ID[2],data,current_gold);
					
				break;
				
				}
			break;
			case 'q':
			cout << "Ok" << endl;
			std::cin.get();
			done = true;
			break;
		}
		system("clear");
	}
	delete [] ID;
	delete [] objects;
}
void sell() {
	cout << "This has yet to be implementated" << endl;
	std::cin.get();
}
void item(int ID,struct variables *data, int &current_gold) {
	
	char command;
	string description = itemDescription(ID);
	
	cout << description << endl;
	cout << "Would you like to buy this item? y/n" << endl;
	
	command = mygetch();
	if (command == 'y' || command == '\n') 
		check(ID,data,current_gold);
	
}
string itemDescription(int ID) {
	
	string description[8];
	description[0] = "Increase your attack by 2";
	description[1] = "Increase your attack by 5";
	description[2] = "Increases mana by .5";
	description[3] = "Increases mana by 1";
	description[4] = "Increases health by 3";
	description[5] = "Increases health by 8";
	description[6] = "Increases mana regeneration by .5";
	description[7] = "Increases mana regeneration by 1.5";
	
	return description[ID];
	
}
void itemName(string name[],int ID[]) {
	
	string *nameprop = new string[10];
	nameprop[0] = "Small Sword";
	nameprop[1] = "Long Sword";
	nameprop[2] = "Small Mana Potion";
	nameprop[3] = "Mana Potion";
	nameprop[4] = "Small Health Potion";
	nameprop[5] = "Health Potion";
	nameprop[6] = "Small Mana Blue";
	nameprop[7] = "Large Mana Blue";
	
	srand(time(NULL));
	int x;
	
	for (int y=0;y<3;y++) {
		
		x = rand()%8;
		name[y] = nameprop[x];
		ID[y] = x;
		
	}
	delete [] nameprop;
}
int itemCost(int ID) {
	
	int cost[8];
	cost[0] = 100;
	cost[1] = 150;
	cost[2] = 50;
	cost[3] = 75;
	cost[4] = 25;
	cost[5] = 50;
	cost[6] = 500;
	cost[7] = 1000;
	
	return cost[ID];
	
}
void check(int ID,struct variables *data, int &current_gold) {
	
	int cost = itemCost(ID); 
	 
	
	if (cost < current_gold) {
		
		current_gold -= cost;
		cout << "Thank you, come again!" << endl;
		stats(ID,data);
		
	} else {
		
		cout << "Sorry you don't have enough gold, come back again when you do!" << endl;
		
	}
	std::cin.get();
	std::cin.get();
}
void stats(int ID,struct variables *data) {
	
	//Stats used for health, and attack. Float used for mana etc.
	int *stats = new int[5];
	stats[0] = 2;
	stats[1] = 4;
	stats[4] = 3;
	stats[5] = 8;
	float *general = new float[8];
	general[2] = .5;
	general[3] = 1;
	general[6] = .5;
	general[7] = 1.5;
	
	switch (ID) {
		case 0:
		case 1:
		
			data->attack+=stats[ID];
			
		break;
		case 2:
		case 3:
		
			data->max_mana+=general[ID];
			
		break;
		case 4:
		case 5:
		
			data->max_health+=stats[ID];
			
		break;
		case 6:
		case 7:
		
			data->mana_regen+=general[ID]; 
			
		break;
		default:
		
			cout << "Item ID not found";
			
		break;
	}
	delete [] stats;
	delete [] general;
}

