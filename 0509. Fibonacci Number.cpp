// solution 1 : C++

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

// solution 2: C

int dp [31] = {0};
int helper(int n){
    if (n == 0)return 0;
    else if (n == 1)return 1;
    else if (dp[n] != 0)return dp[n];
    return dp[n] = helper(n - 2) + helper(n - 1);
}

int fib(int n){
    if (n == 0)return 0;
    else if (n == 1)return 1;
    
    dp[0] = 0;
    dp[1] = 1;
    return helper(n);
}

//Runtime: 0 ms, faster than 100.00% of C online submissions for Fibonacci Number.
// Memory Usage: 5.4 MB, less than 95.22% of C online submissions for Fibonacci Number.
