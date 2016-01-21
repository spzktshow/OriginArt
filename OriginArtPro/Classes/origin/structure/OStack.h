#ifndef __ORIGIN_STACK_H_
#define __ORIGIN_STACK_H_

#include "cocos2d.h"

NS_O_BEGIN
/**
*The container shall support the following operations:
*.empty
*.size
*.back
*.pushBack
*.popBack
***/
template<class _T, class _Container = cocos2d::Vector<_T>>
class Stack
{
public:
	Stack<_T, _Container>()
	{
		static_assert(std::is_convertible<_T, cocos2d::Ref *>::value, "Invalid type for Stack!");
	};

	virtual ~Stack<_T, _Container>()
	{
		CCLOGINFO("In the destructor of Stack. ");
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

	void push(_T object)
	{
		_container.pushBack(object);
	};

	void pop()
	{
		_container.popBack();
	};

	_T top() const
	{
		return _container.back();
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

NS_O_END
#endif// !__OSTACK_H_