#include"command.h"

#include"../manager/task.h"
#include"../manager/manager.h"

void commandAppend(struct command *command) {
	task newTask;
	strcpy(newTask.subject, command->parameters[0].info);
	strcpy(newTask.account, command->parameters[1].info);
	newTask.status = NOT_STARTED;
}

void commandShow(struct command *command) {

}

void getCommandName(char *command, char *commandName) {
	int i;
	for (i = 0; command[i] != ' '; i++) {
		commandName[i] = command[i];
	}
	commandName[i] = '\0';
}

void fillParameters(struct command *command, char *parameters) {
	int commandPos = 0;

	while (parameters[commandPos] != ' ')
		commandPos++;
	commandPos++;

	for (int i = 0; i < command->amountParameter; i++) {
		command->parameters[i].info[i + j] = parameters[j];
	}
}

int getIndexFromCommand(char *command) {
	int index = 0;

	for (int i = 0; i < INDEX_WIDTH; i++)
		index += command[i];

	return index;
}

bool compareListAndCommandIndex(char *listCommand, char *inputCommand) {
	if (getIndexFromCommand(listCommand) == getIndexFromCommand(inputCommand))
		return true;

	return false;
}

void command_execute(char *command) {
	struct command *executeCommand = NULL;


	char *commandName = calloc(10, sizeof(char));
	getCommandName(command, commandName);

	for (int i = 0; i < COMMAND_AMOUNT; i++) {
		if (compareListAndCommandIndex(commandList[i].indentifier, command)) {
			executeCommand = &commandList[i];
			break;
		}
	}

	fillParameters(executeCommand, command);

	executeCommand->execute(executeCommand);
}
