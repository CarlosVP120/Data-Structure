#include <iostream>
#include <list>

using namespace std;


class Graph
{
private:
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int V)
    {
        numVertices = V;
        adjLists = new list<int>[V];
        visited = new bool[V];
    }

    ~Graph()
    {
        delete[] adjLists;
    }

    void addEdge(int, int);
    void printGraph();
    void ResetVisited();

    void DFS(int);
    void BFS(int);
};

void Graph::addEdge(int s, int d)
{
    this->adjLists[s].push_back(d);
    this->adjLists[d].push_back(s);
}

void Graph::printGraph()
{
    for (int i = 0; i < this->numVertices; i++) 
    {
        cout << "\nVertex " << i << ":";
        for (auto x : this->adjLists[i])
            cout << " -> " << x;
        cout << endl;
    }
}

void Graph::ResetVisited()
{
    for (int i = 0; i < this->numVertices; i++)
        this->visited[i] = false;
}

void Graph::DFS(int vertex)
{
    this->visited[vertex] = true;
    cout << vertex << " ";

    for (auto x : this->adjLists[vertex])
        if (!this->visited[x])
            DFS(x);
}

void Graph::BFS(int vertex)
{
    list<int> queue;
    this->visited[vertex] = true;
    queue.push_back(vertex);

    while (!queue.empty())
    {
        vertex = queue.front();
        cout << vertex << " ";
        queue.pop_front();

        for (auto x : this->adjLists[vertex])
            if (!this->visited[x])
            {
                this->visited[x] = true;
                queue.push_back(x);
            }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);

    g.printGraph();

    cout << "\nDFS: ";
    g.DFS(0);

    return 0;
}