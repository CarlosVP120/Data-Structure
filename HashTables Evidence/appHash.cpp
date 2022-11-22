#include <iostream>
#include <list>
#include <math.h>
#include <vector>
#include <fstream>

// Carlos Alberto Veryan Peña A01641147

using namespace std;

// Hash Table of strings
class HashTable
{
private:
    // Hash table
    list<string> *table;
    // Number of buckets
    int buckets;

public:
    // Constructor
    HashTable(int b)
    {
        buckets = b;
        table = new list<string>[buckets];
    }

    // Hash function
    int hashFunction(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
        {
            sum += key[i];
        }
        return sum % buckets;
    }

    // Insert key into hash table
    void insertItem(string key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Search
    bool searchItem(string key)
    {
        int index = hashFunction(key);
        for (auto x : table[index])
        {
            if (x == key)
            {
                return true;
            }
        }
        return false;
    }

    // Delete
    void deleteItem(string key)
    {
        int index = hashFunction(key);
        list<string>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++)
        {
            if (*i == key)
            {
                break;
            }
        }
        if (i != table[index].end())
        {
            table[index].erase(i);
        }
    }

    // Print
    void printTable()
    {
        for (int i = 0; i < buckets; i++)
        {
            cout << i;
            for (auto x : table[i])
            {
                cout << " --> " << x;
            }
            cout << endl;
        }
    }

    // Getters
    int getBuckets()
    {
        return buckets;
    }

    list<string> *getTable()
    {
        return table;
    }
};

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

string intToIP(long long ip)
{ // O(n)
    string iPstr = to_string(ip);
    string finalIP = "";
    int count = 0;
    for (int i = 0; i < iPstr.length()+1; i++)
    { // O(n)
        if (count == 1 || count == 3 || count == 6)
        {
            finalIP += iPstr[i];
            finalIP += ".";
            count ++;
        } 
        else
        {
            finalIP += iPstr[i];
            count++;
        }
    }
    finalIP.pop_back();
    return finalIP;
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

    HashTable table(1000000);
    for (int i = 0; i < lines.size(); i++)
    {
        table.insertItem(getIP(lines[i]));
    }
    // print the hash table in a new file
    ofstream newFile("bitacoraHash.txt");
    for (int i = 0; i < table.getBuckets(); i++)
    {
        newFile << i;
        for (auto x : table.getTable()[i])
        {
            newFile << " --> " << x;
        }
        newFile << endl;
    }
    newFile.close();





    return 0;
}