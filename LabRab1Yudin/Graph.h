#pragma once

#include "Pipe.h"
#include "Station.h"
#include <list>
#include <map>
#include <vector>
#include <set>

struct Connections
{
	int FirstStation;
	int SecondStation;
	int Pipeline;
};

class Graph
{
public:
	Connections edge;
	std::vector<std::vector<bool>>Adj;
	std::vector<std::vector<int>>Incidence;
	std::map<int, Connections> StationsPair;

	

	void AddArc(std::map<int, Pipe>& MapOfPipes, std::map<int, Station> MapOfStations);
	void FillAdj(std::map<int, Station> MapOfStations);
	void FillIncidence(std::map<int, Pipe> MapOfPipes, std::map<int, Station> MapOfStations);
	void TopologicalSort(std::map<int, Station> MapOfStations);
	void TopologicalSortUtil(int v, std::vector<int>& Vertexes, std::vector<bool>&visited);


	//friend std::ifstream& operator>> (std::ifstream& fin, Connections& ConnectedStations);
	//friend std::ofstream& operator<< (std::ofstream& fout, Connections& ConnectedStations);
};

