/*********************
Name: Max Macigewski
Final Project
Purpose: This program represents a graph
**********************/

#include "Graph.h"

Edge::Edge(Vertex startP, Vertex endP, int weightP)
{
	start = startP;
	end = endP;
	weight = weightP;
}