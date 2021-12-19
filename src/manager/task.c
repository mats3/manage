#include"task.h"

void task_setRefCode(task *task) {
	task->refCode = 0;
	task->refCode += task->should.end.day;
	task->refCode += task->should.end.month * 100;
	task->refCode += task->should.end.year * 10000;
}
