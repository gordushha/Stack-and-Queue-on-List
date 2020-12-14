#pragma once
#include <List.h>

template<class T>
class Stack
{
protected:
	List<T> data;
public:
	Stack() : data() {}
	Stack(Stack& _v) : data(_v.data) {}

	bool IsEmpty()
	{
		return(data.GetSize() == 0);
	}
	int GetSize()
	{
		return(data.GetSize());
	}
	virtual void push(const T& data)
	{
		this->data.push_front(data);
	}
	T pop()
	{
		T temp = data[0];
		data.pop_front();

		return(temp);
	}
};

template<class T>
class Queue : public Stack<T>
{
public:
	void push(const T& data) override
	{
		this->data.push_back(data);
	}
};