class Solution {
public:
    bool canJump(vector<int>& nums) {
        return helper(nums, nums.size());
    }
private:
    bool helper(vector<int>& nums, int n){
        bool is_last = false;
        int max_ = 0;
        for (int i = 0; i < n; i++){
            if (i > max_){ //cannot reach the i-th index
                is_last = false;
                break;
            } 
            max_ = max(max_, i + nums[i]); // cur the max index
            if (max_ >= n - 1){ //can reach the last index?
                is_last = true;
                break;
            }
        }
        return is_last;
    }
};

// Runtime 65 ms Beats 96.25%
// Memory 48.5 MB Beats 47.25%
