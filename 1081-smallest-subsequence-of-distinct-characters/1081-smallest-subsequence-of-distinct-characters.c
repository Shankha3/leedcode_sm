#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char* smallestSubsequence(char* s) {
    int len = strlen(s);
    int last_idx[26] = {0};
    bool seen[26] = {false};
    
    for (int i = 0; i < len; i++) {
        last_idx[s[i] - 'a'] = i;
    }
    
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        int curr = s[i] - 'a';
        if (seen[curr]) continue;
        
        while (top >= 0 && stack[top] > s[i] && last_idx[stack[top] - 'a'] > i) {
            seen[stack[top] - 'a'] = false;
            top--;
        }
        
        stack[++top] = s[i];
        seen[curr] = true;
    }
    
    stack[top + 1] = '\0';
    return stack;
}