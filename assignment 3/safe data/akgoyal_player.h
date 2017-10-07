#include <iostream>
using namespace std;

class Player {
    public:
		int id;
		int teamId;
		string fullName;
		int age;
		string phoneNumber;
		string position;
		float salary;
		
		Player (int id, int teamId, string fullName, int age, string phoneNumber, string position, float salary);
		Player ();

};