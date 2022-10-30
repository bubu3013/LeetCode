solution 1 - quick sort + two pointers: O(nlogn)

void quickSort(int* nums, int left, int right){
    if (left >= right)return;
    
    int i = left;
    int j = right;
    int pivot = nums[left];
    
    while (i != j){
        while ((nums[j] >= pivot) && (i < j)){
            j--;
        }
        while ((nums[i] <= pivot) && (i < j)){
            i++;
        }
        if (i < j){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
    nums[left] = nums[i];
    nums[i] = pivot;
    
    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
}

int thirdMax(int* nums, int numsSize){
    quickSort(nums, 0, numsSize - 1);
    
    int idx = 0;
    
    for (int i = 1; i < numsSize; i++){
        if (nums[idx] != nums[i]){
            idx++;
            nums[idx] = nums[i];
        }
    }
    if (idx < 2)return nums[numsSize - 1];
    return nums[idx - 2];
}

// Runtime: 66 ms, faster than 15.00% of C online submissions for Third Maximum Number.
// Memory Usage: 6.1 MB, less than 92.50% of C online submissions for Third Maximum Number.

// solution 2: O(N) ?
