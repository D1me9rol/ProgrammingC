#pragma once

#include "Pipe.h"
#include "Station.h"
#include <list>
#include <map>
#include <vector>
#include <set>
//#include "Functions.h"

class Graph
{
public:
	std::vector<std::vector<int>>Adj;// (MapOfStations.size(), vector<int>(MapOfStations.size()));
	std::vector<std::vector<int>>Incidence;// (MapOfPipes.size(), vector<int>(MapOfStations.size()));

	

	void AddArc(std::map<int, Pipe>& MapOfPipes, std::map<int, Station> MapOfStations);
	void FillAdj(std::map<int, Station> MapOfStations);
	void FillIncidence(std::map<int, Pipe> MapOfPipes, std::map<int, Station> MapOfStations);


};

