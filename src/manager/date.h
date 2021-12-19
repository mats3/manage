#ifndef DATE_H
#define DATE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>

#include"../check.h"

typedef struct date {
	int8_t day;
	int8_t month;
	int16_t year;
	int8_t hour;
	int8_t minute;
} date;

typedef struct datePeriod {
	date start;
	date end;
} datePeriod;

char *date_getDateFormat(date *date);

char *date_getTimeFormat(date *date);

void date_current(date *date);

#endif
