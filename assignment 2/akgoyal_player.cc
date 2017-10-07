#include <iostream>
#include "akgoyal_player.h"
using namespace std;

Player * createPlayer(int id, int teamId, string fullName, int age, string phoneNumber, string position, float salary) {
	
	//struct Player newPlayer;
	//struct Player * newPlayer = (struct Player*) malloc(sizeof(struct Player));
	struct Player * newPlayer = new Player;
	
	newPlayer->id = id;
	newPlayer->teamId = teamId;
	newPlayer->fullName = fullName;
	newPlayer->age = age;
    newPlayer->phoneNumber = phoneNumber;
	newPlayer->position = position;
	newPlayer->salary = salary;
	
	return newPlayer;
}