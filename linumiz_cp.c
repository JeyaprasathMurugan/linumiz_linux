#include<stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER 2048


void copy (char* source , char* dest){

 FILE* source_file , *desti_file ;
char buffer[BUFFER];
int nbyte;

 source_file=fopen(source,"rb");

 if(source_file == NULL){
  printf("file not found or permission denied");
  exit(EXIT_FAILURE);
 }

desti_file = fopen(dest,"wb");

if(desti_file == NULL){
    printf("access denied");
    exit(EXIT_FAILURE);
}


while((nbyte = fread(buffer,1,BUFFER,source_file)) > 0){

if ((fwrite(buffer, 1, nbyte, desti_file)) != nbyte) {
    fclose(source_file);
    fclose(desti_file);
    printf("writing error occurred\n");
    exit(EXIT_FAILURE);
}


}
        fclose(source_file);
        fclose(desti_file);


}


void main(int arg_count ,  char* com_arr[]){

if(arg_count != 3){
    printf("invalid number of arguments");
}

copy(com_arr[1],com_arr[2]);


}