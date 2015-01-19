
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>






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






int main(int argc,char *argv[]){
	long abstand=atol(argv[1]);
	long endwert=atol(argv[2]);

	pid_t pid=getpid();
	
	long zahl;
	long anz=0;
	for (zahl=2; zahl<=endwert; zahl++){
		if (isPrime(zahl)){
			if (++anz%abstand==0) printf("Prozess %d: Primzahl gefunden: %ld\n",pid,zahl);
		}
	}

	return 0;
}


