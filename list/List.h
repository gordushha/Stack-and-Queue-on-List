#pragma once;
#include <iostream>
using namespace std;
template<class T>
class Node
{
public:
	Node* pNext;
	T data;

	Node(T data = T(), Node* pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
};
template<class T>
class List
{
private:

	int Size;
	Node<T>* head;
	Node<T>* tail;

	Node<T>* find_prev(int index)
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;
		return previous;
	}
public:
	List()
	{
		Size = 0;
		head = nullptr;
	}
	List(List<T>& _l)
	{
		Size = 0;
		head = nullptr;
		for (int i = 0; i < _l.Size; i++)
			push_back(_l[i]);
	}
	~List()
	{
		clear();
	}

	int GetSize() const { return Size; }

	T& operator[](const int index)
	{
		if (index < 0 || index >= Size)
			throw length_error("incorrect index");

		int counter = 0;
		Node<T>* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
				return current->data;
			current = current->pNext;
			counter++;
		}
	}

	void push_back(T data)
	{
		if (head == nullptr)
			head = new Node<T>(data);
		else
		{
			Node<T>* current = this->head;
			while (current->pNext != nullptr)
				current = current->pNext;
			current->pNext = new Node<T>(data);
		};

		Size++;
	}

	void pop_front()
	{
		if (Size == 0)
			throw logic_error("list empty");

		Node<T>* temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	}

	void clear()
	{
		while (Size)
			pop_front();
	}

	void push_front(T data)
	{
		head = new Node<T>(data, head);
		Size++;
	}

	void insert(T data, int index)
	{
		if (index < 0 || index > Size)
			throw logic_error("incorrect index");

		if (index == 0)
			push_front(data);
		else
		{
			Node<T>* previous = find_prev(index);

			Node<T>* newNode = new Node<T>(data, previous->pNext);
			previous->pNext = newNode;
			
			Size++;
		}
	}

	void remove(int index)
	{
		if (index < 0 || index >= Size)
			throw logic_error("incorrect index");

		if (index == 0)
			pop_front();
		else
		{
			Node<T>* previous = find_prev(index);

			Node<T>* toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;

			delete toDelete;
			Size--;
		}
	}

	void pop_back()
	{
		if (Size == 0)
			throw logic_error("list empty");

		remove(Size - 1);
	}

	friend ostream& operator << (ostream& ostr, List<T>& _l)
	{
		ostr << "{";
			for (int i = 0; i < _l.GetSize() - 1; i++)
				ostr << _l[i] << ", ";
		ostr << _l[_l.GetSize() - 1] << "}";

		return ostr;
	}
};