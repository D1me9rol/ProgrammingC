#include "Station.h"
#include "Functions.h"

using namespace std;


void Station::RedactWorkShopNum()
{
	WorkShopNum = INT_MAX;
	cout << "������� ���������� ������� ����� �� ������� " << StationName << " �� 0 �� " << ShopNum << endl;

	while (WorkShopNum > ShopNum)
	{
		cout << "������� ����� �� 0 �� " << ShopNum << endl;
		Validation(WorkShopNum);
	}
}

std::istream& operator >> (std::istream& in, Station& MainStation)
{
	cout << "������� �������� �������" << endl;
	cin.ignore();
	getline(cin, MainStation.StationName);

	cout << "������� ���������� �����" << endl;
	Validation(MainStation.ShopNum);

	cout << "������� ���������� ������� �����" << endl;
	Validation(MainStation.WorkShopNum);

	while (MainStation.WorkShopNum > MainStation.ShopNum)
	{
		cout << "���������� ������� ����� �� ����� ��������� ����� ���������� �����" << endl;
		cout << "������� ���������� ������� ����� �� 0 �� " << MainStation.ShopNum << endl;
		Validation(MainStation.WorkShopNum);
	}

	cout << "������� ���������� �������������" << endl;
	Validation(MainStation.Efficiency);

	return in;
}
//friend std::ostream& operator << (std::ostream& out, const Station& MainStation);
std::ostream& operator<<(std::ostream& out, const Station& MainStation)
{
	//cout << "ID �����:" << MainStation
	cout << "��������: " << MainStation.StationName << "\t���������� �����: " << MainStation.ShopNum << "\t���������� ������� �����: " << MainStation.WorkShopNum << "\t�������������:" << MainStation.Efficiency << endl;
	return out;
}

std::ifstream& operator>>(std::ifstream& fin, Station& MainStation)
{
	fin.ignore();
	getline(fin, MainStation.StationName);
	fin >> MainStation.ShopNum >> MainStation.WorkShopNum >> MainStation.Efficiency;
	return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const Station& MainStation)
{
	fout << MainStation.StationName << "\n" << MainStation.ShopNum << "\n" << MainStation.WorkShopNum << "\n" << MainStation.Efficiency << endl;
	return fout;
}

