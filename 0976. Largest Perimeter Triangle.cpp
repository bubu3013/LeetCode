class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
//       find from the largest
        for (int i = nums.size() - 1; i >= 2; i--){
            if (nums[i] < nums[i - 1] + nums[i - 2]){
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return 0;
    }
};

// Runtime: 46 ms, faster than 83.29% of C++ online submissions for Largest Perimeter Triangle.
// Memory Usage: 21.9 MB, less than 22.11% of C++ online submissions for Largest Perimeter Triangle.0
