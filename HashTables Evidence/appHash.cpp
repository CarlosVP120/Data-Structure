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
    int capacity;
    list<int> *table;

public:
    HashTable(int V)
    {
        int size = getPrime(V);
        this->capacity = size;
        table = new list<int>[capacity];
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

int HashTable::hashFunction(int key)
{
    return key % this->capacity;
} // O(1 + alpha)

void HashTable::deleteItem(int key)
{
    int index = hashFunction(key);
    table[index].remove(key);
} // O(1 + alpha)

void HashTable::displayHash()
{
    for (int i = 0; i < this->capacity; i++)
    {
        cout << "table[" << i << "]";

        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
} // O(n)

void HashTable::quadratic(int key)
{
    int index = hashFunction(key);
    int i = 0;
    while (table[index].size() != 0)
    {
        index = (index + i * i) % this->capacity;
        i++;
    }
    table[index].push_back(key);
} // O(1 + alpha)

void HashTable::chain(int key)
{
    int index = hashFunction(key);
    int i = 0; 
    while (table[index].size() != 0)
    {
        index = (index + 1) % this->capacity;
        i++;
    }
    table[index].push_back(key);
} // O(1 + alpha)

void HashTable::clearHash()
{
    for (int i = 0; i < this->capacity; i++)
        table[i].clear();
} // O(n)

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

    // save the lines in a new file
    ofstream newFile("bitacora2.txt");
    for (int i = 0; i < lines.size(); i++)
    {
        newFile << lines[i] << endl;
    }

    // We are going to organize the IP addresses, using a hash function to assign them a space in the hash table that contains the information of that IP address, the information (in the form of a node) that must be stored in that space is: the value of the IP itself , the number of accesses, a list with dates and times together (an array of strings containing the data as "Oct 9 10:32:24"), and a list of the numbers of ports (the value after the ":" of the IP address) that appear with that IP address.
    


    return 0;
}