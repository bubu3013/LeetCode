using namespace std;
class Solution {
public:
    vector <int> dp;
    int minCost(int n, vector<int>& cost){
//         basic case
        if (n < 0)return 0;
        if (dp[n] != (-1)){return dp[n];}
//         recursive case
//         the current cost of n-th starircase is "the current cost" + the min cost of backward 1 or 2 step(s) 
        return dp[n] = cost[n] + min(minCost(n - 1, cost), minCost(n - 2, cost)); 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(cost.size() + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
//       from the top backward 1 step or 2 steps 
        return min(minCost(n - 1, cost), minCost(n - 2, cost));
    }
};

// Runtime: 15 ms, faster than 40.68% of C++ online submissions for Min Cost Climbing Stairs.
// Memory Usage: 13.8 MB, less than 31.29% of C++ online submissions for Min Cost Climbing Stairs.

