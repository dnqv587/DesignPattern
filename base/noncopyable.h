#pragma once

/// @brief 禁止派生类的拷贝构造

class noncopyable
{
 public:
	noncopyable(const noncopyable&) = delete;
	noncopyable& operator=(const noncopyable&) = delete;
 protected:
	noncopyable()=default;
	~noncopyable()=default;
};