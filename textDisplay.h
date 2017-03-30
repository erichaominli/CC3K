#ifndef __TEXTDIS_H__
#define __TEXTDIS_H__
#include <iostream>
#include <vector>


class TextDisplay {
	std::vector<std::vector<char>> theDisplay;
	int floor;
public:
	TextDisplay();
	void newfloor();
	void notify(int r,int c, char cha);
	~TextDisplay();
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
			

