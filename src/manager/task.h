#ifndef TASK_H
#define TASK_H

#include<stdbool.h>

#include"date.h"
#include"status.h"

typedef struct task {
	int refCode;
	char subject[50];
	char account[250];
	date shouldDate;
	date isDate;
	status status;
	bool isEdit;

	struct task *pre;
	struct task *next;
} task;

void task_setRefCode(task *task);

void manager_addTask(task **head, task *task);

#endif
