#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "Pipe.h"
#include "Station.h"
#include <set>
#include "Graph.h"


template <typename T>
void Validation(T& input);

void AddPipe(std::map<int, Pipe>& MapOfPipes);

void AddStation(std::map<int, Station>& MapOfStations);

void ObjReview(std::map<int, Pipe> MapOfPipes, std::map<int, Station> MapOfStations, Graph ConnectedStations);

void FileSave(std::map<int, Pipe> MapOfPipes, std::map<int, Station> MapOfStations, Graph ConnectedStations);

void FileRead(std::map<int, Pipe>& MapOfPipes, std::map<int, Station>& MapOfStations, Graph& ConnectedStations);

void RedactStation(std::map<int, Station>& MapOfStations);

void RedactPipe(std::map<int, Pipe>& MapOfPipes, Graph& graph);

void FilterPipes(std::map<int, Pipe>& MapOfPipes);

void FilterStations(std::map<int, Station>& MapOfStations);

void ConnectStations(std::map<int, Station> MapOfStations, std::map<int, Pipe>& MapOfPipes, Graph& ConnectedStations);

void TopologicalSort(std::map<int, Station> MapOfStations, Graph& ConnectedStations);