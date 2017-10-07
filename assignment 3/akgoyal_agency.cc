#include <iostream>
#include "akgoyal_agency.h"

using namespace std;

Player players[50];

Team * teamsRootNode = new Team(-1, "DUMMY", "DUMMY");
//Team * teamsRootNode = &teamRootNodeValue;

bool sortAllPlayersOfATeam(string teamName, SearchCriteria criteria){
	Team * teamCounter = teamsRootNode;
	bool teamFound = false;
	while(teamCounter->next != NULL){
		if(teamCounter->next->uniqueTeamName == teamName){
			teamFound = true;
			break;
		}
		teamCounter = teamCounter->next;
	}
	if(teamFound == false){
		cout<<"\nTeam not found!!";
		return false;
	}
	//now we have found our team. teamCounter->next points to our team.
	PlayerNode * playerCounter = teamCounter->next->linkedPlayerFirstNode;
	int numberOfPlayers = teamCounter->next->numberOfPlayers;
	if(playerCounter->next == NULL){
		cout<<"No players found in the team!!";
		return false;
	}
	playerCounter = playerCounter->next;
	//now we have found the linked list of players to be sorted. Lets sort it based on criteria. playerCounter points to the first player
	if(criteria == ID){
		PlayerNode * temphead = playerCounter;
		int tempid;
		for (int j=0; j<numberOfPlayers; j++)
		{
			while (temphead->next)  //iterate through list until next is null
			{
				if (temphead->id > temphead->next->id)
				{
					tempid = temphead->id;
					temphead->id = temphead->next->id;
					temphead->next->id = tempid;
					temphead = temphead->next;//increment node
				}
				else {
					temphead = temphead->next;//increment node
				}
			}	
			temphead = playerCounter;//reset temphead
		}
	}
	else if(criteria == NAME){
		string nameFirst = "DUMMY1";
		string nameSecond = "DUMMY2";
		PlayerNode * temphead = playerCounter;
		int tempid;
		for (int j=0; j<numberOfPlayers; j++)
		{
			while (temphead->next)  //iterate through list until next is null
			{
				for(int e=0; e<50; e++){
					if(players[e].id == temphead->id){
						nameFirst = players[e].fullName;
						break;
					}
				}
				for(int e=0; e<50; e++){
					if(players[e].id == temphead->next->id){
						nameSecond = players[e].fullName;
						break;
					}
				}
				if (nameFirst > nameSecond)
				{
					tempid = temphead->id;
					temphead->id = temphead->next->id;
					temphead->next->id = tempid;
					temphead = temphead->next;//increment node
				}
				else {
					temphead = temphead->next;//increment node
				}
			}	
			temphead = playerCounter;//reset temphead
		}
	}
	else if(criteria == SALARY){
		float salaryFirst = 0;
		float salarySecond = 0;
		PlayerNode * temphead = playerCounter;
		int tempid;
		for (int j=0; j<numberOfPlayers; j++)
		{
			while (temphead->next)  //iterate through list until next is null
			{
				for(int e=0; e<50; e++){
					if(players[e].id == temphead->id){
						salaryFirst = players[e].salary;
						break;
					}
				}
				for(int e=0; e<50; e++){
					if(players[e].id == temphead->next->id){
						salarySecond = players[e].salary;
						break;
					}
				}
				if (salaryFirst < salarySecond)
				{
					tempid = temphead->id;
					temphead->id = temphead->next->id;
					temphead->next->id = tempid;
					temphead = temphead->next;//increment node
				}
				else {
					temphead = temphead->next;//increment node
				}
			}	
			temphead = playerCounter;//reset temphead
		}
	}
	else{
		cout<<"\nSearch criteria did not match!";
		return false;
	}
	//if we reach here means playerCounter points to the first player after sort. now we need to show them all
	Player playerThis;
	for(int e=0; e<50; e++){
		if(players[e].id == playerCounter->id){
			playerThis = players[e];
			break;
		}
	}
	int counter = 1;
	cout<<"\n\n#"<<counter;
	cout<<"\nPlayer id: "<<playerThis.id;
	cout<<"\nPlayer name: "<<playerThis.fullName;
	cout<<"\nPlayer team id: "<<playerThis.teamId;
	cout<<"\nPlayer age: "<<playerThis.age;
	cout<<"\nPlayer phone: "<<playerThis.phoneNumber;
	cout<<"\nPlayer position: "<<playerThis.position;
	cout<<"\nPlayer salary: "<<playerThis.salary;
	while(playerCounter->next != NULL){
		for(int e=0; e<50; e++){
			if(players[e].id == playerCounter->next->id){
				playerThis = players[e];
				break;
			}
		}
		cout<<"\n\n#"<<counter;
		cout<<"\nPlayer id: "<<playerThis.id;
		cout<<"\nPlayer name: "<<playerThis.fullName;
		cout<<"\nPlayer team id: "<<playerThis.teamId;
		cout<<"\nPlayer age: "<<playerThis.age;
		cout<<"\nPlayer phone: "<<playerThis.phoneNumber;
		cout<<"\nPlayer position: "<<playerThis.position;
		cout<<"\nPlayer salary: "<<playerThis.salary;

		playerCounter = playerCounter->next;
		counter++;
	}
	return true;
}

