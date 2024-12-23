#include "src/Observer.h"
#include <iostream>
#include <thread>
#include <chrono>

 class ObserverA:public Observer
 {
  public:
	 ObserverA()=default;
	 ~ObserverA() override =default;
	 void update() override
	 {
		 std::cout<<"ObserverA update"<<std::endl;
	 }
 };

class ObserverB:public Observer
{
 public:
	~ObserverB() override =default;
	void update() override
	{
		std::cout<<"ObserverB update"<<std::endl;
	}
};

class ObservableA:public Observable
{
 public:
	ObservableA()=default;
	~ObservableA() override =default;
	ObservableA(const ObservableA&) = default;

};

int main()
{
	auto obba = std::make_shared<ObservableA>();
	ObservableA aaa(*obba);
	auto oba = std::make_shared<ObserverA>();
	auto obb = std::make_shared<ObserverB>();
	oba->observe(obba.get());
	obb->observe(obba.get());
	int i = 0;
	while(1)
	{
		obba->notify();
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(2s);
		++i;
		if(i == 5)
		{
			std::cout<<"release ob"<<std::endl;
			oba.reset();
		}
	}



}
