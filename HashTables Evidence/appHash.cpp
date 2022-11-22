#include <iostream>
#include <list>
#include <math.h>
#include <vector>
#include <fstream>

// Carlos Alberto Veryan Peña A01641147

using namespace std;

class HashTable
{
private:
    // hash table of long long values
    long long *table;
    // capacity of the hash table
    int capacity;
    // number of elements in the hash table
    int size;

public:
    HashTable(int V)
    {
        int size = getPrime(V);
        this->capacity = size;
        table = new long long[capacity];
        this->size = 0;
    }

    ~HashTable()
    {
        delete[] table;
        cout << "\nDestructor: HashTable deleted. " << endl;
    }

    bool checkPrime(int); // O(sqrt(n))
    int getPrime(int);   // O(sqrt(n))
    void deleteItem(int); // O(1 + alpha)
    int hashFunction(int); // O(1 + alpha)
    void displayHash(); // O(n)
    void clearHash(); // O(n)

    void quadratic(int); // O(1 + alpha)
    void chain(int); // O(1 + alpha)

    long long *getTable() { 
        return table; 
    }

    int getCapacity() { 
        return capacity; 
    }

};

bool HashTable::checkPrime(int n) 
{
    if (n == 1 || n == 0)
        return false;

    int sqr_root = sqrt(n);
    for (int i = 2; i <= sqr_root; i++)
        if (n % i == 0)
            return false;
    return true;
} // O(sqrt(n))

int HashTable::getPrime(int n)
{
    if (n % 2 == 0)
        n++;
    while (!checkPrime(n))
        n += 2;
    return n;
} // O(sqrt(n))

void HashTable::deleteItem(int key)
{
    int index = hashFunction(key);
    table[index] = 0;
    size--;
} // O(1 + alpha)

int HashTable::hashFunction(int key)
{
    int index = key % capacity;
    return index;
} // O(1 + alpha)

void HashTable::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        if (table[i] != 0)
            cout << i << " --> " << table[i] << endl;
        else
            cout << i << endl;
    }
} // O(n)

void HashTable::clearHash()
{
    for (int i = 0; i < capacity; i++)
        table[i] = 0;
} // O(n)

void HashTable::quadratic(int key)
{
    int index = hashFunction(key);
    int i = 1;
    while (table[index] != 0)
    {
        index = (index + i * i) % capacity;
        i++;
    }
    table[index] = key;
    size++;
} // O(1 + alpha)

void HashTable::chain(int key)
{
    int index = hashFunction(key);
    table[index] = key;
    size++;
} // O(1 + alpha)

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

    // normalize the iPs[0] to 3 digits
    if (iPs[0].length() == 1)
    {
        iPs[0] = "00" + iPs[0];
    }
    else if (iPs[0].length() == 2)
    {
        iPs[0] = "0" + iPs[0];
    }

    if (iPs[1].length() == 1)
    {
        iPs[1] = "0" + iPs[1];
    }

    if (iPs[2].length() == 1)
    {
        iPs[2] = "00" + iPs[2];
    }
    else if (iPs[2].length() == 2)
    {
        iPs[2] = "0" + iPs[2];
    }

    if (iPs[3].length() == 1)
    {
        iPs[3] = "0" + iPs[3];
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
        if (count == 2 || count == 4 || count == 7)
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
    // cout << stoll(iPstr) << endl;
    return stoll(iPstr);
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

    // add the IP of each line to the hash table
    HashTable hashTable(lines.size());
    for (int i = 0; i < lines.size(); i++)
    {
        string ip = getIP(lines[15]);
        long long ipInt = ipToInt(ip);
        hashTable.quadratic(ipInt);
        cout << ip << endl;
        cout << ipInt << endl;
        cout << intToIP(ipInt) << endl;
    }

    // // print the hash table in a new file
    // ofstream newFile("bitacora2.txt");
    // for (int i = 0; i < lines.size(); i++)
    // {
    //     string ip = getIP(lines[i]);
    //     long long ipInt = ipToInt(ip);
    //     newFile << intToIP(ipInt) << endl;
    // }
    // newFile.close();
}



