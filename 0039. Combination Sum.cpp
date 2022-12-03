class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return helper(candidates, target);
    }
private:
    vector<vector<int>> res;
    vector<vector<int>> helper(vector<int>& nums, int target) {
        vector<int> ans;
        sum(nums, ans, target, 0);
        return res;
    }
    void sum(vector<int>& nums, vector<int>& ans, int target, int idx) {
        if (target == 0){ // base case
            res.push_back(ans);
            return;
        }
        for (int i = idx; i < nums.size(); i++){
            if (target - nums[i] >= 0){ // valid choice?
                ans.push_back(nums[i]); // make this choice
                sum(nums, ans, target - nums[i], i); // next iteration
                ans.pop_back(); // undo the choice
            }
        }
        return;
    }
};

// Runtime 3 ms Beats 97.11% 
// Memory 11 MB Beats 54.18%
