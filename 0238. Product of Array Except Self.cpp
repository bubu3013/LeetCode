class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        return helper(nums);
    }
private:
    vector<int> helper(vector<int>& nums){
        int n = nums.size();
        vector<int> res_1(nums.size(), 1);
        vector<int> res_2(nums.size(), 1);
        // from left to right
        for (int i = 1; i < n; i++){
            res_1[i] = nums[i - 1] * res_1[i - 1];
        }
        // from right to left
        for (int i = n - 2; i >= 0; i--){
            res_2[i] = nums[i + 1] * res_2[i + 1]; 
        }
        // to calculate the sum
        for (int i = 0; i < nums.size(); i++){
            res_1[i] = res_1[i] * res_2[i];
        }
        return res_1;
    }
};

// Runtime 34 ms Beats 78.98% 
// Memory 24.5 MB Beats 50.17%
