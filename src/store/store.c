#include"store.h"

FILE *store = NULL;

void saveTask(task *task) {
	fprintf(store, "(%d)(%s)(%s)(%d,%d,%d,%d,%d)(%d)(%d)\n",
		task->refCode,
		(task->subject[0] == '\0') ?"NULL" :task->subject,
		(task->account[0] == '\0') ?"NULL" :task->account,
		task->should.end.day,
		task->should.end.month,
		task->should.end.year,
		task->should.end.hour,
		task->should.end.minute,
		task->status,
		task->isEdit);
}

void freeAll(task *head) {
	task *forFree;
	while (head != NULL) {
		forFree = head;
		head = head->next;
		free(forFree);
	}
}

void genFileName(task *head, char *fileName) {
	sprintf(fileName, "%d", head->refCode);
}

void store_saveTasks(task *head) {
	char fileName[10];
	genFileName(head, fileName);

	char path[50] = STORE_LOCATION;
	strcat(path, fileName);

	store = fopen(path, "w+");

	while (head != NULL) {
		saveTask(head);
		head = head->next;
	}

	fclose(store);

	freeAll(head);
}

void store_loadTask(task **head, date *from, date *to) {
	DIR *tasksFolder = opendir(STORE_LOCATION);
	struct dirent *dirptr;

	readdir(tasksFolder);
	readdir(tasksFolder);
	chdir(STORE_LOCATION);

	while ((dirptr = readdir(tasksFolder)) != NULL) {
		store = fopen(dirptr->d_name, "r");

		task *newTask = malloc(sizeof(task));

		fscanf(store, "(%d)(%[^)])(%[^)])(%d,%d,%d,%d,%d)(%d)(%d)",
			&newTask->refCode,
			newTask->subject,
			newTask->account,
			(int *)&newTask->should.end.day,
			(int *)&newTask->should.end.month,
			(int *)&newTask->should.end.year,
			(int *)&newTask->should.end.hour,
			(int *)&newTask->should.end.minute,
			(int *)&newTask->status,
			(int *)&newTask->isEdit);

		manager_addTask(head, newTask);
		fclose(store);
	}

	chdir("..");
	chdir("..");
}
