#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
typedef unsigned char BYTE;

int main(int argc, char* argv[]){
char *filename;
unsigned long i;
int mod;
size_t fileSize;
FILE *file;
void *p;
BYTE encryptedByte;
char key[]= "bhUlIshutrea98liOp";
size_t keyLen;

filename = argv[1];

file = fopen(filename,"rb");
if(file==(FILE*)0x0){
	printf("Error opening file\n");
	return 1;
}
fseek(file,0,2);
fileSize = ftell(file);
rewind(file);
p=malloc(fileSize);
fread(p,1,fileSize,file);
fclose(file);
keyLen = strlen(key);
for(i=0;mod=i, (long)i<(long)fileSize; i++){
	encryptedByte = *(BYTE*)((long)p+i);
	printf("%c",(encryptedByte)^key[mod%keyLen]);
}


free(p);
return 0;
}