bool sortAllPlayers(SearchCriteria criteria){
	if(criteria == ID){
		Team * teamCounter = teamsRootNode;
		int largest, last;
		Player temp;
		for(last = 49; last>=1; --last){
			int indexSoFar = 0, currentIndex;
			for(currentIndex=1; currentIndex<last+1; ++currentIndex){
				if(players[currentIndex].id > players[indexSoFar].id){
					indexSoFar = currentIndex;
				}
			}
			largest = indexSoFar;
			temp = players[largest];
			players[largest] = players[last];
			players[last] = temp;
			//we need to change the index in the linked list as well
			while(teamCounter->next != NULL){
				if(teamCounter->next->id == players[last].teamId){
					//now we have found our team. We need to traverse through the players node to find our player node
					struct PlayerNode * playerCounter = teamCounter->next->linkedPlayerFirstNode;
					while(playerCounter->next != NULL){
						if(players[last].id != -1 && players[last].id == playerCounter->next->id){
							playerCounter->next->index = last;
							break;
						}
						playerCounter = playerCounter->next;
					}
					break;
				}
				teamCounter = teamCounter->next;
			}
		}
	}
	else if(criteria == NAME){
		Team * teamCounter = teamsRootNode;
		int largest, last;
		Player temp;
		for(last = 49; last>=1; --last){
			int indexSoFar = 0, currentIndex;
			for(currentIndex=1; currentIndex<last+1; ++currentIndex){
				if(players[currentIndex].fullName > players[indexSoFar].fullName){
					indexSoFar = currentIndex;
				}
			}
			largest = indexSoFar;
			temp = players[largest];
			players[largest] = players[last];
			players[last] = temp;
			//we need to change the index in the linked list as well
			while(teamCounter->next != NULL){
				if(teamCounter->next->id == players[last].teamId){
					//now we have found our team. We need to traverse through the players node to find our player node
					struct PlayerNode * playerCounter = teamCounter->next->linkedPlayerFirstNode;
					while(playerCounter->next != NULL){
						if(players[last].id != -1 && players[last].id == playerCounter->next->id){
							playerCounter->next->index = last;
							break;
						}
						playerCounter = playerCounter->next;
					}
					break;
				}
				teamCounter = teamCounter->next;
			}
		}
	}
	else if(criteria == SALARY){
		Team * teamCounter = teamsRootNode;
		int smallest, last;
		Player temp;
		for(last = 49; last>=1; --last){
			int indexSoFar = 0, currentIndex;
			for(currentIndex=1; currentIndex<last+1; ++currentIndex){
				if(players[currentIndex].salary < players[indexSoFar].salary){
					indexSoFar = currentIndex;
				}
			}
			smallest = indexSoFar;
			temp = players[smallest];
			players[smallest] = players[last];
			players[last] = temp;
			//we need to change the index in the linked list as well
			while(teamCounter->next != NULL){
				if(teamCounter->next->id == players[last].teamId){
					//now we have found our team. We need to traverse through the players node to find our player node
					struct PlayerNode * playerCounter = teamCounter->next->linkedPlayerFirstNode;
					while(playerCounter->next != NULL){
						if(players[last].id != -1 && players[last].id == playerCounter->next->id){
							playerCounter->next->index = last;
							break;
						}
						playerCounter = playerCounter->next;
					}
					break;
				}
				teamCounter = teamCounter->next;
			}
		}
	}
	else{
		cout<<"\nSearch criteria did not match!";
		return false;
	}
	return true;
}

bool findAndDisplayPlayerWithId(int id){
	bool playerFound = false;
	for(int i=0; i<50; i++){
		if(players[i].id != -1 && players[i].id == id){
			cout<<"\nPlayer found!!";
			cout<<"\nPlayer Id: "<<players[i].id;
			cout<<"\nPlayer Name: "<<players[i].fullName;
			cout<<"\nPlayer Age: "<<players[i].age;
			cout<<"\nPlayer Phone: "<<players[i].phoneNumber;
			cout<<"\nPlayer Position: "<<players[i].position;
			cout<<"\nPlayer Salary: "<<players[i].salary;
			playerFound = true;
			return true;
		}
	}
	if(playerFound == false){
		cout<<"\nPlayer not found!!!";
		return false;
	}
}

