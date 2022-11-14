#include "Functions.h"

template <typename T>
void Validation(T& input) // Процедура проверки правильности ввода
{
    while ((cin >> input).fail() || input < 0)
    {
        cout << "Введите корректное значение" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void AddPipe(map<int, Pipe>& MapOfPipes) // Процедура добавления трубы
{
    Pipe Pipeline;
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
        cout << "Труба добавлена!" << endl;
    }

}

void AddStation(map<int, Station>& MapOfStations) // Процедура добавления станции
{
    Station MainStation;
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
        cout << "Станция добавлена!" << endl;
    }
}


void ObjReview(map<int, Pipe> MapOfPipes, map<int, Station> MapOfStations) // Процедура просмотра объектов
{
    Pipe pipe;
    Station station;
    if (!MapOfPipes.empty())
    {
        cout << "Информация о трубах" << endl;
        for (const auto& p : MapOfPipes)
        {
            pipe = p.second;
            pipe.Print();
        }
    }
    if (!MapOfStations.empty())
    {
        cout << "Информация о компрессорных станциях" << endl;
        for (const auto& s : MapOfStations)
        {
            station = s.second;
            station.Print();
        }
    }

    if (MapOfStations.empty() && MapOfPipes.empty())
        cout << "Данные не заданы!" << endl;
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
    if (!OutData.is_open())
    {
        cout << "Не удалось открыть файл" << endl;
    }
    else
    {

        OutData << MapOfPipes.size() << endl;
        OutData << MapOfStations.size() << endl;

        if (!MapOfPipes.empty())
        {
            for (const auto& p : MapOfPipes)
            {
                pipe = p.second;
                OutData << pipe.PipeName << "\n" << pipe.PipeLength << "\n" << pipe.PipeDiametre << "\n" << pipe.PipeSign << endl;;
            }
        }
        if (!MapOfStations.empty())
        {
            for (const auto& s : MapOfStations)
            {
                station = s.second;
                OutData << station.StationName << "\n" << station.ShopNum << "\n" << station.WorkShopNum << "\n" << station.Efficiency << endl;
            }
        }
        OutData.close();
        if (MapOfPipes.empty() && MapOfStations.empty())
            cout << "Сохранен пустой файл" << endl;
        else
            cout << "Данные сохранены!" << endl;
    }
    OutData.close();
}

void FileRead(map<int, Pipe>& MapOfPipes, map<int, Station>& MapOfStations) // Процедура загрузки данных из файла
{
    int PipesAmount;
    int StationsAmount;
    string FileName;
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

        if (PipesAmount == 0 && StationsAmount == 0)
        {
            cout << "Файл не содержит данных" << endl;
        }

        else if (PipesAmount > 0 && StationsAmount == 0)
        {
            MapOfPipes.clear();
            for (int i = 0; i < PipesAmount; i++)
            {
                InData.ignore();
                getline(InData, MapOfPipes[i].PipeName);
                InData >> MapOfPipes[i].PipeLength >> MapOfPipes[i].PipeDiametre >> MapOfPipes[i].PipeSign;
            }
        }
        else if (StationsAmount > 0 && PipesAmount == 0)
        {
            MapOfStations.clear();
            for (int i = 0; i < StationsAmount; i++)
            {
                InData.ignore();
                getline(InData, MapOfStations[i].StationName);
                InData >> MapOfStations[i].ShopNum >> MapOfStations[i].WorkShopNum >> MapOfStations[i].Efficiency;
            }
        }

        else
        {
            MapOfPipes.clear();
            MapOfStations.clear();
            for (int i = 0; i < PipesAmount; i++)
            {
                InData.ignore();
                getline(InData, MapOfPipes[i].PipeName);
                InData >> MapOfPipes[i].PipeLength >> MapOfPipes[i].PipeDiametre >> MapOfPipes[i].PipeSign;
            }
            for (int i = 0; i < StationsAmount; i++)
            {
                InData.ignore();
                getline(InData, MapOfStations[i].StationName);
                InData >> MapOfStations[i].ShopNum >> MapOfStations[i].WorkShopNum >> MapOfStations[i].Efficiency;
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
    Pipe pipe;

    cout << "0.Название\t 1.Признак 'в ремонте'" << endl;
    Validation(Sign);
    if (!Sign)
    {
        cout << "Введите название трубы" << endl;
        cin.ignore();
        getline(cin, Name);

        for (const auto& p : MapOfPipes)
        {
            pipe = p.second;
            string PipeName = pipe.PipeName;
            if (PipeName.find(Name) >= 0 && PipeName.find(Name) <= PipeName.length())
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
            }
        }
    }
    if (VecOfPipes.empty())
        cout << "Объекты не найдены!" << endl;
}

void FindStation(map<int, Station>& MapOfStations, vector<int>& VecOfStations)
{
    VecOfStations.clear();
    string Name;
    bool Sign;
    float ShopProcent;
    Station station;

    cout << "0.Название\t1.Процент незадействованных цехов" << endl;
    Validation(Sign);
    if (!Sign)
    {
        cout << "Введите название станции" << endl;
        cin.ignore();
        getline(cin, Name);

        for (const auto& s : MapOfStations)
        {
            station = s.second;
            if (station.StationName.find(Name) >= 0 && station.StationName.find(Name) <= station.StationName.length())
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
        for (const auto& s : MapOfStations)
        {
            station = s.second;
            if (((station.ShopNum - station.WorkShopNum) / station.ShopNum) * 100 >= ShopProcent)
            {
                station.Print();
                VecOfStations.push_back(s.first);
            }
        }
    }
    if (VecOfStations.empty())
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

void RedactPipes(map<int, Pipe>& MapOfPipes, vector<int> VecOfPipes)
{
    cout << "Выберите признак для поиска труб" << endl;
    FindPipe(MapOfPipes, VecOfPipes);
    bool RepairSign;
    bool Option;
    if (!VecOfPipes.empty())
    { 
        cout << "Веберите действие:\n0.Удалить\t1.Редактировать" << endl;
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

        cout << "Данные отредактированы!" << endl;
    }
}

void RedactStation(map<int, Station>& MapOfStations, vector<int> VecOfStations)
{
    cout << "Выберите признак для поиска станций" << endl;
    FindStation(MapOfStations, VecOfStations);
    int WorkShopNum;
    bool Option;
    if (!VecOfStations.empty())
    {
        cout << "Веберите действие:\n0.Удалить\t1.Редактировать" << endl;
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
        cout << "Данные отредактированы!" << endl;
    }
}