/**
 * Note: The returned array must be malloced, assume caller calls free().
*/

// solution 1
# define pow(x) (x) * (x)

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int * ans = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++){
        nums[i]= pow(nums[i]);
        ans[i] = nums[i];
    }
// // two pointers to sort
    int i = 0; int j = numsSize - 1; int k = numsSize - 1;
    while (i <= j){
        if (nums[i] > nums[j]){
            ans[k] = nums[i];
            k--;i++;
        }else{
            ans[k] = nums[j];
            k--;j--;
        }
    }
// to revise the value directly, not only read it
//     assign a value for a pointer:
//     * pointer = value
    * returnSize = numsSize; 
    return ans;
}

// Runtime: 232 ms, faster than 43.28% of C online submissions for Squares of a Sorted Array.
// Memory Usage: 20.2 MB, less than 62.63% of C online submissions for Squares of a Sorted Array.

// solution 2

// to sort [-4, -1, 0 , 1, 10] for their square equeals to sort [4, 1, 0. 3, 10]
// do not need to calculate the pow for nums first
# define pow(x) (x) * (x)

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int * ans = (int *)malloc(sizeof(int) * numsSize);
// // two pointers to sort
    int i = 0; int j = numsSize - 1; int k = numsSize - 1;
    while (i <= j){
        if (abs(nums[i]) > abs(nums[j])){
            ans[k] = pow(nums[i]);
            k--;i++;
        }else{
            ans[k] = pow(nums[j]);
            k--;j--;
        }
    }
    * returnSize = numsSize; // to revise the value directly, not only read it
//     assign a value for a pointer:
//     * pointer = value
    return ans;
}

// Runtime: 246 ms, faster than 28.23% of C online submissions for Squares of a Sorted Array.
// Memory Usage: 20.2 MB, less than 62.63% of C online submissions for Squares of a Sorted Array.

// solution 3

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        ans.resize(nums.size(), -1);
        
        int left = 0;
        int right = nums.size() - 1;
        int idx = nums.size() -1;
        
        while (left <= right){
            if (abs(nums[right]) < abs(nums[left])){
                ans[idx] = nums[left] * nums[left];
                left++;
            }else if (abs(nums[right]) >= abs(nums[left])){
                ans[idx] = nums[right] * nums[right];
                right--;
            }
            idx--;
        }
        return ans;
        
    }
};

// two pointers do not mean you can not use more  than two pointers