bool findAndDisplayPlayerWithName(string name){
	bool playerFound = false;
	for(int i=0; i<50; i++){
		if(players[i].id != -1 && players[i].fullName == name){
			cout<<"\nPlayer found!!";
			cout<<"\nPlayer Id: "<<players[i].id;
			cout<<"\nPlayer Name: "<<players[i].fullName;
			cout<<"\nPlayer Age: "<<players[i].age;
			cout<<"\nPlayer Phone: "<<players[i].phoneNumber;
			cout<<"\nPlayer Position: "<<players[i].position;
			cout<<"\nPlayer Salary: "<<players[i].salary;
			playerFound = true;
			return true;
		}
	}
	if(playerFound == false){
		cout<<"\nPlayer not found!!!";
		return false;
	}
}

bool findAndDisplayPlayerWithPhone(string phone){
	bool playerFound = false;
	for(int i=0; i<50; i++){
		if(players[i].id != -1 && players[i].phoneNumber == phone){
			cout<<"\nPlayer found!!";
			cout<<"\nPlayer Id: "<<players[i].id;
			cout<<"\nPlayer Name: "<<players[i].fullName;
			cout<<"\nPlayer Age: "<<players[i].age;
			cout<<"\nPlayer Phone: "<<players[i].phoneNumber;
			cout<<"\nPlayer Position: "<<players[i].position;
			cout<<"\nPlayer Salary: "<<players[i].salary;
			playerFound = true;
			return true;
		}
	}
	if(playerFound == false){
		cout<<"\nPlayer not found!!!";
		return false;
	}
}

bool displayTeamInfoAndPlayers(string teamName){
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////test
	//cout<<"\nTESTING ARRAY";
	/*for(int i=0; i<50; i++){
		if(players[i].id != -1){
			cout<<"\nPlayer found: "<<players[i].fullName;
			cout<<"\nPlayer id: "<<players[i].id;
			cout<<"\nPlayer teamId: "<<players[i].teamId;
		}
	}*/
	bool teamFound = false;
	Team * teamCounter = teamsRootNode;
	while(teamCounter->next != NULL){
		if(teamCounter->next->uniqueTeamName == teamName){
			cout<<"\n\n\nTeam found!!";
			cout<<"\nTeam Name: "<<teamCounter->next->uniqueTeamName;
			PlayerNode * playerCounter = teamCounter->next->linkedPlayerFirstNode;
			cout<<"\nNumber of players: "<<teamCounter->next->numberOfPlayers;
			for(int j=0; j<teamCounter->next->numberOfPlayers+1; j++){
				int playerId = playerCounter->id;
				for(int i=0; i<50; i++){
					if(players[i].id != -1 && players[i].id == playerId){
						cout<<"\n\nPlayer of this team found!!";
						cout<<"\nPlayer Id: "<<players[i].id;
						cout<<"\nPlayer Name: "<<players[i].fullName;
						cout<<"\nPlayer Age: "<<players[i].age;
						cout<<"\nPlayer Phone: "<<players[i].phoneNumber;
						cout<<"\nPlayer Position: "<<players[i].position;
						cout<<"\nPlayer Salary: "<<players[i].salary;
						break;
					}
				}
				playerCounter = playerCounter->next;
			}
			teamFound = true;
			return true;
		}
		teamCounter = teamCounter->next;
	}
	if(teamFound == false){
		cout<<"\nTeam not found!!!";
		return false;
	}
}

int addPlayerToArray(Player addThisPlayer){
	for(int i=0; i<50; i++){
		if(players[i].id == -1){
			players[i] = addThisPlayer;
			return i;
		}
	}
	cout<<"\nCould not add player to array";
	return -1;
}

bool addTeamToList(Team * addThisTeam){
	//cout<<"\ncame to addTeamToList";
	Team * teamCounter = teamsRootNode;
	while(teamCounter->next != NULL){
		//cout<<"\nCame inside while in addTeamToList";
		teamCounter = teamCounter->next;
	}
	teamCounter->next = addThisTeam;
	//cout<<"\ndifficult territory";
	//cout<<"\nteamCounter.next->id "<<teamCounter->next->id;
	//cout<<"\nteamCounter.next->uniqueTeamName "<<teamCounter->next->uniqueTeamName;
	//cout<<"\nteamCounter.next->city "<<teamCounter->next->city;
	//free(teamCounter);
	//delete teamCounter;
	return true;
}

bool addPlayerToTeam(Team * teamNode, PlayerNode * newPlayer){
	PlayerNode * playerNodeCounter = teamNode->linkedPlayerFirstNode;
	while(playerNodeCounter->next != NULL){
		playerNodeCounter = playerNodeCounter->next;
	}
	playerNodeCounter->next = newPlayer;
	teamNode->numberOfPlayers = teamNode->numberOfPlayers + 1;
	return true;
}

