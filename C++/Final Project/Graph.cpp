/*********************
Name: Max Macigewski
Final Project
Purpose: This program represents a graph
**********************/

#include "Graph.h"

Graph::Graph(int numVertices)
{
	for (int i = 0; i < numVertices; i++)
	{
		addVertex();
		vertexLabels.push_back("");
	}
}

void Graph::addVertex()
{
	std::vector<Edge*> adjList(size(), INVALID_EDGE);
	adjacency.push_back(adjList);

	for (int i = 0; i < size(); i++)
	{
		adjacency[i].push_back(INVALID_EDGE);
	}
}

void Graph::addEdge(Vertex start, Vertex end, int weight, bool dir)
{
	if (start != end)
	{
		Edge* newEdge = new Edge(start, end, weight);
		adjacency[start][end] = newEdge;

		if (!dir)
		{
			addEdge(end, start, weight, true);
		}
	}
}

std::vector<Vertex> Graph::getAdjacent(Vertex vertex) const
{
	std::vector<Vertex> adjacent;

	for (int i = 0; i < adjacency[vertex].size(); i++)
	{
		if (adjacency[vertex][i] != INVALID_EDGE)
		{
			adjacent.push_back(i);
		}
	}

	return adjacent;
}

Edge& Graph::getEdge(Vertex start, Vertex end)
{
	return *(adjacency[start][end]);
}

void Graph::setVertexLabel(Vertex vertex, std::string label)
{
	vertexLabels[vertex] = label;
}

std::string Graph::getVertexLabel(Vertex vertex) const
{
	return vertexLabels[vertex];
}

int Graph::size() const
{
	return adjacency.size();
}