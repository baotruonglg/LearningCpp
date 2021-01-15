#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    vector<int> arr;
    vector<int>::iterator it;
    int number;
    cout << "Enter the number of vector: " << endl;
    cin >> number;
    arr.resize(number);
    for (int i = 0; i < arr.size(); i++) {
        cout << "Array[" << i << "] = ";
        cin >> arr[i];
    }
    cout << endl << "List of element in vector: ";
    for (it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl << "Capacity of vector: " << arr.capacity() << endl;
    cout << endl << "Max size of vector: " << arr.max_size() << endl;
    if (!arr.empty()) {
        cout << "vector is unempty";
    }
    else {
        cout << "vector is empty";
    }
}