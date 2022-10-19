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
