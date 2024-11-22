nclude <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if (pid > 0)
	{ //Parent Process Code
		sleep(20); //wait for 20 seconds
		printf(“The process ID of the parent is: %d \n”, getpid());
	}
	else if (pid == 0)
	{ //Child process code
		printf(“The process ID of the child is: %d \n”, getpid());
exit(0); // Exit the child process
	}
	else
	{ //Forking failed
		printf(“Forking failed!\n”);
		exit(1);
	}
	return 0;
}
