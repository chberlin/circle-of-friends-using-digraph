#include "circle.h"


Circle::Circle(){};

void Circle::addMember(string name){
	if(!hive.addVertex(name)){
		cout << "Unable to add " << name<< " to circle"<< endl;
	}
}
void Circle::addFriendship(string name1, string name2){
	if(name1 == name2){
		cout << name1 << " can't be friends with himself. Sorry :(" << endl;
		return;
	}
	if(!hive.addDirectedEdge(name1, name2)){
		cout << "Unable to make friendship" << endl;
	}
}
void Circle::destroyFriendship(string name1, string name2){
	if(!hive.removeEdge(name1, name2)){
		cout << "Can't sever a friendship that doesn't exist" << endl;
	}
	else{
		cout << name2 << " is no longer on " << name1 << "'s friend list" << endl;
	}
}
void Circle::displayAllMembers(){
	if(hive.countVertex() < 1){
		cout << "No friends to display" << endl;
	}
	else{
		vector<string> members = hive.getVertices();
		cout << "Members of the circle consist of: " << members.at(0);
		for(int i = 1; i < members.size()-1; i++){
			cout << ", "<< members.at(i);
		}
		cout << " and " << members.at(members.size()-1)<<"." << endl;
	}
}
void Circle::displayCircleSize(){
	cout <<"There are " << hive.countVertex() <<" friends in the circle" << endl;
}
void Circle::displayNumberFriendships(){
	cout <<"There are " <<hive.countEdges() <<" friendships in the circle"<< endl;
}
void Circle::checkMemberStatus(string name){
	if(hive.findVertex(name)){
		cout << name << " is a member of the circle" << endl;
	}
	else{
		cout << name << " is not a member of the circle" << endl;
	}
}
void Circle::displayFriendsOf(string name){
	if(!hive.findVertex(name)){
		cout << name << " is not a member of the circle" << endl;
		return;
	}
	vector<string> friends = hive.getSuccessors(name);
	if(friends.empty()){
		cout << name << " is not friends with anyone" << endl;
	}
	else{
		cout << name << " is friends with ";
		for(int i = 0; i < friends.size()-1; i++){
			cout << friends.at(i) << ", ";
		}
		cout << "and " << friends.at(friends.size()-1)<<"." << endl;
	}
}
void Circle::checkForFriendShip(string name1, string name2){
	if(!hive.findVertex(name1)){
		cout << name1 << " is not a member of the circle" << endl;
		return;
	}
	if(!hive.findVertex(name2)){
		cout << name2 << " is not a member of the circle" << endl;
		return;
	}
	if(hive.findDirectEdge(name1, name2)){
		cout << name1 << " considers " << name2<< " a friend" << endl;
	}
	else{
		cout << name1 << " does not consider " << name2<< " a friend" << endl;
	}
}
void Circle::displayFriendCount(string name){
	if(!hive.findVertex(name)){
		cout << name << " is not a member of the circle" << endl;
		return;
	}
	else{
		cout << hive.predecessorCount(name) << " other members consider " << name << " to be a friend"<< endl;
	}
}
void Circle::removeFromCircle(string name){
	if(!hive.removeMember(name)){
		cout << name << " could not be removed" << endl;
	}
	else{
		cout << name << " has successfully been removed from the circle" << endl;
	}
}