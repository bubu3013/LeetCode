// solution 1: c

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

// solution 2: c++

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)return 1;
        return path(0, 0, m, n);
    }
private:
    vector<vector<int>> dp;
    int path(int i, int j, int m, int n){
        dp.resize(105, vector<int> (105, -1));
        return helper(i, j, m, n);
    }
    int helper(int i, int j, int m, int n){
        if (i < 0 || i >= m || j < 0 || j >= n){
            return 0;
        }
        else if (dp[i][j] != -1){
            return dp[i][j];
        }
        else if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        return dp[i][j] = helper(i + 1, j, m, n) + helper(i, j + 1, m, n);
    }
};


// Runtime 0 ms Beats 100%
// Memory 9.7 MB Beats 29.70%
