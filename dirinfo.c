#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

void dir(char * path){
  DIR * stream = opendir(path);
  struct dirent * entry;
  entry = readdir(stream);
  printf("%s",entry -> d_name);
  //dir(readdir(stream));

}
int main(){
  dir("./");
  return 0;
}
