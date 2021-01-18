#include <iostream>
#include <string>
using namespace std;

class BackendA {
public:
	virtual void setName(string) = 0;
	virtual string getName() = 0;
};

class User : public BackendA {
private:
	string _name;
public: 
	void setName(string name) {
		_name = name;
	}
	string getName() {
		return _name;
	}
};

class BackendB {
public:
	virtual void setFName(string) = 0;
	virtual string getFName() = 0;
	virtual void setLName(string) = 0;
	virtual string getLName() = 0;
};

class UserAtoBAdapter : public BackendB {
private:
	User _user;
	string _Fname;
	string _Lname;
public:
	UserAtoBAdapter(User& user) {
		_user = user;
		unsigned int splitpos = user.getName().find_first_of(" ");
		if (splitpos != string::npos) {
			_Fname = user.getName().substr(0, splitpos + 1);
			_Lname = user.getName().substr(splitpos + 1, user.getName().length());
		}
	}
	void setFName(string Fname) {
		_Fname = Fname;
	}
	void setLName(string Lname) {
		_Lname = Lname;
	}
	string getFName() {
		return _Fname;
	}
	string getLName() {
		return _Lname;
	}
}; 

int main() {
	User user;
	user.setName("Bao Truong");
	UserAtoBAdapter adapter(user);
	cout << adapter.getFName(); cout << endl;
	cout << adapter.getLName();
}
