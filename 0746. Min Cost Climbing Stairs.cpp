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

// solution 2: C 

int dp[1001];

int min(int a, int b){
    return (a < b) ? a : b;
}
int helper(int * cost, int n){
    if (n == 0)return dp[0];
    else if (n == 1)return dp[1];
    else if (dp[n] != (-1))return dp[n];
    return dp[n] = cost[n] + min(helper(cost, n - 2), helper(cost, n - 1));
}

int minCostClimbingStairs(int* cost, int costSize){
    if (costSize == 0)return cost[0];
    else if (costSize == 1) return min(cost[0], cost[1]);
    
    dp[0] = cost[0];
    dp[1] = cost[1];
    
    for (int i = 2; i < costSize; i++){
        dp[i] = -1;
    }
    
    int ans = min(helper(cost, costSize - 1), helper(cost, costSize - 2));
    return ans;
}

// I only seperate return XXXXX into 
// int ans = XXX
// return ans

// Runtime: 6 ms, faster than 79.79% of C online submissions for Min Cost Climbing Stairs.
// Memory Usage: 5.9 MB, less than 50.80% of C online submissions for Min Cost Climbing Stairs.
