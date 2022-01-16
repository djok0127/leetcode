#include <stdio.h>

// swap method
void swap(int * a, int * b){
    int temp;
    printf("swapping : %d %d\n", *a,*b);
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int * array, int low, int high){
    // pivot as the last element
    int pivot = array[high];
    int i = low;
    printf("partition indexes : %d %d\n", low,high);

    for (int j = low; j <= high - 1; j++){
        // if current element is less than pivot
        if (array[j] < pivot) {
            printf("current j: %d pivot :  %d\n", array[j], pivot);
            swap(&array[i], &array[j]);
            i++; // increment the index of the smaller element
        }
    }
    swap(&array[i], &array[high]);
    return (i);
}

void quick_sort(int * array, int low, int high) {
    printf("quicking sorting indexes : %d %d\n", low,high);
    // partition
    if (low < high){
        int pi = partition (array,low,high);
    
        // Separately sort elements before 
        // partition and after partition 
        quick_sort(array, low, pi - 1); 
        quick_sort(array, pi + 1, high); 
    }
}




void print(int * array, int array_size) {
    for (int i = 0; i < array_size;i++) {
        printf("%d\n",array[i]);
    }
}

int main(){

    int input[] = {10, 7, 8, 9, 1, 5}; 
    int input_size = sizeof(input)/sizeof(input[0]);
    print(input, input_size);
    quick_sort(input, 0, input_size-1);
    printf("after sorting: \n");
    print(input, input_size);
    return 0;
}