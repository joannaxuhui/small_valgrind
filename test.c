#include <stdlib.h>
#include <stdio.h>
#include "mini_valgrind.h"
int main() {
  // your tests here using malloc and free

  // Do NOT modify this line
	char* ptr1 =(char*)malloc(1000);
      ptr1[1]='k';
	free(ptr1);
     
  char* ptr4=(char*)malloc(10);
  int invalid;
    
     free(ptr4);
    free(ptr4);
   
     free(&invalid);
   char* ptr5=malloc(100);
   ptr5[0]='p'; 
char* o = malloc(198);
o[1]='a';

char* ppp = malloc (200);
ppp[0]= 'a';
  atexit(print_report);
  return 0;
}
