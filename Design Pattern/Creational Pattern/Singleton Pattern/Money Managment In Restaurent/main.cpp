#include<iostream>
using namespace std;

class MoneyInRestaurent {
private:
	int _money;
	MoneyInRestaurent() {
		_money = 1000000;
	}
	static MoneyInRestaurent* instance;
public:
	MoneyInRestaurent(const MoneyInRestaurent&) = delete;
	void operator=(MoneyInRestaurent&) = delete;
	static MoneyInRestaurent* GetInstance() {
		if (instance == nullptr) {
			instance = new MoneyInRestaurent();
		}
		return instance;
	}
	int GetMoney() {
		return _money;
	}
	int RemainingMoneyWhenBuy(int money) {
		_money -= money;
	}	
};
MoneyInRestaurent* MoneyInRestaurent::instance = nullptr;

class StaffInRestaurent {
protected:
	MoneyInRestaurent* money = MoneyInRestaurent::GetInstance();
public:
	void CheckMoneyInRestaurent() {
		cout << "The remaining money in restaurent: " << money->GetMoney() << endl;
	}
	void BuyFood(int numbermon) {
		money->RemainingMoneyWhenBuy(numbermon);
		CheckMoneyInRestaurent();
	}	
};

class Chief : public StaffInRestaurent {
};

class Manager : public StaffInRestaurent {
};


int main() {
	StaffInRestaurent* chief = new Chief();
	StaffInRestaurent* manager = new Manager();
	chief->CheckMoneyInRestaurent();
	chief->BuyFood(500000);
	manager->CheckMoneyInRestaurent();
	manager->BuyFood(300000);
	chief->CheckMoneyInRestaurent();
	
}
