#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> s) {
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
int main() {
	stack<int> s, s2;
	s.push(4);
	s.push(41);
	s.push(14);
	s.push(23);
	s.push(7);
	s2.push(15);
	s2.push(10);
	cout << "Size of stack: " << s.size() << endl;
	cout << "List of element in stack: " << endl;
	printStack(s);
	s.swap(s2);
	printStack(s);
}
