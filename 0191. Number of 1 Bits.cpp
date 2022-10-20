class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n){
//           mask
            if (n & 1)ans++;
//           bit shift
            n = n >> 1;
        }
        return ans;
    }
};

// Runtime: 3 ms, faster than 66.06% of C++ online submissions for Number of 1 Bits.
// Memory Usage: 6.1 MB, less than 47.52% of C++ online submissions for Number of 1 Bits.
