#include <iostream>
#include <vector>
#include "Sort.h"

using namespace std;

#define ARY_SIZE 10

int main()
{
	vector<int> ary;

	srand(100);

	for (int i = 0; i < ARY_SIZE; i++) {
		ary.push_back(rand()%100);
	}
	
	sort<int> s(ary);

	cout << *(ary.end()-1) << endl;

	ary.insert(ary.end(), 19);

	s.selected_sort();

	s.insert_sort();

	return 0;
}