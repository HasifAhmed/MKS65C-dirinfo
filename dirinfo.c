#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

extern int errno;

void dir(char * path){
  errno=0;
  DIR * stream;
  struct dirent * entry;
  struct stat * info = calloc(sizeof(struct stat),1);
  long int totSize = 0;
  char permissions[8][4] = {"---","--x","-w-","-wx","r--","r-x","rw-","rwx"};

  //THIS IS WHERE ERROR OCCURS
  if (opendir(path)== NULL & errno!=0){
    printf("\n**** Error With File Name : %s \n", strerror(errno));
    return;
  }
  else
    {
      stream = opendir(path);
      entry = readdir(stream);
    }
  printf("PERMISSIONS---------FILESIZE-------FILENAME\n");
  while(entry){
    stat(entry -> d_name,info);
    //printf("%o        ",info->st_mode);
    int u = ((info->st_mode)/64)%8;
    int g = ((info->st_mode)/8)%8;
    int o = ((info->st_mode))%8;
    //char user[4];
    if(S_ISDIR(info->st_mode)){
      printf("d");
    }
    else{
      printf("-");
    }
    printf("%s",permissions[u]);
    printf("%s",permissions[g]);
    printf("%-13s",permissions[o]);

    printf("%-15ld",info -> st_size);
    printf("%s\n",entry -> d_name);

    totSize+= info -> st_size;

    entry = readdir(stream);
    //dir(readdir(stream));
  }
  free(info);
  closedir(stream);

  printf("Total Diectory Size: %ld Bytes\n",totSize);

}
int main(int argc, char *argv[]){

  if(argc > 1){
    dir(argv[1]);
  }
  else{
    char dirname[100];
    printf("Type in valid path:\n");
    scanf("%s", dirname);
    dir(dirname);
  }


  return 0;
}
