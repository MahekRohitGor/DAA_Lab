#include <stdio.h>

int main() {
  int n, i;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements of the array: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int max1 = -999999, max2 = -999999;
  for (i = 0; i < n; i++) {
    if (arr[i] > max1) {
      max2 = max1;
      max1 = arr[i];
    } else if (arr[i] > max2 && arr[i] != max1) {
      max2 = arr[i];
    }
  }
  printf("The second largest number is %d\n", max2);
  return 0;
}
