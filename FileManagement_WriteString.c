#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char str[80];
  char fileName[80];
  printf("Enter a name of file\n");
  scanf("%s",fileName);
  FILE *fp;	

  if((fp = fopen(fileName, "w"))==NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }

   printf("Enter a string \n");
    scanf("%s",str);
    strcat(str, "\n");  /* add a newline */
    fputs(str, fp);
 

  return 0;
}
