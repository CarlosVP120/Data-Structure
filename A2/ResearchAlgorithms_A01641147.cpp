#include <iostream>
#include <vector>
#include <algorithm>    
#include <list>

using namespace std;

void print(vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        cout << input.at(i) << ' ';
    }
    cout << endl;
} 

// Sorting Functions

vector<int> exchangeOrder(vector<int> x) {

    // 1. The for loop is used to iterate through the entire array.
    // 2. The inner for loop is used to iterate through the array starting from the second element.
    // 3. The if statement is used to compare the two elements and swap them if the first element is greater than the second element.

    // Exchange Order O(n^2)
    int i, j, temp; 
    for ( i = 0; i < x.size() - 1; i ++ ) 
    {
        for ( j = i + 1; j < x.size(); j ++ )
        {
            if( x[ i ] > x[ j ] ) 
            {
                    temp = x[ i ]; 
                    x[ i ] = x[ j ];
                    x[ j ] = temp; 
            }           
        }
    }

    return x;
}

vector<int> bubbleSort(vector<int> x, bool wantText = true) {

// 1. We declare a temporary variable temp to store the value of the element that is to be swapped.
// 2. We use the for loop to iterate through the array.
// 3. We use the if statement to check if the element at index j is greater than the element at index j+1.
// 4. If the element at index j is greater than the element at index j+1, we swap the two elements. 
    
    // Bubble Sort O(n^2)
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x.size() - 1; j++) {
            if (x[j] > x[j + 1]) {
                int temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }

    return x;
}

vector<int> merge(vector<int> left, vector<int> right)
{
   vector<int> result;
   while ((int)left.size() > 0 || (int)right.size() > 0) {
      if ((int)left.size() > 0 && (int)right.size() > 0) {
         if ((int)left.front() <= (int)right.front()) {
            result.push_back((int)left.front());
            left.erase(left.begin());
         } 
   else {
            result.push_back((int)right.front());
            right.erase(right.begin());
         }
      }  else if ((int)left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
               result.push_back(left[i]);
            break;
      }  else if ((int)right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
               result.push_back(right[i]);
            break;
      }
   }
   return result;
}

vector<int> mergeSort(vector<int> m)
{

    // 1. We firstly define two vectors, left and right, to store the first half and the second half of the array, respectively.
    // 2. We then define a vector result to store the sorted array.
    // 3. We then define a variable middle to store the middle index of the array.
    // 4. We then loop through the array and store the first half of the array in left, and the second half of the array in right.
    // 5. We then sort the two halves of the array, and store the result in result.
    // 6. We then return result.

    // Merge Sort O(n log n)
   if (m.size() <= 1)
      return m;
 
   vector<int> left, right, result;
   int middle = ((int)m.size()+ 1) / 2;
 
   for (int i = 0; i < middle; i++) {
      left.push_back(m[i]);
   }

   for (int i = middle; i < (int)m.size(); i++) {
      right.push_back(m[i]);
   }
 
   left = mergeSort(left);
   right = mergeSort(right);
   result = merge(left, right);
 
   return result;
}

// Searching Functions

int sequentialSearch(vector<int> x, int key) {

    // 1. The for loop is used to iterate through the vector x.
    // 2. The if statement is used to check if the value of the current index in the vector x is equal to the value of the key.
    // 3. If the value is equal, then the index is returned.
    // 4. If the value is not equal, then the index is returned as -1. 

    // Sequential Search O(n)
    for (int i = 1; i < x.size(); i++) {
        if (x[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int> x, int key) {

    // 1. We create a low and high pointer that point to the first and last element of the array.
    // 2. We create a mid pointer that points to the middle element of the array.
    // 3. We check if the key is equal to the middle element. If it is, we return the index of the middle element.
    // 4. If the key is not equal to the middle element, we check if the key is less than the middle element.
    // 5. If the key is less than the middle element, we set the low pointer to the middle element + 1.
    // 6. If the key is not less than the middle element, we set the high pointer to the middle element - 1.
    // 7. We repeat the process until the low pointer is less than the high pointer.
    // 8. If the low pointer is equal to the high pointer, we return -1.

    // Bubble Sort O(n^2)
        for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < x.size() - 1; j++) {
            if (x[j] > x[j + 1]) {
                int temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }

    // Binary Search O(log n)
    int low = 0;
    int high = x.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (x[mid] == key) {
            return mid;
        }
        if (x[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {

    cout << endl << "Act 1.2 - Research algorithms" << endl << "------------------------------" << endl;
    cout << "Carlos Alberto Veryan Peña A01641147" << endl << "------------------------------" << endl;

    // Sorting Functions
    vector<int> v[4] = {{8,4,6,5,3,2,9,10,7,1},{9,6,8,7,5,4,1,2,3,10},{1,2,10,9,3,4,8,7,5,6},{10,7,6,5,4,3,2,1,9,8}};
    for (int i = 0; i < 4; i++)
    {
        cout << endl << "TEST CASE " << i + 1 << endl << "-------------------------" << endl;
        cout << endl << "Unsorted Vector:"<< endl;
        print(v[i]);
        cout << "---------------" << endl;

        cout << "Exchange Order:" << endl;
        vector<int> exchangeOrdered = exchangeOrder(v[i]);
        print(exchangeOrdered);
        cout << "---------------" << endl;

        cout << "Bubble Sort:" << endl;
        vector<int> bubbleSorted = bubbleSort(v[i]);
        print(bubbleSorted);
        cout << "---------------" << endl;

        cout << "Merge Sort:" << endl;
        vector<int> mergeSorted = mergeSort(v[i]);
        print(mergeSorted);
        cout << "---------------" << endl;
    }
    
    // Searching Functions
    int key;
    int option;

    cout << endl << "How many searches would you like to do?" << endl << "-> ";
    cin >> option;
    int cont = 0;
    while (cont < option) {
        cout << endl << "What is the key you want to search?" << endl << "-> ";
        cin >> key;
        cout << endl << "Sequential Search" << endl << "---------------" << endl;
        cout << "Unsorted Vector:" << endl;
        print(v[1]);
        cout << endl << "Find: " << key << endl;
        cout << "Index: " << sequentialSearch(v[1], key) << endl;
        cout << endl << "Binary Search" << endl << "---------------" << endl;
        cout << "Unsorted Vector:" << endl;
        print(v[1]);
        cout << endl << "Sorted Vector:" << endl;
        print(bubbleSort(v[1],false));
        cout << endl << "Find: " << key << endl;
        cout << "Index: " << binarySearch(v[1], key) << endl;
        cont++;
    }
    
}