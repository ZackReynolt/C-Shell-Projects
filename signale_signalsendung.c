
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "delay.c"



int main(int argc,char* argv[]){
	if (argc<1) return 1;
	int sig;
	while(1){
		printf("\nSignalnummer? ");
		scanf("%d",&sig);
		if (!(sig==SIGUSR1||sig==SIGUSR2||sig==SIGINT||sig==SIGQUIT)){
			printf("\nNur die Signale SIGUSR1 (%d), SIGUSR2 (%d), SIGINT (%d) und SIGQUIT (%d) sind erlaubt.\n",SIGUSR1,SIGUSR2,SIGINT,SIGQUIT);
			continue;
		}
		kill(atol(argv[1]),sig);
		delay(100);
		if (sig==SIGQUIT) return 0;
	}
}
