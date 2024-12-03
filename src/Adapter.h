#pragma once
#include <string>
#include <string_view>
#include <iostream>

//***********************************************
// name      : 适配器模式
// brief     : 适配器模式（Adapter Pattern）充当两个不兼容接口之间的桥梁，属于结构型设计模式。它通过一个中间件（适配器）将一个类的接口转换成客户期望的另一个接口，使原本不能一起工作的类能够协同工作。
// 目标接口（Target）：定义客户需要的接口。
// 适配者类（Adaptee）：定义一个已经存在的接口，这个接口需要适配。
// 适配器类（Adapter）：实现目标接口，并通过组合或继承的方式调用适配者类中的方法，从而实现目标接口。
// attention : 适配器模式是一种软件设计模式，旨在解决不同接口之间的兼容性问题。
//	目的：将一个类的接口转换为另一个接口，使得原本不兼容的类可以协同工作。
//	主要解决的问题：在软件系统中，需要将现有的对象放入新环境，而新环境要求的接口与现有对象不匹配。
//***********************************************

//目标接口，待适配
class Target
{
 public:
	virtual void todoSth(std::string_view data)=0;
};

class TargetImpl1:public Target
{
 public:
	void todoSth(std::string_view data) override
	{
		std::cout<< " TargetImpl1 to do "<<data<<std::endl;
	}
};

class TargetImpl2:public Target
{
 public:
	void todoSth(std::string_view data) override
	{
		std::cout<< " TargetImpl2 to do "<<data<<std::endl;
	}
};


//适配者类，需适配目标对象
class Adaptee
{
 public:
	 virtual void play(int type,std::string_view data) = 0;
};

//适配器类，适配目标对象
class Adapter:public Adaptee
{
 public:
	Adapter():_target(nullptr){}

	~Adapter()
	{
		delete _target;
	}

	void AdaptForType(int type)
	{
		if(type == 1)
		{
			_target = new TargetImpl1();
		}
		else if (type == 2)
		{
			_target = new TargetImpl2();
		}
	}

	void play(int type,std::string_view data) override
	{
		if(type == 1 || type == 2)
		{
			_target->todoSth(data);
		}
	}
 private:
	Target* _target;
};

//适配者类实例化对象
class AdapteeImpl:public Adaptee
{
 public:
	AdapteeImpl():_adapter(new Adapter){}

	~AdapteeImpl()
	{
		delete _adapter;
	}

	void play(int type,std::string_view data) override
	{
		if(type == 0)
		{
			std::cout<< " AdapteeImpl play "<<data<<std::endl;
		}
		else
		{
			_adapter->AdaptForType(type);
			_adapter->play(type,data);
		}
	}
 private:
	Adapter* _adapter;
};