class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)return nums[0];
        else if (nums.size() == 2)return max(nums[0], nums[1]);
        // vector原來可以這樣用!!!
        vector<int> v1 (nums.begin(), nums.end() - 1);
        vector<int> v2 (nums.begin() + 1, nums.end());

        return max(helper(v1), helper(v2));
    }
    int helper(vector<int>& n){
        if (n.size() == 1)return n[0];
        else if (n.size() == 2)return max(n[0], n[1]);

        vector<int> dp (n.size(), -1);
        dp[0] = n[0];
        dp[1] = max(n[0], n[1]);

        for (int i = 2; i < dp.size(); i++){
            dp[i] = max(n[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n.size() - 1];
    }
};

// Runtime 0 ms Beats 100%
// Memory 8 MB Beats 43.3%
