#ifndef STATUS_H
#define STATUS_H

typedef enum { NOT_STARTED, IN_PROGRESS, DONE } status;

char *status_convertToShort(status status);

#endif
