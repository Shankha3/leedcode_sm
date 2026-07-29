long long countPermutations(int freq[26], int total_len, long long max_cap) {
    long long res = 1;
    int current_len = 0;

    for (int i = 0; i < 26; i++) {
        int count = freq[i];
        for (int j = 1; j <= count; j++) {
            current_len++;
            res = (res * current_len) / j;
            if (res > max_cap) {
                return max_cap;
            }
        }
    }
    return res;
}

char* smallestPalindrome(char* s, int k) {
    int n = strlen(s);
    int freq[26] = {0};
    
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    int half_freq[26] = {0};
    int half_len = n / 2;
    char mid_char = '\0';

    for (int i = 0; i < 26; i++) {
        half_freq[i] = freq[i] / 2;
        if (freq[i] % 2 != 0) {
            mid_char = 'a' + i;
        }
    }

    long long total_palindromes = countPermutations(half_freq, half_len, k);
    if (total_palindromes < k) {
        char* empty_res = (char*)malloc(1 * sizeof(char));
        empty_res[0] = '\0';
        return empty_res;
    }

    char* left_half = (char*)malloc((half_len + 1) * sizeof(char));
    left_half[half_len] = '\0';

    long long current_k = k;
    for (int pos = 0; pos < half_len; pos++) {
        int remaining_len = half_len - 1 - pos;

        for (int c = 0; c < 26; c++) {
            if (half_freq[c] > 0) {
                half_freq[c]--;
                
                long long ways = countPermutations(half_freq, remaining_len, current_k);

                if (ways >= current_k) {
                    left_half[pos] = 'a' + c;
                    break;
                } else {
                    current_k -= ways;
                    half_freq[c]++;
                }
            }
        }
    }

    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0';

    for (int i = 0; i < half_len; i++) {
        result[i] = left_half[i];
    }

    int right_start = half_len;
    if (n % 2 != 0) {
        result[half_len] = mid_char;
        right_start = half_len + 1;
    }

    for (int i = 0; i < half_len; i++) {
        result[right_start + i] = left_half[half_len - 1 - i];
    }

    free(left_half);
    return result;
}