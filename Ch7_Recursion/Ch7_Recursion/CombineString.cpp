#include <iostream>
#include <string>
#include "global.h"

using namespace std;

void combinations_of_string(string str, string parent="")
{
	

	for (int i = 0; i < str.size(); i++) {
		string cur = str;
		string par = parent;

		par.push_back(cur[i]);

		cout << par << endl;

		cur.erase(0, i+1);

		combinations_of_string(cur, par);
	}
}

#if COMBINE_STRING
/*
PROB LEM Implement a function that prints all possible combinations of the
characters in a string. These combinations range in length from one to the length
of the string. Two combinations that differ only in ordering of their characters are
the same combination. In other words, “12” and “31” are different combinations
from the input string “123”, but “21” is the same as “12”.
*/

int main()
{
	cout << "combinations of a string!" << endl;

	string str = "abcde";

	combinations_of_string(str);

	return 0;
}
#endif