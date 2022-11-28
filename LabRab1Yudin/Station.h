#pragma once
#include <string>
#include <iostream>


class Station
{
public:
	    std::string StationName;
	    int ShopNum, WorkShopNum, Efficiency;
	
		void RedactWorkShopNum();

		friend std::istream& operator >> (std::istream& in, Station& MainStation);
		friend std::ostream& operator << (std::ostream& out, const Station& MainStation);
		friend std::ifstream& operator >> (std::ifstream& fin, Station& MainStation);
		friend std::ofstream& operator << (std::ofstream& fout, const Station& MainStation);
};

