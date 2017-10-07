#include <iostream>
#include "akgoyal_team.h"
using namespace std;

Team * createTeam(int id, string uniqueTeamName, string city){
	
	//struct Team newTeam;
	//struct Team * newTeam = (struct Team*) malloc(sizeof(struct Team));
	struct Team * newTeam = new Team;
	
	newTeam->id = id;
	newTeam->uniqueTeamName = uniqueTeamName;
    newTeam->city = city;
	newTeam->numberOfPlayers = 0;
	//struct PlayerNode dummyHead;
	//struct PlayerNode * dummyHead = (struct PlayerNode*) malloc(sizeof(struct PlayerNode));
	struct PlayerNode * dummyHead = new PlayerNode;
	dummyHead->id = -1;
	dummyHead->index = -1;
	dummyHead->next = NULL;
	newTeam->linkedPlayerFirstNode = dummyHead;
	newTeam->next = NULL;
	
	return newTeam;
}

PlayerNode * createPlayerNode(int id, int index){
	
	//struct PlayerNode newPlayerNode;
	//struct PlayerNode * newPlayerNode = (struct PlayerNode*) malloc(sizeof(struct PlayerNode));
	struct PlayerNode * newPlayerNode = new PlayerNode;
	
	newPlayerNode->id = id;
	newPlayerNode->index = index;
	newPlayerNode->next = NULL;
	
	return newPlayerNode;
}