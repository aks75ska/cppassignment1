#include <iostream>
#include "akgoyal_player.h"
#include "akgoyal_team.h"
using namespace std;

enum SearchCriteria{
  NAME = 0,
  ID,
  SALARY
};

bool createAndRunTestCases();

void showMenu();
void runProgram();

bool menuOne();
bool menuTwo();
bool menuThree();
bool menuFour();
bool menuFive();
bool menuSix();
bool menuSeven();
bool menuEight();
bool menuNine();
bool menuTen();
bool menuEleven();
bool menuTwelve();


bool validateTeam(int id, string name);
bool validatePlayer(int id, int teamId, string phone);


bool findAndDisplayPlayerWithId(int id);
bool findAndDisplayPlayerWithName(string name);
bool findAndDisplayPlayerWithPhone(string phone);

bool displayTeamInfoAndPlayers(string teamName);

int addPlayerToArray(Player addThisPlayer);
bool addTeamToList(Team * addThisTeam);
bool addPlayerToTeam(Team * teamNode, PlayerNode * newPlayer);

bool sortAllPlayers(SearchCriteria criteria);
bool sortAllPlayersOfATeam(string teamName, SearchCriteria criteria);

void showAllPlayers();