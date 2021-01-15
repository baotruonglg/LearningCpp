#include <queue>
#include <iostream>
using namespace std;

void printQueue(priority_queue<int> pq) {
	priority_queue<int> g = pq;
	while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

int main() {
	priority_queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);
    cout << "Size of priority_queue: " << gquiz.size() << endl;
    cout << "List of element in priority_queue: " << endl;
    printQueue(gquiz);
}
