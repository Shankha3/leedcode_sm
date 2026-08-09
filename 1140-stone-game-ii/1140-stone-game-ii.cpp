using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        vector<int> suffixSum(n);
        
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        auto dp = [&](auto& self, int i, int M) -> int {
            if (i >= n) return 0;
            if (i + 2 * M >= n) return suffixSum[i];
            if (memo[i][M] != -1) return memo[i][M];

            int maxStones = 0;
            for (int X = 1; X <= 2 * M; ++X) {
                int nextM = max(M, X);
                int stones = suffixSum[i] - self(self, i + X, nextM);
                maxStones = max(maxStones, stones);
            }

            return memo[i][M] = maxStones;
        };

        return dp(dp, 0, 1);
    }
};