class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        return helper(nums, target);
    }
private:
    int helper(vector<int>& nums, int target){
        vector<int> dp(target + 5, -1);
        return backtracking(nums, dp, target);
    }
    int backtracking(vector<int>& nums, vector<int>& dp, int target){
        if (target == 0){
            return 1;
        }
        else if (dp[target] != -1)return dp[target];

        // how many solutions with this target? 
        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            if (target - nums[i] >= 0){
                ans += backtracking(nums, dp, target - nums[i]);
            }
        }
        return dp[target] = ans;
    }
};

// Runtime 0 ms Beats 100%
// Memory 6.7 MB Beats 66.60%
