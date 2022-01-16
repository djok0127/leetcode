#include<stdio.h>
#include<conio.h>
#include<string.h>

// get anagram, anagram is when the character has same character in the string
int palindrome(char * input){
    for (int i = 0; i < strlen(input)/2; i++) {
        printf("%c %c \n",input[i],input[strlen(input - i - 1)]);

        if(input[i] != input[strlen(input - i - 2)]){
            printf("not palindrome: %c %c \n",input[i],input[strlen(input - i - 1)]);
            return -1;
        }
    }
    return 0;
    
}   

void main(){
    char str[100],c;
    int count;
    printf("enter the string : \n");
    scanf("%[^\n]%c",str,&c);
    count = palindrome(str);
    printf("output: %d \n",count);
    getch();
 } 