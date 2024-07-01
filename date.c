#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    time_t lt;
    struct tm *tim;
    time(&lt);
    tim=gmtime(&lt);
    time_t utctime=mktime(tim);
    char s[100];
    memset(s,0,sizeof(s));

    tim=localtime(&lt);
    strftime(s, sizeof(s),"Date in localtime format is %F", tim);
    


    if (argc == 1)
    {
        printf("local time is %s",ctime(&lt));
        exit(EXIT_FAILURE);
    }
    else if (argc == 2)
    {   
        if((int)strlen(argv[1])!=2){
            puts("invalid expression");
            exit(EXIT_FAILURE);
        }
        if (argv[1][0] == '-')
        {
            
                if(argv[1][1] == '-'){
                    printf("Invalid expression");
                    exit(EXIT_FAILURE);
                }
                if (argv[1][1] == 'u')
                {
                    printf("UTC time is %s",ctime(&utctime));
                    exit(EXIT_FAILURE);
                }
                else if (argv[1][1] == 'R')
                {
                    printf("local time is %s",ctime(&lt));
                    exit(EXIT_FAILURE);
                }
                else
                {
                    printf("Invalid option\n");
                    exit(EXIT_FAILURE);
                }
            }
        else
        {
            printf("Inavlid option\n");
            exit(EXIT_FAILURE);
        }
    }
    else if (argc == 3)
    {   
        if((int)strlen(argv[1])!=2 || (int)strlen(argv[2])!=2){
            puts("invrlid expression");
            exit(EXIT_FAILURE);
        }
        
        if (argv[1][0] == '-' && argv[2][0] == '-')
        {if(argv[1][1]=='u' && argv[2][1]=='R' || argv[1][1]=='R' && argv[2][1]=='u')
             printf("UTC time is %s",ctime(&utctime));
                    exit(EXIT_FAILURE);
            }
        else{
            printf("invalid option");
            exit(EXIT_FAILURE);
        }
    }
    else{
        perror("TOO many arguments");
        exit(EXIT_FAILURE);
    }

    return 0;
}