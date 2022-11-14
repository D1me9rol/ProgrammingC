#include "Station.h"

void Station::Print()
{
	cout << "Название: " << StationName << "\tКоличество цехов: " << ShopNum << "\tКоличество рабочих цехов: " << WorkShopNum << "\tЭффективность:" << Efficiency << endl;
}
