
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>


#define forever while(1)







int main(int argc,char *argv[]){
	char z=0;
	FILE *datei=fopen(argv[1],"a");
	forever{
		z=fgetc(stdin);
		if (z==EOF) break;
		fputc(z,datei);
	}
	fclose(datei);
	kill(atol(argv[2]),SIGUSR1);
	return(0);
}
