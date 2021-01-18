#include <iostream>
using namespace std;

class Array {
private:
	int n;
	int *arr;
	static Array* instance;
	Array();
	Array(int n) {
		arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	~Array() {
		delete arr;
	}
public:
	Array(const Array&) = delete;
	void operator=(Array&) = delete;
	static Array* GetInstance(int n) {
		static Array instance(n);
		return &instance;
	}
};
Array* Array::instance = nullptr;

int main() {
	Array* arr = Array::GetInstance(5);
	Array* arr2 = Array::GetInstance(10);
}
