#include "Pipe.h"
#include "Functions.h"

using namespace std;


void Pipe::RedactRepairSign()
{
	cout << "Выберите состояние трубы "<< PipeName<<"\t0. В ремонте\t1. Починена" << endl;
	Validation(PipeSign);
}

std::istream& operator >> (std::istream& in, Pipe& Pipeline) {
	
	int Diametre=0;

	cout << "Введите название трубы" << endl;
	cin.ignore();
	getline(cin, Pipeline.PipeName);

	cout << "Введите длину трубы" << endl;
	Validation(Pipeline.PipeLength);

	cout << "Выберите диаметр трубы: 1.500мм 2.700мм 3.1400мм" << endl;
	
	while (Diametre < 1 || Diametre>3)
	{
		cout << "Введите число от 1 до 3" << endl;
		Validation(Diametre);
	}
	if (Diametre == 1)
		Pipeline.PipeDiametre = 500;
	else if (Diametre == 2)
		Pipeline.PipeDiametre = 700;
	else
		Pipeline.PipeDiametre = 1400;

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
