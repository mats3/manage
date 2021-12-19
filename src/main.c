#include<stdio.h>
#include"ui_cmd/ui_cmd.h"

int main(int argc, char **argv) {
	ui_cmd_init();

	return 0;
}

	/*
	task *list = NULL;
	
	task t1 = { .refCode = 10, .isEdit = true };
	task t2 = { .refCode = 5, .isEdit = true };
	task t3 = { .refCode = 6, .isEdit = true };
	task t4 = { .refCode = 10, .isEdit = true };
	task t5 = { .refCode = 5, .isEdit = true };
	task tmp0 = { .refCode = 20210813, .isEdit = true };
	task tmp1 = { .refCode = 20210813, .isEdit = true };
	task tmp3 = { .refCode = 20210813, .isEdit = true };
	task test = { .refCode = 20210813, .isEdit = true };
	task test1 = { .refCode = 20210813, .isEdit = true };

	manager_addTask(&list, &t1);
	manager_addTask(&list, &tmp1);
	manager_addTask(&list, &t2);
	manager_addTask(&list, &t3);
	manager_addTask(&list, &t4);
	manager_addTask(&list, &t5);
	manager_addTask(&list, &tmp0);
	manager_addTask(&list, &tmp3);
	manager_addTask(&list, &test);
	manager_addTask(&list, &test1);

	manager_storeTasks(list);

	list = NULL;

	store_loadTask(&list, NULL, NULL);

	test_printTasks(list);
	*/
