//program.cpp
#include "circle.h"
#include <vector>
#include <iostream>

void createCircle(Circle& friends);
//input: Circle Object
//output: none
//side effect: adds members and friendships to the circle

int evalulateResponse(Circle& friends, int response);
//input: Circle object; response from user
//output: response value (int) (Only used if value is 0 to terminate program)
//side effect: Calls apprirate Circle function based on response

int callMenu(const vector<string> menu);
//input: vector<string> containing menu options
//output: int response of user
//side effect: none


int main(){

	Circle friends = Circle();
	createCircle(friends);

	vector<string> menu = {"Quit", //0
						"Who are the members of the circle of friends?",//1
						"How many people belong to the circle of friends?",//2
						"How many friendships are part of the circle of friends?",//3
						"Is name a member of the circle of friends?",//4
						"Who has name designated as a friend?",//5
						"Has name1 designated name2 as a friend?",//6
						"Has name1 been designated by name2 as a friend?",//7
						"Remove name1 as a designated friend of name2",//8
						"How many people have designated name as a friend?",//9
						"remove name as a member of the circle of friends",//10
	};
	
	while(true){
		if(evalulateResponse(friends, callMenu(menu)) == 0){
			break;
		}
	}

	return 0;
}
int callMenu(const vector<string> menu){

	cout << "Please Select a query option between 0 and 10" << endl;
	int response;
	bool valid = false;
	while(!valid){
			for(int i=0; i < menu.size(); i++){
				cout << "["<< i <<"] "<<menu.at(i)<< endl;
			}
			cin >> response;
			if(response >=0 && response <= 10){
				valid = true;
			}
			else{
				cout << "Invalid Response. Please try again" << endl;
			}
				
	}
	return response;
}

int evalulateResponse(Circle& friends, int response){
	if(response == 1){
		friends.displayAllMembers();
	}
	else if(response == 2){
		friends.displayCircleSize();
	}
	else if(response == 3){
		friends.displayNumberFriendships();
	}
	else if(response == 4){
		string name;
		cout << "Please Enter a name to check the status of: ";
		cin >> name;
		cout << endl;
		friends.checkMemberStatus(name);

	}
	else if(response == 5){
		string name;
		cout << "Please Enter a name to check the status of: ";
		cin >> name;
		cout << endl;
		friends.displayFriendsOf(name);
		
	}
	else if(response == 6 || response == 7){
		string name1;
		string name2;
		cout << "Please Enter two names to check the status of: ";
		cin >> name1 >> name2;
		cout << endl;
		friends.checkForFriendShip(name1, name2);
		
	}
	else if(response == 8){
		string name1;
		string name2;
		cout << "Enter name whose friend list you want to amend: ";
		cin >> name1;
		cout << endl;
		cout << "Enter the name of the friend you want to remove: ";
		cin >> name2;
		cout << endl;
		friends.destroyFriendship(name1, name2);
	}
	else if(response == 9){
		string name;
		cout << "Please Enter a name to see how many people view them as a friend: ";
		cin >> name;
		cout << endl;
		friends.displayFriendCount(name);
	}
	else if(response == 10){
		string name;
		cout << "Please enter a name to remove from the circle" << endl;
		cin >> name;
		cout << endl;
		friends.removeFromCircle(name);
	}
	else if(response == 0){
		cout << "Thanks for playing. Goodbye!" << endl;
	}
	else{
		cout << "Not a valid response, please try again" << endl;
	}
	return response;

}

void createCircle(Circle& friends){

	friends.addMember("Sally");
	friends.addMember("John");
	friends.addMember("Billy");
	friends.addMember("Debbie");
	friends.addMember("George");
	friends.addMember("Lisa");
	friends.addMember("Laura");
	friends.addMember("Josh");


	friends.addFriendship("Sally", "John");
	friends.addFriendship("Sally", "Billy");
	friends.addFriendship("Sally", "George");
	friends.addFriendship("Sally", "Laura");
	friends.addFriendship("Sally", "Josh");

	friends.addFriendship("John", "Debbie");
	friends.addFriendship("John", "George");
	friends.addFriendship("John", "Josh");
	friends.addFriendship("John", "Sally");


	friends.addFriendship("Billy", "Sally");
	friends.addFriendship("Billy", "John");
	friends.addFriendship("Billy", "Debbie");
	friends.addFriendship("Billy", "George");
	friends.addFriendship("Billy", "Lisa");
	friends.addFriendship("Billy", "Laura");


	friends.addFriendship("Debbie", "Josh");
	friends.addFriendship("Debbie", "Billy");
	friends.addFriendship("Debbie", "George");
	friends.addFriendship("Debbie", "Lisa");
	friends.addFriendship("Debbie", "Sally");


	friends.addFriendship("Lisa", "George");


	friends.addFriendship("Laura", "Debbie");
	friends.addFriendship("Laura", "Sally");
	friends.addFriendship("Laura", "Lisa");

}