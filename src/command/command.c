#include"command.h"

const int COMMAND_AMOUNT = sizeof(commandList) / sizeof(struct command);

void commandAppend(struct command *command) {
	task newTask;
	strcpy(newTask.subject, command->parameters[0].info);
	strcpy(newTask.account, command->parameters[1].info);

	newTask.status = NOT_STARTED;

	manager_addTask(&head, &newTask);
}

void commandShow(struct command *command) {

}

void setIdentifier(char *input, char *identifier, int *inputPos) {
	while (input[*inputPos] != ' ') {
		identifier[*inputPos] = input[*inputPos];
		(*inputPos)++;
	}

	identifier[(*inputPos)++] = '\0';
}

int getIndexOfExecuteCommand(char *identifier) {
	for (int i = 0; i < COMMAND_AMOUNT; i++) {
		if (strcmp(identifier, commandList[i].identifier) == 0)
			return i;
	}

	return -1;
}

bool charIsDigit(char c) {
	if (c >= 0x30 &&
		c <= 0x39)
		return true;
	return false;
}

int getCounter(char *input, int *inputPos) {
	int counter = 0;

	(*inputPos)++;
	bool negativ = false;

	if (input[*inputPos] == '-') {
		negativ = true;
		(*inputPos)++;
	}

	int faktor = 1;
	while (charIsDigit(input[*inputPos])) {
		counter += faktor * (input[*inputPos] - 0x30);

		faktor *= 10;
		(*inputPos)++;
	}

	return (negativ) ? -1 * counter : counter;
}

void fillParameters(struct command *command, char *input, int *inputPos) {
	char infoBuffer[INFO_SIZE];
	int infoPos = 0;

	char sign;
	int counter;

	while (input[*inputPos] != '\0') {
		counter = getCounter(input, inputPos);
		sign = input[(*inputPos)++]; 

		while (input[*inputPos] != '-' && input[*inputPos] != '\0') {
			infoBuffer[infoPos] = input[*inputPos];

			infoPos++;
			(*inputPos)++;
		}

		infoBuffer[infoPos] = '\0';
		infoPos = 0;

		for (int i = 0; i < command->amountParameter; i++) {
			if (command->parameters[i].sign == sign) {
				command->parameters[i].counter = counter;
				strcpy(command->parameters[i].info, infoBuffer);
				break;
			}
		}
	}
}

void command_execute(char *input) {
	struct command *executeCommand = NULL;
	int index;

	int inputPos = 0;

	char identifier[10];
	setIdentifier(input, identifier, &inputPos);

	index = getIndexOfExecuteCommand(identifier);

	executeCommand = &commandList[index];

	fillParameters(executeCommand, input, &inputPos);

	executeCommand->execute(executeCommand);
	bzero(executeCommand, sizeof(struct command));
}
