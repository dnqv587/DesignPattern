#pragma once
#include "base/noncopyable.h"

//***********************************************
// name      : 单例模式
// brief     :
// attention : None
//***********************************************

template <typename T>
class Singleton:noncopyable
{
 public:
	Singleton()=delete;
	~Singleton()=delete;

	static T* getInstance()
	{
		static T obj{};
		return &obj;
	}
};