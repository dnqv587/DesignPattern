#pragma once
#include "base/noncopyable.h"
#include <string>
#include <string_view>
#include <iostream>

//***********************************************
// name      : 建造者模式
// brief     :作用：封装一个复杂对象构造过程，并允许按步骤构造
//1、生成器 （Builder） 接口声明在所有类型生成器中通用的产品构造步骤，一般都由虚函数组成。
//2、具体生成器 （Concrete Builders） 提供构造过程的不同实现。 具体生成器也可以构造不遵循通用接口的产品。
//3、产品 （Products） 是最终生成的对象。 由不同生成器构造的产品无需属于同一类层次结构或接口。
//4、主管 （Director） 类定义调用构造步骤的顺序， 这样你就可以创建和复用特定的产品配置。
//5、客户端 （Client） 必须将某个生成器对象与主管类关联。 一般情况下， 你只需通过主管类构造函数的参数进行一次性关联即可。 此后主管类就能使用生成器对象完成后续所有的构造任务。
// attention : None
//***********************************************


class Products;

/// @brief 生成器 （Builder）,接口声明在所有类型生成器中通用的产品构造步骤，一般都由虚函数组成
class Builder:noncopyable
{
 public:
	virtual ~Builder() = default;
	//每个接口都生产产品的部分
	virtual void ProducePartA() = 0;
	virtual void ProducePartB() = 0;
	virtual void ProducePartC() = 0;
};

/// @brief 产品 （Products） 是最终生成的对象。 由不同生成器构造的产品无需属于同一类层次结构或接口
class Products
{
 public:
	void print() const
	{
		std::cout<<m_value<<std::endl;
	}

	void setValue(std::string_view str)
	{
		m_value.append(str);
	}

 private:
	std::string m_value;

};

/// @brief 具体生成器 （Concrete Builders） 提供构造过程的不同实现。 具体生成器也可以构造不遵循通用接口的产品
class ConcreteBuilder1:public Builder
{
 public:
	ConcreteBuilder1()
	{
		init();
	}
	~ConcreteBuilder1() override
	{
		delete m_products;
	}

	void ProducePartA() override
	{
		m_products->setValue("ConcreteBuilder1-ProducePartA;");
	}

	void ProducePartB() override
	{
		m_products->setValue("ConcreteBuilder1-ProducePartB;");
	}

	void ProducePartC() override
	{
		m_products->setValue("ConcreteBuilder1-ProducePartC;");
	}

	Products* GetProduct()
	{
		auto obj = m_products;
		init();
		return obj;
	}


 private:
	void init()
	{
		m_products = new Products();
	}

	Products* m_products;
};

class ConcreteBuilder2:public Builder
{
 public:
	ConcreteBuilder2()
	{
		init();
	}
	~ConcreteBuilder2() override
	{
		delete m_products;
	}

	void ProducePartA() override
	{
		m_products->setValue("ConcreteBuilder2-ProducePartA;");
	}

	void ProducePartB() override
	{
		m_products->setValue("ConcreteBuilder2-ProducePartB;");
	}

	void ProducePartC() override
	{
		m_products->setValue("ConcreteBuilder2-ProducePartC;");
	}

	Products* GetProduct()
	{
		 auto obj = m_products;
		 init();
		return obj;
	}

 private:
	void init()
	{
		m_products = new Products();
	}

	Products* m_products;
};

/// @brief 主管 （Director） 类定义调用构造步骤的顺序， 这样你就可以创建和复用特定的产品配置
class Director:noncopyable
{
 public:
	Director(Builder* builder):m_builder(builder){}

	void setBuilder(Builder* builder)
	{
		m_builder = builder;
	}

	void BuildAC()
	{
		m_builder->ProducePartA();
		m_builder->ProducePartC();
	}
	void BuildBC()
	{
		m_builder->ProducePartB();
		m_builder->ProducePartC();
	}

	void BuildABC()
	{
		m_builder->ProducePartA();
		m_builder->ProducePartB();
		m_builder->ProducePartC();
	}
 private:
	Builder* m_builder = nullptr;
};