#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(){
	int fd[2];
	pid_t pid;
	char buffer[100];

	pipe(fd);
	pid = fork();//fork has a child with pid of 0
	if(pid>0){
	close(fd[0]);
	char msg[]="Hello parent";
	write(fd[1], msg, strlen(msg)+1);
	close(fd[1]);
	}	
	else{ 
	close(fd[1]);	
	read(fd[0], buffer, sizeof(buffer));
	printf("child received:\n %s\n", buffer);
	close(fd[0]);
	}
return 0;
}
