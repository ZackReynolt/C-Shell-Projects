
#include <time.h>

void delay(int milliseconds){
	clock_t endwait;
	endwait=clock()+milliseconds*(CLOCKS_PER_SEC/1000);
	while (clock()<endwait);
}
