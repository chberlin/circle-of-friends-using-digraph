#ifndef circle_
#define circle_

#include "digraph.h"
#include "iostream"

class Circle{
public:
	Circle();


	void addMember(string name);
	//input: name of friend to be added to the circle
	//output: Prints to terminal if friend can't be added
	//side effect: adds member to circle

	void addFriendship(string name1, string name2);
	//input: name of member, name of friend to be added
	//output: Prints to terminal if friendship can't be created
	//side effect: adds friendship

	void destroyFriendship(string name1, string name2);
	//input: name of friend to be removed and name of member whose list is being amended
	//output: Confirmation if a name has been removed or error if name can't be removed
	//side effect: deletes friendship from member


	void displayCircleSize();
	//input: none
	//output: prints to terminal number of members in the circle
	//side effect: none


	void displayAllMembers();
	//inpit: none
	//output: prints to terminal the list of names in the circle
	//side effect: none

	void displayNumberFriendships();
	//input: none
	//output: prints to terminal the number of friendships in the circle
	//side effect: none
	

	void checkMemberStatus(string name);
	//input: name to check the status of
	//output: prints to the terminal if the name is a member of the circle
	//side effect: none
	


	void displayFriendsOf(string name);
	//input: name of member whose friend list to check
	//output: member's friend's list or error if name is not a member
	//side effect: none
	


	void checkForFriendShip(string name1, string name2);
	//input: name of member and name of friend
	//output: prints to the terminal if member is friends with the other name
	//side effect: none
	


	void displayFriendCount(string name);
	//input: name of member to check
	//output: the number of other members who view name as a friend
	//output: error if name is not a member
	//side effect: none

	void removeFromCircle(string name);
	//input: name of member to be removed
	//output: confirmation if name has been removed
	//output: error if name cannot be removed
	//side effect: removes name from circle and all corresponding friend's lists.
	//side effect: decreases member count and friendship count.


private:
	Digraph hive;

};
#endif