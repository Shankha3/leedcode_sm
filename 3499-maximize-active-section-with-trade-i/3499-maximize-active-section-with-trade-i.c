int maxActiveSectionsAfterTrade(char* s) {
    int initial_ones = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            initial_ones++;
        }
    }

    int zero_lens[n + 2];
    int zero_count = 0;

    int i = 0;
    while (i < n) {
        if (s[i] == '0') {
            int len = 0;
            while (i < n && s[i] == '0') {
                len++;
                i++;
            }
            zero_lens[zero_count++] = len;
        } else {
            i++;
        }
    }

    int max_gain = 0;
    for (int j = 0; j < zero_count - 1; j++) {
        int gain = zero_lens[j] + zero_lens[j + 1];
        if (gain > max_gain) {
            max_gain = gain;
        }
    }

    return initial_ones + max_gain;
}