class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++){
            nums[i] = nums[i - 1] + nums[i];
        }
        return nums;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Running Sum of 1d Array.
// Memory Usage: 8.4 MB, less than 93.50% of C++ online submissions for Running Sum of 1d Array.

// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, (1+2)+3, (1+2+3)+4].
