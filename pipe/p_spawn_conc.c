#include <stdio.h>
#include <spawn.h>
#include <sys/wait.h>

extern char **environ;
//it combineoffork+exec

int main()
{
    pid_t pid;

    char *argv[] = {"date", NULL};

    printf("Parent: Before spawn\n");

    posix_spawn(  &pid,"/bin/date",  NULL,NULL,argv,environ   );

    waitpid(pid, NULL, 0);

    printf("Parent: After spawn\n");

    return 0;
}
