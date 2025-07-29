#include <iostream>
#include "Dragon.h"
#include "Ogre.h"
#include "Slime.h"
#include "CrimsonRaptor.h"

using namespace std;

// ���� ����

int main() {
	Dragon dragonA("dragonA", 100, 24, 10);
	Dragon dragonB("dragonB", 90, 20, 12);

	Ogre ogreA("ogreA", 50, 10, 8);
	Ogre ogreB("ogreB", 48, 11, 9);

	Slime slimeA("slimeA", 30, 5, 5, 8);
	Slime slimeB("SlimeB", 28, 8, 7, 10);

	CrimsonRaptor crimsonRaptorA("Į���θ�A", 40, 13, 5, 30);
	CrimsonRaptor crimsonRaptorB("Į���θ�B", 40, 13, 5, 30);

	crimsonRaptorA.Attack(crimsonRaptorB);
	crimsonRaptorA.Attack(crimsonRaptorB);
	crimsonRaptorA.Attack(crimsonRaptorB);
	crimsonRaptorA.Attack(crimsonRaptorB);
	crimsonRaptorA.Attack(crimsonRaptorB);

	crimsonRaptorA.Info();

	return 0;
}