void showMenu(){
	//cout<<"\n\nWelcome to assignment 2!!!!";
	cout<<"\n<<------------Menu----------->>>>";
	cout<<"\n1.Create team";
	cout<<"\n2.Create player";
	cout<<"\n3.Display players of a team";
	cout<<"\n4.Find player with id";
	cout<<"\n5.Find player with name";
	cout<<"\n6.Find player with phone number";
	cout<<"\n7.Sort players by id (ascending)";
	cout<<"\n8.Sort players by name (ascending)";
	cout<<"\n9.Sort players by salary (descending)";
	cout<<"\n10.Sort players of a team by id (ascending)";
	cout<<"\n11.Sort players of a team by name (ascending)";
	cout<<"\n12.Sort players of a team by salary (descending)";
	cout<<"\n13.Automatic testing. This will create 2 teams and 5 players, then test all options automatically and display result on screen";
	cout<<"\n14.Quit";
	cout<<"\n--------->Enter an option (1-14): ";
}

bool validateTeam(int id, string name){
	//cout<<"\nvalidate team begins";
	Team * teamCounter = teamsRootNode;
	//cout<<"\nvalidate team team counter initialized";
	//cout<<"\nteam counter id "<<teamCounter->id;
	//cout<<"\nteam counter team name "<<teamCounter->uniqueTeamName;
	//cout<<"\nteam counter team next "<<teamCounter->next;
	//cout<<"\nteam counter city "<<teamCounter->city;
	while(teamCounter->next != NULL){
		//cout<<"\ncame inside while";
		//cout<<"\nTESTING BEGINS";
		//cout<<"\nid "<<id;
		//cout<<"\nname "<<name;
		//cout<<"\nteamCounter->next->id "<<teamCounter->next->id;
		//cout<<"\nteamCounter->next->uniqueTeamName "<<teamCounter->next->uniqueTeamName;;
		if(teamCounter->next->id == id || teamCounter->next->uniqueTeamName == name){
			cout<<"\nteam id or name already there";
			return false;
		}
		teamCounter = teamCounter->next;
	}
	return true;
}

bool menuOne(){
	int teamId;
	string uniqueName, city;
	cout<<"\nCreate a Team!!!";
	cout<<"\nEnter team id (natural number): ";
	cin>>teamId;
	cin.ignore();
	cout<<"\nEnter team unique name: ";
	//cin>>uniqueName;
	getline(cin, uniqueName);
	cout<<"\nEnter team city: ";
	//cin>>city;
	getline(cin, city);
	bool validation = validateTeam(teamId, uniqueName);
	//cout<<"\nAfter validate is returned "<<validation;
	if(validation==true){
		//cout<<"\nTeam validation was passed!!";
		Team * newTeam = new Team(teamId, uniqueName, city);
		//Team * newTeam = &newTeamValue;
		//cout<<"\nnew team id "<<newTeam->id;
		//cout<<"\nnew team name "<<newTeam->uniqueTeamName;
		//cout<<"\nnew team city "<<newTeam->city;
		//cout<<"\nnew team next "<<newTeam->next;
		bool addTeamToListAnswer = addTeamToList(newTeam);
		//cout<<"\naddTeamToListAnswer: "<<addTeamToListAnswer;
		return true;
	}
	else{
		cout<<"\nTeam validation was failed!!";
		return false;
	}
	return false;
}

bool validatePlayer(int id, int teamId, string phone){
	//cout<<"\ninside validate player";
	Team * teamCounter = teamsRootNode;
	bool teamFound = false;
	while(teamCounter->next != NULL){
		if(teamCounter->next->id == teamId){
			//cout<<"\nTEAM WAS FOUND inside validatePlayer. returning true!!";
			teamFound = true;
			break;
		}
		teamCounter = teamCounter->next;
	}
	if(teamFound == false){
		cout<<"\nTeam not found in validation function!!!!";
		return false;
	}
	//if compiler comes here means team is found
	//cout<<"\nbefore for loop in validatePlayer";
	for(int i=0; i<50; i++){
		if(players[i].id != -1 && (players[i].id == id || players[i].phoneNumber == phone) ){
			cout<<"\nPlayer id or phone already there!!";
			return false;
		}
	}
	return true;
}

