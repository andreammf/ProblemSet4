
#include <stdio.h>
#include <string.h>

char pixels[200];
char compressed[200];

int read(void);
int  write(void);
void decode(void);

int main(){
  if(read() == 1) return 1;
  decode();
  if(write() == 1) return 1;

  return 0;
}

int read(void){
  FILE *readFile;
  readFile = fopen("compressed.txt", "r");

  if(readFile == NULL){
    printf("File cannot be opened or does not exist.\n");
    return 1; //Return error
  }

  // Copy the content of file to array
  int count = 0;
  char c;
  while((c = fgetc(readFile)) != EOF){
    compressed[count++] = c;
  }

  compressed[count] = '\0';

  //Close opened file
  if(readFile) fclose(readFile);
  return 0;
}

int write(void){
  FILE *writeFile;
  writeFile = fopen("pixelsDecompressed.txt", "w");

  if(writeFile == NULL){
    printf("File cannot be opened or does not exist.\n");
    return 1; //Return error
  }

  char c;
  int i = 0;
  while((c = pixels[i++]) != '\0'){
    fputc(c, writeFile);
  }

  if(writeFile) fclose(writeFile);
  return 0;
}

void decode(void){
  int n = strlen(compressed);
  int col = 0;
  int letter = 1;
  for (int i = 0; i < n; i++) {
    int freq = compressed[i]-'0';
    for (int j = 0; j < freq; j++) {
      printf("%c", letter+'0');
      col++;
      if (col == 9) {
          col = 0;
          printf("\n");
      }
    }
    letter = 1-letter;
  }
}