#include"command.h"

#include"../manager/task.h"
#include"../manager/manager.h"

void commandAdd(struct command *command) {
	task newTask;
	strcpy(newTask.title, command->parameter[0].info);
	strcpy(newTask.description, command->parameter[1].info);
	newTask.status = NOT_STARTED;
}

void commandList(struct command *command) {

}

void getCommandName(char *command, char *commandName) {
	int i;
	for (i = 0; command[i] != ' '; i++) {
		commandName[i] = command[i];
	}
	commandName[i] = '\0';
}

void fillParameters(struct command *command, char *parameters) {
	for (int i = 0; i < command->amountParameter; i++) {
		//todo
	}
}

void command_execute(char *command) {
	struct command *executeCommand = NULL;

	char *commandName = calloc(10, sizeof(char));
	getCommandName(command, commandName);

	for (int i = 0; i < COMMAND_AMOUNT; i++) {
		if (list[i].name == commandName) {
			executeCommand = &list[i];
			break;
		}
	}

	fillParameters(executeCommand, command);

	executeCommand->execute(executeCommand);
}