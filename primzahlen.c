#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
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


int main(){
	
	long zahl;
	long max;
	long anz;
	int prozessnr;
	
	pid_t pid=fork();
	if (pid==-1){
		exit(-1);
	}else{
		prozessnr=getpid();
		if (pid==0){
			max=3000000;
			printf("Child: pid=%d; ppid=%d\n",prozessnr,getppid());
		}else{
			max=2000000;
			printf("Parent: pid=%d\n",prozessnr);
		}
	}
	
	anz=0;
	for (zahl=2; zahl<=max; zahl++){
		if (isPrime(zahl)){
			if (++anz%5000==0) printf("Prozess %d: Primzahl gefunden: %ld\n",prozessnr,zahl);
		}
	}

	if (pid==0){
		exit(1);
	}else{
		int childstatus;
		wait(&childstatus);
		if (WIFEXITED(childstatus)) childstatus=WEXITSTATUS(childstatus); else childstatus=WTERMSIG(childstatus);
		printf("Child-Prozess beendet (Status: %d)\n",childstatus);
	}

}
