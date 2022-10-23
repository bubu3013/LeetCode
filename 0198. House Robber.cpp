class Solution {
public:
    vector <int> dp;
    int rob(vector<int>& nums) {
        dp.resize(nums.size() + 1, -1);

        dp[0] = nums[0];
        if (nums.size() == 1)return nums[0];
        
        dp[1] = std::max(nums[0], nums[1]);
        if (nums.size() == 2)return dp[1];
        
        for (int i = 2; i < nums.size(); i++){
            dp[i] = std::max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 7.8 MB, less than 25.66% of C++ online submissions for House Robber.
