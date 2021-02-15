#include <stdio.h>
#include "Source.h"

int main(void)
{
	int x[] = {5, 3, 2, 6, 9};

	QSort(x, 0, 4) ;

	for(int i = 0 ; i < sizeof(x)/sizeof(int) ; i++)
		printf("%d ",x[i]) ;
}
