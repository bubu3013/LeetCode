// solution 1: C++
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

// solution 2: C

int dp[105] = {-1}; 

int rob(int* nums, int numsSize){
//     size = 1
    if (numsSize == 1)return nums[0];
//     size = 2
    else if (numsSize == 2)return (nums[0] > nums[1]) ? nums[0] : nums[1];
//     size >= 3
    dp[0] = nums[0];
    dp[1] = (nums[0] > nums[1]) ? nums[0] : nums[1];
    return helper(nums, numsSize);
}
int helper(int * nums, int numsSize){
    
    for (int i = 2; i < numsSize; i++){
        dp[i] = ((nums[i] + dp[i - 2]) > dp[i - 1]) ? (nums[i] + dp[i - 2]) : dp[i - 1];
    }
    return dp[numsSize - 1];
}

// Runtime: 0 ms, faster than 100.00% of C online submissions for House Robber.
// Memory Usage: 6 MB, less than 30.82% of C online submissions for House Robber.
