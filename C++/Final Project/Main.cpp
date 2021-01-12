/*********************
Name: Max Macigewski
Final Project
Purpose: This program represents a graph
**********************/

#include "Main.h"

int main()
{
	//edge class testing
	std::cout << "Edge class testing" << std::endl;
	Edge* edge1 = new Edge(-1, -1, -1);
	Edge* edge2 = new Edge(2, 4, 50);

	std::vector<Edge*> edges;
	edges.push_back(edge1);
	edges.push_back(edge2);

	for (Edge* edge : edges)
	{
		std::cout << "Start: " << edge->start << " End: " << edge->end;
		std::cout << " Weight: " << edge->weight << std::endl;
	}

	std::cout << "\nGraph class testing" << std::endl;
	Graph* g1 = new Graph(1);
	Graph* g2 = new Graph(10);

	std::vector<Graph*> graphs;
	graphs.push_back(g1);
	graphs.push_back(g2);

	for (Graph* graph : graphs)
	{
		std::cout << "Graph size: " << graph->size() << " verticies" << std::endl;
	}

	g2->setVertexLabel(6, "test label");

	std::cout << "\nLabel (6): " << g2->getVertexLabel(6) << std::endl;

	g2->addEdge(5, 3, 20, true);
	g2->addEdge(1, 5, 15, false);

	std::cout << "Edge 1 (5 --> 3) weight: " << g2->getEdge(5, 3).weight << " (Should be 20.)" << std::endl;
	std::cout << "Edge 1 (3 --> 5) weight: " << g2->getEdge(3, 5).weight << " (Should be -1.)" << std::endl;
	std::cout << "Edge 2 (1 --> 5) weight: " << g2->getEdge(1, 5).weight << " (Should be 15.)" << std::endl;
	std::cout << "Edge 2 (5 --> 1) weight: " << g2->getEdge(5, 1).weight << " (Should be 15.)" << std::endl;

	std::cout << "\nVerticies adjacent to 5: [";

	for (Vertex vertex : g2->getAdjacent(5))
	{
		std::cout << " " << vertex;
	}

	std::cout << "] (Should be [1 3].)" << std::endl;

	return 0;
}