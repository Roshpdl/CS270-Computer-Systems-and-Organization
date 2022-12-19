/*   
  *  Roshan Poudel
  *  HW1 #2 and #3 Programming Problem
  */

#include <stdio.h>

int find_first(int a[], int target, int n);

int main() {

    int whereval, i, trgt, loop;

    int arr[10];

    for (i=0; i<=9; i++){
        printf("Enter the %dst element for the array\n", i+1);
        scanf("%d", &arr[i]);
    }

    printf("The array you just made is shown below\n");
    for(loop = 0; loop < 10; loop++){
      printf("%d ", arr[loop]);}

    printf("\nNow enter the number you want to check if its in the array.\n");
    scanf("%d", &trgt);

    whereval = find_first(arr, trgt, sizeof(arr));

    printf("The number %d is in the index %d of array.\n", trgt, whereval);

    return 0;
}

int find_first(int a[], int target, int n) {

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