bool menuTwo(){
	int id, teamId, age;
	string name, phone, position;
	float salary;
	cout<<"\nCreate Player!!!";
	cout<<"\nEnter a valid team id: ";
	cin>>teamId;
	cin.ignore();
	cout<<"\nEnter the player id (natural number): ";
	cin>>id;
	cin.ignore();
	cout<<"\nEnter player full name: ";
	//cin>>name;
	getline(cin, name);
	cout<<"\nEnter player age: ";
	cin>>age;
	cin.ignore();
	cout<<"\nEnter player phone number: ";
	//cin>>phone;
	getline(cin, phone);
	cout<<"\nEnter player position: ";
	//cin>>position;
	getline(cin, position);
	cout<<"\nEnter player salary: ";
	cin>>salary;
	cin.ignore();
	//cout<<"\nbefore calling validatePlayer";
	bool validation = validatePlayer(id, teamId, phone);
	if(validation == true){
		//cout<<"validation was successful!!";
		Player * newPlayer = new Player(id, teamId, name, age, phone, position, salary);
		//Player * newPlayer = &newPlayerValue;
		int addPlayerToArrayIndex = addPlayerToArray(*newPlayer);
		//we have no need of new player pointer now. we can free the memory
		delete newPlayer;
		//cout<<"\addPlayerToArrayIndex: "<<addPlayerToArrayIndex;
		if(addPlayerToArrayIndex != -1){
			//now we need to find the team in which to add the player
			Team * teamCounter = teamsRootNode;
			bool teamFound = false;
			while(teamCounter->next != NULL){
				if(teamCounter->next->id == teamId){
					PlayerNode * newPlayerNode = new PlayerNode(id, addPlayerToArrayIndex);
					//PlayerNode * newPlayerNode = &newPlayerNodeValue;
					bool addPlayerToTeamAnswer = addPlayerToTeam(teamCounter->next, newPlayerNode);
					//cout<<"addPlayerToTeamAnswer: "<<addPlayerToTeamAnswer;
					teamFound = true;
					break;
				}
				teamCounter = teamCounter->next;
			}
			if(teamFound == false){
				cout<<"Team not found!!!!";
				return false;
			}
			return true;
		}
		else{
			cout<<"player was not added to array. exiting!";
			return false;
		}	
	}
	else{
		return false;
	}
	return false;
}

bool menuThree(){
	string teamName;
	cout<<"\nShow Team info and Players!!!!!";
	cout<<"\nEnter team name: ";
	//cin>>teamName;
	getline(cin, teamName);
	bool result = displayTeamInfoAndPlayers(teamName);
	//cout<<"\ndisplayTeamInfoAndPlayers result: "<<result;
	return result;
}

bool menuFour(){
	int id;
	cout<<"\nFind Player with id!!!!!";
	cout<<"\nEnter player id: ";
	cin>>id;
	cin.ignore();
	bool result = findAndDisplayPlayerWithId(id);
	//cout<<"\nfindAndDisplayPlayerWithId result: "<<result;
	return result;
}

bool menuFive(){
	string name;
	cout<<"\nFind player with name!!!!!";
	cout<<"\nEnter player name: ";
	//cin>>name;
	getline(cin, name);
	bool result = findAndDisplayPlayerWithName(name);
	//cout<<"\nfindAndDisplayPlayerWithName result"<<result;
	return result;
}

bool menuSix(){
	string phone;
	cout<<"\nFind player with phone number!!!!!";
	cout<<"\nEnter player phone: ";
	//cin>>phone;
	getline(cin, phone);
	bool result = findAndDisplayPlayerWithPhone(phone);
	//cout<<"\findAndDisplayPlayerWithPhone result"<<result;
	return result;
}

bool menuSeven(){
	cout<<"\nSort Players by Id--------->>>";
	SearchCriteria criteria = ID;
	bool result = sortAllPlayers(criteria);
	if(result==true){
		showAllPlayers();
	}
	else{
		cout<<"\nPlayers could not be sorted!!!";
		return false;
	}
	return true;
}

bool menuEight(){
	cout<<"\nSort Players by Name--------->>>";
	SearchCriteria criteria = NAME;
	bool result = sortAllPlayers(criteria);
	if(result==true){
		showAllPlayers();
	}
	else{
		cout<<"\nPlayers could not be sorted!!!";
		return false;
	}
	return true;
}

bool menuNine(){
	cout<<"\nSort Players by Salary--------->>>";
	SearchCriteria criteria = SALARY;
	bool result = sortAllPlayers(criteria);
	if(result==true){
		showAllPlayers();
	}
	else{
		cout<<"\nPlayers could not be sorted!!!";
		return false;
	}
	return true;
}

bool menuTen(){
	string teamName;
	SearchCriteria criteria = ID;
	cout<<"\nSort players of a team by Id---------->";
	cout<<"\nEnter team name: ";
	//cin>>teamName;
	getline(cin, teamName);
	bool result = sortAllPlayersOfATeam(teamName, criteria);
	if(result==true){
		cout<<"Everything is fine!";
	}
	else{
		cout<<"\nPlayers could not be sorted!!!";
		return false;
	}
}

