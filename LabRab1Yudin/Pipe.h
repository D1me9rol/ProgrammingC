#pragma once
#include <iostream>
#include <string>

class Pipe
{
public:
	std::string PipeName;
	int PipeLength, PipeDiametre;
	bool PipeSign;
	
	void RedactRepairSign();

	friend std::istream& operator >> (std::istream& in, Pipe& Pipeline);
	friend std::ostream& operator << (std::ostream& out, const Pipe& Pipeline);
	friend std::ifstream& operator >> (std::ifstream& fin, Pipe& Pipeline);
	friend std::ofstream& operator << (std::ofstream& fout, const Pipe& Pipeline);
};

