//Suppose you are given an array 𝐴 with 𝑛 entries, with each entry holding a distinct 
//number. You are told that the sequence of values 𝐴[1], 𝐴[2], . . . , 𝐴[𝑛] is unimodal. That 
//is, for some index 𝑝 between 1 and 𝑛, the values in the array entries increase up to 
//position 𝑝 in 𝐴 and then decrease the remainder of the way until position 𝑛. (So if you 
//were to draw a plot with the array position 𝑗 on the 𝑥-axis and the value of the entry 
//𝐴[𝑗] on the 𝑦-axis, the plotted points would rise until 𝑥-value 𝑝, where they’d achieve 
//their maximum value, and then fall from there on). You’d like to find the “peak entry” 
//𝑝 without having to read the entire array - in fact, by reading as few entries of 𝐴 as 
//possible. Show how to find the entry 𝑝 by reading at most 𝑂(𝑙𝑜𝑔 𝑛) entries of A

#include <stdio.h>

int find_peak(int A[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if ((mid == 0 || A[mid - 1] <= A[mid]) && (mid == n - 1 || A[mid + 1] <= A[mid])) {
            return mid;
        }
        else if (mid > 0 && A[mid - 1] > A[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int A[] = { 1, 2, 5, 4, 3, 2 };
    int n = sizeof(A) / sizeof(A[0]);
    int peak_index = find_peak(A, n);
    if (peak_index != -1) {
        printf("Peak element found at index %d with value %d\n", peak_index, A[peak_index]);
    }
    else {
        printf("No peak element found in the array\n");
    }
    return 0;
}
