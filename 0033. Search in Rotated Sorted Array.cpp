class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1){
            if (nums[0] == target)return 0;
            else return -1;
        } 
        bool is_rotated = false;
        int ans = -1;
        int pivot = 1;
        // find the pivot
        while (pivot < nums.size()){
            if (nums[pivot - 1] > nums[pivot]){
                is_rotated = true;
                break;
            }
            pivot++;
        }
        // if rotation
        if (is_rotated){
            ans = helper(nums, 0, pivot - 1, target);
            if (ans == -1){
                ans = helper(nums, pivot, nums.size() - 1, target);
            }
        }
        // if no rotation
        else{
            ans = helper(nums, 0, nums.size() - 1, target);
        }
        return ans;
    }
private:
    // binary search
    int helper(vector<int>& nums, int left, int right, int target){
        int ans = -1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target){
                ans = mid;
                break;
            }
            else if (nums[mid] < target){
                left = mid + 1;
            }
            else if (nums[mid] > target){
                right = mid - 1;
            }
        }
        return ans;
    }
};

// Runtime 4 ms Beats 79.65%
// Memory 11.1 MB Beats 75.20%
