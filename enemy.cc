#include "enemy.h"

Enemy::Enemy( int HP, int baseHP, int atk, int baseAtk, int def, int baseDef, int gold, std::string race, char symbol ) : Character( HP, baseHP, atk, baseAtk, def, baseDef, gold, race, symbol, "enemy") {}

Enemy::~Enemy() {}
