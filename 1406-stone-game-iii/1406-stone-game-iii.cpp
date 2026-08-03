#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        std::vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int max_diff = INT_MIN;
            int current_sum = 0;

            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                current_sum += stoneValue[i + k - 1];
                max_diff = std::max(max_diff, current_sum - dp[i + k]);
            }

            dp[i] = max_diff;
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};