int helper(int dp[105][105], int i, int j, int m, int n){
//     base case
    if (i >= m || j >= n){
        return 0;
    }
    if (i == m - 1 && j == n - 1){
        return 1;
    }
    if (dp[i][j] != 0)return dp[i][j];
//     go down & right 
    return dp[i][j] = helper(dp, i + 1, j, m, n) + helper(dp, i, j + 1, m, n);
}

int uniquePaths(int m, int n){
    int dp[105][105] = {0};
    int ans = helper(dp, 0, 0, m, n);
    return ans;
}

// Runtime: 0 ms, faster than 100.00% of C online submissions for Unique Paths.
// Memory Usage: 5.6 MB, less than 35.28% of C online submissions for Unique Paths.
