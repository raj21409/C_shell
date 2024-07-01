#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <pthread.h>
#define MAX 1000
#define MAX1 1056


int main()
{
	while (1)
	{
		char *input = malloc(1024 * sizeof(char));
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		printf("Dir: %s", cwd);
		char **args = malloc(1024 * sizeof(char *));

		input = readline("\n$ ");
		
		{
			
			int i = 0;
			int flag = 0;
			char *path = (char *)calloc(FILENAME_MAX, sizeof(char));
			char *token = strtok(input, " ");
			int count = 0;
			while (token != NULL)
			{
				args[count] = token;
				count++;
				token = strtok(NULL, " ");
			}
			if (!strcmp(args[0], "ls"))
			{
				strcpy(path, "./ls");
				flag = 1;
			}
			else if (!strcmp(args[0], "cat"))
			{
				strcpy(path, "./cat");
				flag = 1;
			}
			else if (!strcmp(args[0], "date"))
			{
				strcpy(path, "./date");
				flag = 1;
			}
			else if (!strcmp(args[0], "rm"))
			{
				strcpy(path, "./rm");
				flag = 1;
			}
			else if (!strcmp(args[0], "ls&t"))
			{
				strcpy(path, "./ls");
				flag = 2;
			}
			else if (!strcmp(args[0], "cat&t"))
			{
				strcpy(path, "./cat");
				flag = 2;
			}
			else if (!strcmp(args[0], "date&t"))
			{
				strcpy(path, "./date");
				flag = 2;
			}
			else if (!strcmp(args[0], "rm&t"))
			{
				strcpy(path, "./rm");
				flag = 2;
			}
			else if (!strcmp(args[0], "cd"))
			{
				chdir(args[1]);
			}
			else if (!strcmp(args[0], "pwd"))
			{
				if(count == 1){
					printf("%s",getenv("PWD"));
				}
				if (count > 2)
				{
					printf("Invalid number of arguments");
				}
				else if (count == 2)
				{
					if(args[1] == "-L"){
						printf("%s",getenv("PWD"));
					}else if(args[1] == "-P"){
						char wd[1000];
						printf("%s", getcwd(wd,sizeof(wd)));
					}else{
						printf("Invalid options");
					}
				}
			}
			else if (!strcmp(args[0], "echo"))
			{
				if (!strcmp(args[1], "-E"))
				{
					for (int i = 2; i < count; i++)
					{
						printf("%s ", args[i]);
					}
					printf("\n");
				}
				if (!strcmp(args[1], "-n"))
				{
					for (int i = 2; i < count; i++)
					{
						printf("%s ", args[i]);
					}
				}
				else
				{
					for (int i = 1; i < count; i++)
					{
						printf("%s ", args[i]);
					}
					printf("\n");
				}
			}
			else if (!strcmp(args[0], "exit"))
			{
				break;
			}

			if (flag == 2)
			{
				pthread_t id;
				char *com = malloc(100);
				strcpy(com, path);
				for (int i = 1; i < count; i++)
				{
					strcat(com, " ");
					strcat(com, args[i]);
				}
				pthread_create(&id, NULL, (void *)system, com);
				pthread_join(id, NULL);
			}

			if (flag == 1)
			{

				pid_t pid;
				pid = fork();
				int status;
				if (pid < 0)
				{
					puts("Forking Error");
					exit(EXIT_FAILURE);
				}
				else if (pid == 0)
				{
					execvp(path, args);
					exit(EXIT_FAILURE);
				}
				else
				{
					wait(&status);
				}
			}
		}
		free(args);
	}
}