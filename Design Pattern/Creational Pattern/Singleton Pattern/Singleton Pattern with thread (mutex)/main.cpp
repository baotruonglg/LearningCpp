#include <iostream>
#include <mutex>
using namespace std;

class Array {
private:
	int n;
	int *arr;
	static mutex _mutex;
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
		if (instance == nullptr) {
			_mutex.lock();
			if (instance == nullptr) {
				instance = new Array(n);
			}
			_mutex.unlock();	
		}
		return instance;
	}
};
Array* Array::instance = nullptr;
mutex Array::_mutex;

int main() {
	Array* arr = Array::GetInstance(5);
	Array* arr2 = Array::GetInstance(10);
	arr2 = Array::GetInstance(5);
}


