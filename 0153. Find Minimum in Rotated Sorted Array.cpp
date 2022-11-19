class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
private:
    int helper(vector<int>& nums, int left, int right){
        if (nums.size() == 1)return nums[0];
        else if (nums[left] <= nums[right])return nums[left]; // if no rotation
        
        int res = -1;
        int n = right;
        while (left <= right){
            int mid = left + (right - left)/2;
            if ((mid + 1 < n) && (nums[mid] > nums[mid + 1])){
                res = nums[mid + 1];
                break;
            }else if ((mid - 1 >= 0) && (nums[mid - 1] > nums[mid])){
                res = nums[mid];
                break;
            }
            else if (nums[mid] >= nums[left]){
                left = mid + 1;
            }else if (nums[mid] < nums[right]){
                right = mid - 1;
            }
        }
        return res;
    }
};

// Runtime 3 ms Beats 91.5%
// Memory 10.2 MB Beats 22.26%
