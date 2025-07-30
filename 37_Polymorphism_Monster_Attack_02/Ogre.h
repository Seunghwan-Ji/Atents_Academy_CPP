#pragma once
#include <string>
#include "Monster.h"

class Ogre : public Monster
{
public:
	Ogre(std::string name, int health, int attack, int defense);
};