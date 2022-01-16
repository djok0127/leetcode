char * longestCommonPrefix(char ** strs, int strsSize){
    int current_indx = 0;
    char current_char = strs[0][0];
    while(current_indx <= sizeof(strs[0])/sizeof(strs[0][0])){
        
        for (int i = 1; i < strsSize;i++){
            if (current_char != strs[i][current_indx]){
                char * output = malloc(current_indx * sizeof(strs[0][0]));
                strcpy(output, strs);
                return output; 
            }
        }
        current_char = strs[0][current_indx];
        current_indx++;
        
    }
    return "";
}

int main(){
    char** strs = {"flower","flow","flight"};
    printf("%x", longestCommonPrefix(strs,3));
    return 0;
}