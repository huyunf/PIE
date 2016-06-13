#include "global_ctrl.h"
#include <iostream>
#include <string>

using namespace std;

inline void local_swap(unsigned char* a, unsigned char* b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

void reverse_str(unsigned char* str_beg, unsigned char* str_end)
{
	while (1)
	{
		local_swap(str_beg, str_end);

		str_beg++;
		str_end--;

		if (str_end - str_beg < 1) break;
	}
}

#if REVERSE_WORDS

/*
Write a function that reverses the order of the words in a string. For
example, your function should transform the string 
"Do or do not, there is no try." 
to 
"try. no is there not, do or Do". 
Assume that all words are space delimited and treat punctuation the same as letters.
*/
int main()
{
	unsigned char str[] = "I have ever been here again!";
	unsigned char* beg = str;
	unsigned char* end = str+sizeof(str)-2;

	// original
	cout << str << endl;

	// revert all
	reverse_str(beg, end);

	cout << str << endl;

	// revert word
	beg = str;
	end = str+1;

	while (end < (str + sizeof(str)))
	{
		if (*end == ' ' || *end=='\0') {
			reverse_str(beg, end - 1);
			beg = end + 1;
		}
		end++;
	}

	cout << str << endl;
}

#endif