#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>

#define MAX_LEN_LINE    100
#define LEN_HOSTNAME    30

int main(void)
{
    char command[MAX_LEN_LINE];
    char *args[] = {command, NULL};
    int ret, status;
    pid_t pid, cpid;

    char hostname[LEN_HOSTNAME + 1];
    memset(hostname, 0x00, sizeof(hostname));
    printf("\x1b[46musername\x1b[0m: %s\n", getpwuid(getuid())->pw_name);

    gethostname(hostname, LEN_HOSTNAME);
    printf("\x1b[43mhostname\x1b[0m: %s\n", hostname);

    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\x1b[42mcwd\x1b[0m: %s\n", cwd);


    while (true) {
        char *s;
        int len;

        printf("MyShell $ ");	
	s = fgets(command, MAX_LEN_LINE, stdin);
	if (s == NULL) {
            fprintf(stderr, "fgets failed\n");
            exit(1);
        }
        
        len = strlen(command);
        printf("%d\n", len);
        if (command[len - 1] == '\n') {
            command[len - 1] = '\0'; 
        }
        
        printf("[%s]\n", command);

	if (!strcmp(args[0], "exit")) {
		break;
	}
      
        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } 
        if (pid != 0) {  /* parent */
            cpid = waitpid(pid, &status, 0);
            if (cpid != pid) {
                fprintf(stderr, "waitpid failed\n");        
            }
            printf("Child process terminated\n");
            if (WIFEXITED(status)) {
                printf("Exit status is %d\n", WEXITSTATUS(status)); 
            }
        }
        else {  /* child */
            ret = execve(args[0], args, NULL);
            if (ret < 0) {
                fprintf(stderr, "execve failed\n");   
                return 1;
            }
        } 
    }
    return 0;
}
