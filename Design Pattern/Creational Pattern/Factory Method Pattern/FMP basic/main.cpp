#include <iostream>
#include <vector>
using namespace std; 

class Product {
public:
	virtual void showProduct() = 0;
};

class Phone : public Product {
public:
	void showProduct() {
		cout << "Phone";
	}
};

class Tablet : public Product {
public:
	void showProduct() {
		cout << "Tablet";
	}
};

class Headphone : public Product {
public:
	void showProduct() {
		cout << "Headphone";
	}
};

enum TypeProduct {
	PHONE = 0,
	TABLET,
	HEADPHONE
};

class CreateProduct {
public:
	static Product* GetProduct(TypeProduct type) {
		Product* product;
		switch(type) {
			case PHONE:
				product = new Phone();
				break;
			case TABLET:
				product = new Tablet();
				break;
			case HEADPHONE:
				product = new Headphone();
				break;
			default:
				product = new Phone();
				break;
		}
	}
};

class showProduct {
private:
	vector<Product*> arrProduct;
public:
	void AddProduct(Product* p) {
		arrProduct.push_back(p);
	}
	vector<Product*> GetProductList() {
		return arrProduct;
	}
};

int main() {
	Product* phone = CreateProduct::GetProduct(TypeProduct::PHONE);
	Product* tablet = CreateProduct::GetProduct(TypeProduct::TABLET);
	Product* headphone = CreateProduct::GetProduct(TypeProduct::HEADPHONE);
	showProduct showproduct;
	showproduct.AddProduct(phone);
	showproduct.AddProduct(tablet);
	showproduct.AddProduct(headphone);
	vector<Product*> listProduct = showproduct.GetProductList();
	for (int i = 0; i < listProduct.size(); i++) {
		Product*p = listProduct[i];
		p->showProduct();
		cout << endl;
	}	
}
