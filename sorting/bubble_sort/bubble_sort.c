#include <stdio.h>

// The above function always runs O(n^2) time even if the array is sorted.
// It can be optimized by stopping the algorithm if inner loop didn’t cause any swap. 
//
// Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
// Auxiliary Space: O(1)
// Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
// Sorting In Place: Yes
// Stable: Yes
int bubble_sort(int * array, int array_size) {
    int temp;
    for (int i = 0; i < array_size - 1; i++){
        for (int j = 0; j < array_size - i - 1; j++){
            // if the current index is bigger than the next one, swap
            // {5,1,4,2,8};
            //  i j
            // {1,5,4,2,8};
            if (array[j] > array[j+1]){
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void print(int * array, int array_size) {
    for (int i = 0; i < array_size;i++) {
        printf("%d\n",array[i]);
    }
}

int main(){

    int input[] = {5,1,4,2,1};
    int input_size = sizeof(input)/sizeof(input[0]);
    print(input, input_size);
    bubble_sort(input, input_size);
    printf("after sorting: \n");
    print(input, input_size);
    return 0;
}