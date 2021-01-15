#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int>::iterator it;
    cout << "List of element in vector: " << endl;
    for (it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}