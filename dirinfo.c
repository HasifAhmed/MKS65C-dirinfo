#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

void dir(char * path){
  DIR * stream = opendir(path);
  struct dirent * entry;
  entry = readdir(stream);
  //struct stat * info = malloc(sizeof(struct stat));
  //stat("Gondal.Adil.txt",info);
  printf("MODE---------FILESIZE-------FILENAME\n");
  while(entry){
    struct stat * info = malloc(sizeof(struct stat));
    stat(entry -> d_name,info);
    printf("%o        ",info->st_mode);
    printf("%ld          ",info->st_size);
    printf("%s\n",entry -> d_name);
    entry = readdir(stream);
    //dir(readdir(stream));
  }
  closedir(stream);

}
int main(){
  dir(".");
  return 0;
}
