#include "Pipe.h"
void Pipe::Print()
{
	cout << "�������� �����: " << PipeName << "\t����� �����: " << PipeLength << " �\t�������: " << PipeDiametre << "��\t���������: ";
	        if (PipeSign)
	        {
	            cout << "��������" << endl;
	        }
	        else
	            cout << "� �������" << endl;
}