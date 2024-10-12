#include "src/Builder.h"


int main()
{
	auto* build1 = new ConcreteBuilder1();
	auto* build2 = new ConcreteBuilder2();

	Director dire{build1};
	dire.BuildABC();
	auto product1= build1->GetProduct();

	dire.setBuilder(build2);
	dire.BuildABC();
	auto product2= build2->GetProduct();

	product1->print();
	product2->print();

	return 0;
}