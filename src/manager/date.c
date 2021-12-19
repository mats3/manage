#include"date.h"

char *date_getDateFormat(date *date) {
	char *buffer = calloc(11, sizeof(char));
	CHECK_ALLOC(buffer);

	buffer[0] = date->day / 10 + 0x30;
	buffer[1] = date->day % 10 + 0x30;
	buffer[2] = '.';
	buffer[3] = date->month / 10 + 0x30;
	buffer[4] = date->month % 10 + 0x30;
	buffer[5] = '.';
	buffer[6] = date->year / 1000 + 0x30;
	buffer[7] = date->year / 100 % 10+ 0x30;
	buffer[8] = date->year / 10 % 10 + 0x30;
	buffer[9] = date->year % 10 + 0x30;

	buffer[10] = '\0';
	
	return buffer;
}

char *date_getTimeFormat(date *date) {
	char *buffer = calloc(6, sizeof(char));
	CHECK_ALLOC(buffer);

	buffer[0] = date->hour / 10 + 0x30;
	buffer[1] = date->hour % 10 + 0x30;

	buffer[2] = ':';

	buffer[3] = date->minute / 10 + 0x30;
	buffer[4] = date->minute % 10 + 0x30;

	buffer[5] = '\0';

	return buffer;
}

void date_current(date *date) {
	time_t now;

	time(&now);
	struct tm *tmnow = localtime(&now);

	date->day = tmnow->tm_mday;
	date->month = tmnow->tm_mon + 1;
	date->year = tmnow->tm_year + 1900;
	date->hour = tmnow->tm_hour;
	date->minute = tmnow->tm_min;
}
