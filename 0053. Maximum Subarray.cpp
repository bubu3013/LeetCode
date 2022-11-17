class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cur_max = nums[0];
//       start from 1 because the sum of nums[0] is already in cur_max
        for (int i = 1; i < n; i++){
//           if the previous sum is greater than 0, then sum up
//           else leave the nums[i] as the same
            if (nums[i - 1] > 0){
                nums[i] = nums[i] + nums[i - 1]; 
            }
//           to compare if the new max is greater than cur_max
            if (cur_max < nums[i]){
                cur_max = nums[i];
            }
        }
        return cur_max;
    }
};

// Runtime: 128 ms, faster than 86.80% of C++ online submissions for Maximum Subarray.
// Memory Usage: 67.7 MB, less than 53.38% of C++ online submissions for Maximum Subarray.

// main idea:
// if the previous max is negative, then do not sum up because the total will decrease.
// Kadane's Algorithm

// the following website helps,
// https://alchemist-al.com/algorithms/maximum-subarray-problem

// solution 2:

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, nums.size());
    }
private:
    int helper(vector<int>& nums, int n){
        if (n == 1)return nums[0];

        vector<int> dp(n + 5, 0);
        dp[0] = nums[0];
        int maximum = nums[0];
        for (int i = 1; i < n; i++){
            if (dp[i - 1] > 0){
                dp[i] = nums[i] + dp[i - 1];
            }else{
                dp[i] = nums[i];
            }
            maximum = max(maximum, dp[i]);
        }
        return maximum;
    }
};

// Runtime 267 ms Beats 47.88% 
// Memory 70.3 MB Beats 7.47%

