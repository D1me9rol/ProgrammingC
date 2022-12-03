#include "Pipe.h"
#include "Functions.h"

using namespace std;


void Pipe::RedactRepairSign()
{
	cout << "�������� ��������� ����� "<< PipeName<<"\t0. � �������\t1. ��������" << endl;
	Validation(PipeSign);
}

std::istream& operator >> (std::istream& in, Pipe& Pipeline) {
	
	int Diametre=0;

	cout << "������� �������� �����" << endl;
	cin.ignore();
	getline(cin, Pipeline.PipeName);

	cout << "������� ����� �����" << endl;
	Validation(Pipeline.PipeLength);

	cout << "�������� ������� �����: 1.500�� 2.700�� 3.1400��" << endl;
	
	while (Diametre < 1 || Diametre>3)
	{
		cout << "������� ����� �� 1 �� 3" << endl;
		Validation(Diametre);
	}
	if (Diametre == 1)
		Pipeline.PipeDiametre = 500;
	else if (Diametre == 2)
		Pipeline.PipeDiametre = 700;
	else
		Pipeline.PipeDiametre = 1400;

	cout << "�������� ������� �����:\n0. � �������\n1. ��������" << endl;
	Validation(Pipeline.PipeSign);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Pipe& Pipeline)
{
	//cout << "ID �����: " << Pipeline.id << endl;
	cout << "�������� �����: " << Pipeline.PipeName << "\t����� �����: " << Pipeline.PipeLength << " �\t�������: " << Pipeline.PipeDiametre << "��\t���������: ";
	if (Pipeline.PipeSign)
	{
		cout << "��������" << endl;
	}
	else
		cout << "� �������" << endl;
	
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
