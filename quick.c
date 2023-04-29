#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int low, int high){
	int pivot = arr[high];
	int i = low-1;
	for(int j=low; j<=high-1; j++){
		if(arr[j] <= pivot){
			i++;
			int m = arr[i];
			arr[i] = arr[j];
			arr[j] = m;
		}
	}
	
	int n = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = n;
	
	return i+1;
}

void quickSort(int *arr, int low, int high){
	if(low < high){
		int q = partition(arr, low, high);
		quickSort(arr, low, q-1);
		quickSort(arr, q+1, high);
	}
}

int main(){
    printf("Enter number of elements: ");
    int n; 
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if(arr != NULL) {
        printf("Enter %d integers:\n", n);
        for(int i = 0; i < n; i++)
            scanf("%d", arr+i);
        quickSort(arr, 0, n-1);
        printf("Sorted array:\n");
        for(int i = 0; i < n; i++)
            printf("%d ", *(arr+i));
        printf("\n");
        free(arr);
    }
	
	


return 0;
}
