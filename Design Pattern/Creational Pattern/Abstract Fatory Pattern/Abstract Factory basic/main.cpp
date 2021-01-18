#include <iostream>
using namespace std;

class PhoneProduct {
public:
	virtual void showProduct() = 0;
};

class Iphone : public PhoneProduct {
public:
	void showProduct() {
		cout << "Iphone 12 Pro Max";
		cout << endl;
	}
};

class Galaxy : public PhoneProduct {
public:
	void showProduct() {
		cout << "Galaxy s10";
		cout << endl;
	}
};

class TabletProduct {
public:
	virtual void showProduct() = 0;
};

class Ipad : public TabletProduct {
public:
	void showProduct() {
		cout << "Ipad air";
		cout << endl;
	}
};

class SamsungTab : public TabletProduct {
public:
	void showProduct() {
		cout << "Samsung Tab";
		cout << endl;
	}
};

class FactoryProduct {
public:
	virtual PhoneProduct* getPhone() = 0;
	virtual TabletProduct* getTablet() = 0;
};

class AppleFactory : public FactoryProduct {
public:
	PhoneProduct* getPhone() {
		return new Iphone();
	}
	TabletProduct* getTablet() {
		return new Ipad();
	}
};

class SamsungFactory : public FactoryProduct {
public:
	PhoneProduct* getPhone() {
		return new Galaxy();
	}
	TabletProduct* getTablet() {
		return new SamsungTab();
	}
};

int main() {
	FactoryProduct* applefactory = new AppleFactory();
	PhoneProduct* applephone = applefactory->getPhone();
	TabletProduct* appletablet = applefactory->getTablet();
	applephone->showProduct();
	appletablet->showProduct();
	
	FactoryProduct* samsungfactory = new SamsungFactory();
	PhoneProduct* samsungphone = samsungfactory->getPhone();
	TabletProduct* samsungtablet = samsungfactory->getTablet();
	samsungphone->showProduct();
	samsungtablet->showProduct();
}
