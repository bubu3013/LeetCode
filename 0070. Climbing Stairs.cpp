class Solution {
public:
    vector <int> step;
    int climb(int n){
        if (step[n] != -1) return step[n]; //basic case
        return step[n] = climb(n - 1) + climb(n - 2); //recursive case
    }
    int climbStairs(int n) {
//       vector initialization needs to be in functions
        step.resize(n + 1, -1); //cuz we from 0 to n --> # of total elements = n + 1
        step[0] = 1; //set up the base case
        step[1] = 1; //set up the base case
        return climb(n);
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 6.2 MB, less than 31.38% of C++ online submissions for Climbing Stairs.

class Solution {
public:
    vector <int> steps;
    int climb(int n){
        if (steps[n] != (-1))return steps[n];
        return steps[n] = climb(n - 2) + climb(n - 1);
    }
    int climbStairs(int n) {
        if (n == 1)return 1;
        steps.resize(n + 1, -1);
        steps[1] = 1;
        steps[2] = 2;
        return climb(n);
    }
};
// the n-th stair is the outcome of (n-1)th stair + (n-2)th stair
// 1. climb(n) = climb(n-1)+climb(n-2)
// 2. steps[n] to store the calculated outcomes

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 6.2 MB, less than 15.78% of C++ online submissions for Climbing Stairs.
