#include <stdio.h>

int addNumbers(int *fiveNumbers); /* declare function */

int main() {
  int array[5];
  int i;

  printf("Enter 5 integers separated by spaces: ");

  for(i=0 ; i<5 ; i++) {
    scanf("%d", &array[i]);
  }

  printf("\nTheir sum is: %d\n", addNumbers(array));
  return 0;
}

int addNumbers(int *fiveNumbers) { /* define function */
  int sum = 0;
  int i;

  for(i=0 ; i<5 ; i++) {
    sum+=fiveNumbers[i];            /* work out the total */
  }
  return sum;                       /* return the total   */
}
