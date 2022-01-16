// leetcode problems
//  median of two sorted arrays
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

bool palindrome(int x) {

    if (x < 0) return false;

    // log 10 (x) = num of digits -1

    // log 10 (x) = num of digits -1 
    while ( x/(int)pow(10,(int)log10(x)) == (x%10) ) {
        cout << "first digit: " <<  x/(int)pow(10,(int)log10(x)) << endl;
        cout << "last digit: " << (x%10) << endl;
        cout << "digit: " <<  (int)pow(10,(int)log10(x)) << endl;
        // remove the first digit
        x -= x/(int)pow(10,(int)log10(x)) * (int)pow(10,(int)log10(x));
        // remove the last digit
        x /= 10;
    }

    return x == 0 ;
    
}

int main(int argc, char *argv[]) {

    palindrome(1000021);
    return 0;
}