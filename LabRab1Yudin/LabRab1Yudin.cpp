// LabRab1Yudin.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <map>
#include <vector>
#include "Pipe.h"
#include "Station.h"
#include "Functions.h"

using namespace std;



//class Pipe // Создание класса Труба
//{
//public:
//    string PipeName;
//    int PipeLength, PipeDiametre;
//    bool PipeSign;
//
//    void Print()
//    {
//        cout <<"Название трубы: " << PipeName << "\tДлина трубы: " <<PipeLength << " м\tДиаметр: " <<PipeDiametre << "мм\tСостояние: ";
//        if (PipeSign)
//        {
//            cout << "Починена" << endl;
//        }
//        else
//            cout << "В ремонте" << endl;
//    }
//};

//class Station // Создание класса Компрессорная станция
//{
//public:
//    string StationName;
//    int ShopNum, WorkShopNum, Efficiency;
//
//    void Print()
//    {
//        cout << "Название: " <<StationName << "\tКоличество цехов: " <<ShopNum << "\tКоличество рабочих цехов: " <<WorkShopNum << "\tЭффективность:" <<Efficiency << endl;
//    }
//};


void ShowMenu() // Вывод меню
{
    cout << "Меню\n";
    cout << "1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n8. Найти объекты\n0. Выход "<< endl;
    cout << "Выберите номер действия" << endl;
}



int main()
{
    setlocale(LC_ALL, "rus");
    
    map<int, Pipe> MapOfPipes;
    map<int, Station> MapOfStations;
    vector<int> VecOfPipes;
    vector<int> VecOfStations;
    int Option;

    do
    {
        ShowMenu();
        Validation(Option);
        switch (Option)
        {
        case 1:
            AddPipe(MapOfPipes);
            break;
        case 2:
            AddStation(MapOfStations);
            break;
        case 3:
            ObjReview(MapOfPipes, MapOfStations);
            break;
        case 4:
            RedactPipes(MapOfPipes, VecOfPipes);
            break;
        case 5:
            RedactStation(MapOfStations, VecOfStations);
            break;
        case 6:
            FileSave(MapOfPipes, MapOfStations);
            break;
        case 7:
            FileRead(MapOfPipes, MapOfStations);
            break;
        case 8:
            FindObj(MapOfPipes, MapOfStations, VecOfPipes, VecOfStations);
            break;
        case 0:
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Выберите значение от 0 до 8" << endl;
            break;
        }
    } while (Option != 0);
    return 0;
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
