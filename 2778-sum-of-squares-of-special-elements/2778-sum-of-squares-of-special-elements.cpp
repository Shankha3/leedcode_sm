class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(n%(i+1)==0){
                ans+= pow(nums[i],2);
            }
        }
        return ans;
        
    }
};