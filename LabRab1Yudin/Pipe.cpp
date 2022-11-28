#include "Pipe.h"
#include "Functions.h"

using namespace std;


void Pipe::RedactRepairSign()
{
	cout << "�������� ��������� ����� "<< PipeName<<"\t0. � �������\t1. ��������" << endl;
	Validation(PipeSign);
}

std::istream& operator >> (std::istream& in, Pipe& Pipeline) {
	
	cout << "������� �������� �����" << endl;
	cin.ignore();
	getline(cin, Pipeline.PipeName);

	cout << "������� ����� �����" << endl;
	Validation(Pipeline.PipeLength);

	cout << "������� ������� �����" << endl;
	Validation(Pipeline.PipeDiametre);

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
