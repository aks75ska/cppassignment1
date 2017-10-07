#include <iostream>
#include <math.h>
#include "akgoyal_op.h"

using namespace std;

void operateNow();
bool isInt(float x);

bool isInt(float x){
	if (ceilf(x) == x){
		return true;
	}
	return false;
}

void operateNow(){

string operandInput1, operandInput2;
float operandInput1Float, operandInput2Float;
char operatorChar;
cout << "\n\n\n\n-------->>> Welcome to Computer Organization and Kernel Programming assignment #1. This program takes in two numbers and one operand (+, -, *, / or %) and returns the result of operation. ";

cout << "\nEnter the operator (+, -, *, / or %): ";
//cin >> operatorChar;
string operatorString;
getline(cin, operatorString);
cout<<"OPERtor :"<<operatorString;
while(operatorString != "+" && operatorString != "-" && operatorString != "*" && operatorString != "/" && operatorString != "%"){
	cout << "\nYou didn't enter a valid operator. Enter a valid operator (+, -, *, / or %): ";
	getline(cin, operatorString);
}
operatorChar = operatorString[0];

bool isFirstCorrect = false;
bool isSecondCorrect = false;

cout << "\nEnter the first number: ";
cin >> operandInput1;
while (isFirstCorrect == false)
	{
		try{
		operandInput1Float = stof(operandInput1);
		isFirstCorrect = true;
		if(operatorChar == '%' && !isInt(operandInput1Float)){
			isFirstCorrect = false;
			cout << "\nNumber must be an integer for finding remainder. Enter the first number again: ";
			cin >> operandInput1;
		}
		}
		catch(const exception &exc){
			//cerr << exc.what();
			cout << "\nYou didn't enter a valid number. Enter the first number again: ";
			cin >> operandInput1;
		}
	}	

cout << "\nEnter the second number: ";
cin >> operandInput2;
while (isSecondCorrect == false)
	{
		try{
		operandInput2Float = stof(operandInput2);
		isSecondCorrect = true;
		if((operatorChar == '/' || operatorChar == '%') && operandInput2Float == 0){
			isSecondCorrect = false;
			cout << "\nCannot divide by 0. Enter the second number again: ";
			cin >> operandInput2;
		}
		if(operatorChar == '%' && !isInt(operandInput2Float)){
			isSecondCorrect = false;
			cout << "\nNumber must be an integer for finding remainder. Enter the second number again: ";
			cin >> operandInput2;
		}
		}
		catch(const exception &exc){
			//cerr << exc.what();
			cout << "\nYou didn't enter a valid number. Enter the second number again: ";
			cin >> operandInput2;
		}
		
	}

int intResult;
float floatResult;

switch(operatorChar) {
	case '+' :
		if(isInt(operandInput1Float) && isInt(operandInput2Float)){
			intResult = add((int)operandInput1Float, (int)operandInput2Float);
			cout << "\n\nThe result of the operation ("<<operandInput1Float<<" + "<<operandInput2Float<<") is: " << intResult;
			break;
		}
		floatResult = add(operandInput1Float, operandInput2Float);
		cout << "\n\nThe result of the operation ("<<operandInput1Float<<" + "<<operandInput2Float<<") is: " << floatResult;
		break;
	  
	case '-' :
		if(isInt(operandInput1Float) && isInt(operandInput2Float)){
			intResult = subtract((int)operandInput1Float, (int)operandInput2Float);
			cout << "\n\nThe result of the operation ("<<operandInput1Float<<" - "<<operandInput2Float<<") is: " << intResult;
			break;
		}
		floatResult = subtract(operandInput1Float, operandInput2Float);
		cout << "\n\nThe result of the operation ("<<operandInput1Float<<" - "<<operandInput2Float<<") is: " << floatResult;
		break;
	  
	case '*' :
		if(isInt(operandInput1Float) && isInt(operandInput2Float)){
			intResult = multiply((int)operandInput1Float, (int)operandInput2Float);
			cout << "\n\nThe result of the operation ("<<operandInput1Float<<" * "<<operandInput2Float<<") is: " << intResult;
			break;
		}
		floatResult = multiply(operandInput1Float, operandInput2Float);
		cout << "\n\nThe result of the operation ("<<operandInput1Float<<" * "<<operandInput2Float<<") is: " << floatResult;
		break;
	  
	case '/' :
		floatResult = divide(operandInput1Float, operandInput2Float);
		cout << "\n\nThe result of the operation ("<<operandInput1Float<<" / "<<operandInput2Float<<") is: " << floatResult;
		break;
	  
	case '%' :
		intResult = mod((int)operandInput1Float, (int)operandInput2Float);
		cout << "\n\nThe result of the operation ("<<operandInput1Float<<" % "<<operandInput2Float<<") is: " << intResult;
		break;
  
   default:
      cout << "\n\nUnexpected Error !!!";
}

}

// main function. Nothing works without this.
int main ()
{
	bool quit = false;
	string more;
	while(quit == false){
		operateNow();
		cout<<"\n\nDo you want to do more calculation?  yes(y)/no(n): ";
		//cin>>more;
		cin.ignore();
		getline(cin, more);
		while(more != "n" && more != "y" && more != "N" && more != "Y"){
			cout << "\n\nYou didn't enter  valid input. Press 'y' or 'n'. Do you want to do more calculation?  yes(y)/no(n) : ";
			//cin >> more;
			getline(cin, more);
		}
		if(more == "n" or more == "N"){
			quit = true;
		}
	}
		
	return 0;
}
