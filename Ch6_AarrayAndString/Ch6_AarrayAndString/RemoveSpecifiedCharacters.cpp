#include "global_ctrl.h"
#include <iostream>
#include <string>

using namespace std;

inline bool if_remove(string remove, unsigned char c)
{
	for (string::iterator iter = remove.begin(); iter < remove.end(); iter++)
	{
		if (c == *iter) return true;
	}
	return false;
}

string removeChars(string &str, const string remove)
{
	string::iterator iter_cur	= str.begin();
	string::iterator iter_scan	= str.begin();

	for (; iter_scan != str.end(); iter_scan++)
	{
		if (if_remove(remove, *iter_scan)==false)
		{
			if (iter_scan != iter_cur) *iter_cur = *iter_scan;
			iter_cur++;
		}
	}

	str.erase(iter_cur, iter_scan);

	return str;
}

#if REMOVE_SPECIFIED_CHAR

/*
"Battle of the Vowels: Hawaii vs. Grozny" and a remove of
"aeiou", the function should transform str to 
“Bttl f th Vwls: Hw vs. Grzny”.
*/
int main()
{
	string str("Battle of the Vowels: Hawaii vs. Grozny");
	string rev("aeiou");

	cout << str << endl;

	cout << removeChars(str, rev) << endl;
}

#endif