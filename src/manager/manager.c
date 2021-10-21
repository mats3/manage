#include"manager.h"

task *head;

void manager_addTask(task **head, task *newTask) {
	if (*head == NULL) {
		*head = newTask;
		newTask->pre = NULL;
		newTask->next = NULL;
	} else {
		newTask->next = *head;
		(*head)->pre = newTask;
		*head = newTask;
		newTask->pre = NULL;
	}
}

void manager_move(task **source, task **targetHead) {
	task *temp = *source;

	if ((*source)->pre == NULL) {
		*source = (*source)->next;
		if (*source != NULL)
			(*source)->pre = NULL;
	} else {
		(*source)->pre->next = (*source)->next;
		if ((*source)->next != NULL)
			(*source)->next->pre = (*source)->pre;
	}
	manager_addTask(targetHead, temp);
}

void manager_loadTasks(date *from, date *to) {
}

void filterEditTasks(task *editTasks, task **filteredTasks) {
	task *tmp = NULL;
	while (editTasks != NULL) {
		if (editTasks->isEdit) {
			tmp = editTasks->next;
			manager_addTask(filteredTasks, editTasks);
			editTasks = tmp;
			continue;
		}

		editTasks = editTasks->next;
	}
}

void saveTasksBySameRefCode(task *editTasks) {
	task *sameRefCode = NULL;
	manager_move(&editTasks, &sameRefCode);
	int refCode = sameRefCode->refCode;

	task *headOfEditTasks = editTasks;
	task *tmp = NULL;

	while (editTasks != NULL) {
		if (editTasks->refCode == refCode) {
			tmp = editTasks->next;
			if (editTasks->pre == NULL)
				headOfEditTasks = tmp;
			manager_move(&editTasks, &sameRefCode);
			editTasks = tmp;
			continue;
		}
		editTasks = editTasks->next;
	}

	store_saveTasks(sameRefCode);
	if (headOfEditTasks != NULL)
		saveTasksBySameRefCode(headOfEditTasks);
}

void manager_storeTasks(task *head) {
	task **editTasks = &head;
	task *newTasks = NULL;
	filterEditTasks(*editTasks, &newTasks);
	saveTasksBySameRefCode(newTasks);
}

void test_printTasks(task *tasks) {
	puts("-------------");
	while (tasks != NULL) {
		printf("[---");

		fprintf(stdout, "(%d),(%s),(%s),(%d,%d,%d,%d,%d),(%d),(%d)",
			tasks->refCode,
			tasks->title,
			tasks->description,
			tasks->shouldDate.day,
			tasks->shouldDate.month,
			tasks->shouldDate.year,
			tasks->shouldDate.time.hour,
			tasks->shouldDate.time.minute,
			tasks->status,
			tasks->isEdit);

		printf("---]\n");

		tasks = tasks->next;
	}
	puts("-------------");
}
