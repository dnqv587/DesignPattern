#pragma once
#include <memory>
#include <list>
#include <mutex>
 
 //***********************************************
 // name      : 观察者模式
 // brief     :
 // 被观察者（Observable）：被观察者或可观察者，它是具有状态的对象，并维护着一个观察者列表。主题提供了添加、删除和通知观察者的方法
 // 观察者（Observer）：观察者是接收主题通知的对象。观察者需要实现一个更新方法，当收到主题的通知时，调用该方法进行更新操作。
 // attention : None
 //***********************************************

 class Observable;
 class Observer:public std::enable_shared_from_this<Observer>
 {
  public:
	 virtual ~Observer();

	 virtual void update() =0;

	 void observe(Observable* observable);

  protected:
	 Observable* _observable;
 };

 class Observable
 {
  public:
	 Observable():_mutex(std::make_shared<std::mutex>()){}
	 virtual ~Observable();

	 Observable(const Observable&) = default;
	 void notify();

	 void _register(std::weak_ptr<Observer> observer);
	 
  private:
	 std::shared_ptr<std::mutex> _mutex;
	 std::list<std::weak_ptr<Observer>> _observers;
 };

 Observer::~Observer()=default;
 Observable::~Observable()=default;

 void Observer::observe(Observable* observable)
 {
	 observable->_register(shared_from_this());
	 _observable = observable;
 }

 void Observable::notify()
 {
	std::lock_guard<std::mutex> lock(*_mutex);
	for(auto iter = _observers.begin();iter!=_observers.end();++iter)
	{
		auto ob = iter->lock();
		if(ob)
		{
			// 执行被观察者更新操作
			ob->update();
		}
		else
		{
			iter = _observers.erase(iter);
		}
	}
 }

 void Observable::_register(std::weak_ptr<Observer> observer)
 {
	 std::lock_guard<std::mutex> lock(*_mutex);
	 _observers.push_back(std::move(observer));
 }
