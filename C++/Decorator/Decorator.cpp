#include<iostream>
#include<string>
using namespace std;

class Beverage {
	public:
	Beverage() {
		description = "Unknown Beverage";
	}
	virtual double cost() = 0;
	string getDescription() {
		return description;
	}
	protected:
	string description;
};

class Espresso:public Beverage {
	public:
	Espresso() {
		description = "Espresso";
	}
	double cost() {
		return 1.99;
	}
};

class DarkRoast:public Beverage {
	public:
	DarkRoast() {
		description = "Dark Roast Coffee";
	}
	
	double cost() {
		return 0.99;
	}
};

class HouseBlend:public Beverage {
	public:
	HouseBlend() {
		description = "House Blend Coffee";
	}
	double cost() {
		return 0.89;
	}
};

class CondimentDecorator:public Beverage {
	protected:
	Beverage *beverage;
};

class Mocha:public CondimentDecorator {
	public:
	Mocha(Beverage* b) {
		beverage = b;
		description = beverage->getDescription() + ", Mocha";
	}
	
	double cost() {
		return 0.2 + beverage->cost();
	}
};

class Whip:public CondimentDecorator {
	public:
	Whip(Beverage* b) {
		beverage = b;
		description = beverage->getDescription() + ", Whip";
	}
	double cost() {
		return 0.1 + beverage->cost();
	}
};

class Soy:public CondimentDecorator {
	public:
	Soy(Beverage* b){
		beverage = b;
		description = beverage->getDescription() + ", Soy";
	}
	
	double cost() {
		return 0.15 + beverage->cost();
	}
};

int main() {
	Beverage *beverage = new Espresso();
	cout<< beverage->getDescription()<<" $"<<beverage->cost()<<endl;
	
	Beverage* beverage2 = new DarkRoast();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);
	cout<< beverage2->getDescription()<<" $"<<beverage2->cost()<<endl;
	
	Beverage* beverage3 = new HouseBlend();
	beverage3 = new Soy(beverage3);
	beverage3 = new Mocha(beverage3);
	beverage3 = new Whip(beverage3);

	cout<< beverage3->getDescription()<<" $"<<beverage3->cost()<<endl;
	return 0;
}
