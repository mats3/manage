#ifndef UI_CMD_H
#define UI_CMD_H

#include<stdio.h>
#include<stdio.h>
#include<stdbool.h>

#include"../manager/date.h"
#include"../command/command.h"

#define WINDOW_WIDTH 100
#define WINDOW_HEIGHT 50

#define INPUT_SIZE 50

#define SUBJECT_VISIBLE 0b1
#define ACCOUNT_VISIBLE 0b10
#define SHOULD_DATE_VISIBLE
#define SHOULD_TIME_VISIBLE

#define FIELD(str, width) \
	pruntw("| %s"); \

void listTasks(void);

void ui_cmd_init(void);

void ui_cmd_terminate(void);

#endif
