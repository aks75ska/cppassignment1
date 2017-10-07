#include <iostream>
using namespace std;

class PlayerNode{
	public:
		int id;
		int index;
		PlayerNode * next;
		
		PlayerNode (int id, int index);
};

class Team {
	public:
		int id;
		string uniqueTeamName;
		string city;
		int numberOfPlayers;
		PlayerNode * linkedPlayerFirstNode;
		Team * next;
		
		Team (int id, string uniqueTeamName, string city);
};
