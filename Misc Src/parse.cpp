/*
 * parse.cpp
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


#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
	int count = 0;
	ifstream infile;
	
	infile.open("Enemies", ios_base::in);
	
	if (!infile.is_open()) {
		
		cout << "Enemies not found";
		return -1;
	
	}
	string buffer;
	while (!infile.eof()) {
		
		infile >> buffer;
		count++;
		
	}
	infile.close();
	
	string *line = new string[count];
	count = 0;
	
	infile.open("Enemies", ios_base::in);
	while (!infile.eof()) {
			
		infile >> line[count];	
		count++;
		
	}
	for (int x = 0 ;x < count;x++) {
		
		cout << line[x] << endl;
	}
	
	infile.close();
	delete [] line;
	
	
	return 0;
}

