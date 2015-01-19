
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>







int main(int argc,char* argv[]){
	
	char* prog_berechnung="signale_primzahlenberechnung";
	char* prog_sendung="signale_signalsendung";
    
    char arg1[20],arg2[20];
	long abstand;
	long endwert;
	if (argc>=2){
		abstand=atol(argv[1]);
	}else{
		printf("Abstand? ");
		scanf("%d",&abstand);
	}
	if (argc>=3){
		endwert=atol(argv[2]);
	}else{
		printf("Endwert? ");
		scanf("%d",&endwert);
	}

	pid_t pid1=fork();
	if (pid1==-1){
		exit(-1);
	}else{
		if (pid1==0){
			char *args_neu[]={prog_berechnung,"","",NULL};
			sprintf(arg1,"%d",abstand);
			args_neu[1]=arg1;
			sprintf(arg2,"%d",endwert);
			args_neu[2]=arg2;
			execv(prog_berechnung,args_neu);
			printf("execv-Fehler\n");
			return -1;
		}else{
			pid_t pid2=fork();
			if (pid2==-1){
				exit(-1);
			}else{
				if (pid2==0){
					char *args_neu2[]={prog_sendung,"",NULL};
					sprintf(arg1,"%d",pid1);
					args_neu2[1]=arg1;
					execv(prog_sendung,args_neu2);
					printf("execv-Fehler\n");
					return -1;
				}else{
					pid_t childendpid;
					int childendstatus;
					int wc;
					for (wc=1; wc<=2; wc++){
						childendpid=wait(&childendstatus);
						if (WIFEXITED(childendstatus)) childendstatus=WEXITSTATUS(childendstatus); else childendstatus=WTERMSIG(childendstatus);
						printf("Child-Prozess beendet (PID: %d; Status: %d)\n",childendpid,childendstatus);
					}
				}
			}
		}
	}
	
}
