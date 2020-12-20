#include <iostream>
using namespace std;
template<class T>
class Node
{
public:
	Node* pNext;
	Node* pPrev;
	T data;

	Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
		this->pPrev = pPrev;
	}
	template<class T>
	friend class ListIterator;
};
template<class T>
class ListIterator
{
protected:
	Node<T>* i;
public:
	ListIterator(Node<T>* _n) : i(_n) {}
	ListIterator(ListIterator<T>& _v) : i(_v.i) {}
	~ListIterator() {}

	bool CanMove() { return (i != nullptr); }
	void Move() { i = i->pNext; }

	bool operator==(const ListIterator<T>& _v) { return i == _v.i; }
	bool operator!=(const ListIterator<T>& _v) { return !((*this) == _v); }

	ListIterator<T> operator++(int)
	{
		if (!CanMove())
			throw logic_error("reached end");
		Move();
		return (*this);
	}
	ListIterator<T>& operator=(const ListIterator<T>& _v) { i = _v.i; return (*this); }

	T& operator* () {
		if (i != nullptr)
			return i->data;
		else throw - 1;
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
		tail = nullptr;
	}
	List(List<T>& _l)
	{
		ListIterator<T> k = _l.begin();
		Size = 0;
		head = nullptr;
		tail = nullptr;
		for (int i = 0; i < _l.Size; i++)
		{
			push_back(*k);
			if (k.CanMove())
				k++;
		}
	}
	~List()
	{
		clear();
	}

	int GetSize() const { return Size; }

	ListIterator<T> begin() { return ListIterator<T>(head); }
	ListIterator<T> end() { return ListIterator<T>(tail); }

	void push_back(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
			tail = head;
		}
		else
		{
			Node<T>* current = this->tail;
			current->pNext = new Node<T>(data, nullptr, current);
			tail = current->pNext;
		}

		Size++;
	}

	void pop_front()
	{
		if (Size == 0)
			throw logic_error("list empty");

		Node<T>* temp = head;
		head = head->pNext;

		if (head != nullptr)
			head->pPrev = nullptr;
		else
			tail = tail->pPrev;

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
		if (head == nullptr)
			push_back(data);
		else
		{
			Node<T>* temp = head;
			head = new Node<T>(data, head);
			temp->pPrev = head;
			Size++;
		}
	}

	void insert(T data, int index)
	{
		if (index < 0 || index > Size)
			throw logic_error("incorrect index");

		if (index == 0)
			push_front(data);
		else if (index == Size)
			push_back(data);
		else
		{
			Node<T>* previous = find_prev(index);

			Node<T>* newNode = new Node<T>(data, previous->pNext, previous);
			previous->pNext->pPrev = newNode;
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
		else if (index == Size - 1)
			pop_back();
		else
		{
			Node<T>* previous = find_prev(index);

			Node<T>* toDelete = previous->pNext;
			toDelete->pNext->pPrev = previous;
			previous->pNext = toDelete->pNext;

			delete toDelete;
			Size--;
		}
	}

	void pop_back()
	{
		if (Size == 0)
			throw logic_error("list empty");

		Node<T>* temp = tail;
		tail = tail->pPrev;

		if (tail != nullptr)
			tail->pNext = nullptr;
		else
			head = head->pNext;

		delete temp;
		Size--;
	}

	friend ostream& operator << (ostream& ostr, List<T>& _l)
	{
		ListIterator<T> k = _l.begin();
		ostr << "{";
		for (int i = 0; i < _l.GetSize() - 1; i++)
		{
			ostr << *k << ", ";
			k++;
		}
		ostr << *k << "}";

		return ostr;
	}
};