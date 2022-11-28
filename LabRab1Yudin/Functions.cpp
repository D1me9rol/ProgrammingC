#include "Functions.h"
#include "Pipe.h"
using namespace std;

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
    cin >> Pipeline;

    if (Pipeline.PipeDiametre > 0 && Pipeline.PipeLength > 0)
    {
        MapOfPipes.emplace(MapOfPipes.size(), Pipeline);
        cout << "Труба добавлена!" << endl;
    }

}

void AddStation(map<int, Station>& MapOfStations) // Процедура добавления станции
{
    Station MainStation;
    cin >> MainStation;
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
            cout << pipe;
        }
    }
    if (!MapOfStations.empty())
    {
        cout << "Информация о компрессорных станциях" << endl;
        for (const auto& s : MapOfStations)
        {
            station = s.second;
            cout << station;
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

            for (const auto& p : MapOfPipes)
            {
                OutData << p.second;
            }
            for (const auto& s : MapOfStations)
            {
                OutData << s.second;
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
        else
        {
            MapOfPipes.clear();
            MapOfStations.clear();
            for (int i = 0; i < PipesAmount; i++)
            {
                InData >> MapOfPipes[i];
            }
            for (int i = 0; i < StationsAmount; i++)
            {
                InData >> MapOfStations[i];
            }
        }

    }
    InData.close();
}

//void FindPipe(map<int, Pipe>& MapOfPipes, vector<int>& VecOfPipes)
//{
//    VecOfPipes.clear();
//    bool RepairSign;
//    bool Sign;
//    string Name;
//    Pipe pipe;
//
//    cout << "0.Название\t 1.Признак 'в ремонте'" << endl;
//    Validation(Sign);
//    if (!Sign)
//    {
//        cout << "Введите название трубы" << endl;
//        cin.ignore();
//        getline(cin, Name);
//
//        for (const auto& p : MapOfPipes)
//        {
//            pipe = p.second;
//            string PipeName = pipe.PipeName;
//            if (PipeName.find(Name) >= 0 && PipeName.find(Name) <= PipeName.length())
//            {
//                cout << pipe;
//                VecOfPipes.push_back(p.first);
//            }
//        }
//    }
//    else
//    {
//        cout << "Введите признак:\t0.В ремонте\t1. Починена" << endl;
//        Validation(RepairSign);
//        for (const auto& p : MapOfPipes)
//        {
//            pipe = p.second;
//            if (pipe.PipeSign == RepairSign)
//            {
//                cout << pipe;
//                VecOfPipes.push_back(p.first);
//            }
//        }
//    }
//    if (VecOfPipes.empty())
//        cout << "Объекты не найдены!" << endl;
//}
//
//void FindStation(map<int, Station>& MapOfStations, vector<int>& VecOfStations)
//{
//    VecOfStations.clear();
//    string Name;
//    bool Sign;
//    float ShopProcent;
//    Station station;
//
//    cout << "0.Название\t1.Процент незадействованных цехов" << endl;
//    Validation(Sign);
//    if (!Sign)
//    {
//        cout << "Введите название станции" << endl;
//        cin.ignore();
//        getline(cin, Name);
//
//        for (const auto& s : MapOfStations)
//        {
//            station = s.second;
//            if (station.StationName.find(Name) >= 0 && station.StationName.find(Name) <= station.StationName.length())
//            {
//                cout << VecOfStations.size() + 1;
//                cout << station;
//                VecOfStations.push_back(s.first);
//            }
//        }
//    }
//    else
//    {
//        cout << "Введите процент незадействованных цехов" << endl;
//        Validation(ShopProcent);
//        for (const auto& s : MapOfStations)
//        {
//            station = s.second;
//            if (((station.ShopNum - station.WorkShopNum) / station.ShopNum) * 100 >= ShopProcent)
//            {
//                cout << station;
//                VecOfStations.push_back(s.first);
//            }
//        }
//    }
//    if (VecOfStations.empty())
//        cout << "Объекты не найдены!" << endl;
//}
//
//void FindObj(map<int, Pipe>& MapOfPipes, map<int, Station>& MapOfStations, vector<int>& VecOfPipes, vector<int>& VecOfStations)
//{
//    bool Object;
//    cout << "Выберите объекты для поиска:\n0.Трубы\t1.Станции" << endl;
//    Validation(Object);
//    cout << "Выберите признак для поиска:" << endl;
//    if (!Object)
//        FindPipe(MapOfPipes, VecOfPipes);
//    else
//        FindStation(MapOfStations, VecOfStations);
//}
//
int ChooseID(set<int> keys)
{
    int key=-1;
    cout << "Введите ID объекта, имеющийся в списке" << endl;
    while (true)
    {
        Validation(key);
        if (keys.find(key - 1) == keys.end())
            cout << "Введите существующий id" << endl;
        else
            break;
    }
    return key-1;
}
void RedactPipe(map<int, Pipe>& MapOfPipes)
{
    set<int> keys;
    int key;
    bool choise;
    if (!MapOfPipes.empty())
    {
        for (const auto& p : MapOfPipes)
        {
            cout << "ID трубы: " << p.first + 1 << endl;
            keys.insert(p.first);
            cout << p.second << endl;
        }

       // cout << "Введите id трубы, которую хотите изменить" << endl;
        key = ChooseID(keys);

        cout << "Выберите действие: 0.Удалить 1. Изменить" << endl;
        Validation(choise);
        if (choise)
            MapOfPipes[key].RedactRepairSign();
        else
            MapOfPipes.erase(key);
    }
    else
        cout << "Трубы не заданы!" << endl;
}

void RedactStation(map<int, Station>& MapOfStations)
{
    if (!MapOfStations.empty())
    {
        int key;
        set<int>keys;
        bool choise;
        for (const auto& s : MapOfStations)
        {
            cout << "ID станции: " << s.first + 1 << endl;
            keys.insert(s.first);
            cout << s.second << endl;

        }

       // cout << "Введите id станции, которую хотите изменить" << endl;
        key = ChooseID(keys);
        cout << "Выберите действие: 0.Удалить 1. Изменить" << endl;
        Validation(choise);
        if (choise)
            MapOfStations[key].RedactWorkShopNum();
        else
            MapOfStations.erase(key);
    }
    else
        cout << "Станции не заданы!" << endl;
}

set<int> RenewIDs(set<int> ids)
{
    set<int> NewIDs;
    int id;

    cout << "Введите id выбранных объектов. Для выхода введите 0" << endl;
    while (true)
    {
        Validation(id);

        if (id == 0)
            break;
        else 
        {
            if ((ids.find(id - 1) != ids.end()) && (NewIDs.find(id-1) == NewIDs.end()))
                NewIDs.insert(id - 1);
            else
                cout << "Введенный id не найден либо введен повторно" << endl;
        }
    }
    return NewIDs;
}

void FilterPipes(map<int, Pipe>& MapOfPipes)
{
    int choise;
    bool action;
    string name;
    set<int> keys;

    if (!MapOfPipes.empty())
    {
        cout << "Выберите фильтр: 1.По имени 2.В ремонте 3.Починена" << endl;
        do
        {
            Validation(choise);
            switch (choise)
            {
            case 1:
                cout << "Введите название трубы" << endl;
                cin.ignore();
                getline(cin, name);

                for (const auto& p : MapOfPipes)
                {
                    if (p.second.PipeName.find(name) != p.second.PipeName.npos)
                    {
                        cout << "ID трубы: " << p.first + 1 << endl;
                        keys.insert(p.first);
                        cout << p.second;
                    }

                }
                break;
            case 2:
                for (const auto& p : MapOfPipes)
                {
                    if (!p.second.PipeSign)
                    {
                        cout << "ID трубы: " << p.first + 1 << endl;
                        keys.insert(p.first);
                        cout << p.second;
                    }

                }
                break;
            case 3:
                for (const auto& p : MapOfPipes)
                {
                    if (p.second.PipeSign)
                    {
                        cout << "ID трубы: " << p.first + 1 << endl;
                        keys.insert(p.first);
                        cout << p.second;
                    }
                }
                break;
            default:
                cout << "Выберите число от 1 до 3" << endl;
                break;

            }
        } while (choise < 1 || choise>3);

        cout << "Выберите дальнейшее действие\t0.Выход\t1.Редактировать" << endl;
        Validation(action);

        if (action)
        {
            cout << "Выберите действие\t0.Выбрать все\t1.Выбрать вручную" << endl;
            Validation(action);
            if (action)
                keys = RenewIDs(keys);

            cout << "Выберите дейтсвие\t0.Удалить\t1.Редактировать" << endl;
            Validation(choise);

            if (!choise)
            {
                for (int p : keys)
                    MapOfPipes.erase(p);
            }
            else
            {
                for (int p : keys)
                    MapOfPipes[p].RedactRepairSign();
            }
        }
        else
            return;
    }
    else
        cout << "Трубы не заданы!" << endl;
}
void FilterStations(map<int, Station>& MapOfStations)
{
    int choise;
    bool action;
    string name;
    int RunWorkShops;
    set<int> keys;

    if (!MapOfStations.empty())
    {
        cout << "Выберите фильтр: 1.По имени 2.Процент рабочих цехов <= 3.Процент рабочих цехов >=" << endl;
        do
        {
            Validation(choise);
            switch (choise)
            {
            case 1:
                cout << "Введите название трубы" << endl;
                cin.ignore();
                getline(cin, name);

                for (const auto& p : MapOfStations)
                {
                    if (p.second.StationName.find(name) != p.second.StationName.npos)
                    {
                        cout << "ID трубы: " << p.first + 1 << endl;
                        keys.insert(p.first);
                        cout << p.second;
                    }
                }
                break;
            case 2:
                cout << "Введите процент рабочих цехов" << endl;
                Validation(RunWorkShops);
                for (const auto& p : MapOfStations)
                {
                    if ((p.second.WorkShopNum / p.second.ShopNum) <= RunWorkShops)
                    {
                        cout << "ID станции: " << p.first + 1 << endl;
                        keys.insert(p.first);
                        cout << p.second;
                    }

                }
                break;
            case 3:
                cout << "Введите процент рабочих цехов" << endl;
                Validation(RunWorkShops);
                for (const auto& p : MapOfStations)
                {
                    if ((p.second.WorkShopNum / p.second.ShopNum) >= RunWorkShops)
                    {
                        cout << "ID станции: " << p.first + 1 << endl;
                        keys.insert(p.first);
                        cout << p.second;
                    }
                }
                break;
            default:
                cout << "Выберите число от 1 до 3" << endl;
                break;

            }
        } while (choise < 1 || choise>3);

        cout << "Выберите дальнейшее действие\t0.Выход\t1.Редактировать" << endl;
        Validation(action);

        if (action)
        {
            cout << "Выберите действие\t0.Выбрать все\t1.Выбрать вручную" << endl;
            Validation(action);
            if (action)
                keys = RenewIDs(keys);

            cout << "Выберите дейтсвие\t0.Удалить\t1.Редактировать" << endl;
            Validation(choise);

            if (!choise)
            {
                for (int p : keys)
                    MapOfStations.erase(p);
            }
            else
            {
                for (int p : keys)
                    MapOfStations[p].RedactWorkShopNum();
            }
        }
        else
            return;
    }
    else
        cout << "Станции не заданы!" << endl;
}
//void RedactPipes(map<int, Pipe>& MapOfPipes)
//{
//    vector<int> VecOfPipes;
//    cout << "Выберите признак для поиска труб" << endl;
//    FindPipe(MapOfPipes, VecOfPipes);
//    bool RepairSign;
//    bool Option;
//    bool Amount;
//    int Number=-1;
//    vector<int> Keys;
//    if (!VecOfPipes.empty())
//    {
//        cout << "Выберите количество изменяемых объектов\t0.Все найденные\t1.По выбору" << endl;
//        Validation(Amount);
//        if (Amount)
//        {
//            cout << "Выберите номера объектов" << endl;
//            while (Number != 0)
//            {
//                Validation(Number);
//                if (Number > 0)
//                {
//                    if (Number <= VecOfPipes.size() && find(Keys.begin(), Keys.end(), Number-1)==Keys.end())
//                        Keys.push_back(Number - 1);
//                    else
//                        cout << "Выберите номер от 1 до " << VecOfPipes.size()<< ", не введенный ранее" << endl;
//                }
//                
//            }
//            
//        }
//        else
//        {
//            for (int i = 0; i < VecOfPipes.size(); i++)
//                Keys.push_back(VecOfPipes[i]);
//        }
//           
//
//            cout << "Веберите действие:\n0.Удалить\t1.Редактировать" << endl;
//            Validation(Option);
//            if (Option)
//            {
//                for (int i = 0; i < Keys.size(); i++)
//                    MapOfPipes[Keys[i]].RedactRepairSign();
//                /*cout << "Выберите признак 'в ремонте'\t0.В ремонте\t1.Починена" << endl;
//                Validation(RepairSign);
//                for (int i = 0; i < Keys.size(); i++)
//                {
//                    MapOfPipes[Keys[i]].PipeSign = RepairSign;
//                }*/
//            }
//
//        
//        else
//        {
//            for (int i = 0; i < Keys.size(); i++)
//            {
//                MapOfPipes.erase(Keys[i]);
//            }
//        }
//
//        cout << "Данные отредактированы!" << endl;
//    }
//}
//
//void RedactStations(map<int, Station>& MapOfStations)
//{
//    vector<int> VecOfStations;
//    cout << "Выберите признак для поиска станций" << endl;
//    FindStation(MapOfStations, VecOfStations);
//    int WorkShopNum;
//    bool Option;
//    bool Amount;
//    int Number=-1;
//    vector<int> Keys;
//
//    if (!VecOfStations.empty())
//    {
//        cout << "Выберите количество изменяемых объектов\t0.Все найденные\t1.По выбору" << endl;
//        Validation(Amount);
//        if (Amount)
//        {
//            cout << "Выберите номера объектов" << endl;
//            while (Number != 0)
//            {
//                Validation(Number);
//                if (Number > 0)
//                {
//                    if (Number <= VecOfStations.size() && find(Keys.begin(), Keys.end(), Number-1) == Keys.end())
//                        Keys.push_back(Number - 1);
//                    else
//                        cout << "Выберите номер от 1 до " << VecOfStations.size() <<", не введенный ранее" << endl;
//                }
//                
//            }
//        }
//        else
//        {
//            for (int i = 0; i < VecOfStations.size(); i++)
//                Keys.push_back(VecOfStations[i]);
//        }
//        cout << "Веберите действие:\n0.Удалить\t1.Редактировать" << endl;
//        Validation(Option);
//        if (Option)
//        {
//            /*cout << "Введите количество рабочих цехов" << endl;
//            Validation(WorkShopNum);
//            for (int i = 0; i < Keys.size(); i++)
//            {
//                MapOfStations[Keys[i]].WorkShopNum = WorkShopNum;
//            }*/
//            for (int i = 0; i < Keys.size(); i++)
//                MapOfStations[Keys[i]].RedactWorkShopNum();
//        }
//        else
//        {
//            for (int i = 0; i < Keys.size(); i++)
//            {
//                MapOfStations.erase(Keys[i]);
//            }
//        }
//        cout << "Данные отредактированы!" << endl;
//    }
//}


