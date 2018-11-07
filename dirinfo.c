#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void dir(char * path){
  DIR * stream = opendir(path);
  if (errno != 0){
    printf("Error: %s\n", strerror(errno));

  } else {
  struct dirent * entry;
  entry = readdir(stream);
  //struct stat * info = malloc(sizeof(struct stat));
  //stat("Gondal.Adil.txt",info);
  printf("PERMISSIONS---------FILESIZE-------FILENAME\n");
  char permissions[8][4] = {"---","--x","-w-","-wx","r--","r-x","rw-","rwx"};
  long int totSize = 0;

  /*
  struct stat * info = malloc(sizeof(struct stat));
  stat(entry -> d_name,info);
  printf("%o\n",info->st_mode);
  */

  while(entry){
    struct stat * info = malloc(sizeof(struct stat));
    stat(entry -> d_name,info);
    //printf("%o        ",info->st_mode);
    int u = ((info->st_mode)/64)%8;
    int g = ((info->st_mode)/8)%8;
    int o = ((info->st_mode))%8;
    char user[4];
    if(S_ISDIR(info->st_mode)){
      printf("d");
    }
    else{
      printf("-");
    }
    printf("%s",permissions[u]);
    printf("%s",permissions[g]);
    printf("%-13s",permissions[o]);
    long int size = info ->st_size;
    printf("%-15ld",size);
    printf("%s\n",entry -> d_name);

    totSize+= size;
    free(info);
    entry = readdir(stream);
    //dir(readdir(stream));
  }

  closedir(stream);

  printf("Total Diectory Size: %ld Bytes\n",totSize);
  }
}
int main(int argc, char *argv[]){
  char dirname[100];
  if(argc > 1){
    strcpy(dirname,argv[1]);
  }
  else{
    char temp[100];
    printf("Type in valid path:\n");
    scanf("%s", temp);
    printf("%s\n",temp);
    strcpy(dirname,temp);
  }

  dir(dirname);
  return 0;
}
