#include <stdio.h>
#include <string.h>

char pixels[200]; // Store the pixel information from "pixels.txt"
char compressed[200]; // Store the compressed pixel information

int read(void);
int  write(void);
void encode(void);

int main(){
  if(read() == 1) return 1;
  encode();
  if(write() == 1) return 1;

  return 0;
}

int read(void){
  FILE *readFile;
  readFile = fopen("pixels.txt", "r");

  if(readFile == NULL){
    printf("File cannot be opened or does not exist.\n");
    return 1; //Return error
  }

  // Copy the content of file to array
  int count = 0;
  char c;
  while((c = fgetc(readFile)) != EOF){
    pixels[count++] = c;
  }

  pixels[count] = '\0';

  //Close opened file
  if(readFile) fclose(readFile);
  return 0;
}

int write(void){
  FILE *writeFile;
  writeFile = fopen("compressed.txt", "w");

  if(writeFile == NULL){
    printf("File cannot be opened or does not exist.\n");
    return 1; //Return error
  }

  char c;
  int i = 0;
  while((c = compressed[i++]) != '\0'){
    fputc(c, writeFile);
  }

  if(writeFile) fclose(writeFile);
  return 0;
}

void encode(void){
    int count = 0;
    int compressedCounter = 0;
    char lastcharacter = '1';
    for (int i = 0; pixels[i] != '\0'; i++){
        if (pixels[i] != '\n'){
            if (pixels[i] != lastcharacter) {
                compressed[compressedCounter] = count + 48;
                compressedCounter++;
                count = 0;
            
        
            }

            if (pixels[i+1] == '\0'){
                compressed[compressedCounter] = count + 48 + 1;
            }
            
            lastcharacter = pixels[i];
            count++;
        }
        else {
            lastcharacter = pixels[i-1];
        }
    }

}