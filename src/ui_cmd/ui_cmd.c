#include"ui_cmd.h"

#include<ncurses.h>
#include<unistd.h>

WINDOW *window;

int x, y;

void printField(char *value, int valueSize) {
	int x, y;
	getyx(stdscr, y, x);

	mvprintw(y, x, "%s\n", value);

	move(y, x + valueSize + 2);
}

void listTasks(void) {
	task *tmpHead = head;

	y = 11, x = 1;
	move(y, x);

	char index[3] = { "00" };

	while (tmpHead != NULL) {
		printField(index, 2);
		if (index[1] >= 0x39) {
			index[0]++;
			index[1] -= 0x9;
		} else
			index[1]++;


		printField(status_convertToShort(tmpHead->status), 2);
		printField(tmpHead->subject, 25);
		printField(date_getDateFormat(&tmpHead->should.end), 10);
		printField(date_getTimeFormat(&tmpHead->should.end), 5);

		move(y += 1, x);

		tmpHead = tmpHead->next;
	}
}

void initWindow(void) {
	initscr();

	curs_set(1);

	window = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);
	refresh();

	mvhline(10, 1, ACS_HLINE, WINDOW_WIDTH);
	wrefresh(window);

	/*
	box(window, 0, 0);
	move(8, 1);
	hline(ACS_HLINE, WINDOW_WIDTH - 2);

	move(10, 1);
	hline(ACS_HLINE, 87);
	wrefresh(window);
	*/
}

void writeTitle(void) {
	char c;
	move(1, 1);
	FILE *title = fopen("src/ui_cmd/title", "r");
	while ((c = fgetc(title)) != EOF) {
		if (c == '\n') {
			getyx(stdscr, y, x);
			move(y + 1, 1);
			continue;
		}
		addch(c);
	}
}

void ui_cmd_init(void) {
	initWindow();

	int x, y;

	writeTitle();

	char buffer[200];
	int i = 0;
	char c;

	move(9, 1);
	while ((c = getch()) != '*') {
		if (c == 127) {
	 		int x, y;
			getyx(stdscr, y, x);
			mvaddch(y, x, ' ');
			mvaddch(y, x - 1, ' ');
			mvaddch(y, x - 2, ' ');
			move(y, x - 3);
			i --;
			continue;
		}
		if (c == '\n') {
			buffer[i] = '\0';
			command_execute(buffer);
			listTasks();
			i = 0;
			move(9, 1);
			hline(' ', 87);
			move(9, 1);
			continue;
		}
		buffer[i++] = c;
	}

	endwin();
}

void ui_cmd_terminate(void) {
}
