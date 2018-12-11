//digraph.h
#ifndef digraph_
#define digraph_

#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <utility>
#include <iterator>

using namespace std;

class Digraph{
public:
		Digraph();

		bool addVertex(string vertex);
		//input: vertex containing string value to add
		//output: True if added successfully. False if unable to be added
		//side effect: Increments vertexCount by 1.



		bool addDirectedEdge(string name1, string name2);
		//input: name2 is the edge that will be added. name1 is the vertex being added to
		//output: True if added successfully
		//side effect: increments edgeCount


		bool removeEdge(string name1, string name2);
		//input: name2 is the edge that will be removed. name1 is the vertex who's edge will be removed
		//output: True if successfully removed. False if not removed
		//side effect: decrements edgeCount


		bool findDirectEdge(const string name1, const string name2);
		//input: name1 is the vertex. name 2 is the edge
		//output: True if edge found on vertex
		//side effect: none

		bool findVertex(const string vertex);
		//input: vertex string to be checked if member
		//output: True if found. False if not found
		//side effect: none

		int countEdges();
		//input: none
		//output: returns number of edges
		//side effect: none



		int countVertex();
		//input: none
		//output: returns number of vertices
		//side effect: none

		vector<string> getVertices();
		//input: none
		//output: Returns a vector of strings containing all vertices
		//side effect: none


		vector<string> getSuccessors(string vertex);
		//input: string value representing vertex
		//output: Returns a vector of strings containing the vector's edges
		//side effect: none


		int predecessorCount(const string vertex);
		//input: value of vertex
		//output: returns number of vertices that the parameter exist as an edge in
		//side effect: none


		bool removeMember(string vertex);
		//input: vertex value to be removed
		//output: Returns true if successfuly removed.
		//side effect: decrements number of vertices and number of edges it resides in



	private:
		vector<string> names;
		vector<list<int> > edges;
		int vertexCount;
		int edgeCount;

		int convertToValue(string name);
		//input: string value of vertex
		//output: integer value of its position in the string vector
		//side effect: none

		string convertToString(int num);
		//input: integer value of value
		//output: string representation of that position value in the string vector
		//side effect: none

		
};
#endif