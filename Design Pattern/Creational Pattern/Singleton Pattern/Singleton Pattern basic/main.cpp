#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	int id;
	string name;
	static Student* instance;
	Student(int id, string name) {
		this->id = id;
		this->name = name;
	}
	~Student();
public:
	Student(const Student&) = delete;
	void operator=(Student&) = delete;
	static Student* GetInstance(int id, string name) {
		if (instance == nullptr) {
			instance = new Student(id, name);
		}
		return instance;
	}
	void GetStudent() {
		cout << id << " " << name;
	}
};
Student* Student::instance = nullptr;

int main() {
	Student* s = Student::GetInstance(1, "bao");
	s->GetStudent();
	cout << endl;
	s = Student::GetInstance(2, "quan");
	s->GetStudent();
}
