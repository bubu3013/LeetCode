// solution 1: avoid the repetition in advance

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return helper(nums);
    }
private:
    vector<vector<int>> res;
    vector<vector<int>> helper(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            // if (i + 1 < n && nums[i] == nums[i + 1]) -> skip all the repetitive elements
            if (i - 1 >= 0 && nums[i] == nums[i - 1])continue; // at least "one" run for the repetivie elements
            twoSum(nums, i, 0 - nums[i]);
        }
        return res;
    }
    void twoSum(vector<int>& nums, int idx, int target) { 
        int n = nums.size();
        int left = idx + 1; // start from idx + 1
        int right = nums.size() - 1;
        while (left < right) {
            // at least one run for the repetitive elements
            if (left - 1 > idx && nums[left] == nums[left - 1]){
                left++;
                continue;
            }
            if (right + 1 < n && nums[right] == nums[right + 1]){
                right--;
                continue;
            }
            int tmp = nums[left] + nums[right];
            if (tmp == target){
                vector<int> ans(3, -1);
                ans[0] = nums[idx];
                ans[1] = nums[left];
                ans[2] = nums[right];
                res.push_back(ans);
                left++; right--;
            }else if (tmp > target){
                right--;
            }else {
                left++;
            }
        }
        return;
    }
};
// Runtime 125 ms Beats 77.57% 
// Memory 23.1 MB Beats 33.48%

// solution 2: with sorting in res to avoid the repetition
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
