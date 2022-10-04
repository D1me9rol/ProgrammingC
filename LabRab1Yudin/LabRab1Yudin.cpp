// LabRab1Yudin.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Pipe // Создание структуры Труба
{
    int PipeLength, PipeDiametre;
    bool PipeSign;
};

struct Station // Создание структуры Компрессорная станция
{
    string StationName;
    int ShopNum, WorkShopNum, Efficiency;
};

// Переменные существования трубы и станции
//bool Pipeline.PipeDiametre>0 && Pipeline.PipeLength>0 = false; 
//bool MainStation.StationName.empty() = false;

void ShowMenu() // Вывод меню
{
    cout << "Меню\n";
    cout << "1. Добавить трубу\n2. Добавить КС\n3. Просмотр всех объектов\n4. Редактировать трубу\n5. Редактировать КС\n6. Сохранить\n7. Загрузить\n0. Выход "<< endl;
    cout << "Выберите номер действия" << endl;
}

template <typename T> // Создание шаблона
void Validation(T& input) // Процедура проверки правильности ввода
{
    while ((cin >> input).fail() || input < 0)
    {
        cout << "Введите корректное значение"<< endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void AddPipe(Pipe& Pipeline) // Процедура добавления трубы
{
        cout << "Введите длину трубы" << endl;
        Validation(Pipeline.PipeLength);

        cout << "Введите диаметр трубы" << endl;
        Validation(Pipeline.PipeDiametre);

        cout << "Выберите признак трубы:\n0. В ремонте\n1. Починена" << endl;
        Validation(Pipeline.PipeSign);

       // Pipeline.PipeDiametre>0 && Pipeline.PipeLength>0 = true;

}

void AddStation(Station& MainStation) // Процедура добавления станции
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

        //MainStation.StationName.empty() = true;
}


void ObjReview(Pipe& Pipeline, Station& MainStation) // Процедура просмотра объектов
{
    if (Pipeline.PipeDiametre>0 && Pipeline.PipeLength>0)
    {
        cout << "Информация о трубе" << endl;
        cout << "Длина трубы: " << Pipeline.PipeLength << " м\nДиаметр: " << Pipeline.PipeDiametre << "мм\nСостояние:";
        if (Pipeline.PipeSign)
        {
            cout << "Починена" << endl;
        }
        else
            cout << "В ремонте" << endl;
    }

    if (!MainStation.StationName.empty())
    {
        cout << "Информация о компрессорной станции" << endl;
        cout << "Название: " << MainStation.StationName << "\nКоличесвто цехов: " << MainStation.ShopNum << "\nКоличество рабочих цехов: " << MainStation.WorkShopNum << "\nЭффективность:" << MainStation.Efficiency << endl;
    }

    if (Pipeline.PipeDiametre <= 0 && Pipeline.PipeLength <= 0 && MainStation.StationName.empty())
    {
        cout << "Данные не заданы!" << endl;
    }
}

void RedactPipe(Pipe& Pipeline) // Процедура редактирования трубы
{
    if (Pipeline.PipeDiametre>0 && Pipeline.PipeLength>0)
    {
        cout << "Выберите признак трубы:\n 0. В ремонте\n 1. Починена" << endl;
        Validation(Pipeline.PipeSign);
        cout << "Данные о трубе изменены" << endl;
    }
    else
    {
        cout << "Действие невозможно. Труба не задана" << endl;
    }
}

void RedactStation(Station& MainStation) // Процедура редактирования станции
{
    if (!MainStation.StationName.empty())
    {
        cout << "Введите количство рабочих цехов. От 0 до "<< MainStation.ShopNum << endl;
        Validation(MainStation.WorkShopNum);
        while (MainStation.WorkShopNum > MainStation.ShopNum)
        {
            cout << "Количетсво рабочих цехов не может превышать общее количество цехов" << endl;
            Validation(MainStation.WorkShopNum);
        }
        cout << "Данные о станции изменены" << endl;
    }

    else
    {
        cout << "Действие невозможно. Станция не задана" << endl;
    }
}

void FileSave(Pipe Pipeline, Station MainStation) // Процедура сохранения данных в файл
{
    ofstream OutData;
    OutData.open("source.txt");
    if (! OutData.is_open())
    {
        cout << "Не удалось открыть файл" << endl;
    }
    else
    {
        if (Pipeline.PipeDiametre>0 && Pipeline.PipeLength>0)
        { 
            OutData << Pipeline.PipeLength << "\n" << Pipeline.PipeDiametre << "\n" << Pipeline.PipeSign << endl;
        }

        if (!MainStation.StationName.empty())
        {
            OutData << MainStation.StationName << "\n" << MainStation.ShopNum << "\n" << MainStation.WorkShopNum << "\n" << MainStation.Efficiency << endl;
        }

        OutData.close();
        cout << "Данные сохранены!" << endl;
    }
}

void FileRead(Pipe& Pipeline, Station& MainStation) // Процедура загрузки данных из файла
{
    int FileLength = 0;
    string str;
    ifstream InData;
    InData.open("source.txt");
    if (!InData.is_open())
    {
        cout << "Не удалось открыть файл" << endl;
    }
    else
    {
        cout << "Файл успешно открыт" << endl;

        while (!InData.eof())
        {
            getline(InData, str);
            FileLength++;
        }
        InData.close();
        InData.open("source.txt");
        if (FileLength <4)
        {
            cout << "Файл не содержит данных" << endl;
        }
        else if (FileLength == 4)
        {
            InData >> Pipeline.PipeLength >> Pipeline.PipeDiametre >> Pipeline.PipeSign;
        }
        else if (FileLength == 5)
        {
            InData.ignore();
            getline(InData, MainStation.StationName);
            InData >> MainStation.ShopNum >> MainStation.WorkShopNum >> MainStation.Efficiency;
        }
        else
        {
            InData >> Pipeline.PipeLength >> Pipeline.PipeDiametre >> Pipeline.PipeSign;
            InData.ignore();
            getline(InData, MainStation.StationName);
            InData >> MainStation.ShopNum >> MainStation.WorkShopNum >> MainStation.Efficiency;
        }
    }
    InData.close();
}

int main()
{
    setlocale(LC_ALL, "rus");
    
    
    Station MainStation;
    Pipe Pipeline;
    int Option;

    do
    {
        ShowMenu();
        Validation(Option);
        switch (Option)
        {
        case 1:
            AddPipe(Pipeline);
            break;
        case 2:
            AddStation(MainStation);
            break;
        case 3:
            ObjReview(Pipeline, MainStation);
            break;
        case 4:
            RedactPipe(Pipeline);
            break;
        case 5:
            RedactStation(MainStation);
            break;
        case 6:
            FileSave(Pipeline, MainStation);
            break;
        case 7:
            FileRead(Pipeline, MainStation);
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
