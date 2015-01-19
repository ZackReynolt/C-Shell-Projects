
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>







void unfug(){{{}}};




int main(int argc,char *argv[]){

    signal(SIGUSR1,unfug);
	sighold(SIGUSR1);

	char* prog_child1="dateien_child1";
	char* prog_child2="dateien_child2";

	char arg1[20],arg2[20];
	char dateiname[100];
	if (argc<2){
		scanf("%s",dateiname);
	}else{
		strcpy(dateiname,argv[1]);
	}


	pid_t pid1=fork();
	if (pid1==-1){
		exit(-1);
	}else{
		if (pid1==0){
			char *args_neu[]={prog_child1,"",NULL};
			sprintf(arg1,"%s",dateiname);
			args_neu[1]=arg1;
			execv(prog_child1,args_neu);
			perror("execv-Fehler");
			return -1;
		}else{
			sigpause(SIGUSR1);
			pid_t pid2=fork();
			if (pid2==-1){
				exit(-1);
			}else{
				if (pid2==0){
					char *args_neu2[]={prog_child2,"","",NULL};
					sprintf(arg1,"%s",dateiname);
					args_neu2[1]=arg1;
					sprintf(arg2,"%d",pid1);
					args_neu2[2]=arg2;
					execv(prog_child2,args_neu2);
					perror("execv-Fehler");
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
