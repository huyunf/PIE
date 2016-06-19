#include <iostream>
#include <string>
#include "global.h"

using namespace std;

#define CHAR2DEC(_c) ((int)(_c)-48)

#define TELE_LENGTH 7

char getCharKey(int telephoneKey, int place)
{
	if (telephoneKey > 9 || telephoneKey < 0 || place < 0 || place>4)
		cout << "Wrong telephone key: " << telephoneKey << " with place: " << place << endl;

	switch (telephoneKey)
	{
		case 1:
			return '1'; break;
		case 2:
			return (place == 1) ? 'A' : (place == 2) ? 'B' : 'C';break;
		case 3:
			return (place == 1) ? 'D' : (place == 2) ? 'E' : 'F';break;
		case 4:
			return (place == 1) ? 'G' : (place == 2) ? 'H' : 'I';break;
		case 5:
			return (place == 1) ? 'J' : (place == 2) ? 'K' : 'L';break;
		case 6:
			return (place == 1) ? 'M' : (place == 2) ? 'N' : 'O';break;
		case 7:
			return (place == 1) ? 'P' : (place == 2) ? 'Q' : (place == 3) ? 'R' : 'S';break;
		case 8:
			return (place == 1) ? 'T' : (place == 2) ? 'U' : 'V';break;
		case 9:
			return (place == 1) ? 'W' : (place == 2) ? 'X' : (place == 3) ? 'Y' : 'Z';break;
	default:
		break;
	}

	return ' ';
}


void Telephone_Word(unsigned int num[], unsigned int cur_head, string parent = "")
{
	unsigned int max_place = 0;
	unsigned int first_num = num[cur_head];

	if (first_num == 1)
		max_place = 1;
	else if (first_num == 7 || first_num == 9)
		max_place = 4;
	else
		max_place = 3;

	for (int i = 1; i <= max_place; i++) {
		string par = parent;

		char c = getCharKey(num[cur_head], i);
		par.push_back(c);
		
		if (cur_head == TELE_LENGTH - 1)
			cout << par << endl;
		else
			Telephone_Word(num, cur_head + 1, par);
	}
}

#if TELEPHONE_WORD

/*PROB LEM People in the United States often give others their telephone number
as a word representing the seven-digit number after the area code. For
example, if my telephone number were 866-2665, I could tell people my number
is “TOOCOOL,” instead of the hard-to-remember seven-digit number. Note
that many other possibilities (most of which are nonsensical) can represent 866-
2665. You can see how letters correspond to numbers on a telephone keypad in

Write a function that takes a seven-digit telephone number and prints out all of
the possible “words” or combinations of letters that can represent the given number.
Because the 0 and 1 keys have no letters on them, you should change only
the digits 2–9 to letters. You’ll be passed an array of seven integers, with each element
being one digit in the number. You may assume that only valid phone numbers
will be passed to your function. You can use the helper function
char getCharKey( int telephoneKey, int place )
which takes a telephone key (0–9) and a place of either 1, 2, 3 and returns the
character corresponding to the letter in that position on the specified key. For
example, GetCharKey(3,2) will return ‘E’ because the telephone key 3 has the
letters “DEF” on it and ‘E’ is the second letter.
*/

int main()
{
	string str;

	cout << "telephone words!" << endl;

	/*
	cout << "Enter Number: ";
	cin >> num;
	*/

	str = "8862665";

	cout << str << endl;

	unsigned int num[TELE_LENGTH];

	for (int i = 0; i < TELE_LENGTH; i++) {
		num[i] = CHAR2DEC(str[i]);
	}

	Telephone_Word(num, 0);
	
	return 0;
}

#endif