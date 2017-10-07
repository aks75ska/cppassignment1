#include <iostream>
using namespace std;

struct PlayerNode{
	int id;
	int index;
	PlayerNode * next;
};

struct Team {
    int id;
	string uniqueTeamName;
	string city;
	int numberOfPlayers;
	PlayerNode * linkedPlayerFirstNode;
	Team * next;
};

Team * createTeam(int id, string uniqueTeamName, string city);
PlayerNode * createPlayerNode(int id, int index);