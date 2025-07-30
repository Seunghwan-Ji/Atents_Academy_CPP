#include "Ogre.h"
#include <iostream>

using namespace std;

Ogre::Ogre(string name, int health, int attack, int defense)
	: Monster(name, health, attack, defense)
{}