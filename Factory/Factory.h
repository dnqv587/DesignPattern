#pragma once
#include "base/noncopyable.h"
#include <iostream>

class Base
{
 public:
	virtual void print() = 0;
};

class DeriveA:public Base
{
 public:
	void print() override
	{
		std::cout<<"DeriveA\n";
	}
};

class DeriveB:public Base
{
 public:
	void print() override
	{
		std::cout<<"DeriveB\n";
	}
};

class SimpleFactory:noncopyable
{
 public:
	SimpleFactory()=delete;
	~SimpleFactory()=delete;

	Base* CreateObj(int flag)
	{
		Base* obj = nullptr;
		switch (flag)
		{
		case 1:
			obj = new DeriveA();
			break;
		case 2:
			obj = new DeriveB();
			break;
		default:
			obj = nullptr;
		}
		return obj;
	}
};