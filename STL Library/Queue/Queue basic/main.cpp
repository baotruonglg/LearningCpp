#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> q) {
	queue<int> temp = q;
	while(!temp.empty()) {
		cout << temp.front() << " ";
		temp.pop();
	}
	cout << endl;
}
int main() {
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(15);
	cout << "Size of queue: " << q.size() << endl;
	cout << "List of elements in queue: " << endl;
	printQueue(q);
}
