#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    int e = 0, n = 0, flag = 0;
    if(argc==1){
        perror("Missing operand");
        exit(EXIT_FAILURE);
    }
    else if(argc==2){
        FILE *fptr;
        int count = 1;
        while(count!=argc){
            fptr = fopen(argv[count], "r");
            int a=1;
            char ch[100000];
            char ch1[10000];
            char temp[100000];
            while ((fgets(ch, 10000, fptr)))
                {
                    // if (n)
                    // {
                    //     printf("%d  ", a);
                    //     a++;
                    // }
                    printf("%s", ch);
                }
                count++;
        }
    }
    else if (argc==3 && argv[1][0] == '-')
    {
        if (argv[1][1] == 'n')
        {
            n = 1;
        }
        else if (argv[1][1] == 'E')
        {
            e = 1;
        }
        else
        {
            printf("This option is not available");
            exit(EXIT_FAILURE);
        }

        if(n==1){
            
            FILE *fptr;
            int count = 2;
            while(count!=argc){
                fptr = fopen(argv[count], "r");
                int a=1;
                char ch[100000];
                char ch1[10000];
                char temp[100000];
                while ((fgets(ch, 10000, fptr)))
                    {
                        if (n)
                        {
                            printf("%d  ", a);
                            a++;
                        }
                        printf("%s", ch);
                    }
                    count++;
            }
        }else if(e==1){
            FILE *fptr;
            int count = 2;
            
            while (count != argc)
            {

                int count1 = 1;
                int count2 = 0;
                fptr = fopen(argv[count], "r");
                char ch[100000];
                char ch1[100000];
                char temp[100000];

                int v = 0;
                while ((fgets(ch, 100000, fptr)))
                {
                    v++;
                }
                fclose(fptr);
                fptr = fopen(argv[count], "r");
                int i = 0;
                while ((fgets(ch, 100000, fptr)))
                {
                    strcpy(ch1, ch);
                    if (i == v - 1)
                    {
                        printf("%s", ch1);
                    }
                    else
                    {
                        ch1[0] = '$';
                        printf("%s", ch1);
                        i++;
                    }
                }
                count++;
                }

        }
        else{
            printf("incorrect argument");
            exit(EXIT_FAILURE);
        }


    
    }
    else{
        perror("INVALID EXPRESSION");
        exit(EXIT_FAILURE);
    }

    return 0;
}