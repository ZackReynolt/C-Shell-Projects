
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>

#define forever while(1)




void Ausgabe(){};



int main(int argc,char *argv[]){

	signal(SIGUSR1,Ausgabe);	
	sighold(SIGUSR1);	
	
	kill(getppid(),SIGUSR1);
	sigpause(SIGUSR1);
	
	char z=0;
	FILE *datei=fopen(argv[1],"r");
	forever{
		z=fgetc(datei);
		if (z==EOF) break;
		fputc(z,stdout);
	}
	fclose(datei);
	return(0);
}
