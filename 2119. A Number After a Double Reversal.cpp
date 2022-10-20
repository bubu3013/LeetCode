class Solution {
public:
    bool isSameAfterReversals(int num) {
        return (num == 0 || num % 10 != 0);
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for A Number After a Double Reversal.
// Memory Usage: 5.8 MB, less than 87.94% of C++ online submissions for A Number After a Double Reversal.
