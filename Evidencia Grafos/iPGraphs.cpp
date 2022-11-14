#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

// Carlos Alberto Veryan Peña A01641147
// Deigo Partida Romero A01641113

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
    void printAdjListInFile(); // function to print the graph O(V^2)
    void ResetVisited(); // function to reset the visited array O(V)

    void DFS(int); // function to perform DFS O(V+E)
    void BFS(int); // function to perform BFS O(V+E)

    vector<vector<int>> getAdjLists(); // function to get the adjLists O(1)
    // void findInOutDegree(); // function to find the in and out degree of a vertex O(V)
};

ofstream newFile1("Vectors.txt");
ofstream newFile2("INsOUTs.txt");

void Graph::loadGraph(int s, int d)
{
    for (auto i = adjLists[s].begin(); i != adjLists[s].end(); i++)
    {
        if (*i == d)
        {
            return;
        }
    } 
    adjLists[s].push_back(d);
}

void Graph::printAdjListInFile()
{   
    for (int i = 0; i < this->numVertices; i++) 
    {
        if (adjLists[i].size() != 0) {
            newFile1 << "Vertex " << i << ":";
            list<int>::iterator j;
            for (j = adjLists[i].begin(); j != adjLists[i].end(); j++)
            {
                newFile1 << " -> " << *j;
            }
            newFile1 << endl;
        }

        // // cout << "\nVertex " << i << ":";
        // newFile1 << "\nVertex " << i << ":";
        // for (auto x : this->adjLists[i])
        // newFile1 << " -> " << x;
        // // cout << " -> " << x;
        // cout << endl;
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

vector<vector<int>> Graph::getAdjLists()
{
    vector<vector<int>> adjListsVector;
    for (int i = 0; i < this->numVertices; i++)
    {
        vector<int> temp;
        temp.push_back(i);
        for (auto x : this->adjLists[i])
            temp.push_back(x);
        adjListsVector.push_back(temp);
    }
    return adjListsVector;
}

long long ipToInt(string ip)
{ // O(n)
    string iPstr = "";
    for (int i = 0; i < ip.length(); i++)
    {
        if (ip[i] == '.')
        {
            // Do nothing
        }
        else
        {
            iPstr += ip[i];
        }
    }
    return stoll(iPstr);
}

string getIP(string line)
{ // O(n)
    string ip = "";
    string finalIP = "";
    for (int i = 16; i < line.length(); i++)
    { // O(n)
        if (line[i] == ':')
        {
            break;
        }
        ip += line[i];
    }

    // Divide the IP in 4 strings
    string ip1 = "";
    string ip2 = "";
    string ip3 = "";
    string ip4 = "";
    int count = 0;
    for (int i = 0; i < ip.length(); i++)
    { // O(n)
        if (ip[i] == '.')
        {
            count++;
        }
        else
        {
            if (count == 0)
            {
                ip1 += ip[i];
            }
            else if (count == 1)
            {
                ip2 += ip[i];
            }
            else if (count == 2)
            {
                ip3 += ip[i];
            }
            else if (count == 3)
            {
                ip4 += ip[i];
            }
        }
    }

    vector<string> iPs = {ip1, ip2, ip3, ip4};

    for (int i = 0; i < iPs.size(); i++)
    {
        while (iPs[i].length() < 3)
        {
            iPs[i] = "0" + iPs[i];
        }
    }

    return iPs[0] + "." + iPs[1] + "." + iPs[2] + "." + iPs[3];
}

string* getIPArray(string line)
{ // O(n)
    string ip = "";
    string finalIP = "";
    for (int i = 16; i < line.length(); i++)
    { // O(n)
        if (line[i] == ':')
        {
            break;
        }
        ip += line[i];
    }

    // Divide the IP in 4 strings
    string ip1 = "";
    string ip2 = "";
    string ip3 = "";
    string ip4 = "";
    int count = 0;
    for (int i = 0; i < ip.length(); i++)
    { // O(n)
        if (ip[i] == '.')
        {
            count++;
        }
        else
        {
            if (count == 0)
            {
                ip1 += ip[i];
            }
            else if (count == 1)
            {
                ip2 += ip[i];
            }
            else if (count == 2)
            {
                ip3 += ip[i];
            }
            else if (count == 3)
            {
                ip4 += ip[i];
            }
        }
    }

    vector<string> iPs = {ip1, ip2, ip3, ip4};

    for (int i = 0; i < iPs.size(); i++)
    {
        while (iPs[i].length() < 3)
        {
            iPs[i] = "0" + iPs[i];
        }
    }

    string *iPArray = new string[4];
    iPArray[0] = iPs[0];
    iPArray[1] = iPs[1];
    iPArray[2] = iPs[2];
    iPArray[3] = iPs[3];
    return iPArray;
}

string normalizeIP(string ip_toNormalize)
{ // O(n)
    string ip_toNormalize1 = "";
    string ip_toNormalize2 = "";
    string ip_toNormalize3 = "";
    string ip_toNormalize4 = "";
    int count = 0;
    for (int i = 0; i < ip_toNormalize.length(); i++)
    {
        if (ip_toNormalize[i] == '.')
        {
            count++;
        }
        else
        {
            if (count == 0)
            {
                ip_toNormalize1 += ip_toNormalize[i];
            }
            else if (count == 1)
            {
                ip_toNormalize2 += ip_toNormalize[i];
            }
            else if (count == 2)
            {
                ip_toNormalize3 += ip_toNormalize[i];
            }
            else if (count == 3)
            {
                ip_toNormalize4 += ip_toNormalize[i];
            }
        }
    }

    vector<string> ip_toNormalizes = {ip_toNormalize1, ip_toNormalize2, ip_toNormalize3, ip_toNormalize4};

    for (int i = 0; i < ip_toNormalizes.size(); i++)
    {
        while (ip_toNormalizes[i].length() < 3)
        {
            ip_toNormalizes[i] = "0" + ip_toNormalizes[i];
        }
    }

    return ip_toNormalizes[0] + "." + ip_toNormalizes[1] + "." + ip_toNormalizes[2] + "." + ip_toNormalizes[3];
}

vector<string> merge(vector<string> left, vector<string> right)
{ // O(n)
    vector<string> result;
    while (left.size() > 0 || right.size() > 0)
    {
        if (left.size() > 0 && right.size() > 0)
        {
            if (ipToInt(getIP(left.front())) <= ipToInt(getIP(right.front())))
            {
                result.push_back(left.front());
                left.erase(left.begin());
            }
            else
            {
                result.push_back(right.front());
                right.erase(right.begin());
            }
        }
        else if (left.size() > 0)
        {
            for (int i = 0; i < left.size(); i++)
            {
                result.push_back(left[i]);
            }
            break;
        }
        else if (right.size() > 0)
        {
            for (int i = 0; i < right.size(); i++)
            {
                result.push_back(right[i]);
            }
            break;
        }
    }
    return result;
}

vector<string> mergeSort(vector<string> array)
{ // O(n)
    if (array.size() == 1)
    {
        return array;
    }
    vector<string> left;
    vector<string> right;
    for (int i = 0; i < array.size() / 2; i++)
    {
        left.push_back(array[i]);
    }
    for (int i = array.size() / 2; i < array.size(); i++)
    {
        right.push_back(array[i]);
    }
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

void findInOutDegree(vector<vector<int>> adjlist, int n)
{
    vector<int> iN(n);
    vector<int> ouT(n);
 
    for(int i=0;i<n;i++)
    {
        ouT[i] = adjlist[i].size();

        for(int j=0;j<adjlist[i].size();j++)
          iN[adjlist[i][j]]++;
    }

    int maxIn = 0;
    int maxOut = 0;
    vector<int> maxInVertexs;
    vector <int> maxOutVertexs;
    for(int i=0;i<n;i++)
    {
        if(iN[i] > maxIn)
        {
            maxIn = iN[i];
            maxInVertexs.clear();
            maxInVertexs.push_back(i);
        }
        else if(iN[i] == maxIn)
        {
            maxInVertexs.push_back(i);
        }

        if(ouT[i] > maxOut)
        {
            maxOut = ouT[i];
            maxOutVertexs.clear();
            maxOutVertexs.push_back(i);
        }
        else if(ouT[i] == maxOut)
        {
            maxOutVertexs.push_back(i);
        }
    }

    cout << "\nThe vertex with the maximum in-degree is: ";
    for(int i=0;i<maxInVertexs.size();i++)
    {
        cout << maxInVertexs[i] << ", ";
    }
    cout << "with a value of: " << maxIn - 1 << endl << endl;

    cout << "The vertex with the maximum out-degree is: ";
    for(int i=0;i<maxOutVertexs.size();i++)
    {
        cout << maxOutVertexs[i] << ", ";
    }
    cout << "with a value of: " << maxOut - 1 << endl << endl;

    newFile2 << "Vertex\t\tIn\t\tOut" << endl;
    for(int k = 0; k < n; k++)
    {
        if (iN[k] != 1 && ouT[k] != 1)
        {
            newFile2 << k << "\t\t"
             << iN[k] - 1 << "\t\t"
             << ouT[k] - 1 << endl;
        }
    }
}

int main()
{
    ifstream file("bitacora.txt");
    string line;
    vector<string> lines;
    while (getline(file, line))
    {
        lines.push_back(line);
    }
    file.close();

    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i][4] >= '0' && lines[i][4] <= '9' && lines[i][5] == ' ')
        {
            lines[i].insert(4, "0");
        }
    }

    vector<string> sortedLines;

    sortedLines = mergeSort(lines);
    
    Graph g(sortedLines.size());
    for (int i = 0; i < sortedLines.size(); i++)
    {
        string* ip = getIPArray(sortedLines[i]);
        g.loadGraph(stoi(ip[0]), stoi(ip[1]));
        g.loadGraph(stoi(ip[1]), stoi(ip[2]));
        g.loadGraph(stoi(ip[2]), stoi(ip[3]));
    }    

    g.printAdjListInFile();

    vector<vector<int>> adjlist = g.getAdjLists();
    
    findInOutDegree(g.getAdjLists(), g.getAdjLists().size());

    return 0;
}