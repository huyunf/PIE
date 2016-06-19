#include <iostream>

#include "global.h"

using namespace std;

unsigned int recursion_time=0;

unsigned int bisearch(int* ary, unsigned int beg_idx, unsigned int end_idx, int find)
{
	unsigned int size = end_idx - beg_idx + 1;

	recursion_time++;

	if (size == 1) // beg == end
	{
		if (ary[beg_idx] != find){
			cout << "find not in ary!" << endl;
			return 0xffffffff;
		}
		cout << "find idx=" << beg_idx << endl;
		return beg_idx;
	}
	else
	{
		int mid = (beg_idx + end_idx) / 2;

		if (ary[mid] == find) {
			cout << "find idx=" << mid << endl;
			return mid;
		}
		else {
			if (ary[mid] > find) {
				return bisearch(ary, beg_idx, mid - 1, find);
			}
			else { // ary[mid] > find
				return bisearch(ary, mid + 1, end_idx, find);
			}
		}
	}
	

	
}

#if BISEARCH_ENABLE
/*
PROB LEM Implement a function to perform a binary search on a sorted array
of integers to find the index of a given integer. Comment on the efficiency of this
search, and compare it with other search methods.
*/
int main()
{
	cout << "Bi search" << endl;

	int ary[100];

	for (int i = 0; i < 100; i++) {
		ary[i] = i * 2 + 3;
	}

	int find = 3;

	cout << "find " << find << " in index: " << bisearch(ary, 0, 99, find) << endl;
	cout << "with recursion time: " << recursion_time << endl;

	return 0;
}
#endif