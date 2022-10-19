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
