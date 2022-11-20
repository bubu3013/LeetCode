class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        return helper(nums);
    }
private:
    vector<vector<int>>helper(vector<int>& nums){
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for (auto& x: nums){
            m[x]++;
        }
        vector<vector<int>> res;
        vector<int> per;
        backtracking(res, per, nums, m);
        return res;
    }
    void backtracking(vector<vector<int>>& res, vector<int>& per, vector<int>& nums, unordered_map<int, int>& m){
        // if (per.size() == nums.size() && find(res.begin(), res.end(), per) == res.end()){ --> too slow
        if (per.size() == nums.size()){
            res.push_back(per);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (m[nums[i]] > 0){// check if the choice is valid
                if (i + 1 < nums.size() && nums[i] == nums[i + 1])continue; //skip the repetition
                else {
                    m[nums[i]]--;
                    per.push_back(nums[i]);
                    backtracking(res, per, nums, m);
                    m[nums[i]]++;
                    per.pop_back();
                }
            }
        }
        return;
    }
};
