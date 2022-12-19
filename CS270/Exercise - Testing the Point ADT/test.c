

#include <stdio.h>

int main() {
   char s[] = "SPDLPO", *p;
   for (p = s; *p; p++) {
      --*p;
   }
   puts(s);
   return 0;
}