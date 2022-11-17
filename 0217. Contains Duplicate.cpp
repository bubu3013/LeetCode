class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return helper(nums, nums.size());
    }
private:
    bool helper(vector<int>& nums, int n){
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++){
            m[nums[i]] += 1;
            if (m[nums[i]] > 1)return true;
        }
        return false;
    }
};

// Runtime 106 ms Beats 90.45%
// Memory 51.5 MB Beats 52.25%
