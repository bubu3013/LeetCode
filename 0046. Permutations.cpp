class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return helper(nums);
    }
private:
    vector<vector<int>> helper(vector<int>& nums){
        vector<vector<int>> res;
        vector<int> permutation;
        vector<bool> is_used(nums.size(), false);
        backtracking(res, nums, permutation, is_used);
        return res;
    }
    void backtracking(vector<vector<int>>& res, vector<int>& nums, vector<int>& permutation, vector<bool>& is_used){
        if (permutation.size() == nums.size()){
            res.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (is_used[i] == false){
                is_used[i] = true;
                permutation.push_back(nums[i]);
                backtracking(res, nums, permutation, is_used);
                is_used[i] = false;
                permutation.pop_back();
            }
        }
        return;
    }

};

Runtime 0 ms Beats 100%
Memory 7.6 MB Beats 78.63%
