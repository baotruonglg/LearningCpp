#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void printArr(vector<int> arr, vector<int>::iterator it) {
	for (it = arr.begin(); it != arr.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
int main() {
	vector<int> arr, arr2;
	vector<int>::iterator it;
	arr.assign(5, 2);
	printArr(arr, it);
	arr2.resize(4);
	cout << endl << "Enter value of Arr2: " << endl;
	for (int i = 0; i < arr2.size(); i++) {
		cout << "Arr2[" << i << "] = ";
		cin >> arr2[i]; 
	}
	arr.swap(arr2);
	printArr(arr, it);
	arr.insert(arr.begin() + 2, 3);
	printArr(arr, it);
	arr.erase(arr.begin() + 3);
	printArr(arr, it);
	cout << "Initial value of vector: " << arr.front() << endl;
	cout << "End value of vector: " << arr.back() << endl;
}
