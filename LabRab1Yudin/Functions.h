#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "Pipe.h"
#include "Station.h"
#include <set>


template <typename T>
void Validation(T& input);

void AddPipe(std::map<int, Pipe>& MapOfPipes);

void AddStation(std::map<int, Station>& MapOfStations);

void ObjReview(std::map<int, Pipe> MapOfPipes, std::map<int, Station> MapOfStations);

void FileSave(std::map<int, Pipe> MapOfPipes, std::map<int, Station> MapOfStations);

void FileRead(std::map<int, Pipe>& MapOfPipes, std::map<int, Station>& MapOfStations);

//void FindPipe(map<int, Pipe>& MapOfPipes, vector<int>& VecOfPipes);

//void FindStation(map<int, Station>& MapOfStations, vector<int>& VecOfStations);

//void FindObj(map<int, Pipe>& MapOfPipes, map<int, Station>& MapOfStations, vector<int>& VecOfPipes, vector<int>& VecOfStations);

//void RedactPipes(map<int, Pipe>& MapOfPipes);

//void RedactStations(map<int, Station>& MapOfStations);

void RedactStation(std::map<int, Station>& MapOfStations);

void RedactPipe(std::map<int, Pipe>& MapOfPipes);

void FilterPipes(std::map<int, Pipe>& MapOfPipes);

void FilterStations(std::map<int, Station>& MapOfStations);