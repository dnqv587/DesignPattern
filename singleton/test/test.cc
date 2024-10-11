#include <iostream>
#include "singleton//Singleton.h"

class Foo
{
 public:
	Foo()
	{
		std::cout<<"construct"<<std::endl;
	}

	void print() const {
		std::cout<<str<<std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os,const Foo& f)
	{
		os<<f.str;
		return os;
	}

 private:
	char str[10] = "print";
};


int main(){
	Singleton<Foo>::getInstance()->print();

	return 0;
}