#include<stdio.h>
#include<string.h>

int main() {
    const char *str= "Hello, World!";
    const char ch = 'o';
    const char *found=strchr(str,ch);
    if(found != NULL) {
      printf("Found '%c' at position: %ld\n", ch,found - str);
    } else {
      printf("‘%c’ not found in string.\n",ch);
    }
    return 0;
}
