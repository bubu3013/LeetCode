class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return helper(candidates, target);
    }
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int>& ans, int target, int idx) {
        if (target == 0){
            res.push_back(ans);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[i - 1]){ // "i != idx" && "nums[i] == nums[i - 1]": to remove the duplicate ans
                continue;
            }
            if (target - nums[i] >= 0){
                ans.push_back(nums[i]);
                dfs(nums, ans, target - nums[i], i + 1);
                ans.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> helper(vector<int>& nums, int target) {
        vector<int> ans;
        dfs(nums, ans, target, 0);
        return res;
    }
};

// Runtime 12 ms Beats 51.60% 
// Memory 10.7 MB Beats 46.83%

// solution 2:
// 讓"本層"去避免重複的發生: 避免相同的解
// i != idx && nums[i] != nums[i - 1] to avoid duplicates
// 下一層從i + 1 開始     : 避免重複的元素

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return helper(candidates, target);
    }
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int>& ans, int target, int idx) {
        if (target == 0){
            res.push_back(ans);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[i - 1]){
                continue;
            }
            if (target - nums[i] >= 0){
                ans.push_back(nums[i]);
                dfs(nums, ans, target - nums[i], i + 1);
                ans.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> helper(vector<int>& nums, int target) {
        vector<int> ans;
        dfs(nums, ans, target, 0);
        return res;
    }
};

// Runtime 7 ms Beats 81.27% 
// Memory 10.8 MB Beats 37.11%
