// solution 1: C++
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
//         if target is out of bound
        if (target > nums[nums.size() - 1])return nums.size();
        else if (target < nums[0] || nums.size() == 1)return 0;
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;
        int idx = (left + right)/2;
        
//       binary search
//       while (l <= right) -> the case left = right sould be considered
        while (left <= right){
            if (target < nums[idx]){
//               exclude nums[idx] -> idx - 1
                right= idx - 1; 
            }else if (target > nums[idx]){
//               exclude nums[idx] -> idx + 1
                left = idx + 1;
            }else if (target == nums[idx]){
                return idx;
            }
//           check if idx is in the range
            idx = (left + right)/2;
            if (idx < 0 || right > nums.size())break;
        }
//       if not found
        if (target < nums[idx]){
            return idx;
        }else{
            return idx + 1;
        }
    }
};

// Runtime: 2 ms, faster than 96.13% of C++ online submissions for Search Insert Position.
// Memory Usage: 9.7 MB, less than 22.75% of C++ online submissions for Search Insert Position.

// solution 2: C
int searchInsert(int* nums, int numsSize, int target){
    int ans = -1;
    int left = 0;
    int right = numsSize - 1;

    if (target <= nums[0])return 0;
    else if (target > nums[numsSize - 1])return numsSize;
    else if (target == nums[numsSize - 1])return numsSize - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;
        if (nums[mid] == target){
            ans = mid;
            break;
        }
        else if (nums[mid] < target && nums[mid + 1] > target){
            ans = mid + 1;
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

// Runtime 0 ms Beats 100%
// Memory 5.9 MB Beats 99.30%
