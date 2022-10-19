class Solution {
public:
    int fib(int n) {
        if (n == 0)return 0;
        else if (n == 1)return 1;
        return fib(n-2) + fib(n-1);
    }
};

// Runtime: 14 ms, faster than 44.39% of C++ online submissions for Fibonacci Number.
// Memory Usage: 6 MB, less than 38.09% of C++ online submissions for Fibonacci Number.
