#include<stdio.h>
#include<conio.h>
#include<string.h>

int maxArea(int* height, int heightSize){
    int largest = 0;
    int bigger = 0;
    int current = 0;
    printf("sizeof(height)/sizeof(*height): %d \n",sizeof(height)/sizeof(*height));
    for (int i = 0; i < (int)(sizeof(height)/sizeof(height[0])); i++){
        for(int j = (int)(sizeof(height)/sizeof(height[0])) - 1; j > 0; j--) {
            bigger = height[i] > height[j]? height[j] : height[i];
            printf("bigger: %d \n",bigger);
            current = (j-i) * bigger;
            if (current > largest) {
                
                largest = current;
                printf("largest: %d \n", largest);
            }
        }
    }
    
    return largest;
}

void main(){

    int height[9] = {1,8,6,2,5,4,8,3,7};

    int max = maxArea(height,9);
    printf("max: %d \n",max);
    getch();
}
