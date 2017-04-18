#include "character.h"
#include "player.h"
#include "enemy.h"
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "cell.h"
#include "floor.h"
#include <stdexcept>
#include <cstdlib>
#include "result.h"

bool reborn = true;
bool move = true;
bool readMap = false;
int main(int argc, const char *argv[] ) 
{
	std::ifstream file;
        if ( argc > 2 )
	{
 		std::cout << "too many arguments" << std::endl;
		return 1;
	}
	if ( argc == 2 )
	{
		std::string str = argv[1];
 		file.open( str );
		readMap = true;
	}
	else file.open("stage.txt");
	while(true){
		reborn = false;
		std::string str;
		std::cout << "Choose your race" << std::endl;
		std::cout << "(S)hade, (D)row, (V)ampire, (T)roll, (G)oblin" << std::endl;
		std::string cmd;
		Floor *floor;
		//choose character
		while(std::cin >> cmd )
		{
			if (std::cin.eof()) return 0;

			else if (cmd == "s" || cmd == "S" || cmd == "D" || cmd == "d" || cmd == "V" || cmd == "v" || cmd == "T" || cmd == "t" || cmd == "G" || cmd == "g") 
			{ 
				floor = new Floor( readMap, 1, file, cmd );
				break;
			}
			else {
				std::cout << "Try again" << std::endl; 
			}
		}
		floor->init( file );
		std::cout << *floor;
		floor->clearAction();
		std::string s;

		//action loop:  
		while(std::cin >> s)
		{
			try{
				if(s == "no" || s == "so" || s == "ea" || s == "nw" || s == "ne" || s == "se" || s == "we" || s == "sw") {
					floor->move(floor->getMainChar(), s);
					if( floor->getMainChar()->getRace() == "Troll" ) floor->getMainChar()->mutHP(5);
				} 
				if(s == "a"){
					std::string atkPos;
					std::cin >> atkPos;
					floor->attack(atkPos);
					floor->getMainChar()->clearAct();
					if( floor->getMainChar()->getRace() == "Troll" ) floor->getMainChar()->mutHP(5);
				}
				if(s == "f") { 
					move = !move;
					std::cout << "Enemy movement freeze!" << std::endl;
				}
				if(s == "q") {
					std::cout << "Admit defeat and quit the game" << std::endl;
					break;
				}
				if(s == "r") {
					floor->file.clear();
                			floor->file.seekg(0, file.beg);
					reborn = !reborn;
					Merchant::agro = false;
					break;
				}
			}
                        catch (result &t){
                                if (t.consequence == "Win") {
				std::cout << "You Win! Your final score was "<< floor->getMainChar()->getScore() << std::endl;
                                break;
                               }
                                else {
                                std::cout <<"You Lost!" << std::endl;
                                }
			}
			if(!reborn){
                                if (floor->getMainChar()->getDead()){
                                   std::cout << "You Lost!" << std::endl;
                                   return 0;
                                }
				if (move) floor->moveEnemies();
				std::cout << *floor;
				floor->clearAction();
			}
			else{
				break;
			}
		}
		if(!reborn) break;
	}
}



