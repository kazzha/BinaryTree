#pragma once

#include <vector>
#include <iostream>


// Time Complext : log n
// space : n
class Heap
{
	std::vector<int> mHeap;

public:
	void Insert(int value)
	{
		mHeap.push_back(value);

		int i = mHeap.size() - 1;
		int half = (i - 1) / 2;
		while (i != 0 && value > mHeap[half])
		{
			mHeap[i] = mHeap[half];
			mHeap[half] = value;
			i = half;

			half = (i - 1) / 2;
		}
	}

	int Pop()
	{
		if (mHeap.size() == 0)
		{
			// INT_MAX, INT_MIN - C스타일
			// C++ 스타일
			return std::numeric_limits<int>::min();
			
		}

		int value = mHeap.front();
		mHeap[0] = mHeap.back();
		mHeap.pop_back();

		int i{};
		while (i < mHeap.size())
		{
			int bigChild = i * 2 + 1;
			if (bigChild >= mHeap.size())
			{
				break;
			}

			if (bigChild + 1 < mHeap.size() && mHeap[bigChild] < mHeap[bigChild + 1])
			{
				bigChild++;
			}

			if (mHeap[i] >= mHeap[bigChild])
			{
				break;
			}

			std::swap(mHeap[i], mHeap[bigChild]);
			i = bigChild;
		}

		return value;
	}

	void Print()
	{
		for (auto e : mHeap)
		{
			std::cout << e << " ";
		}
	}
};

void HeapTest()
{
	Heap h;

	h.Insert(1);
	h.Insert(2);
	h.Insert(3);
	h.Insert(4);
	h.Insert(5);

	h.Print();

	// heap sort : n log n, n
}
