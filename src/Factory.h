#pragma once
#include "base/noncopyable.h"
#include <iostream>

//***********************************************
// name      : 工厂模式
// brief     : 
// attention : None
//***********************************************

class Base
{
 public:
	virtual ~Base()=default;

	virtual void print() = 0;
};

class DeriveA:public Base
{
 public:
	~DeriveA() override =default;

	void print() override
	{
		std::cout<<"DeriveA\n";
	}
};

class DeriveB:public Base
{
 public:
	~DeriveB() override =default;

	void print() override
	{
		std::cout<<"DeriveB\n";
	}
};

class SimpleFactory:noncopyable
{
 public:

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

class Factory:noncopyable
{
 public:
	virtual ~Factory() = default;

	virtual Base* CreateObj() = 0;
};

class AFactory:public Factory
{
 public:
	~AFactory() override = default;

	Base* CreateObj() override
	{
		return new DeriveA{};
	}
};

class BFactory:public Factory
{
 public:
	~BFactory() override = default;

	Base* CreateObj() override
	{
		return new DeriveB{};
	}
};
