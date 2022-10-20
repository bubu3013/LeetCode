using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i ++){
//             pick up i-th weight from the right
            rightSum -= nums[i];
//             check if the left weight is equal to right weight 
            if (rightSum == leftSum)return i;
//              put the i-th weight on the left 
            leftSum += nums[i];
        }
        return -1;
    }
};

// 1. putting all weight on the right of the balance
// 2. pick up i-th weight to see if the leftSum equals to rightSum
// 3. put the i-th weight to the left of the balance

// Runtime: 49 ms, faster than 52.91% of C++ online submissions for Find Pivot Index.
// Memory Usage: 31.1 MB, less than 51.55% of C++ online submissions for Find Pivot Index.
