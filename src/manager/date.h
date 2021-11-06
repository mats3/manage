#ifndef DATE_H
#define DATE_H

#include<stdint.h>

#include"time.h"

typedef struct date {
	int8_t day;
	int8_t month;
	int16_t year;
	time time;
} date;

#endif
