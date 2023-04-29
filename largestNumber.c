#include <stdio.h>
#include <stdlib.h>

int Largest(int *arr, int n) {
    	int max = arr[0];
    	for(int i=0; i<n; i++){
    		if(arr[i] > max){
    			max = arr[i];
    		}
    	}
    	return max;
    }

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = Largest(arr, n);
    printf("Largest Number is: %d", max);
    

    free(arr);

    return 0;
}

