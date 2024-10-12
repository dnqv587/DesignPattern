#include "src/Factory.h"

int main()
{
	Base* obj1 = SimpleFactory().CreateObj(1);
	Base* obj2 = SimpleFactory().CreateObj(2);
	obj1->print(); // DeriveA
	obj2->print(); // DeriveB

	Factory* fac1 = new AFactory();
	Factory* fac2 = new BFactory();
	Base* obj3 = fac1->CreateObj();
	Base* obj4 = fac2->CreateObj();
	obj3->print(); // DeriveA
	obj4->print(); // DeriveB

	delete obj1;
	delete obj2;
	delete obj3;
	delete obj4;
	delete fac1;
	delete fac2;


	return 0;
}