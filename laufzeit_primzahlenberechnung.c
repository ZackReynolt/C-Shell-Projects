
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <sys/time.h>










int SIGUSR1_count=0;
int SIGUSR2_count=0;
int SIGINT_count=0;
int SIGQUIT_count=0;

long letzte_primzahl=0;
int neustart=0;


short isPrime(long p){
	long s, d;
	s = (long) sqrt(p) + 1;
	if ( p <  2 ) return 0;
	if ( p == 2 ) return 1;
	if ( p % 2 == 0 ) return 0;
	for ( d = 3; d <= s; d+=2 )
	if ( p % d == 0 ) return 0;
	return 1;
}






void Primzahlausgabe(){
	SIGUSR1_count++;
	printf("\n%d\n",letzte_primzahl);
}

void Neustart(){
	SIGUSR2_count++;
	neustart=1;
}

void Zaehlerstandausgabe(){
	SIGINT_count++;
	printf("\nSIGUSR1: %d, ",SIGUSR1_count);
	printf("SIGUSR2: %d, ",SIGUSR2_count);
	printf("SIGINT: %d, ",SIGINT_count);
	printf("SIGQUIT: %d\n",SIGQUIT_count);
}

void Ende(){
	SIGQUIT_count++;
	exit(0);
}










int main(int argc,char *argv[]){
	
	sigset(SIGUSR1,Primzahlausgabe);
	sigset(SIGUSR2,Neustart);
	sigset(SIGINT,Zaehlerstandausgabe);
	sigset(SIGQUIT,Ende);
	
	//long abstand=atol(argv[1]);
	long endwert=atol(argv[2]);

	pid_t pid=getpid();
	
	long zahl;
	long anz=0;
	for (zahl=2; zahl<=endwert; zahl++){
		if (neustart){
			neustart=0;
			zahl=2;
		}
		if (isPrime(zahl)){
			letzte_primzahl=zahl;
		}
	}

	return 0;
}


