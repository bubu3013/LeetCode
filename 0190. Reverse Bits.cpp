class Solution {
public:
    unsigned int pow(int i){
        if (i == 0)return 1;
        return 2 * pow(i - 1);
    }
    uint32_t reverseBits(uint32_t n) {
//         the 32-th bit = 2^31
//         the 1-th bit  = 2^0
        unsigned int val = pow(31);
        unsigned int ans = 0;
        while (n){
            ans = ans + (n & 1) * val; 
            n = n >> 1;
            val = val / 2;
        }  
        return ans;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Bits.
// Memory Usage: 5.9 MB, less than 50.70% of C++ online submissions for Reverse Bits.
