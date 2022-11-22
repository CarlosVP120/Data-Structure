#include <iostream>
#include <list>
#include <math.h>
#include <vector>

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
    int test1[]  = {76, 85, 92, 50, 700, 73, 101};
    int test2[]  = {231, 321, 212, 321, 433, 262, 210};
    int test3[]  = {77, 94, 89, 17, 45, 35, 76};
    int test4[]  = {91,22,93,40,47,76,10};

    int *tests[] = {test1, test2, test3, test4};
    int sizes[]  = {sizeof(test1)/sizeof(test1[0]), sizeof(test2)/sizeof(test2[0]), sizeof(test3)/sizeof(test3[0]), sizeof(test4)/sizeof(test4[0])};

    for (int i = 0; i < 4; i++)
    {
        cout << "\nTEST CASE " << i + 1 <<": " << endl;
        int n = sizes[i];
        cout << "n = " << n << endl;
        HashTable h(n);

        for (int j = 0; j < n; j++)
            h.quadratic(tests[i][j]);

        cout << "\nQuadratic Probing: " << endl;
        h.displayHash();

        h.clearHash();

        for (int j = 0; j < n; j++)
            h.chain(tests[i][j]);

        cout << "\nChain Probing: " << endl;
        h.displayHash();

        h.clearHash();
    }
    return 0;
}