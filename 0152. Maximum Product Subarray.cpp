class Solution {
public:
    int maxProduct(vector<int>& nums) {
        return helper(nums, nums.size());
    }
private:
    int helper(vector<int>& nums, int n){
        int max_ = nums[0];
        int min_ = nums[0];
        int res = nums[0];

        for (int i = 1; i < n; i++){
            int temp = max_;
            // find the cur max
            max_ = max(max(temp * nums[i], min_ * nums[i]), nums[i]);
            // find the cur min
            min_ = min(min(temp * nums[i], min_ * nums[i]), nums[i]);

            res = max_ > res ? max_ : res;
        }
        return res;
    }
};

// max value comes from (1) prev min value * nums[i] or (2) prev max value * nums[i] or (3) itself

// Runtime 16 ms Beats 46.84%
// Memory 13.6 MB Beats 95.7%
