//digraph.cpp
#include "digraph.h"

Digraph::Digraph() : edges(20){
	names.reserve(20);
	edges.reserve(20);
	vertexCount=0;
	edgeCount=0;
}
bool Digraph::addVertex(string vertex){
	if(findVertex(vertex)){
		return false;
	}
	if(vertexCount <= 20){
		names.push_back(vertex);
		vertexCount++;
		return true;
	}
	else{
		return false;
	}
}
bool Digraph::addDirectedEdge(string name1, string name2){
	bool added = false;
	int pos;
	if(findVertex(name1) && findVertex(name2)){
		if(!findDirectEdge(name1, name2)){
			int edge = convertToValue(name2);
			pos = convertToValue(name1);
			edges.at(pos).push_back(edge);
			added = true;
			edgeCount++;
		}
	}
	return added;
}
bool Digraph::removeEdge(string name1, string name2){
	bool removed = false;
	if(findVertex(name1) && findVertex(name2)){
		if(findDirectEdge(name1, name2)){
			int edge = convertToValue(name2);
			int pos = convertToValue(name1);
			edges.at(pos).remove(edge);
			edgeCount--;
			removed = true;
		}
	}
	return removed;
}
bool Digraph::findDirectEdge(const string name1, const string name2){
	bool found = false;
	if(findVertex(name1) && findVertex(name2)){
		int name1pos = convertToValue(name1);
		int name2pos = convertToValue(name2);
		if(find(edges.at(name1pos).begin(), edges.at(name1pos).end(), name2pos)
			!= edges.at(name1pos).end()){
			found = true;
		}
	}
	return found;
}
bool Digraph::findVertex(const string vertex){
	bool found = false;
	if(find(names.begin(), names.end(), vertex) != names.end()){
		found = true;
	}
	return found;
}
int Digraph::countEdges(){
	return edgeCount;
}
int Digraph::countVertex(){
	return vertexCount;
}
vector<string> Digraph::getVertices(){
	return names;
}
vector<string> Digraph::getSuccessors(string vertex){
	vector<string> successors;
	if(findVertex(vertex)){
		int pos = convertToValue(vertex);
		if(!edges.at(pos).empty()){
			for(int i : edges.at(pos)){
				successors.push_back(convertToString(i));
			}
		}
	}
	return successors;
}
int Digraph::predecessorCount(const string vertex){
	int predCount = 0;
	if(findVertex(vertex)){
		int person = convertToValue(vertex);
		for(list<int> i : edges){
			if(find(i.begin(), i.end(), person) != i.end()){
				predCount++;
			}
		}
	}
	return predCount;
}
int Digraph::convertToValue(string name){
	return distance(names.begin(), find(names.begin(), names.end(), name));
}
string Digraph::convertToString(int num){
	string name = "";
	if(num < vertexCount){
		name = names.at(num);
	}
	return name;
}
bool Digraph::removeMember(string vertex){
	bool removed = false;
	if(findVertex(vertex)){
		int person = convertToValue(vertex);
		for(list<int> i : edges){
			if(find(i.begin(), i.end(), person)!= i.end()){
				i.remove(person);
				edgeCount--;
			}
		}
		names.erase(find(names.begin(), names.end(), vertex));
		vertexCount--;
		removed = true;
		
	}
	return removed;
}