#ifndef __ORIGIN_QUEUE_H_
#define __ORIGIN_QUEUE_H_

#include "cocos2d.h"
#include "OList.h"
#include "ODeque.h"

NS_O_BEGIN
/****
*This underlying container shall support at least the following operations:
*.empty
*.size
*.front
*.back
*.pushBack
*.popBack
**/
template<class _T, class _Container = origin::Deque<_T>>
class Queue
{
public:
	Queue<_T, _Container>()
	{
		static_assert(std::is_convertible<_T, cocos2d::Ref *>::value, "Invalid type for Queue!");
	};

	virtual ~Queue<_T, _Container>()
	{
		CCLOGINFO("In the destructor of Queue. ");
		_container.clear();
	};

	bool empty() const
	{
		return _container.empty();
	};

	size_t size()
	{
		return _container.size();
	};

	_T front() const
	{
		return _container.front();
	};

	_T back() const
	{
		return _container.back();
	};

	void push(_T object)
	{
		_container.pushBack(object);
	};

	void pop()
	{
		_container.popBack();
	};

	const _Container& getContainer() const
	{
		return _container;
	};

	_Container& getContainer()
	{
		return _container;
	};
protected:
	_Container _container;
};

NS_O_END;

#endif // !__OQUEUE_H_
