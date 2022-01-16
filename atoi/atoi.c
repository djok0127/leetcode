#include<stdio.h>
#include<conio.h>
#include<string.h>

int myAtoi(char * s){
    long output = 0;
    int negative = 0;
    // check for number whitespace
    printf("strlen(s): %d \n", strlen(s));
    for(int i = 0; strlen(s); i++){
        if (s[i] == '-') {
            negative = 1;
            continue;
        }
        if (s[i] == ' ') {
            continue;
        }
        if(s[i] > '0' && s[i] < '9') {
            printf("output: %d \n", output);
            output = output *10 + (s[i] - '0');
        }

    }
    
    if(negative){
        output = output * -1;
    }
    
    return output;
}
void main(){
    char str[100],c;
    int count;
    printf("enter the string : \n");
    scanf("%[^\n]%c",str,&c);
    count = myAtoi(str);
    printf("output: %d \n",count);
    getch();
} 