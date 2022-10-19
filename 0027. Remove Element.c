// idx to store
// i to search

// C solution
int removeElement(int* nums, int numsSize, int val){
    int idx = 0;
    
    for (int i = 0; i < numsSize; i++){
        if (nums[i] != val){
            nums[idx] = nums[i];
            idx++; //move to the next place to store element
        }
    }
    return idx;
}

// Runtime: 0 ms, faster than 100.00% of C online submissions for Remove Element.
// Memory Usage: 6 MB, less than 67.46% of C online submissions for Remove Element.

// C++ solution

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != val){
                nums[idx] = nums[i];
                idx++;
            }
        }
        return idx; //notice this variable
    }
};

// Runtime: 3 ms, faster than 70.57% of C++ online submissions for Remove Element.
// Memory Usage: 8.8 MB, less than 35.97% of C++ online submissions for Remove Element.