bool menuEleven(){
	string teamName;
	SearchCriteria criteria = NAME;
	cout<<"\nSort players of a team by Name---------->";
	cout<<"\nEnter team name: ";
	//cin>>teamName;
	getline(cin, teamName);
	bool result = sortAllPlayersOfATeam(teamName, criteria);
	if(result==true){
		cout<<"Everything is fine!";
	}
	else{
		cout<<"\nPlayers could not be sorted!!!";
		return false;
	}
}

bool menuTwelve(){
	string teamName;
	SearchCriteria criteria = SALARY;
	cout<<"\nSort players of a team by Salary---------->";
	cout<<"\nEnter team name: ";
	//cin>>teamName;
	getline(cin, teamName);
	bool result = sortAllPlayersOfATeam(teamName, criteria);
	if(result==true){
		cout<<"Everything is fine!";
	}
	else{
		cout<<"\nPlayers could not be sorted!!!";
		return false;
	}
}

void showAllPlayers(){
	int counter = 1;
	for(int i=0; i<50; i++){
		if(players[i].id != -1){
			cout<<"\n\n#"<<counter;
			cout<<"\nPlayer id: "<<players[i].id;
			cout<<"\nPlayer name: "<<players[i].fullName;
			cout<<"\nPlayer team id: "<<players[i].teamId;
			cout<<"\nPlayer age: "<<players[i].age;
			cout<<"\nPlayer phone: "<<players[i].phoneNumber;
			cout<<"\nPlayer position: "<<players[i].position;
			cout<<"\nPlayer salary: "<<players[i].salary;
			counter++;
		}
	}
}

void runProgram(){
	string optionSelect = "";
	showMenu();
	//cin>>optionSelect;
	getline(cin, optionSelect);
	//cin.ignore();
	while(optionSelect!="1" && optionSelect!="2" && optionSelect!="3" && optionSelect!="4" && optionSelect!="5" && optionSelect!="6" && optionSelect!="7" && optionSelect!="8" &&
	 optionSelect!="9" && optionSelect!="10" && optionSelect!="11" && optionSelect!="12" && optionSelect!="13" && optionSelect!="14"){
		cout<<"\nIncorrect Input. Try again.";
		showMenu();
		//cin>>optionSelect;
		getline(cin, optionSelect);
		//cin.ignore();
	}
	//now we have a correct menu option in our variable. Lets use if statement
	if(optionSelect == "1"){
		bool menuOneReturn = menuOne();
		if(menuOneReturn == true){
			cout<<"\nTeam created successfully!!";
			runProgram();
		}
		else{
			cout<<"\nTeam NOT created. Validation error in menu 1!!";
			runProgram();
		}
	}
	else if(optionSelect == "2"){
		bool menuTwoReturn = menuTwo();
		if(menuTwoReturn == true){
			cout<<"\nPlayer created successfully!!";
			runProgram();
		}
		else{
			cout<<"\nPlayer NOT created. Validation error in menu 2!!";
			runProgram();
		}
	}
	else if(optionSelect == "3"){
		bool menuThreeReturn = menuThree();
		if(menuThreeReturn == true){
			cout<<"\nTeam was found!!";
			runProgram();
		}
		else{
			cout<<"\nTeam NOT found. Validation error in menu 3!!";
			runProgram();
		}
	}
	else if(optionSelect == "4"){
		bool menuFourReturn = menuFour();
		if(menuFourReturn == true){
			cout<<"\nPlayer was found!!";
			runProgram();
		}
		else{
			cout<<"\nPlayer NOT found. Validation error in menu 4!!";
			runProgram();
		}
	}
	else if(optionSelect == "5"){
		bool menuFiveReturn = menuFive();
		if(menuFiveReturn == true){
			cout<<"\nPlayer was found!!";
			runProgram();
		}
		else{
			cout<<"\nPlayer NOT found. Validation error in menu 5!!";
			runProgram();
		}
	}
	else if(optionSelect == "6"){
		bool menuSixReturn = menuSix();
		if(menuSixReturn == true){
			cout<<"\nPlayer was found!!";
			runProgram();
		}
		else{
			cout<<"\nPlayer NOT found. Validation error in menu 6!!";
			runProgram();
		}
	}
	else if(optionSelect == "7"){
		bool menuSevenReturn = menuSeven();
		if(menuSevenReturn == true){
			cout<<"\nEverything worked fine!!";
			runProgram();
		}
		else{
			cout<<"\nValidation error in menu 7!!";
			runProgram();
		}
	}
	else if(optionSelect == "8"){
		bool menuEightReturn = menuEight();
		if(menuEightReturn == true){
			cout<<"\nEverything worked fine!!";
			runProgram();
		}
		else{
			cout<<"\nValidation error in menu 8!!";
			runProgram();
		}
	}
	else if(optionSelect == "9"){
		bool menuNineReturn = menuNine();
		if(menuNineReturn == true){
			cout<<"\nEverything worked fine!!";
			runProgram();
		}
		else{
			cout<<"\nValidation error in menu 9!!";
			runProgram();
		}
	}
	else if(optionSelect == "10"){
		bool menuTenReturn = menuTen();
		if(menuTenReturn == true){
			cout<<"\nEverything worked fine!!";
			runProgram();
		}
		else{
			cout<<"\nValidation error in menu 10!!";
			runProgram();
		}
	}
	else if(optionSelect == "11"){
		bool menuElevenReturn = menuEleven();
		if(menuElevenReturn == true){
			cout<<"\nEverything worked fine!!";
			runProgram();
		}
		else{
			cout<<"\nValidation error in menu 11!!";
			runProgram();
		}
	}
	else if(optionSelect == "12"){
		bool menuTweleveReturn = menuTwelve();
		if(menuTweleveReturn == true){
			cout<<"\nEverything worked fine!!";
			runProgram();
		}
		else{
			cout<<"\nValidation error in menu 12!!";
			runProgram();
		}
	}
	else if(optionSelect == "13"){
		bool createAndRunTestCasesResult = createAndRunTestCases();
		if(createAndRunTestCasesResult == true){
			cout<<"\nEverything worked fine!!";
			runProgram();
		}
		else{
			cout<<"\nValidation error in automatic testing!!";
			runProgram();
		}
	}
	else if(optionSelect == "14"){
		cout<<"\nQUITING...";
	}
	else{
		cout<<"\nQUITING...";
	}
}

