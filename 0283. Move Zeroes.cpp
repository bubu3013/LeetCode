class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
//       move forward every non-zero element
        for (int i = 0; i < n; i++){
            if (nums[i] != 0){
                nums[idx] = nums[i];
                idx++;
            }
        }
//       put 0 on the remaining part
        while (idx < n){
            nums[idx++] = 0;
        }
    }
};

// Runtime: 32 ms, faster than 78.97% of C++ online submissions for Move Zeroes.
// Memory Usage: 19.2 MB, less than 57.91% of C++ online submissions for Move Zeroes.
