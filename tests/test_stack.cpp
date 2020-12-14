#include <../gtest/gtest.h>
#include "Stack.h"

TEST(stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack<int> A);
}

TEST(stack, can_copy)
{
	Stack<int> A;

	A.push(1);
	A.push(2);
	A.push(3);

	Stack<int> B(A);

	EXPECT_EQ(3, B.pop());
}

TEST(stack, can_push)
{
	Stack<int> A;

	A.push(1);
	A.push(2);
	A.push(3);

	EXPECT_EQ(3, A.pop());
	EXPECT_EQ(2, A.pop());
	EXPECT_EQ(1, A.pop());
}

TEST(stack, can_pop)
{
	Stack<int> A;

	A.push(1);
	A.push(2);
	A.push(3);

	EXPECT_EQ(3, A.pop());
}

TEST(stack, cant_pop_if_empty)
{
	Stack<int> A;

	A.push(1);
	A.push(2);
	A.pop();
	A.pop();

	ASSERT_ANY_THROW(A.pop());
}


TEST(queue, can_create_queue)
{
	ASSERT_NO_THROW(Queue<int> A);
}

TEST(queue, can_copy)
{
	Queue<int> A;
	A.push(1);
	A.push(2);
	A.push(3);

	Queue<int> B(A);

	EXPECT_EQ(1, B.pop());
}

TEST(queue, can_push)
{
	Queue<int> A;

	A.push(1);
	A.push(2);
	A.push(3);

	EXPECT_EQ(1, A.pop());
	EXPECT_EQ(2, A.pop());
	EXPECT_EQ(3, A.pop());
}

TEST(queue, can_pop)
{
	Queue<int> A;

	A.push(1);
	A.push(2);
	A.push(3);

	EXPECT_EQ(1, A.pop());
}

TEST(queue, cant_pop_if_empty)
{
	Queue<int> A;

	A.push(1);
	A.push(2);
	A.pop();
	A.pop();

	ASSERT_ANY_THROW(A.pop());
}