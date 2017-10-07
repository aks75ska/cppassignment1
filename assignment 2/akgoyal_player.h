#include <iostream>
using namespace std;

struct Player {
    int id;
	int teamId;
	string fullName;
	int age;
	string phoneNumber;
	string position;
	float salary;
};

Player * createPlayer(int id, int teamId, string fullName, int age, string phoneNumber, string position, float salary);