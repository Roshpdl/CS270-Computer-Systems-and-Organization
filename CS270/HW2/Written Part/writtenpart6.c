/*   
  *  Roshan Poudel
  *  
  */

#include <stdio.h>
#include <stdlib.h>

int *find_first(int *a, int target, int n);

int main() {
    
    int arr[5] = {10,20,30,40,50};
    int *whereval;

    whereval = find_first(arr, 30, 5);
    printf("The address is %p", whereval);

    return 0;
}

int *find_first(int *a, int target, int n) {

    int i, val;
    int *returnval;

    for (i=0; i <= n-1; i++){
        val = a[i];
        if (val == target){
            returnval = &a[i];
            break;
        }
        else 
        {
            returnval = NULL;
        }
    }
    return returnval;
}