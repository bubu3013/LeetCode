class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return helper(nums, nums.size());
    }
private:
    vector<vector<int>> helper(vector<int>& nums, int n){
        vector<vector<int>> res;

        for (int i = 0; i < n; i++){
            // to skip the repetition
            if (i >= 1 && nums[i - 1] == nums[i])continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r){
                // to avoid the repetition
                if (l == i)l++;
                else if (r == i)r--;

                int tmp = nums[l] + nums[r]; 
                if (tmp == -nums[i]){
                    vector<int> ans;
                    ans.push_back(nums[i]);
                    ans.push_back(nums[l]);
                    ans.push_back(nums[r]);
                    // avoid repetition ans
                    sort(ans.begin(), ans.end());
                    if ((res.size() > 0 && ans != res[res.size() - 1]) || (res.size() == 0)){
                       res.push_back(ans); 
                    }
                    l++;
                    r--;
                }else if (tmp < -nums[i]){ // too small
                    l++;
                }else if (tmp > -nums[i]){ // too larget
                    r--;
                }
            }
        }
        return res;
    }
};

// Runtime 204 ms Beats 42.37%
// Memory 26 MB Beats 17.66%
