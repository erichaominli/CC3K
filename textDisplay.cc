#include <iostream>
#include <fstream>
#include "textDisplay.h"
using namespace std;

TextDisplay::TextDisplay(): floor{1} {
	ifstream file("cc3kfloor.txt");
	int row = 0;
	int col = 0;
	char cha;
	while (file.get(cha)) {
		if (col == 0 ) {
			theDisplay.emplace_back();
		}
		if (col >= 0 && col < 80){
			theDisplay[row].emplace_back(cha);
			col++;
		}
		if (col == 80){
			col = 0;
			row++;
		}
	}
}
	
TextDisplay::~TextDisplay() {}

void TextDisplay::notify(int r, int c, char cha) {
	theDisplay[r][c] = cha;
}

void TextDisplay::newfloor(){
	ifstream file("cc3kfloor.txt");
	int row = 0;
	int col = 0;
	char cha;
	while (file.get(cha)) {
		if (col == 0 ) {
			theDisplay.emplace_back();
		}
		if (col >= 0 && col < 80){
			theDisplay[row].emplace_back(cha);
			col++;
		}
		if (col == 80){
			col = 0;
			row++;
		}
	}
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for(int row = 0; row < 25; row++){
		for(int col = 0; col < 80; col++){
			out << td.theDisplay[row][col];
		}
	}
	cout << endl;
	return out;
}

