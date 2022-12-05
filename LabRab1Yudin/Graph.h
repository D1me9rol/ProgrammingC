#pragma once

#include "Pipe.h"
#include "Station.h"
#include <list>
#include <map>
#include <vector>
#include <set>
#include <stack>
//#include "Functions.h"

class Graph
{
public:
	std::vector<std::vector<bool>>Adj;// (MapOfStations.size(), vector<int>(MapOfStations.size()));
	std::vector<std::vector<int>>Incidence;// (MapOfPipes.size(), vector<int>(MapOfStations.size()));

	

	void AddArc(std::map<int, Pipe>& MapOfPipes, std::map<int, Station> MapOfStations);
	void FillAdj(std::map<int, Station> MapOfStations);
	void FillIncidence(std::map<int, Pipe> MapOfPipes, std::map<int, Station> MapOfStations);
	void TopologicalSort(std::map<int, Station> MapOfStations);
	void TopologicalSortUtil(int v, std::vector<int>& Vertexes, std::vector<bool>&visited);

};

