 /*  
  *  part2
  *  Roshan Poudel
  *  HW1 #Q2, 9/15/2022 
  */


#include <stdio.h>

int find_first(int a[], int target, int n);

int main(){

    int whereval;

    int arr[5] = {12, 323, 1, 2, 20};

    whereval = find_first(arr, 323, 5); //testing where 323 is in the array

    printf("The required index is %d\n", whereval);

    return 0;
}


int find_first(int a[], int target, int n) 

{
    int i, returnval;

    for (i=0; i <= n-1; i++){
        if (a[i]== target){
            returnval = i;
            break;
        }
        else 
        {
            returnval = -1;
        }
    }
    return returnval;
}
