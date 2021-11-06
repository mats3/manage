#ifndef MANAGER_H
#define MANAGER_H

#include<stdio.h>

#include"task.h"
#include"../store/store.h"

extern task *head;

void manager_addTask(task **head, task *newTask);

void manager_move(task **source, task **targetHead);


void manager_storeTasks(task *head);

void test_printTasks(task *tasks);

#endif
