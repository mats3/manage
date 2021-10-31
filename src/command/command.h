#ifndef COMMAND_H
#define COMMAND_H

#include<stdlib.h>
#include<string.h>

#define COMMAND_AMOUNT 2

#define INDEX_WIDTH 3

struct parameter {
	char sign;
	int counter;
	char info[50];
};

struct command {
	char indentifier[10];
	struct parameter parameters[10];
	int amountParameter;

	void (*execute)(struct command *command);
};

void commandAppend(struct command *command);

void commandShow(struct command *command);

struct command commandList[] = {
	{
		"append",
		{
			{ 's', 0, "" },
			{ 'a', 0, "" },
			{ 'd', 0, "" },
			{ 't', 0, "" },
		}, 5,
		commandAppend
	},
	{ 
		"show", 
		{
			{ 'd', 0, "" },
		}, 5,
		commandShow
	},
};

void command_execute(char *command);

#endif
