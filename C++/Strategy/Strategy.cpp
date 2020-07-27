//实现设计模式 - 策略模式 
#include<iostream>
using namespace std;

class QuackBehavior {
	public:
		virtual void quack() = 0;
};

class Quack:public QuackBehavior {
	public:
		void quack() {
			cout<<"Quack"<<endl;
		}
};

class Squeak:public QuackBehavior {
	public:
		void quack() {
			cout<<"Squeak"<<endl;
		}
};

class FlyBehavior {
	public:
		virtual void fly() = 0;
};

class FlyWithWings:public FlyBehavior {
	public:
		void fly() {
			cout<<"I'm flying!!"<<endl;
		}
};

class FlyNoWay:public FlyBehavior {
	public:
		void fly() {
			cout<<"I can't fly"<<endl;
		}
};

class FlyRocketPowered: public FlyBehavior {
	public:
		void fly() {
			cout<<"I'm flying with a rocket"<<endl;
		}
};

class Duck {
	
	public:
		~Duck() {
			if(qb != 0) {
			   delete qb;
			}
			if(fb != 0) {
				delete fb;
			}
		}
		virtual void display() = 0;
		virtual void swim() {
			cout<<"All ducks float, even decoys!"<<endl;
		}
		
		void setQuackBehavior(QuackBehavior* qb) {
			if(NULL != this->qb) {
				delete this->qb;
			}
			this->qb = qb;		
		}
		void setFlyBehavior(FlyBehavior *fb) {
			if(NULL != this->fb) {
				delete this->fb;
			}
			this->fb = fb;
		}
		
		void performQuack() {
			if(NULL != qb) {
				qb->quack();
			}
		}
	
		void performFly() {
			if(NULL != fb) {
				fb->fly();
			}
		}
	
	protected:
		QuackBehavior *qb;
		FlyBehavior *fb;
};

class MallardDuck:public Duck {
	public:
		MallardDuck() {
			qb = new Quack();
			fb = new FlyWithWings();
		}
	
		void display() {
			cout<<"I'm a real Mallard duck"<<endl;
		}
};

class RubberDuck:public Duck{
	public:
		RubberDuck() {
			fb = new FlyNoWay();
			qb = new Squeak();
		}
		void display() {
			cout<<"I'm a rubber duckie"<<endl;
		}
};

class ModelDuck:public Duck{
	public:
		ModelDuck() {
			fb = new FlyNoWay();
			qb = new Quack();
		}
		void display() {
			cout<<"I'm a model duck"<<endl;
		}
};

int main() {
	Duck* ducks[] = {
		new MallardDuck(), new RubberDuck(),
		new ModelDuck()
	};
	for(int i = 0; i < 3; i++) {
		ducks[i]->performQuack();
		ducks[i]->performFly();
		ducks[i]->display();
	}
	
	Duck* modelDuck = ducks[2];
	modelDuck->performFly();	
	modelDuck->setFlyBehavior(new FlyRocketPowered());
	modelDuck->performFly();
	return 0;
}

