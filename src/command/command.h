#ifndef COMMAND_H
#define COMMAND_H

#include<stdlib.h>
#include<string.h>

#define COMMAND_AMOUNT 2

struct parameter {
	char sign;
	int counter;
	char info[50];
};

struct command;

void commandAdd(struct command *command);

void commandList(struct command *command);

struct command {
	char name[10];
	struct parameter parameter[10];
	int amountParameter;

	void (*execute)(struct command *command);
} list[] = {
	{ .name = "list" }
};

void command_execute(char *command);

#endif
