#include<stdio.h>
#include<conio.h>
#include<string.h>
int countOccurrence(char * str, char ch){
    int counter = 0 ;
    for (int i = 0; i < strlen(str);i++){
        if (str[i] == ch) counter++;
    }
    return counter;
}

void main(){
	 char str[100],ch,c;
	 int count;
	 printf("enter the string : \n");
	 scanf("%[^\n]%c",str,&c);
	 printf("enter a char want to count occurence : ");
	 scanf("%c",&ch);
	 count = countOccurrence(str,ch);
	 printf("total occurence of '%c': %d",ch,count);
	 getch();
 } 