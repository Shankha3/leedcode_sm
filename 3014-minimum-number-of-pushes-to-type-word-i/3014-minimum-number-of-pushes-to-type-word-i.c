int minimumPushes(char* word) {
    int n = strlen(word);
    int pushes = 0;
    
    for (int i = 0; i < n; i++) {
        pushes += (i / 8) + 1;
    }
    
    return pushes;
}