#include"task.h"

void task_setRefCode(task *task) {
	task->refCode = 0;
	task->refCode += task->shouldDate.day;
	task->refCode += task->shouldDate.month * 100;
	task->refCode += task->shouldDate.year * 10000;
}