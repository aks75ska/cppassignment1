#include <iostream>
#include "akgoyal_team.h"
using namespace std;

Team::Team (int id, string uniqueTeamName, string city){
	
	this->id = id;
	this->uniqueTeamName = uniqueTeamName;
    this->city = city;
	this->numberOfPlayers = 0;
	PlayerNode * dummyHead = new PlayerNode(-1, -1);
	//dummyHead.id = -1;
	//dummyHead.index = -1;
	//dummyHead.next = NULL;
	this->linkedPlayerFirstNode = dummyHead;
	this->next = NULL;

}

PlayerNode::PlayerNode (int id, int index){
	
	this->id = id;
	this->index = index;
	this->next = NULL;

}