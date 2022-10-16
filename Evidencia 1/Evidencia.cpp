#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int monthToInt(string month) {
    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    for (int i = 0; i < months.size(); i++) {
        if (month == months[i]) {
            return i + 1;
        }
    }
    return 0;
}

vector<string> merge(vector<string> left, vector<string> right) {
    vector<string> result;
    while (left.size() > 0 || right.size() > 0) {
        if (left.size() > 0 && right.size() > 0) {
            if (monthToInt(left.front().substr(0, 3)) <= monthToInt(right.front().substr(0, 3))) {
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

vector<string> mergeSort(vector<string> array) {
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
    
    ifstream file("Bitacora.txt");
    string line;
    vector<string> lines;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    for (int i = 0; i < lines.size(); i++) {
        if (lines[i][4] >= '0' && lines[i][4] <= '9' && lines[i][5] == ' ') {
            lines[i].insert(4, "0");
        }
    }

    vector<string> sortedLines;

    sort(lines.begin() + 3, lines.end());

    sortedLines = mergeSort(lines);
    
    // ofstream newFile1("Sorted.txt");
    // for (int i = 0; i < sortedLines.size(); i++)
    // {
    //     newFile1 << sortedLines[i] << endl;
    // }
    // newFile1.close();

    string startMonth, startDay, endMonth, endDay;
    cout << "Enter the start date (mmm dd): ";
    cin >> startMonth >> startDay;
    cout << "Enter the end date (mmm dd): ";
    cin >> endMonth >> endDay;
    int endDayInt = stoi(endDay);
    endDayInt++;
    endDay = to_string(endDayInt);
    cout << endl;

    int startIndex = 0;
    for (int i = 0; i < sortedLines.size(); i++)
    {
        if (sortedLines[i].substr(0, 3) == startMonth && sortedLines[i].substr(4, 2) == startDay)
        {
            startIndex = i;
            break;
        }
    }

    int endIndex = 0;
    for (int i = 0; i < sortedLines.size(); i++)
    {
        if (sortedLines[i].substr(0, 3) == endMonth && sortedLines[i].substr(4, 2) == endDay)
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