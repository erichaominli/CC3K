#include "player.h"

Player::Player( int HP, int baseHP, int atk, int baseAtk, int def, int baseDef, int gold, std::string race ) : Character( HP, baseHP, atk, baseAtk, def, baseDef, gold, race ) {}

Player::~Player(){}
