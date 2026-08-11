class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix_sum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                prefix_sum += nums[i];
            } else {
                break; 
            }
        }

        std::unordered_set<int> num_set(nums.begin(), nums.end());

        int ans = prefix_sum;
        while (num_set.count(ans)) {
            ans++;
        }

        return ans;
    }
        

};