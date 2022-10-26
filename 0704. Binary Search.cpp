// solution 1: C++
class Solution {
public:
    int search(vector<int>& nums, int target) {
//         binary search
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right)/2;
        
        while (left <= right){
            if (target < nums[mid]){
                right = mid - 1;
            }else if (target > nums[mid]){
                left = mid + 1;
            }else if (target == nums[mid]){
                return mid;
            }
            mid = (left + right)/2;
        }
        return -1;
    }
};

// Runtime: 111 ms, faster than 17.88% of C++ online submissions for Binary Search.
// Memory Usage: 27.5 MB, less than 63.52% of C++ online submissions for Binary Search.

// solution 2: C

int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right){
        int mid = (left + right) / 2;
        if (target < nums[mid]){
            right = mid - 1;
        }else if (target > nums[mid]){
            left = mid + 1;
        }else if (target == nums[mid]){
            return mid;
        }
    }
    return -1;
}

// Runtime: 71 ms, faster than 51.87% of C online submissions for Binary Search.
// Memory Usage: 7 MB, less than 66.11% of C online submissions for Binary Search.