bool createAndRunTestCases(){
	//This function will create 2 teams and 5 players in total using our functions. Then it will automate all the menu options and display results on screen!!
	
	//Create two teams
	Team * newTeam1 = new Team(1, "USA", "NYC");
	//Team * newTeam1 = &newTeam1Value;
	bool addTeamToListAnswer1 = addTeamToList(newTeam1);
	Team * newTeam2 = new Team(2, "CANADA", "TORONTO");
	//Team * newTeam2 = &newTeam2Vlaue;
	bool addTeamToListAnswer2 = addTeamToList(newTeam2);
	
	//create 5 players
	Player * newPlayer1 = new Player(1, 1, "Mark", 23, "123456", "Forward", 1000.00);
	Player * newPlayer2 = new Player(2, 1, "Jim", 34, "123676", "Goalkeeper", 9000.00);
	Player * newPlayer3 = new Player(3, 1, "Adam", 22, "677777", "Middle", 6000.00);
	Player * newPlayer4 = new Player(4, 2, "Freddy", 21, "999999", "Forward", 500.00);
	Player * newPlayer5 = new Player(5, 2, "Brad", 20, "8888888", "Goalkeeper", 600.00);
	
	//Player * newPlayer1 = &newPlayer1Value;
	//Player * newPlayer2 = &newPlayer2Value;
	//Player * newPlayer3 = &newPlayer3Value;
	//Player * newPlayer4 = &newPlayer4Value;
	//Player * newPlayer5 = &newPlayer5Value;
	
	int addPlayerToArrayIndex1 = addPlayerToArray(*newPlayer1);
	int addPlayerToArrayIndex2 = addPlayerToArray(*newPlayer2);
	int addPlayerToArrayIndex3 = addPlayerToArray(*newPlayer3);
	int addPlayerToArrayIndex4 = addPlayerToArray(*newPlayer4);
	int addPlayerToArrayIndex5 = addPlayerToArray(*newPlayer5);
	
	if(addPlayerToArrayIndex1 != -1){
		//now we need to find the team in which to add the player
		Team * teamCounter = teamsRootNode;
		while(teamCounter->next != NULL){
			if(teamCounter->next->id == 1){
				PlayerNode * newPlayerNode = new PlayerNode(1, addPlayerToArrayIndex1);
				//PlayerNode * newPlayerNode = &newPlayerNodeValue;
				bool addPlayerToTeamAnswer = addPlayerToTeam(teamCounter->next, newPlayerNode);
				break;
			}
			teamCounter = teamCounter->next;
		}
	}
	if(addPlayerToArrayIndex2 != -1){
		//now we need to find the team in which to add the player
		Team * teamCounter = teamsRootNode;
		while(teamCounter->next != NULL){
			if(teamCounter->next->id == 1){
				PlayerNode * newPlayerNode = new PlayerNode(2, addPlayerToArrayIndex2);
				//PlayerNode * newPlayerNode = &newPlayerNodeValue;
				bool addPlayerToTeamAnswer = addPlayerToTeam(teamCounter->next, newPlayerNode);
				break;
			}
			teamCounter = teamCounter->next;
		}
	}
	if(addPlayerToArrayIndex3 != -1){
		//now we need to find the team in which to add the player
		Team * teamCounter = teamsRootNode;
		while(teamCounter->next != NULL){
			if(teamCounter->next->id == 1){
				PlayerNode * newPlayerNode = new PlayerNode(3, addPlayerToArrayIndex3);
				//PlayerNode * newPlayerNode = &newPlayerNodeValue;
				bool addPlayerToTeamAnswer = addPlayerToTeam(teamCounter->next, newPlayerNode);
				break;
			}
			teamCounter = teamCounter->next;
		}
	}
	if(addPlayerToArrayIndex4 != -1){
		//now we need to find the team in which to add the player
		Team * teamCounter = teamsRootNode;
		while(teamCounter->next != NULL){
			if(teamCounter->next->id == 2){
				PlayerNode * newPlayerNode = new PlayerNode(4, addPlayerToArrayIndex4);
				//PlayerNode * newPlayerNode = &newPlayerNodeValue;
				bool addPlayerToTeamAnswer = addPlayerToTeam(teamCounter->next, newPlayerNode);
				break;
			}
			teamCounter = teamCounter->next;
		}
	}
	if(addPlayerToArrayIndex5 != -1){
		//now we need to find the team in which to add the player
		Team * teamCounter = teamsRootNode;
		while(teamCounter->next != NULL){
			if(teamCounter->next->id == 2){
				PlayerNode * newPlayerNode = new PlayerNode(5, addPlayerToArrayIndex5);
				//PlayerNode * newPlayerNode = &newPlayerNodeValue;
				bool addPlayerToTeamAnswer = addPlayerToTeam(teamCounter->next, newPlayerNode);
				break;
			}
			teamCounter = teamCounter->next;
		}
	}
	cout<<"\n\n2 Teams and 5 Players created. Now displaying both teams....";
	//now we have created teams and players. we need to test the menu options!!
	bool displayTeam1 = displayTeamInfoAndPlayers("USA");
	bool displayTeam2 = displayTeamInfoAndPlayers("CANADA");
	
	cout<<"\n\nFinding player with a valid id 3: ";
	bool findPlayer1 = findAndDisplayPlayerWithId(3);
	
	cout<<"\n\nFinding player with a valid name Adam: ";
	bool findPlayer2 = findAndDisplayPlayerWithName("Adam");
	
	cout<<"\n\nFinding player with a valid phone 8888888: ";
	bool findPlayer3 = findAndDisplayPlayerWithPhone("8888888");
	
	cout<<"\n\nFinding player with invalid id 8: ";
	bool findPlayer4 = findAndDisplayPlayerWithId(8);
	
	cout<<"\n\nFinding player with invalid name Kane: ";
	bool findPlayer5 = findAndDisplayPlayerWithName("Kane");
	
	cout<<"\n\nFinding player with invalid phone 6712: ";
	bool findPlayer6 = findAndDisplayPlayerWithPhone("6712");
	
	SearchCriteria criteria1 = ID;
	SearchCriteria criteria2 = NAME;
	SearchCriteria criteria3 = SALARY;
	
	cout<<"\n\nSort all players by id: ";
	bool sortAllPlayers1 = sortAllPlayers(criteria1);
	showAllPlayers();
	
	cout<<"\n\nSort all players by name: ";
	bool sortAllPlayers2 = sortAllPlayers(criteria2);
	showAllPlayers();
	
	cout<<"\n\nSort all players by salary (descending): ";
	bool sortAllPlayers3 = sortAllPlayers(criteria3);
	showAllPlayers();
	
	cout<<"\n\nTrying to sort players of an invalid team India based on salary";
	bool sortAllPlayersOfATeam1 = sortAllPlayersOfATeam("India", criteria3);
	
	cout<<"\n\nTrying to sort players of team USA based on id";
	bool sortAllPlayersOfATeam2 = sortAllPlayersOfATeam("USA", criteria1);
	cout<<"\n\nTrying to sort players of team USA based on name";
	bool sortAllPlayersOfATeam3 = sortAllPlayersOfATeam("USA", criteria2);
	cout<<"\n\nTrying to sort players of team USA based on salary";
	bool sortAllPlayersOfATeam4 = sortAllPlayersOfATeam("USA", criteria3);
	
	cout<<"\n\nTESTING COMPLETED SUCCESSFULLY!!!!!!";
	
	return true;
}

int main ()
{
	for(int i=0; i<50; i++){
		players[i].id = -1;
	}
	runProgram();	
	//we need to de-allocate all the dynamic memory space before we quit the program..
	Team * teamCounterForDelete = teamsRootNode;
	cout<<"Deallocating dynamic memory....Have a good day!!!!";
	delete teamCounterForDelete->linkedPlayerFirstNode;
	while(teamCounterForDelete->next != NULL){
		delete teamCounterForDelete->next->linkedPlayerFirstNode;
		teamCounterForDelete = teamCounterForDelete->next;
	}
	delete teamsRootNode;
	return 0;
}


