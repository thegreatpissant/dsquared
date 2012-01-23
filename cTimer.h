/* cTimer.h
 * James A. Feister		Dsquared Timer.
 */
#include <sys/times.h>
#include <iostream>

extern int CurLevel;
int level_delay = 100;

clock_t elapsed, current, clock_ticks;

void prep_timer()
{
	struct tms tbuf;
	clock_ticks = sysconf(_SC_CLK_TCK);
	current = times(&tbuf);
	elapsed = 0;
}

bool move_piece()
{

	struct tms tbuf;
	
	elapsed = (times(&tbuf) - current);
	if ( (elapsed) > level_delay )
	{
		current += elapsed;
		elapsed = 0;
		return true;
	}

	return false;
}

void setLevel_delay()
{
	switch( CurLevel )
	{
		case 0:
			level_delay = 100;
			break;
		case 1: 
			level_delay = 90;
			break;
		case 2:
			level_delay = 80;
			break;
		case 3:
			level_delay = 70;
			break;
		case 4:
			level_delay = 60;
			break;
		case 5:
			level_delay = 50;
			break;
		case 6:
			level_delay = 40;
			break;

		case 7:
			level_delay = 30;
			break;
		case 8:
			level_delay = 20;
			break;

		case 9:
		case 10:level_delay = 10;
			break;

		default:
			level_delay = 100;
			break;
	}
}
