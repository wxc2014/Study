#include <stdio.h>
#include <stdlib.h>

void CalRowAndCol(unsigned long pTestVal, unsigned* pRow, unsigned* pCol);

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Input Error!\n");
		return 1;
	}

	unsigned long testVal = atol( argv[1] );
	if(testVal < 1)
	{
		printf("Input Error!\n");
		return 1;
	}

	unsigned row = 0, col = 0;
	CalRowAndCol(testVal, &row, &col);

	if(row == 0)
	{
		printf("%d\n", col);
	}
	else if(row % 2 != 0)
	{
		printf("%d\n", 5-col);
	}
	else
	{
		printf("%d\n", 1+col);
	}

	return 0;
}

void CalRowAndCol(unsigned long pTestVal, unsigned * pRow, unsigned * pCol)
{
	if(pTestVal <= 5)
	{
		*pRow = 0;
		*pCol = pTestVal;
	}
	else 
	{
		*pRow = (pTestVal - 5) >> 2;
		*pCol = (pTestVal - 5) - (*pRow << 2);

		if(*pCol == 0)
		{
			*pCol = 4;
		}
		else
		{
			*pRow += 1;
		}
	}
}