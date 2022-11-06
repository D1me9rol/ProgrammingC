// LabRab1Yudin.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;



class Pipe // Создание класса Труба
{
public:
    string PipeName;
    int PipeLength, PipeDiametre;
    bool PipeSign;

    void Print()
    {
        cout <<"Номер трубы: " << PipeName << "\tДлина трубы: " <<PipeLength << " м\tДиаметр: " <<PipeDiametre << "мм\tСостояние: ";
        if (PipeSign)
        {
            cout << "Починена" << endl;
        }
        else
            cout << "В ремонте" << endl;
    }
};

class Station // Создание класса Компрессорная станция
{
public:
    string StationName;
    int ShopNum, WorkShopNum, Efficiency;

    void Print()
    {
        cout << "Название: " <<StationName << "\tКоличество цехов: " <<ShopNum << "\tКоличество рабочих цехов: " <<WorkShopNum << "\tЭффективность:" <<Efficiency << endl;
    }
};


void ShowMenu() // Вывод меню
{
    cout << "Меню\n";
    cout << "1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n8. Найти объекты\n0. Выход "<< endl;
    cout << "Выберите номер действия" << endl;
}

template <typename T> // Создание шаблона
void Validation(T& input) // Процедура проверки правильности ввода
{
    while ((cin >> input).fail() || input < 0)
    {
        cout << "Введите корректное значение" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void AddPipe(Pipe& Pipeline, map<int, Pipe>& MapOfPipes) // Процедура добавления трубы
{
    cout << "Введите название трубы" << endl;
    cin.ignore();
    getline(cin, Pipeline.PipeName);

    cout << "Введите длину трубы" << endl;
    Validation(Pipeline.PipeLength);

    cout << "Введите диаметр трубы" << endl;
    Validation(Pipeline.PipeDiametre);

    cout << "Выберите признак трубы:\n0. В ремонте\n1. Починена" << endl;
    Validation(Pipeline.PipeSign);

    if (Pipeline.PipeDiametre > 0 && Pipeline.PipeLength > 0)
    { 
        MapOfPipes.emplace(MapOfPipes.size(), Pipeline);
        //MapOfPipesCount++;
    }

}

void AddStation(Station& MainStation, map<int, Station>& MapOfStations) // Процедура добавления станции
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

        if (MainStation.ShopNum > 0)
        { 
            MapOfStations.emplace(MapOfStations.size(), MainStation);
        }
}


void ObjReview(map<int, Pipe> MapOfPipes, map<int, Station> MapOfStations) // Процедура просмотра объектов
{
    Pipe pipe;
    Station station;
    if (MapOfPipes.size()>0)
    {
        cout << "Информация о трубах" << endl;
        for (const auto& p:MapOfPipes)
        {
            pipe = p.second;
            pipe.Print();
        } 
    }
    if (MapOfStations.size()>0)
    {
        cout << "Информация о компрессорных станциях" << endl;
        for (const auto& s:MapOfStations)
        {
            station = s.second;
            station.Print();
        }
    }

    if (MapOfStations.size()==0 && MapOfPipes.size()==0)
    {
        cout << "Данные не заданы!" << endl;
    }
}

void FileSave(map<int, Pipe> MapOfPipes, map<int, Station> MapOfStations) // Процедура сохранения данных в файл
{
    Pipe pipe;
    Station station;
    string FileName;

    cout << "Введите название файла" << endl;
    cin.ignore();
    getline(cin, FileName);
    ofstream OutData;
    OutData.open(FileName);
    if (! OutData.is_open())
    {
        cout << "Не удалось открыть файл" << endl;
    }
    else
    {
        
        OutData << MapOfPipes.size() << endl;
        OutData << MapOfStations.size() << endl;

        if (MapOfPipes.size() > 0)
        { 
            for (const auto& p : MapOfPipes)
            {
                pipe = p.second;
                OutData << pipe.PipeName << "\n" << pipe.PipeLength << "\n" << pipe.PipeDiametre << "\n" << pipe.PipeSign << endl;;
            }
        }
        if (MapOfStations.size() > 0)
        {
            for (const auto& s : MapOfStations)
            {
                station = s.second;
                OutData << station.StationName << "\n" << station.ShopNum << "\n" << station.WorkShopNum << "\n" << station.Efficiency << endl;
            }
        }
            OutData.close();
        if (MapOfPipes.size() == 0 && MapOfStations.size() == 0)
            cout << "Сохранен пустой файл" << endl;
        else
            cout << "Данные сохранены!" << endl;    
    }
}

void FileRead(map<int, Pipe>& MapOfPipes, map<int, Station> MapOfStations, vector<int>& VecOfPipes, vector<int>& VecOfStations) // Процедура загрузки данных из файла
{
    int PipesAmount;
    int StationsAmount;
    string FileName ="";
    ifstream InData;

        cout << "Введите название файла с исходными данными" << endl;
        cin.ignore();
        getline(cin, FileName);

    InData.open(FileName);

    if (!InData.is_open())
    {
        cout << "Не удалось открыть файл" << endl;
    }
    else
    {
        cout << "Файл успешно открыт" << endl;

        InData >> PipesAmount >> StationsAmount;
        //cout << PipesAmount << " " << StationsAmount << endl;

        if (PipesAmount==0 && StationsAmount==0)
        {
            cout << "Файл не содержит данных" << endl;
        }

        else if (PipesAmount>0 && StationsAmount==0)
        {
            for (int i=0; i<PipesAmount; i++)
            { 
                InData.ignore();
                getline(InData, MapOfPipes[i].PipeName);
                InData >> MapOfPipes[i].PipeLength >> MapOfPipes[i].PipeDiametre >> MapOfPipes[i].PipeSign;
                //VecOfPipes.push_back(i);
            }
        }
        else if (StationsAmount>0 && PipesAmount==0)
        {
            for (int i =0; i<StationsAmount; i++)
            { 
                InData.ignore();
                getline(InData, MapOfStations[i].StationName);
                InData >> MapOfStations[i].ShopNum >> MapOfStations[i].WorkShopNum >> MapOfStations[i].Efficiency;
                //VecOfStations.push_back(i);
            }
        }

        else
        {
                for (int i = 0; i < PipesAmount; i++)
                {
                        InData.ignore();
                        getline(InData, MapOfPipes[i].PipeName);
                        InData >> MapOfPipes[i].PipeLength >> MapOfPipes[i].PipeDiametre >> MapOfPipes[i].PipeSign;
                        //VecOfPipes.push_back(i);
                }
                for (int i = 0; i < StationsAmount; i++)
                {
                    InData.ignore();
                    getline(InData, MapOfStations[i].StationName);
                    InData >> MapOfStations[i].ShopNum >> MapOfStations[i].WorkShopNum >> MapOfStations[i].Efficiency;
                    //VecOfStations.push_back(i);
                }
        }
    }
    InData.close();
}

void FindPipe(map<int, Pipe>& MapOfPipes, vector<int>& VecOfPipes)
{
    VecOfPipes.clear();
    bool RepairSign;
    bool Sign;
    string Name;
    int counter = 0;
    Pipe pipe;

    cout << "0.Название\t 1.Признак 'в ремонте'" << endl;
    Validation(Sign);
    if (!Sign)
    {
        cout << "Введите название трубы" << endl;
        cin.ignore();
        getline(cin, Name);

        for (const auto& p:MapOfPipes)
        {
            pipe = p.second;
            string PipeName = pipe.PipeName;
            if (PipeName.find(Name) >= 0 && PipeName.find(Name)<=PipeName.length())
            {
                cout << PipeName.find(Name) << endl;
                pipe.Print();
                VecOfPipes.push_back(p.first);
            }
        }
    }
    else
    {
        cout << "Введите признак:\t0.В ремонте\t1. Починена" << endl;
        Validation(RepairSign);
        for (const auto& p : MapOfPipes)
        {
            pipe = p.second;
            if (pipe.PipeSign == RepairSign)
            {
                pipe.Print();
                VecOfPipes.push_back(p.first);
               // cout << VecOfPipes[0] << endl;
            }
        }
    }
}

void FindStation(map<int, Station>& MapOfStations, vector<int>& VecOfStations)
{
    VecOfStations.clear();
    string Name;
    bool Sign;
    float ShopProcent;
    int counter = 0;
    Station station;

    cout << "0.Название\t1.Процент незадействованных цехов" << endl;
    Validation(Sign);
    if (!Sign)
    {
        cout << "Введите название станции" << endl;
        cin.ignore();
        getline(cin, Name);

        for (const auto& s:MapOfStations)
        {
            station = s.second;
            if (station.StationName.find(Name) >= 0 && station.StationName.find(Name)<= station.StationName.length())
            {
                station.Print();
                VecOfStations.push_back(s.first);
            }
        }
    }
    else
    {
        cout << "Введите процент незадействованных цехов" << endl;
        Validation(ShopProcent);
        for (const auto& s:MapOfStations)
        {
            station = s.second;
            if (((station.ShopNum - station.WorkShopNum) / station.ShopNum)*100 >= ShopProcent)
            {
                station.Print();
                VecOfStations.push_back(s.first);
            }
        }
    }
    if (counter == 0)
        cout << "Объекты не найдены!" << endl;
}

void FindObj(map<int, Pipe>& MapOfPipes, map<int, Station>& MapOfStations, vector<int>& VecOfPipes, vector<int>& VecOfStations)
{
    bool Object;
    cout << "Выберите объекты для поиска:\n0.Трубы\t1.Станции" << endl;
    Validation(Object);
    cout << "Выберите признак для поиска:" << endl;
    if (!Object)
        FindPipe(MapOfPipes, VecOfPipes);
    else
        FindStation(MapOfStations, VecOfStations);
}

void RedactPipes(map<int, Pipe>& MapOfPipes, vector<int>& VecOfPipes)
{
    cout << "Выберите признак для поиска труб" << endl;
    FindPipe(MapOfPipes, VecOfPipes);
    bool RepairSign;
    bool Option;
    cout << "Веберите действие:\n0.Удалить\t1.Редактировать";
    Validation(Option);
    if (Option)
    {
        cout << "Выберите признак 'в ремонте'\t0.В ремонте\t1.Починена" << endl;
        Validation(RepairSign);
        for (int i = 0; i < VecOfPipes.size(); i++)
        {
            MapOfPipes[VecOfPipes[i]].PipeSign = RepairSign;
        }
    }
    else
    {
        for (int i = 0; i < VecOfPipes.size(); i++)
        {
            MapOfPipes.erase(VecOfPipes[i]);
        }
    }
}

void RedactStation(map<int, Station>& MapOfStations, vector<int>& VecOfStations)
{
    cout << "Выберите признак для поиска станций" << endl;
    FindStation(MapOfStations, VecOfStations);
    int WorkShopNum;
    bool Option;

    cout << "Веберите действие:\n0.Удалить\t1.Редактировать";
    Validation(Option);
    if (Option)
    {
        cout << "Введите количество рабочих цехов" << endl;
        Validation(WorkShopNum);
        for (int i = 0; i < VecOfStations.size(); i++)
        {
            MapOfStations[VecOfStations[i]].WorkShopNum = WorkShopNum;
        }
    }
    else
    {
        for (int i = 0; i < VecOfStations.size(); i++)
        {
            MapOfStations.erase(VecOfStations[i]);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    
    
    Station MainStation;
    Pipe Pipeline;
    map<int, Pipe> MapOfPipes;
    map<int, Station> MapOfStations;
   // int StationsCount=0;
    //int MapOfPipesCount=0;
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
            AddPipe(Pipeline, MapOfPipes);
            break;
        case 2:
            AddStation(MainStation, MapOfStations);
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
            FileRead(MapOfPipes, MapOfStations, VecOfPipes, VecOfStations);
            break;
        case 8:
            FindObj(MapOfPipes, MapOfStations, VecOfPipes, VecOfStations);
            break;
        case 0:
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Выберите значение от 0 до 7" << endl;
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
