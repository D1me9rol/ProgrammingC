#include "Functions.h"

template <typename T>
void Validation(T& input) // ��������� �������� ������������ �����
{
    while ((cin >> input).fail() || input < 0)
    {
        cout << "������� ���������� ��������" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void AddPipe(map<int, Pipe>& MapOfPipes) // ��������� ���������� �����
{
    Pipe Pipeline;
    cout << "������� �������� �����" << endl;
    cin.ignore();
    getline(cin, Pipeline.PipeName);

    cout << "������� ����� �����" << endl;
    Validation(Pipeline.PipeLength);

    cout << "������� ������� �����" << endl;
    Validation(Pipeline.PipeDiametre);

    cout << "�������� ������� �����:\n0. � �������\n1. ��������" << endl;
    Validation(Pipeline.PipeSign);

    if (Pipeline.PipeDiametre > 0 && Pipeline.PipeLength > 0)
    {
        MapOfPipes.emplace(MapOfPipes.size(), Pipeline);
        cout << "����� ���������!" << endl;
    }

}

void AddStation(map<int, Station>& MapOfStations) // ��������� ���������� �������
{
    Station MainStation;
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

    if (MainStation.ShopNum > 0)
    {
        MapOfStations.emplace(MapOfStations.size(), MainStation);
        cout << "������� ���������!" << endl;
    }
}


void ObjReview(map<int, Pipe> MapOfPipes, map<int, Station> MapOfStations) // ��������� ��������� ��������
{
    Pipe pipe;
    Station station;
    if (!MapOfPipes.empty())
    {
        cout << "���������� � ������" << endl;
        for (const auto& p : MapOfPipes)
        {
            pipe = p.second;
            pipe.Print();
        }
    }
    if (!MapOfStations.empty())
    {
        cout << "���������� � ������������� ��������" << endl;
        for (const auto& s : MapOfStations)
        {
            station = s.second;
            station.Print();
        }
    }

    if (MapOfStations.empty() && MapOfPipes.empty())
        cout << "������ �� ������!" << endl;
}

void FileSave(map<int, Pipe> MapOfPipes, map<int, Station> MapOfStations) // ��������� ���������� ������ � ����
{
    Pipe pipe;
    Station station;
    string FileName;

    cout << "������� �������� �����" << endl;
    cin.ignore();
    getline(cin, FileName);
    ofstream OutData;
    OutData.open(FileName);
    if (!OutData.is_open())
    {
        cout << "�� ������� ������� ����" << endl;
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
            cout << "�������� ������ ����" << endl;
        else
            cout << "������ ���������!" << endl;
    }
    OutData.close();
}

void FileRead(map<int, Pipe>& MapOfPipes, map<int, Station>& MapOfStations) // ��������� �������� ������ �� �����
{
    int PipesAmount;
    int StationsAmount;
    string FileName;
    ifstream InData;

    cout << "������� �������� ����� � ��������� �������" << endl;
    cin.ignore();
    getline(cin, FileName);

    InData.open(FileName);

    if (!InData.is_open())
    {
        cout << "�� ������� ������� ����" << endl;
    }
    else
    {
        cout << "���� ������� ������" << endl;

        InData >> PipesAmount >> StationsAmount;

        if (PipesAmount == 0 && StationsAmount == 0)
        {
            cout << "���� �� �������� ������" << endl;
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

    cout << "0.��������\t 1.������� '� �������'" << endl;
    Validation(Sign);
    if (!Sign)
    {
        cout << "������� �������� �����" << endl;
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
        cout << "������� �������:\t0.� �������\t1. ��������" << endl;
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
        cout << "������� �� �������!" << endl;
}

void FindStation(map<int, Station>& MapOfStations, vector<int>& VecOfStations)
{
    VecOfStations.clear();
    string Name;
    bool Sign;
    float ShopProcent;
    Station station;

    cout << "0.��������\t1.������� ����������������� �����" << endl;
    Validation(Sign);
    if (!Sign)
    {
        cout << "������� �������� �������" << endl;
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
        cout << "������� ������� ����������������� �����" << endl;
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
        cout << "������� �� �������!" << endl;
}

void FindObj(map<int, Pipe>& MapOfPipes, map<int, Station>& MapOfStations, vector<int>& VecOfPipes, vector<int>& VecOfStations)
{
    bool Object;
    cout << "�������� ������� ��� ������:\n0.�����\t1.�������" << endl;
    Validation(Object);
    cout << "�������� ������� ��� ������:" << endl;
    if (!Object)
        FindPipe(MapOfPipes, VecOfPipes);
    else
        FindStation(MapOfStations, VecOfStations);
}

void RedactPipes(map<int, Pipe>& MapOfPipes, vector<int> VecOfPipes)
{
    cout << "�������� ������� ��� ������ ����" << endl;
    FindPipe(MapOfPipes, VecOfPipes);
    bool RepairSign;
    bool Option;
    if (!VecOfPipes.empty())
    { 
        cout << "�������� ��������:\n0.�������\t1.�������������" << endl;
        Validation(Option);
        if (Option)
        {
            cout << "�������� ������� '� �������'\t0.� �������\t1.��������" << endl;
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

        cout << "������ ���������������!" << endl;
    }
}

void RedactStation(map<int, Station>& MapOfStations, vector<int> VecOfStations)
{
    cout << "�������� ������� ��� ������ �������" << endl;
    FindStation(MapOfStations, VecOfStations);
    int WorkShopNum;
    bool Option;
    if (!VecOfStations.empty())
    {
        cout << "�������� ��������:\n0.�������\t1.�������������" << endl;
        Validation(Option);
        if (Option)
        {
            cout << "������� ���������� ������� �����" << endl;
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
        cout << "������ ���������������!" << endl;
    }
}