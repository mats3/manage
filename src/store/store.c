#include"store.h"

FILE *store = NULL;

void saveTask(task *task) {
	fprintf(store, "(%d)(%s)(%s)(%d,%d,%d,%d,%d)(%d)(%d)\n",
		task->refCode,
		(task->title[0] == '\0') ?"NULL" :task->title,
		(task->description[0] == '\0') ?"NULL" :task->description,
		task->shouldDate.day,
		task->shouldDate.month,
		task->shouldDate.year,
		task->shouldDate.time.hour,
		task->shouldDate.time.minute,
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
			newTask->title,
			newTask->description,
			(int *)&newTask->shouldDate.day,
			(int *)&newTask->shouldDate.month,
			(int *)&newTask->shouldDate.year,
			(int *)&newTask->shouldDate.time.hour,
			(int *)&newTask->shouldDate.time.minute,
			(int *)&newTask->status,
			(int *)&newTask->isEdit);

		manager_addTask(head, newTask);
		fclose(store);
	}

	chdir("..");
	chdir("..");
}
