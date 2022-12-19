#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    
    int i;
    char str[16];
/* below written code is for dynamic allocation of the memory*/
//     char *str; 
//     str = (char *) malloc(sizeof(char) * 15);
//     if (str == NULL) {
//     printf("Error: malloc failed\n");
//     exit(1);
// }

    strcpy(str, "tire-bouchon");
    strcpy(&str[4], "d-or-wi");
    strcat(str, "red?");

    for (i=0; i<16; i++){
        printf("%c", str[i]);
    }

    return 0;
}
