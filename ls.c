#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,const char *argv[]){
    if(argc==1){
        int op_a=0;
        int op_l=0;
        struct dirent *d;
        DIR *dh=opendir(".");
        if(!dh){
            if(errno=ENOENT){
                perror("DIRECTORY NOT FOUND");
            }else{
                perror("UNABLE TO READ DIRECTORY");
            }
            exit(EXIT_FAILURE);
        }

        while((d=readdir(dh))!=NULL){
            if(!op_a && d->d_name[0]=='.')
                continue;
            printf("%s ",d->d_name);

            if(op_l)
                printf("\n");
        }
    }
    else if(argc==2)
    {
        if((int)strlen(argv[1])==2 && argv[1][0]=='-')
        {
            int op_a=0;
            int op_l=0;
                if(argv[1][1]=='a'){
                    op_a=1;
                    struct dirent *d;
                    DIR *dh=opendir(".");
                    if(!dh){
                        if(errno=ENOENT){
                            perror("DIRECTORY NOT FOUND");
                        }else{
                            perror("UNABLE TO READ DIRECTORY");
                        }
                        exit(EXIT_FAILURE);
                    }

                    while((d=readdir(dh))!=NULL){
                        if(!op_a && d->d_name[0]=='.')
                            continue;
                        printf("%s ",d->d_name);
                    }
                }
                else if(argv[1][1]=='l'){
                    op_l=1;
                    struct dirent *d;
                    DIR *dh=opendir(".");
                    if(!dh){
                        if(errno=ENOENT){
                            perror("DIRECTORY NOT FOUND");
                        }else{
                            perror("UNABLE TO READ DIRECTORY");
                        }
                        exit(EXIT_FAILURE);
                    }

                    while((d=readdir(dh))!=NULL){
                        if(!op_a && d->d_name[0]=='.')
                            continue;
                        printf("%s ",d->d_name);

                        if(op_l)
                            printf("\n");
                    }
                }else{
                    perror("not extra option available");
                    exit(EXIT_FAILURE);
                }
        }


        else if((int)strlen(argv[1])>2){
            perror("invalid option");
            exit(EXIT_FAILURE);
        }
    }else{
        perror("Too many arguments");
        exit(EXIT_FAILURE);
    }
    return 0;
}