
int lengthOfLastWord(char * s){
    int length = strlen(s) - 1;
    int size = 0;
    char curr = ' ';
    bool isLastChar = curr == ' ';
    while (length >= 0 && (curr != ' ' || isLastChar) ) {
        curr = s[length--];
        if (curr != ' '){
             isLastChar = false;
            if (!isLastChar) {
                size++;
            }
        }
    }
    return size;
}