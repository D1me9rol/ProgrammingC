#include "Station.h"
#include "Functions.h"

using namespace std;


void Station::RedactWorkShopNum()
{
	WorkShopNum = INT_MAX;
	cout << "Введите количество рабочих цехов на станции " << StationName << " от 0 до " << ShopNum << endl;

	while (WorkShopNum > ShopNum)
	{
		cout << "Введите число от 0 до " << ShopNum << endl;
		Validation(WorkShopNum);
	}
}

std::istream& operator >> (std::istream& in, Station& MainStation)
{
	cout << "Введите название станции" << endl;
	cin.ignore();
	getline(cin, MainStation.StationName);

	cout << "Введите количество цехов" << endl;
	Validation(MainStation.ShopNum);

	cout << "Введите количество рабочих цехов" << endl;
	Validation(MainStation.WorkShopNum);

	while (MainStation.WorkShopNum > MainStation.ShopNum)
	{
		cout << "Количество рабочих цехов не может превышать общее количество цехов" << endl;
		cout << "Введите количество рабочих цехов от 0 до " << MainStation.ShopNum << endl;
		Validation(MainStation.WorkShopNum);
	}

	cout << "Введите показатель эффективности" << endl;
	Validation(MainStation.Efficiency);

	return in;
}
//friend std::ostream& operator << (std::ostream& out, const Station& MainStation);
std::ostream& operator<<(std::ostream& out, const Station& MainStation)
{
	//cout << "ID трубы:" << MainStation
	cout << "Название: " << MainStation.StationName << "\tКоличество цехов: " << MainStation.ShopNum << "\tКоличество рабочих цехов: " << MainStation.WorkShopNum << "\tЭффективность:" << MainStation.Efficiency << endl;
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

