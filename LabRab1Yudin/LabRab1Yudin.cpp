// LabRab1Yudin.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Tube
{
    int TubeLength, TubeDiametre;
    bool TubeSign;
};

struct Station
{
    string StationName;
    int ShopNum, WorkShopNum, Efficiency;
};

bool TubeExistence = false;
bool StationExistence = false;

void ShowMenu()
{
    cout << "Меню\n";
    cout << "1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход "<< endl;
    cout << "Выберите номер действия" << endl;
}

template <typename T>
void Validation(T& input)
{
    while ((cin >> input).fail() || input < 0)
    {
        cout << "Введите корректное значение"<< endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void AddTube(Tube& MainTube)
{
    if (!TubeExistence)
    {
        cout << "Введите длину трубы" << endl;
        Validation(MainTube.TubeLength);

        cout << "Введите диаметр трубы" << endl;
        Validation(MainTube.TubeDiametre);

        cout << "Выберите признак трубы:\n0. В ремонте\n1. Починена" << endl;
        Validation(MainTube.TubeSign);

        TubeExistence = true;
    }

    else
    {
        cout << "Труба уже существует" << endl;
    }
}

void AddStation(Station& AddedStation)
{
    if (!StationExistence)
    {
        cout << "Введите название станции" << endl;
        cin.ignore();
        getline(cin, AddedStation.StationName);

        cout << "Введите количество цехов" << endl;
        Validation(AddedStation.ShopNum);

        cout << "Введите количество рабочих цехов" << endl;
        Validation(AddedStation.WorkShopNum);
        while (AddedStation.WorkShopNum > AddedStation.ShopNum)
        {
            cout << "Количество рабочих цехов не может превышать общее количество цехов" << endl;
            cout << "Введите количество рабочих цехов" << endl;
            Validation(AddedStation.WorkShopNum);
        }
        cout << "Введите показатель эффективности" << endl;
        Validation(AddedStation.Efficiency);

        StationExistence = true;
    }
    

    else
    {
        cout << "Компрессорная станция уже существует" << endl;
    }
}


void ObjReview(Tube& MainTube, Station& AddedStation)
{
    if (TubeExistence)
    {
        cout << "Информация о трубе" << endl;
        cout << "Длина трубы: " << MainTube.TubeLength << " м\nДиаметр: " << MainTube.TubeDiametre << "мм\nСостояние:";
        if (MainTube.TubeSign)
        {
            cout << "Починена" << endl;
        }
        else
            cout << "В ремонте" << endl;
    }

    if (StationExistence)
    {
        cout << "Информация о компрессорной станции" << endl;
        cout << "Название: " << AddedStation.StationName << "\nКоличесвто цехов: " << AddedStation.ShopNum << "\nКоличество рабочих цехов: " << AddedStation.WorkShopNum << "\nЭффективность:" << AddedStation.Efficiency << endl;
    }
}

void RedactTube(Tube& MainTube)
{
    if (TubeExistence)
    {
        cout << "Выберите признак трубы:\n 0. В ремонте\n 1. Починена" << endl;
        Validation(MainTube.TubeSign);
        cout << "Данные о трубе изменены" << endl;
    }
    else
    {
        cout << "Действие невозможно. Труба не задана" << endl;
    }
}

void RedactStation(Station& AddedStation)
{
    if (StationExistence)
    {
        cout << "Введите количство рабочих цехов. От 0 до "<< AddedStation.ShopNum << endl;
        Validation(AddedStation.WorkShopNum);
        while (AddedStation.WorkShopNum > AddedStation.ShopNum)
        {
            cout << "Количетсво рабочих цехов не может превышать общее количество цехов" << endl;
            Validation(AddedStation.WorkShopNum);
        }
        cout << "Данные о станции изменены" << endl;
    }

    else
    {
        cout << "Действие невозможно. Станция не задана" << endl;
    }
}

void FileSave(Tube MainTube, Station AddedStation)
{
    ofstream OutData;
    OutData.open("source.txt");
    if (! OutData.is_open())
    {
        cout << "Не удалось открыть файл" << endl;
    }
    else
    {
        if (TubeExistence)
        { 
            /*OutData << "Параметры трубы\nДлина трубы: " << MainTube.TubeLength << " м\nДиаметр трубы: " << MainTube.TubeDiametre << " мм\nСостояние трубы:";
            if (MainTube.TubeSign)
            {
                OutData << "Починена\n";
            }
            else
            {
                OutData << "В ремонте\n\n";
            }*/
            OutData << MainTube.TubeLength << "\n" << MainTube.TubeDiametre << "\n" << MainTube.TubeSign << endl;
        }

        if (StationExistence)
        {
           // OutData << "Параметры станции\nНазвание станции: " << AddedStation.StationName << "\nКоличество цехов: " << AddedStation.ShopNum<< "\nКоличество рабочих цехов:" << AddedStation.WorkShopNum << "\nЭффективность:" << AddedStation.Efficiency << endl;
            OutData << AddedStation.StationName << "\n" << AddedStation.ShopNum << "\n" << AddedStation.WorkShopNum << "\n" << AddedStation.Efficiency << endl;
        }

        OutData.close();
        cout << "Данные сохранены!" << endl;
    }
}

void FileRead(Tube& MainTube, Station& AddedStation)
{
    ifstream InData;
    InData.open("source.txt");
    if (!InData.is_open())
    {
        cout << "Не удалось открыть файл" << endl;
    }
    else
    {
        //cout << "Файл успешно открыт" << endl;
        /*InData >> MainTube.TubeLength >> MainTube.TubeDiametre >> MainTube.TubeSign;
        getline(InData, AddedStation.StationName);
        InData >> AddedStation.ShopNum >> AddedStation.WorkShopNum >> AddedStation.Efficiency;*/
        string Data[7] = {};
        for (int i = 0; i < 7; i++)
        {
            getline(InData, Data[i]);
        }
        MainTube.TubeLength = stoi(Data[0]);
        MainTube.TubeDiametre = stoi(Data[1]);
        MainTube.TubeSign = stoi(Data[2]);
        AddedStation.StationName = Data[3];
        AddedStation.ShopNum = stoi(Data[4]);
        AddedStation.WorkShopNum = stoi(Data[5]);
        AddedStation.Efficiency = stoi(Data[6]);
        cout << "Данные прочитаны!" << endl;
        TubeExistence = true;
        StationExistence = true;
    }
    InData.close();
}

int main()
{
    setlocale(LC_ALL, "rus");
    
    
    Station AddedStation;
    Tube MainTube;
    int Option;

    do
    {
        ShowMenu();
        Validation(Option);
        switch (Option)
        {
        case 1:
            AddTube(MainTube);
            break;
        case 2:
            AddStation(AddedStation);
            break;
        case 3:
            ObjReview(MainTube, AddedStation);
            break;
        case 4:
            RedactTube(MainTube);
            break;
        case 5:
            RedactStation(AddedStation);
            break;
        case 6:
            FileSave(MainTube, AddedStation);
            break;
        case 7:
            FileRead(MainTube, AddedStation);
            break;
        case 0:
            cout << "До свидания!" << endl;
            break;
            //exit(0);
        /*case 0:
            exit(0);*/
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
