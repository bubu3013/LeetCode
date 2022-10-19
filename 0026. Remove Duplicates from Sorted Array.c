// 1. do not allocate extra memory
// 2. sorted data to remove duplicates
// => two pointers

// C solution
int removeDuplicates(int* nums, int numsSize){
    int left = 0;
    
    for (int right = 1; right < numsSize; right++){
        if (nums[left] != nums[right]){
            left++;
            nums[left] = nums[right];
        }
    }
    return left + 1;
}

// Runtime: 25 ms, faster than 51.77% of C online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 7.6 MB, less than 33.70% of C online submissions for Remove Duplicates from Sorted Array.

// C++ solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for (int i = 1; i < nums.size(); i ++){
            if (nums[idx] != nums[i]){
                idx++;
                nums[idx] = nums[i];
            }
        }
        return idx + 1; // idx: originally -> pos but now -> # of items
    }
};

// Runtime: 12 ms, faster than 89.90% of C++ online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 18.4 MB, less than 36.93% of C++ online submissions for Remove Duplicates from Sorted Array.
