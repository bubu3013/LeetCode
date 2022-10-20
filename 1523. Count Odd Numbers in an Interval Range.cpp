class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (high - low)/2;
//       high and low are even, ans do not need to plus 1
        if (high % 2 == 0 && low % 2 == 0)return ans;
//       else case, return ans + 1 
        return ans + 1;      
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Odd Numbers in an Interval Range.
// Memory Usage: 5.9 MB, less than 72.62% of C++ online submissions for Count Odd Numbers in an Interval Range.
