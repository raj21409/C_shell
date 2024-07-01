#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
void _rm(int x,int y,int argc,char *argv[]){
    
}

int main(int argc, char *argv[])
{
  int perm;
  int direct;
  int m;
  if (argc == 1)
  {
    perror("Missing operand");
    exit(EXIT_FAILURE);
  }

  else if (argc == 2)
  {
    if ((int)strlen(argv[1])==1 && argv[1][0]=='-')
    {
      perror("Operand missing\n");
      exit(EXIT_FAILURE);
    }
    else if((int)strlen(argv[1])>1)
    {
      int status;
      status = remove(argv[1]);
      if (status==0)
      {
        printf("removed '%s\n'", argv[1]);
      }
      else{
        switch (errno)
      {
        case EACCES:
          printf("rm: cannot remove '%s': Permission denied\n",argv[1]);
          break;

        case EISDIR:
          printf("rm: cannot remove '%s': Is a directory\n",argv[1]);
          break;

        case ENOENT:
            printf("rm: cannot remove '%s': No such file or directory\n",argv[1]);
      }
      }
    }
  }
  else if(argc==3){
        if((int)strlen(argv[1])==1 &&argv[1][0]=='-'){
                perror("Operand missing\n");
                exit(EXIT_FAILURE);
              }
        else if((int)strlen(argv[1])>1){
          if(argv[1][0]=='-'&& argv[1][1]=='v' && (int)strlen(argv[1])==2|| !strcmp(argv[1],"--verbose") ){
              perm=1;
          }else if(argv[1][0]=='-'&&argv[1][1]=='f' && (int)strlen(argv[1])==2 || !strcmp(argv[1],"--force")){
              direct=1;
          }else{
            perror("invalid expression");
            exit(EXIT_FAILURE);
          }
          if(perm==1){
             
            int status;
            status = remove(argv[2]);
            if (status == 0)
            {
              printf("removed '%s\n'", argv[2]);
            }
            else
            {
              switch (errno)
            {
              case EACCES:
                printf("rm: cannot remove '%s': Permission denied\n",argv[2]);
                break;

              case EISDIR:
                printf("rm: cannot remove '%s': Is a directory\n",argv[2]);
                break;

              case ENOENT:
                  printf("rm: cannot remove '%s': No such file or directory\n",argv[2]);
            }
            }
          }
          if(direct==1){
            remove(argv[2]);
          }
          }
        }

}
    
  
  // else if (argc == 2)
  // {
  //   if (argv[1][0] == '-')
  //   {
  //     printf("Missing operand\n");
  //     exit(EXIT_FAILURE);
  //   }
  //   else
  //   {
  //     int status;
  //     status = remove(argv[1]);
  //     if (status)
  //     {
  //       switch (errno)
  //     {
  //       case EACCES:
  //         printf("rm: cannot remove '%s': Permission denied\n",argv[1]);
  //         break;

  //       case EISDIR:
  //         printf("rm: cannot remove '%s': Is a directory\n",argv[1]);
  //         break;

  //       case ENOENT:
  //           printf("rm: cannot remove '%s': No such file or directory\n",argv[1]);
  //     }
  //     }
  //   }
  // }
//   else if (argc == 3)
//   {
//     if ((argv[1][0] == '-' && argv[1][1] == 'v' && (strlen(argv[1]) == 2)) || !strcmp(argv[1], "--verbose"))
//     {
//       int status;
//       status = remove(argv[2]);
//       if (status == 0)
//       {
//         printf("removed '%s\n'", argv[2]);
//       }
//       else
//       {
//         switch (errno)
//       {
//         case EACCES:
//           printf("rm: cannot remove '%s': Permission denied\n",argv[1]);
//           break;

//         case EISDIR:
//           printf("rm: cannot remove '%s': Is a directory\n",argv[1]);
//           break;

//         case ENOENT:
//             printf("rm: cannot remove '%s': No such file or directory\n",argv[1]);
//       }
//       }
//     }
//     else if ((argv[1][0] == '-' && argv[1][1] == 'f' && (strlen(argv[1]) == 2)) || !strcmp(argv[1], "--force"))
//     {
//       remove(argv[2]);
//     }
//   }
//   return 0;
// }