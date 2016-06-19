#include <iostream>
#include <string>
#include "global.h"

using namespace std;


void permutations_of_string(string str, string parent="")
{
	if (1 == str.size()) {
		parent.push_back(str[0]);
		cout << parent << endl;
	}

	for (int i = 0; i < str.size(); i++)
	{
		string cur = str;
		string par = parent;

		par.push_back(cur[i]);

		cur.erase(i, 1);

		permutations_of_string(cur, par);
	}
}

#if PERMUTATION_STRING_ENABLE

/*
PROB LEM Implement a routine that prints all possible orderings of the characters
in a string. In other words, print all permutations that use all the characters from
the original string. For example, given the string “hat”, your function should print
the strings “tha”, “aht”, “tah”, “ath”, “hta”, and “hat”. Treat each character in the
input string as a distinct character, even if it is repeated. Given the string “aaa”,
your routine should print “aaa” six times. You may print the permutations in any
order you choose.
*/

int main()
{
	cout << "permutaion a string!" << endl;

	string str = "abcdefg";

	permutations_of_string(str);

	return 0;
}

#endif