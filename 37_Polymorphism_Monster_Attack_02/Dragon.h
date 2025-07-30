#pragma once
#include <string>
#include "Monster.h"

class Dragon : public Monster
{
public:
	Dragon(std::string name, int health, int attack, int defense);
};