class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        bool pos = true;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0)return 0;
            else if (nums[i] < 0)pos = !pos;
        }
        return pos ? 1 : -1;
    }
};

// Runtime: 4 ms, faster than 93.14% of C++ online submissions for Sign of the Product of an Array.
// Memory Usage: 10.3 MB, less than 43.55% of C++ online submissions for Sign of the Product of an Array.
