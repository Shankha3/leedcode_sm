using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> last(m + 1, -1);
        last[m] = n;

        int p = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (p >= 0 && word1[p] != word2[j]) {
                p--;
            }
            if (p >= 0) {
                last[j] = p;
                p--; 
            } else {
                break;
            }
        }

        vector<int> result;
        bool used_change = false;
        int w1_idx = 0;

        for (int i = 0; i < m; ++i) {
            bool matched = false;

            while (w1_idx < n) {
                if (word1[w1_idx] == word2[i]) {
                    result.push_back(w1_idx);
                    w1_idx++;
                    matched = true;
                    break;
                }
                
                if (!used_change && last[i + 1] > w1_idx) {
                    result.push_back(w1_idx);
                    w1_idx++;
                    used_change = true;
                    matched = true;
                    break;
                }

                w1_idx++;
            }

            if (!matched) {
                return {};
            }
        }

        return result;
    }
};