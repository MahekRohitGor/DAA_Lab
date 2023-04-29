#include <stdio.h>
#include <stdlib.h>

int Linear(int *arr, int n, int key) {
    	for(int i=0; i<n; i++){
    		if(arr[i] == key){
    			return i;
    		}
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

    int num = Linear(arr, n, key);
    printf("Number found at index: %d", num);
    

    free(arr);

    return 0;
}

