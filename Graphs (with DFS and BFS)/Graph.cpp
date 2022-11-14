#include <iostream>
#include <list>

using namespace std;

// Carlos Alberto Veryan Peña A01641147

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
        delete[] visited;
    }

    void loadGraph(int, int); // function to load the graph O(V^2)
    void printAdjList(); // function to print the graph O(V^2)
    void ResetVisited(); // function to reset the visited array O(V)

    void DFS(int); // function to perform DFS O(V+E)
    void BFS(int); // function to perform BFS O(V+E)

    void printGraph(); // function to print the graph O(V^2)
};

void Graph::printGraph()
{
    cout << endl << "Adjacency List:" << endl;
    this->printAdjList();
        
}

void Graph::loadGraph(int s, int d)
{
    this->adjLists[s].push_back(d);
}

void Graph::printAdjList()
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
    Graph g(7);
    g.loadGraph(0, 1);
    g.loadGraph(0, 2);
    g.loadGraph(0, 3);
    g.loadGraph(1, 2);
    g.loadGraph(1, 5);
    g.loadGraph(2, 4);
    g.loadGraph(2, 3);
    g.loadGraph(3, 2);
    g.loadGraph(4, 1);
    g.loadGraph(4, 2);
    g.loadGraph(5, 3);
    g.loadGraph(5, 2);
    g.loadGraph(5, 4);
    g.loadGraph(6, 5);
    g.loadGraph(6, 3);
    g.loadGraph(6, 6);
    g.loadGraph(6, 1);

    g.printGraph();
    cout << endl;

    cout << "DFS: ";
    g.DFS(0);

    cout << endl << "BFS: ";
    g.ResetVisited();
    g.BFS(0);
    cout << endl;

    return 0;
}