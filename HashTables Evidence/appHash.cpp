#include <iostream>
#include <list>
#include <math.h>
#include <vector>
#include <fstream>

// Carlos Alberto Veryan Peña A01641147
// Diego Partida Romero A01641113 

using namespace std;

struct node {
    string ip;
    int numAccesses;
    list <string> dateTime;
    list <string> puertos;
};

class HashTable {
    private:
        vector <node> table;
        int size;
        int numElements;
        int hash(string ip); // O(1 + alpha)
        void rehash(); // O(n)
    public:
        HashTable(int size); // O(1)
        void insertQProbe(string ip, string dateTime, string puerto); // O(1 + alpha)
        void print(); // O(n)
        void printToFile(); // O(n)
        void search(string ip); // O(1 + alpha)
};

HashTable::HashTable(int size) {
    this->size = size;
    this->numElements = 0;
    table.resize(size);
} // O(1)

int HashTable::hash(string ip) {
    int hash = 0;
    for (int i = 0; i < ip.length(); i++) {
        hash += (int)ip[i];
    }
    return hash % size;
} // O(1 + alpha)

void HashTable::rehash() {
    vector <node> oldTable = table;
    table.clear();
    size = size * 2;
    table.resize(size);
    numElements = 0;
    for (int i = 0; i < oldTable.size(); i++) {
        if (oldTable[i].ip != "") {
            insertQProbe(oldTable[i].ip, oldTable[i].dateTime.front(), oldTable[i].puertos.front());
        }
    }
} // O(n)

void HashTable::insertQProbe(string ip, string dateTime, string puerto) {
    int index = hash(ip);
    int i = 1;

    // If the table at the calculated index is not empty, we use the quadratic probing method to find a new index for the IP address.
    while (table[index].ip != "" && table[index].ip != ip) {
        index = (index + i * i) % size;
        i++;
    }
    if (table[index].ip == "") {
        table[index].ip = ip;
        table[index].numAccesses = 1;
        table[index].dateTime.push_back(dateTime);
        table[index].puertos.push_back(puerto);
        numElements++;
    } else {
        table[index].numAccesses++;
        table[index].dateTime.push_back(dateTime);
        table[index].puertos.push_back(puerto);
    }
} // O(1 + alpha)

void HashTable::print() {
    for (int i = 0; i < table.size(); i++) {
        if (table[i].ip != "") {
            cout << "IP: " << table[i].ip << endl;
            cout << "Numero de accesos: " << table[i].numAccesses << endl;
            cout << "Fecha y hora de los accesos: " << endl;
            for (auto it = table[i].dateTime.begin(); it != table[i].dateTime.end(); it++) {
                cout << *it << endl;
            }
            cout << "Puertos de los accesos: " << endl;
            for (auto it = table[i].puertos.begin(); it != table[i].puertos.end(); it++) {
                cout << *it << endl;
            }
            cout << endl;
        }
    }
} // O(n)

void HashTable::printToFile() {
    ofstream file;
    file.open("evidence.txt");
    for (int i = 0; i < table.size(); i++) {
        if (table[i].ip != "") {
            file << "IP: " << table[i].ip << endl;
            file << "Numero de accesos: " << table[i].numAccesses << endl;
            file << "Fecha y hora de los accesos: " << endl;
            for (auto it = table[i].dateTime.begin(); it != table[i].dateTime.end(); it++) {
                file << *it << endl;
            }
            file << "Puertos de los accesos: " << endl;
            for (auto it = table[i].puertos.begin(); it != table[i].puertos.end(); it++) {
                file << *it << endl;
            }
            file << endl;
        }
    }
    file.close();
} // O(n)

void HashTable::search(string ip) {
    int index = hash(ip);
    int i = 1;

    // If the ip address is not there, then we will search for the next index using quadratic probing.
    while (table[index].ip != "" && table[index].ip != ip) {
        index = (index + i * i) % size;
        i++;
    }

    if (table[index].ip == "") {
        cout << "IP no encontrada" << endl;
    } else {
        cout << "IP: " << table[index].ip << endl;
        cout << "Numero de accesos: " << table[index].numAccesses << endl;
        cout << "Fecha y hora de los accesos: " << endl;
        for (auto it = table[index].dateTime.begin(); it != table[index].dateTime.end(); it++) {
            cout << *it << endl;
        }
        cout << "Puertos de los accesos: " << endl;
        for (auto it = table[index].puertos.begin(); it != table[index].puertos.end(); it++) {
            cout << *it << endl;
        }
        cout << endl;
    }

    // print the result in a new file
    ofstream file;
    file.open("SearchResult.txt");
    if (table[index].ip == "") {
        file << "IP no encontrada" << endl;
    } else {
        file << "IP: " << table[index].ip << endl;
        file << "Numero de accesos: " << table[index].numAccesses << endl;
        file << "Fecha y hora de los accesos: " << endl;
        for (auto it = table[index].dateTime.begin(); it != table[index].dateTime.end(); it++) {
            file << *it << endl;
        }
        file << "Puertos de los accesos: " << endl;
        for (auto it = table[index].puertos.begin(); it != table[index].puertos.end(); it++) {
            file << *it << endl;
        }
        file << endl;
    }

} // O(1 + alpha)

string getIP(string line, bool normalize)
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

    if (normalize) {
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

    return ip;
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

    // Why if i have 16807 it works, but if i have 16808 i get segmantation fault?
    HashTable hashTable(lines.size()+1);
    for (int i = 0; i < lines.size(); i++) {
        string ip = getIP(lines[i], false);
        string dateTime = lines[i].substr(0, 15);
        string puerto = "";

        if (ip.length() == 10) {
            puerto = lines[i].substr(27, 5);
        } else if (ip.length() == 11) {
            puerto = lines[i].substr(28, 5);
        } else if (ip.length() == 12) {
            puerto = lines[i].substr(29, 5);
        } else if (ip.length() == 13) {
            puerto = lines[i].substr(30, 5);
        } else {
            // Do nothing
        }
        hashTable.insertQProbe(ip, dateTime, puerto);
    }
    hashTable.printToFile();

    // search for an IP
    string ip;
    cout << "\nIngrese la IP que desea buscar: ";
    cin >> ip;
    cout << endl;
    hashTable.search(ip);
}