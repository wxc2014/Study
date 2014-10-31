#include <stdio.h>

#define HALF_BITS_LENGTH	4
#define FULLMASK	255
#define LMASK	(FULLMASK << HALF_BITS_LENGTH)
#define	RMASK	(FULLMASK >> HALF_BITS_LENGTH)
#define RSET(b, n)	((b) = (b) & LMASK | (n))
#define LSET(b, n)	((b) = (b) & RMASK | (n))
#define RGET(b)		((b) & RMASK)
#define LGET(b)		((b) & LMASK) >> HALF_BITS_LENGTH

#define WIDTH	3

void Print()
{
	unsigned int data;
	for(data = 1; RGET(data) <= WIDTH * WIDTH; data++)
	{
	}
}