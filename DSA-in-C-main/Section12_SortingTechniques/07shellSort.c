#include<stdio.h>
#include<stdlib.h>

void shellSort(int A[], int n) {
    int gap, i, j, temp;

    // Start with a large gap, then reduce the gap
    for (gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size
        for (i = gap; i < n; i++) {
            temp = A[i];
            // Shift earlier gap-sorted elements up until the correct location for A[i] is found
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
                A[j] = A[j - gap];
            }
            A[j] = temp;
        }
    }
}

int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = 10, i;

    shellSort(A, n);

    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
