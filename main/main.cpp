#include "List.h"
#include "Stack.h"

int main()
{
	Stack<int> A;
	A.push(1);
	A.push(2);
	A.push(3);

	cout << A.pop();

	Queue<int> B;
	B.push(1);
	B.push(2);
	B.push(3);

	cout << B.pop();

}