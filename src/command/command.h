#ifndef COMMAND_H
#define COMMAND_H

#include<stdlib.h>
#include<string.h>
#include<strings.h>

#include"../manager/task.h"
#include"../manager/manager.h"

#define INFO_SIZE 50

#define TEST 0b0000001

struct parameter {
	char sign;
	int counter;
	char info[INFO_SIZE];
};

#define IDENTIFIER_SIZE 10
#define PARAMETERS_SIZE 10

struct command {
	char identifier[IDENTIFIER_SIZE];
	struct parameter parameters[PARAMETERS_SIZE];
	int amountParameter;

	void (*execute)(struct command *command);
};

void commandAppend(struct command *command);

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
};

extern const int COMMAND_AMOUNT;

void command_execute(char *input);

#endif
