#include "stdio.h"
#include "stdlib.h"
#include "global_ctrl.h"

typedef struct scan_info {
	int		pos;
	int		times;
};

unsigned int Find1st_NonRep_Char(const unsigned char* s, unsigned int size)
{
	scan_info info[256];
	scan_info* pinfo;

	for (int i = 0; i < 256; i++)
	{
		pinfo = &info[i];
		pinfo->pos = -1;
		pinfo->times = 0;
	}

	for (int i = 0; i < size; i++){
		pinfo = &info[s[i]];
		if (pinfo->pos == -1)
			pinfo->pos = i;

		pinfo->times++;
	}

	int min_pos = -1;

	for (int i = 0; i < 256; i++)
	{
		pinfo = &info[i];
		if (pinfo->times == 1 && (min_pos == -1 || min_pos>pinfo->pos))
			min_pos = pinfo->pos;
	}

	printf("min_pos = %d, char=%c\n", min_pos, s[min_pos]);

	return 0;
}

#if FIND_FIRST_NON_REP_CHAR
int main() 
{
	unsigned char str[] = "kjkjoijfdjkajfj;agioepjiojgodjsagij kjkhjklvjfklvnkl0";

	Find1st_NonRep_Char(str, sizeof(str)-1);
}
#endif
