#include<stdio.h>
#include<conio.h>
#include<string.h>

// get anagram, anagram is when the character has same character in the string
int anagram(char * str1, char * str2){
    char temp;
    if (strlen(str1) != strlen(str2)){
        return 0;
    } else {
        for (int i = 0; i < strlen(str1) - 1 ; i++ ){
            for (int j = i+1; j < strlen(str1); j++) {
                if(str1[i] > str1[j]){
                    temp = str1[i];
                    str1[i] = str1[j];
                    str1[j] = temp;
                }
                if(str2[i] > str2[j]){
                    temp = str2[i];
                    str2[i] = str2[j];
                    str2[j] = temp;
                }
            }
        }
        for(int i = 0; i< strlen(str1); i++) {
            if(str1[i] != str2[i]) {    
                printf("Strings are not anagram \n", str1, str2);
                return 0;
            }
        }    
    }
    return 1;
}   

void main(){
    char str1[100],str2[100],c;
    int count;
    printf("enter the string1 : \n");
    scanf("%[^\n]%c",str1,&c);
    printf("enter the string2 : \n");
    scanf("%[^\n]%c",str2,&c);
    count = anagram(str1,str2);
    printf("string1 string2 '%s': %s",str1,str2);
    printf("true: %d",count);
    getch();
 } 