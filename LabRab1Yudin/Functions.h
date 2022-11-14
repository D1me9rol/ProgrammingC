#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include "Pipe.h"
#include "Station.h"
using namespace std;

template <typename T>
void Validation(T& input);

void AddPipe(map<int, Pipe>& MapOfPipes);

void AddStation(map<int, Station>& MapOfStations);

void ObjReview(map<int, Pipe> MapOfPipes, map<int, Station> MapOfStations);

void FileSave(map<int, Pipe> MapOfPipes, map<int, Station> MapOfStations);

void FileRead(map<int, Pipe>& MapOfPipes, map<int, Station>& MapOfStations);

void FindPipe(map<int, Pipe>& MapOfPipes, vector<int>& VecOfPipes);

void FindStation(map<int, Station>& MapOfStations, vector<int>& VecOfStations);

void FindObj(map<int, Pipe>& MapOfPipes, map<int, Station>& MapOfStations, vector<int>& VecOfPipes, vector<int>& VecOfStations);

void RedactPipes(map<int, Pipe>& MapOfPipes, vector<int> VecOfPipes);

void RedactStation(map<int, Station>& MapOfStations, vector<int> VecOfStations);


