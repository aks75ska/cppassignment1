#include <iostream>
#include "akgoyal_player.h"
using namespace std;

Player::Player (int id, int teamId, string fullName, int age, string phoneNumber, string position, float salary) {

	this->id = id;
	this->teamId = teamId;
	this->fullName = fullName;
	this->age = age;
    this->phoneNumber = phoneNumber;
	this->position = position;
	this->salary = salary;

}

Player::Player() {
	this->id = -1;
}