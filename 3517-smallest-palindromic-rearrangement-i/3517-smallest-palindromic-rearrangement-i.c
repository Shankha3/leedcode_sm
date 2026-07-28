char* smallestPalindrome(char* s) {
    int n = strlen(s);
    int half_len = n / 2;

    int freq[26] = {0};
    for (int i = 0; i < half_len; i++) {
        freq[s[i] - 'a']++;
    }

    char* result = (char*)malloc((n + 1) * sizeof(char));

    int index = 0;
    for (int i = 0; i < 26; i++) {
        while (freq[i] > 0) {
            result[index++] = 'a' + i;
            freq[i]--;
        }
    }

    if (n % 2 != 0) {
        result[index++] = s[half_len];
    }

    int start = 0;
    int end = half_len - 1;
    while (end >= 0) {
        result[index++] = result[end--];
    }

    result[n] = '\0';

    return result;
}