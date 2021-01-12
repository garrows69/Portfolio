/*********************
Name: Max Macigewski
Final Project
Purpose: This program represents a graph
**********************/

#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include <vector>
#include <string>

class Graph
{
public:


	Graph(int);

	void addVertex();
	void addEdge(Vertex, Vertex, int, bool);
	std::vector<Vertex> getAdjacent(Vertex) const;
	Edge& getEdge(Vertex, Vertex);
	void setVertexLabel(Vertex, std::string label);
	std::string getVertexLabel(Vertex) const;

	int size() const;

private:
	std::vector<std::vector<Edge*>> adjacency;
	std::vector<std::string> vertexLabels;

	Edge* INVALID_EDGE = new Edge(-1, -1, -1);
};

#endif // !GRAPH_H
