#include <iostream>
#include <random>
using namespace std;

class State {
public:
	virtual void getForm() = 0;
	virtual void checkForm() = 0;
	virtual void rentApartment() = 0;
	virtual void dispenseKeys() = 0;
};

class InterfaceRentalRobot {
public:
	virtual void getForm() = 0;
	virtual void checkForm() = 0;
	virtual State* setState(State*) = 0;
	virtual State* getState() = 0;
	virtual State* getWaitingState() = 0;
	virtual State* getReceivingFromState() = 0;
	virtual State* getRentApartmentState() = 0;
	virtual State* getFullyRentedState() = 0;
	virtual int getCount() = 0;
	virtual void setCount(int count) = 0;
};

class WaitingState : public State {
private:
	InterfaceRentalRobot* _robot;
public:
	WaitingState(InterfaceRentalRobot* robot) {
		_robot = robot;
	}
	void getForm() {
		_robot->setState(_robot->getReceivingFromState());
		cout << "Thanks for the form." << endl;
	}
	void checkForm()
    {
        cout << "You have to submit an form." << endl;
    }
 
    void rentApartment()
    {
        cout << "You have to submit an form." << endl;
    }
 
    void dispenseKeys()
    {
        cout << "You have to submit an form." << endl;
    }
};

class ReceivingFromState : public State {
private:
	InterfaceRentalRobot* _robot;
	random_device mRandomGenerator;
public:
	ReceivingFromState(InterfaceRentalRobot* robot) {
		_robot = robot;
	}
	void getForm() {
		cout << "Thanks for the form." << endl;
	}
	void checkForm()
    {
        uniform_int_distribution<int> int_distribution(0, 9);
        bool isFormOk = (int_distribution(mRandomGenerator) > 5);
 
        if (isFormOk && _robot->getCount() > 0) {            
            cout << "Congratulations, you were approved." << endl;
            _robot->setState(_robot->getRentApartmentState());
            _robot->getState()->rentApartment();
        }
        else {
            _robot->setState(_robot->getWaitingState());
            cout << "Sorry, you were not approved." << endl;
        }
    }
 
    void rentApartment()
    {
        cout << "You have to submit an form." << endl;
    }
 
    void dispenseKeys()
    {
        cout << "You have to submit an form." << endl;
    }
};

class RentApartmentState : public State {
private:
	InterfaceRentalRobot* _robot;
public:
	RentApartmentState(InterfaceRentalRobot* robot) {
		_robot = robot;
	}
	void getForm() {
		cout << "Thanks for the form." << endl;
	}
	void checkForm()
    {
        cout << "You have to submit an form." << endl;
    }
 
    void rentApartment()
    {
    	_robot->setCount(_robot->getCount() - 1);
        cout << "You have to submit an form." << endl;
        dispenseKeys();
    }
 
    void dispenseKeys()
    {
        if (_robot->getCount() > 0) {
            _robot->setState(_robot->getWaitingState());
        }
        else {            
            _robot->setState(_robot->getFullyRentedState());
        }
        cout << "Here are your keys!" << endl;
    }
};


class FullyRentedState  : public State {
private:
	InterfaceRentalRobot* _robot;
public:
	FullyRentedState (InterfaceRentalRobot* robot) {
		_robot = robot;
	}
	void getForm() {
		cout << "Sorry, we’re fully rented." << endl;
	}
	void checkForm()
    {
        cout << "Sorry, we’re fully rented." << endl;
    }
 
    void rentApartment()
    {
    	cout << "Sorry, we’re fully rented." << endl;
    }
 
    void dispenseKeys()
    {
        cout << "Sorry, we’re fully rented." << endl;
    }	
};

class RentalRobot : public InterfaceRentalRobot {
private:
	State* _currentstate;
	State* _waitingstate;
	State* _receivingstate;
	State* _rentapartmentstate;
	State* _fullystate;
	int _count;
public:
	RentalRobot(int count) {
		_count = count;
		_waitingstate = new WaitingState(this);
		_receivingstate = new ReceivingFromState(this);
		_rentapartmentstate = new RentApartmentState(this);
		_fullystate = new FullyRentedState(this);
		_currentstate = _waitingstate;
	}
	void getForm() {
		_currentstate->getForm();
	}
	void checkForm() {
		_currentstate->checkForm();
	}
	State* setState(State* state) {
		_currentstate = state;
	}
	State* getState() {
		return _currentstate;
	}
	State* getWaitingState() {
		return _waitingstate;
	}
	State* getReceivingFromState() {
		return _receivingstate;
	}
	State* getRentApartmentState() {
		return _rentapartmentstate;
	}
	State* getFullyRentedState() {
		return _fullystate;
	}
	int getCount() {
		return _count;
	}
	void setCount(int count) {
		_count = count;
	}
};

int main() {
	RentalRobot robot(10);
    robot.getForm();
    robot.checkForm();
    return 0;
}
