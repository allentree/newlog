#ifndef LOG_PROCESS_H
#define LOG_PROCESS_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>

unsigned long get_file_size(FILE *fp);
void EventLogFileOpen(void);
int PrintEventLog(const char *pcEventSource, char *pcStrBuff);
void EventLogFileSizeJudge(void);
int Print_PID(int pid);

#endif

