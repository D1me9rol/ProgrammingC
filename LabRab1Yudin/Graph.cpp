#include "Graph.h"
#include "Functions.h"

using namespace std;


//std::ostream& operator<< (std::ostream& out, const Graph& ConnectedStations)
//{
//    for (int i = 0; i < ConnectedStations.Adj.size(); i++)
//    {
//        for (int j = 0; j < ConnectedStations.Adj[i].size(); j++)
//            cout << ConnectedStations.Adj[i][j] << " ";
//        cout << "\n";
//    }
//    return out;
//}

void Graph::FillAdj(std::map<int, Station> MapOfStations)
{

    for (int i = Adj.size(); i < MapOfStations.size(); i++)
        Adj.push_back(vector<int>(MapOfStations.size()-1));
    if (MapOfStations.size()>Adj[0].size())
    {
        for (int i = 0; i < MapOfStations.size(); i++)
            Adj[i].push_back(0);
    }
		
}

void Graph::FillIncidence(std::map<int, Pipe> MapOfPipes, std::map<int, Station> MapOfStations)
{
	for (int i = Incidence.size(); i < MapOfPipes.size(); i++)
		Incidence.push_back(vector<int>(MapOfStations.size()-1));
    if(MapOfStations.size()>Incidence[0].size())
    {
        for (int i = 0; i < MapOfPipes.size(); i++)
            Incidence[i].push_back(0);
    }
}


int GetID(set<int> keys)
{
    int key = -1;
    cout << "Введите ID объекта, имеющийся в списке" << endl;
    while (true)
    {
        Validation(key);
        if (keys.find(key - 1) == keys.end())
            cout << "Введите существующий id" << endl;
        else
            break;
    }
    return key - 1;
}

void Graph::AddArc(std::map<int, Pipe>& MapOfPipes, std::map<int, Station> MapOfStations)
{
    int FirstStationID;
    int SecondStationID;
    set<int>Stations;
    set<int>Pipelines;
    int PipeDiametre;

    

    if (!MapOfStations.empty())
    {
        FillAdj(MapOfStations);
        FillIncidence(MapOfPipes, MapOfStations);

        cout << "Список станций" << endl;

        for (const auto& p : MapOfStations)
        {
            Stations.insert(p.first);
            cout << "ID станции: " << p.first + 1 << endl;
            cout << p.second;
        }
        cout << "Выберите начальную станцию: ";
        FirstStationID = GetID(Stations);
        cout << "Выберите конечную станцию: ";
        SecondStationID = GetID(Stations);
        if (FirstStationID == SecondStationID || Adj[FirstStationID][SecondStationID] == 1)
        {
            cout << "Станции уже соединены" << endl;
            return;
        }
        else
        {
            cout << "Введите диаметр трубы для соединения станций: ";
            Validation(PipeDiametre);

            bool Connected = 0;
            bool Unused = 1;
            int Line;
            for (const auto& p : MapOfPipes)
            {
                if (p.second.PipeDiametre == PipeDiametre)
                {
                    Line = p.first;
                    for (int i = 0; i < MapOfStations.size(); i++)
                        if (Incidence[p.first][i] > 0)
                        {
                            Unused = 0;
                            Line = -1;
                            break;
                        }
                
                    if (Line > -1)
                    {
                        Adj[FirstStationID][SecondStationID] = 1;
                        Incidence[p.first][FirstStationID] = 1;
                        Incidence[p.first][SecondStationID] = 2;
                        Connected = true;
                        break;

                    }
                }
                    
            }
                   
            if (!Connected)
            {
                bool Choise;
                cout << "Труба не найдена! Хотите создать новую трубу?\n0.НЕТ 1.ДА" << endl;
                Validation(Choise);
                if (Choise)
                {
                    Incidence.push_back(vector<int>(MapOfStations.size()));
                    /*for (int i = 0; i < MapOfPipes.size(); i++)
                        Incidence[i].push_back(0);*/
                    AddPipe(MapOfPipes);
                    Adj[FirstStationID][SecondStationID] = 1;
                    Incidence[MapOfPipes.size() - 1][FirstStationID] = 1;
                    Incidence[MapOfPipes.size() - 1][SecondStationID] = 2;
                }
                else
                    return;
                    //Incidence[MapOfPipes.size()-1].push_back(0);

            }
        }
    }
    else
        cout << "Станции не заданы" << endl;
}

