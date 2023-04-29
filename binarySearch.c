#include<stdio.h>
#include <stdlib.h>

int binarySearch(int array[], int x, int low, int high) {
  // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main() {
    int n,key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter key: ");
    scanf("%d", &key);

    int num = binarySearch(arr, key, 0, n);
    printf("Number found at index: %d", num);
    

    free(arr);

    return 0;
}
