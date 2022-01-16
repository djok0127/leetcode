#include <stdio.h>

int triple( int a ) {
    return 3 *a;
}

int square (int a ) {
    return a*a;
}

void transform(int array[], size_t len, int (*fun)(int)) {
    size_t i = 0;
    for(; i < len; ++i)
        array[i] = fun(array[i]);
}

int main() {
    int array[3] = {1,2,3};
    transform(array, 3, &triple);
    transform(array, 3, &square);

    for (int i = 0; i < 3; i++){
        printf("%d ",array[i]);
    }

    return 0;
}