#pragma once
#include <type_traits>
#include "base/noncopyable.h"

class Foo;

template <typename T>
concept Constructible = requires {
	!std::is_void<T>::value &&
	std::is_default_constructible<T>::value;
};

/// @brief 单例模式
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