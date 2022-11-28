#include "Pipe.h"
#include "Functions.h"

using namespace std;


void Pipe::RedactRepairSign()
{
	cout << "Выберите состояние трубы "<< PipeName<<"\t0. В ремонте\t1. Починена" << endl;
	Validation(PipeSign);
}

std::istream& operator >> (std::istream& in, Pipe& Pipeline) {
	
	cout << "Введите название трубы" << endl;
	cin.ignore();
	getline(cin, Pipeline.PipeName);

	cout << "Введите длину трубы" << endl;
	Validation(Pipeline.PipeLength);

	cout << "Введите диаметр трубы" << endl;
	Validation(Pipeline.PipeDiametre);

	cout << "Выберите признак трубы:\n0. В ремонте\n1. Починена" << endl;
	Validation(Pipeline.PipeSign);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Pipe& Pipeline)
{
	//cout << "ID трубы: " << Pipeline.id << endl;
	cout << "Название трубы: " << Pipeline.PipeName << "\tДлина трубы: " << Pipeline.PipeLength << " м\tДиаметр: " << Pipeline.PipeDiametre << "мм\tСостояние: ";
	if (Pipeline.PipeSign)
	{
		cout << "Починена" << endl;
	}
	else
		cout << "В ремонте" << endl;
	
	return out;
}

std::ifstream& operator>>(std::ifstream& fin, Pipe& Pipeline)
{
	string name;
	fin.ignore();
	if (getline(fin, name)) 
		Pipeline.PipeName=name;
	fin >> Pipeline.PipeLength >> Pipeline.PipeDiametre >> Pipeline.PipeSign;
	return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const Pipe& Pipeline)
{
	fout << Pipeline.PipeName << "\n" << Pipeline.PipeLength << "\n" << Pipeline.PipeDiametre << "\n" << Pipeline.PipeSign << endl;
	return fout;
}
