// solution 1: DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums, nums.size());
    }
private:
    int helper(vector<int>& nums, int n){
        vector<int> dp(n + 5, 1);
        int longest = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                // before me, the longest increasing subsequence is X.
                if (nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (longest < dp[i]){
                longest = dp[i];
            }
        }
        return longest;
    }
};

// Runtime 356 ms Beats 63.79%
// Memory 10.5 MB Beats 72.29%

// solution 2: DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums, nums.size());
    }
private:
    int helper(vector<int>& nums, int n){
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        sort(dp.begin(), dp.end());
        return dp[n - 1];
    }
};

// Runtime 347 ms Beats 64.37%
// Memory 10.5 MB Beats 50.39%
