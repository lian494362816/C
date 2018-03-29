#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define SECOND_TO_MRCROSECOND          (1000000)

int main(int argc, char *argv)
{
	struct timeval stStart;
	struct timeval stEnd;
	double s64Time;    
	int i = 0;

	gettimeofday(&stStart,NULL);//start time

	for (i = 0; i < 1000; i++)
	{
		usleep(1000);
	}

	gettimeofday(&stEnd,NULL); //end time

	s64Time = stEnd.tv_usec-stStart.tv_usec + SECOND_TO_MRCROSECOND*(stEnd.tv_sec-stStart.tv_sec);

	printf("s64Time:%lf\n", s64Time / SECOND_TO_MRCROSECOND);

	return 0;
}
