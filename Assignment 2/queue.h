#include<iostream>
using namespace std;

template<class Q>

class Queue
{
	Q* queue;
	int front;
	int back;
	int max;
	int size;

public:

	Queue(int size)
	{
		max = size;
		queue = new Q[max];
		front = -1;
		back = 0;
		this->size = 0;
	}


	Q Front()
	{
		if (front == -1)
			return 0;
		else
			return queue[front];
	}


	void push(Q object)
	{
		if (size == max)
			return 0;
		else
		{
			if (front == -1)
			{
				front = 0;
			}

			data[back] = object;
			back++;
			size++;
		}
	}

	Q pop()
	{
		if (front == -1)
		{
			return 0;
		}

		Q x = queue[front];

		for (int i = 0; i < size; i++)
		{
			queue[i] = queue[i + 1];
		}

		back--;
		size--;

		if (size == 0)
		{
			front = -1;
			back = 0;
		}
		return x;
	}
};

