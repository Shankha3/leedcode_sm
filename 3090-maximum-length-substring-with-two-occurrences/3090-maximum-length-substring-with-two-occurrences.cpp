class Solution {
public:
       int maximumLengthSubstring(std::string s) {
        std::vector<int> counts(26, 0);
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < s.length(); ++right) {
            counts[s[right] - 'a']++;

            while (counts[s[right] - 'a'] > 2) {
                counts[s[left] - 'a']--;
                left++;
            }

            max_len = std::max(max_len, right - left + 1);
        }

        return max_len; 
    }
};