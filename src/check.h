#ifdef DATE_H
#define DATE_H

#include<stdio.h>

#define CHECK_ALLOC(x) \
	if ((x) == NULL) \
		printf("allocation fail\nline: %d\n", __LINE__);

#endif
