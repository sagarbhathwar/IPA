#ifndef TIME_CALC_H
#define TIME_CALC_H
#include <time.h>

/*
** define two timespec variables as start and end where
** call the function gettime whereever appropriate
** use time_elapsed to find out the time difference between the start and end time
*/

typedef struct timespec timespec;

void gettime(timespec* t)
{
	clock_gettime(CLOCK_REALTIME, t);
}

double time_elapsed(timespec start, timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001;		
	return t;
}


#endif
