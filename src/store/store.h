#ifndef STORE_H
#define STORE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>

#include"../manager/date.h"
#include"../manager/task.h"

#define STORE_LOCATION "storage/tasks/"

void store_saveTasks(task *head);

void store_loadTask(task **head, date *from, date *to);

#endif
