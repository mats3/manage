#include"status.h"

char *status_convertToShort(status status) {
	switch (status) {
		case NOT_STARTED: return "NS"; break;
		case IN_PROGRESS: return "IP"; break;
		case DONE: return "DN"; break;
	}

	return "";
}
