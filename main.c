#include<stdio.h>
#include<unistd.h>
#include <string.h>
#include "log_process.h"

int main(int argc, char *argv[])
{
	EventLogFileOpen();
	printf("main pid=%d\n", getpid() );

	pid_t pid=0;
	if(0 == (pid=fork())) {
		if(0 != (pid=fork())) {
                	while(1) Print_PID( getpid() );
        	}

		while(1) Print_PID( getpid() );
	}
	else {
                if(0 != (pid=fork())) {
                        while(1) Print_PID( getpid() );
                }

                while(1) Print_PID( getpid() );
	}

	return 0;
}

