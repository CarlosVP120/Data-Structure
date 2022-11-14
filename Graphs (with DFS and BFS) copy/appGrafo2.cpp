#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>

using namespace std;

// Carlos Alberto Veryan Peña A01641147

class Graph
{
private:
    int numVertices;
    list<int> *adjLists;
    bool *visited;
    int** matrix;

    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack); // DFS

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
    
    bool isTree();   // returns true if the graph is a tree O(V+E)
    void topologicalSort(); // function to perform topological sort O(V+E)
    bool isbipartiteGraph(); // function to check if the graph is bipartite O(V+E)
    
};

void Graph::topologicalSortUtil(int v, bool visited[],stack<int>& Stack)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adjLists[v].begin(); i != adjLists[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    Stack.push(v);
}
 
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    for (int i = 0; i < numVertices; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

bool Graph::isbipartiteGraph()
{
    int colorArr[numVertices];
    for (int i = 0; i < numVertices; ++i)
        colorArr[i] = -1;
 
    colorArr[0] = 1;
 
    queue <int> q;
    q.push(0);
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        if (adjLists[u].begin() != adjLists[u].end())
        {
            list<int>::iterator i;
            for (i = adjLists[u].begin(); i != adjLists[u].end(); ++i)
            {
                if (colorArr[*i] == -1)
                {
                    colorArr[*i] = 1 - colorArr[u];
                    q.push(*i);
                }
 
                else if (colorArr[*i] == colorArr[u])
                    return false;
            }
        }
    }
    return true;
}

void Graph::printGraph()
{
    cout << endl << "Adjacency List:" << endl;
    this->printAdjList();
    
    cout << endl << "Adjacency Matrix:" << endl << endl << "   ";

    for (int i = 0; i < this->numVertices; i++) 
    {
        cout << i << " ";
    }
    cout << endl << "  ---------------------" << endl;

    for (int i = 0; i < numVertices; i++)
    {
        cout << i << "|" << " ";
        for (int j = 0; j < numVertices; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}

void Graph::loadGraph(int s, int d)
{
    this->adjLists[s].push_back(d);

    matrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        matrix[i] = new int[numVertices];
    }

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < numVertices; i++)
    {
        for (list<int>::iterator it = adjLists[i].begin(); it != adjLists[i].end(); it++)
        {
            matrix[i][*it] = 1;
        }
    }
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
 
bool Graph::isTree()
{
    visited[0] = true;

    list<int> queue;
    queue.push_back(0);

    while (!queue.empty())
    {
        int currVertex = queue.front();

        queue.pop_front();

        for (auto i : adjLists[currVertex])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    
    Graph g(10);
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
    g.loadGraph(7, 2);
    g.loadGraph(7, 4);
    g.loadGraph(8, 5);
    g.loadGraph(8, 3);
    g.loadGraph(9, 6);
    g.loadGraph(9, 1);

    // Graph g(6);
    // g.loadGraph(5, 2);
    // g.loadGraph(5, 0);
    // g.loadGraph(4, 0);
    // g.loadGraph(4, 1);
    // g.loadGraph(2, 3);
    // g.loadGraph(3, 1);

    // Graph g(6);
    // g.loadGraph(0, 1);
    // g.loadGraph(0, 5);
    // g.loadGraph(1, 0);
    // g.loadGraph(1, 2);
    // g.loadGraph(2, 1);
    // g.loadGraph(2, 3);
    // g.loadGraph(3, 2);
    // g.loadGraph(3, 4);
    // g.loadGraph(4, 3);
    // g.loadGraph(4, 5);
    // g.loadGraph(5, 4);
    // g.loadGraph(5, 0);

    // Graph g(5);
    // g.loadGraph(1, 0);
    // g.loadGraph(0, 2);
    // g.loadGraph(0, 3);
    // g.loadGraph(3, 4);

    g.printGraph();

    cout <<  endl << "Topological Sort: ";
    g.topologicalSort();
    cout << endl << endl;

    g.isTree()? cout << "Graph is Tree\n": cout << "Graph is not Tree\n";
    cout << endl;
    g.isbipartiteGraph()? cout << "Graph is Bipartite\n": cout << "Graph is not Bipartite\n";
    cout << endl;

    return 0;
}