#ifndef TASK_H
#define TASK_H

#include<stdbool.h>

#include"date.h"
#include"status.h"

#define SUBJECT_SIZE 50
#define ACCOUNT_SIZE 250

typedef struct task {
	int refCode;
	char subject[SUBJECT_SIZE];
	char account[ACCOUNT_SIZE];
	datePeriod should;
	datePeriod is;
	status status;
	bool isEdit;

	struct task *pre;
	struct task *next;
} task;

void task_setRefCode(task *task);

void manager_addTask(task **, task *);

#endif
