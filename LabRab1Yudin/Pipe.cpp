#include "Pipe.h"
void Pipe::Print()
{
	cout << "Название трубы: " << PipeName << "\tДлина трубы: " << PipeLength << " м\tДиаметр: " << PipeDiametre << "мм\tСостояние: ";
	        if (PipeSign)
	        {
	            cout << "Починена" << endl;
	        }
	        else
	            cout << "В ремонте" << endl;
}