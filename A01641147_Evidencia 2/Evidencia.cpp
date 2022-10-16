#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;

// Carlos Alberto Veryan Peña
// Diego Partida Romero 

int monthToInt(string month) { //O(n)
    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    for (int i = 0; i < months.size(); i++) { 
        if (month == months[i]) {
            return i + 1;
        }
    }
    return 0;

}

long ipToInt(string ip) { //O(n)
    string iPstr = "";
    for (int i = 0; i < ip.length(); i++) {
        if (ip[i] == '.') {
            // Do nothing
        } else {
            iPstr += ip[i];
        }
    }
    return stol(iPstr);
}

string getIP(string line) { //O(n)
    string ip = "";
    string finalIP = "";
    for (int i = 16; i < line.length(); i++) { //O(n)
        if (line[i] == ':') {
            break;
        }
        ip += line[i];
    }

    //Divide the IP in 4 strings
    string ip1 = "";
    string ip2 = "";
    string ip3 = "";
    string ip4 = "";
    int count = 0;
    for (int i = 0; i < ip.length(); i++) { //O(n)
        if (ip[i] == '.') {
            count++;
        } else {
            if (count == 0) {
                ip1 += ip[i];
            } else if (count == 1) {
                ip2 += ip[i];
            } else if (count == 2) {
                ip3 += ip[i];
            } else if (count == 3) {
                ip4 += ip[i];
            }
        }
    }

    vector<string> iPs = {ip1, ip2, ip3, ip4};
    //add zeros so that each part has 3 values
    for (int i = 0; i < iPs.size(); i++) { 
        while (iPs[i].length() < 3) {
            iPs[i] = "0" + iPs[i];
        }
    }

    return iPs[0] + "." + iPs[1] + "." + iPs[2] + "." + iPs[3];
}

string normalizeIP(string ip_toNormalize) { //O(n)
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
    // add zeros so that each part has 3 values
    for (int i = 0; i < ip_toNormalizes.size(); i++)
    {
        while (ip_toNormalizes[i].length() < 3)
        {
            ip_toNormalizes[i] = "0" + ip_toNormalizes[i];
        }
    }

    return ip_toNormalizes[0] + "." + ip_toNormalizes[1] + "." + ip_toNormalizes[2] + "." + ip_toNormalizes[3];
}

vector<string> merge(vector<string> left, vector<string> right) { //O(n)
    vector<string> result;
    while (left.size() > 0 || right.size() > 0) {
        if (left.size() > 0 && right.size() > 0) {
            if (ipToInt(getIP(left.front())) <= ipToInt(getIP(right.front()))) {
                result.push_back(left.front());
                left.erase(left.begin());
            } else {
                result.push_back(right.front());
                right.erase(right.begin());
            }
        } else if (left.size() > 0) {
            for (int i = 0; i < left.size(); i++) {
                result.push_back(left[i]);
            }
            break;
        } else if (right.size() > 0) {
            for (int i = 0; i < right.size(); i++) {
                result.push_back(right[i]);
            }
            break;
        }
    }
    return result;
}

vector<string> mergeSort(vector<string> array) { //O(n)
    if (array.size() == 1) {
        return array;
    }
    vector<string> left;
    vector<string> right;
    for (int i = 0; i < array.size() / 2; i++) {
        left.push_back(array[i]);
    }
    for (int i = array.size() / 2; i < array.size(); i++) {
        right.push_back(array[i]);
    }
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

int main() {
    
    // Save all the lines in a vector
    ifstream file("Bitacora.txt");
    string line;
    vector<string> lines;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    // Add a zero if the day is only one digit
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i][4] >= '0' && lines[i][4] <= '9' && lines[i][5] == ' ') {
            lines[i].insert(4, "0");
        }

    }

    vector<string> sortedLines;

    // Sort the lines with merge sort
    sortedLines = mergeSort(lines);
    
    // Save the sorted lines in a new file
    ofstream newFile1("Sorted.txt");
    for (int i = 0; i < sortedLines.size(); i++)
    {
        newFile1 << sortedLines[i] << endl;
    }
    newFile1.close();

    // Ask the user for the IP to normalize
    string startIP, endIP;
    cout << "Enter the start IP: ";
    cin >> startIP;
    startIP = normalizeIP(startIP);

    cout << "Enter the end IP: ";
    cin >> endIP;
    endIP = normalizeIP(endIP);
    
    cout << endl;

    // Save the lines that are between the start and end IP in a new file
    int startIndex = 0;
    for (int i = 0; i < sortedLines.size(); i++)
    {
        if (getIP(sortedLines[i]) == startIP)
        {
            startIndex = i;
            break;
        }
    }

    int endIndex = 0;
    for (int i = 0; i < sortedLines.size(); i++)
    {
        if (getIP(sortedLines[i]) == endIP)
        {
            endIndex = i;
            break;
        }
    }

    ofstream newFile("SearchResults.txt");
    for (int i = startIndex; i < endIndex; i++)
    {
        newFile << sortedLines[i] << endl;
    }
    newFile.close();

    for (int i = startIndex; i <= endIndex; i++)
    {
        cout << sortedLines[i] << endl;
    }

    return 0;
}