//solution 1 - (1) find the pivot (2) check if rotate (3) search the left part (4) search the right part 
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

// solution 2 - 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return helper(nums, target);
    }
private:
    int helper(vector<int>& nums, int target) {
        int ans = -1;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target){
                ans = mid;
                break;
            }
            // the upper side
            else if (nums[left] <= nums[mid]){
                if (nums[left] <= target && target <= nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            // the lower side
            else {
                if (nums[mid] <= target && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return ans;
    }
};

// Runtime 7 ms Beats 66.25%
// Memory 10.9 MB Beats 95.71%

// 2022/12/03

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int res = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target){
                res = mid;
                break;
            }else if (nums[mid] >= nums[left]){ // the upper side
                if (nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }else {
                    left = mid + 1;
                }
            }else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }else {
                    right = mid - 1;
                }
            }
        }
        return res;
    }
};

/*
if nums[mid] is in upper side
-----------------------------------
(1-1) (1-2)
|--||-------|
      /
     x 
    /
  (mid)
  /
 x 
/
          /
         /
        /
-----------------------------------

if the nums[mid] is in the lower side
(2-1)      (2-2)
|---------|----|
      
    
    
   /
  /
 / 
/
             /
            X
           /
        (mid)
         /
        X
       / 
-----------------------------------
*/

// Runtime 4 ms Beats 78.50% 
// Memory 11.1 MB Beats 75.64%
