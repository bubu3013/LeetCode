// 1. do not allocate extra memory
// 2. sorted data to remove duplicates
// => two pointers

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
