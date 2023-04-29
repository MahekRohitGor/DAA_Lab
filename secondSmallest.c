#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, i;
  int *arr;

  // Get the number of elements in the array
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  // Allocate memory for the array
  arr = malloc(n * sizeof(int));

  // Get the elements of the array
  printf("Enter %d integers: ", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Find the second smallest number
  int min1 = arr[0];
  int min2 = arr[1];
  if (min2 < min1) {
    int temp = min1;
    min1 = min2;
    min2 = temp;
  }
  for (i = 2; i < n; i++) {
    if (arr[i] < min1) {
      min2 = min1;
      min1 = arr[i];
    } else if (arr[i] < min2 && arr[i] != min1) {
      min2 = arr[i];
    }
  }

  // Print the result
  printf("The second smallest number is %d\n", min2);

  // Free the memory
  free(arr);

  return 0;
}

