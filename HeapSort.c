#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int *arr, int i, int n) {
    int left = 2*i;
    int right = 2*i + 1;
    int largest;
    if (left <= n && arr[left-1] > arr[i-1]) {
        largest = left;
    } else {
        largest = i;
    }
    if (right <= n && arr[right-1] > arr[largest-1]) {
        largest = right;
    }
    if (largest != i) {
        int temp = arr[i-1];
        arr[i-1] = arr[largest-1];
        arr[largest-1] = temp;
        maxHeapify(arr, largest, n);
    }
}

void build_max_heap(int *arr, int n) {
    for (int i = n/2; i >= 1; i--) {
        maxHeapify(arr, i, n);
    }
}

void heapSort(int *arr, int n) {
    build_max_heap(arr, n);
    for (int i = n; i >= 2; i--) {
        int temp = arr[0];
        arr[0] = arr[i-1];
        arr[i-1] = temp;
        n = n - 1;
        maxHeapify(arr, 1, n);
    }
}

int main() {
    printf("Enter number of elements: ");
    int n;
    scanf("%d", &n);

    int *arr = (int *) malloc(n * sizeof(int));
    if (arr != NULL) {
        printf("Enter %d integers:\n", n);
        for (int i = 0; i < n; i++)
            scanf("%d", arr+i);
        heapSort(arr, n);
        printf("Sorted array:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", *(arr+i));
        printf("\n");
        free(arr);
    }

    return 0;
}

