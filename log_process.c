#include "log_process.h"

#define NEW_LOG_FILE_NAME	"eventlog.txt"
#define OLD_LOG_FILE_NAME	"eventlogbak.txt"

FILE	*m_pFd;

unsigned long get_file_size(FILE *fp)
{
	unsigned long file_size = 0;
	file_size = ftell(fp);
	return file_size;
}

void EventLogFileOpen(void)
{
	m_pFd = fopen(NEW_LOG_FILE_NAME, "a+");
}

int PrintEventLog(const char *pcEventSource, char *pcStrBuff)
{
	int ret;
	char *pTimeStr;	

	EventLogFileSizeJudge();	
	ret = fprintf(m_pFd, "####Time:%s[%s]: %s\n", "11:22:33",
		pcEventSource, pcStrBuff);
	
	int f_ret = fflush(m_pFd);
	if(f_ret != 0)
	{
		printf("f_ret=%d,pid=%d,\n",f_ret, getpid() );
		perror("fflush");
		sleep(5000);
	}
}

void EventLogFileSizeJudge(void)
{
	int iFileSize = 0;
	int ret;
	int m_iFileMaxSize = 50000;

	FILE *pTemp;

	iFileSize = ftell(m_pFd);

	if (iFileSize > m_iFileMaxSize)
	{
		fclose(m_pFd);//close NEW_LOG_FILE_NAME
		ret = rename(NEW_LOG_FILE_NAME, OLD_LOG_FILE_NAME);
		
		if (0 == ret) {
			EventLogFileOpen();
		}
		else {
			perror("rename");
		}
	}
}

int Print_PID(int pid)
{
	char StrBuff[100];
	memset(StrBuff,0,sizeof(StrBuff));
	sprintf(StrBuff, "pid=%d", getpid());

	char buf2[500];
	sprintf(buf2, "pid=%d", pid);
	PrintEventLog(StrBuff, buf2 );

	usleep(500);
}
