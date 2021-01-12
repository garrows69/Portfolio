/*********************
Name: Max Macigewski
Final Project
Purpose: This program represents a graph
**********************/

#ifndef EDGE_H
#define EDGE_H

#include <vector>

typedef int Vertex; //allows verticies to be representented by non-negative ints

class Edge
{
public:
	Vertex start;
	Vertex end;
	int weight;

	Edge(Vertex, Vertex, int);


};

#endif