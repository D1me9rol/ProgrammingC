#include "Graph.h"
#include "Functions.h"

using namespace std;





void Graph::FillAdj(std::map<int, Station> MapOfStations)
{

    for (int i = Adj.size(); i < MapOfStations.size(); i++)
        Adj.push_back(vector<bool>(MapOfStations.size()-1));
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
            cout << "Станции уже соединены"<< endl;
            return;
        }
        else
        {
            cout << "Введите диаметр трубы для соединения станций: ";
            Validation(PipeDiametre);

            bool Connected = 0;
            bool Unused = 1;
            int PipeID;
            for (const auto& p : MapOfPipes)
            {
                if (p.second.PipeDiametre == PipeDiametre)
                {
                    PipeID= p.first;
                    for (int i = 0; i < MapOfStations.size(); i++)
                        if (Incidence[p.first][i] > 0)
                        {
                            Unused = 0;
                            PipeID= -1;
                            break;
                        }
                
                    if (PipeID > -1)
                    {
                        Adj[FirstStationID][SecondStationID] = 1;
                        Incidence[p.first][FirstStationID] = 1;
                        Incidence[p.first][SecondStationID] = 2;
                        Connected = true;
                        edge.FirstStation = FirstStationID;
                        edge.SecondStation = SecondStationID;
                        edge.Pipeline = p.first;
                        StationsPair.emplace(StationsPair.size(), edge);
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
                    AddPipe(MapOfPipes);
                    Adj[FirstStationID][SecondStationID] = 1;
                    Incidence[MapOfPipes.size() - 1][FirstStationID] = 1;
                    Incidence[MapOfPipes.size() - 1][SecondStationID] = 2;
                    edge.FirstStation = FirstStationID;
                    edge.SecondStation = SecondStationID;
                    edge.Pipeline = MapOfPipes.size() - 1;
                    StationsPair.emplace(StationsPair.size(), edge);
                }
                else
                    return;

            }
        }
    
}

void Graph::TopologicalSortUtil(int v, std::vector<int>& Vertexes, vector <bool>& visited)
{
    bool used = 0;
    
    if (!visited[v])
    {
        for (int i = 0; i < Adj.size(); i++)
        {
            if (!visited[i] && Adj[v][i] == 1)
            {
                TopologicalSortUtil(i, Vertexes, visited);
            }
        }

        visited[v] = 1;

        for (int p : Vertexes)
            if (p == v)
                used = 1;
        if (!used)
            Vertexes.push_back(v);
    }
}



void Graph::TopologicalSort(std::map<int, Station> MapOfStations)
{
    vector<int> Vertexes;
    vector<bool>visited;
    int v = MapOfStations.size();
    
        for (const auto& p : MapOfStations)
            visited.push_back(false);

        for (const auto& p : MapOfStations)
        {
            if (!visited[p.first])
                TopologicalSortUtil(p.first, Vertexes, visited);
        }

        reverse(Vertexes.begin(), Vertexes.end());
        for (int p : Vertexes)
            cout << p + 1 << " ";
        cout << "\n";
    
    
}

