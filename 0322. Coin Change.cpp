// solution 1: dp

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return helper(coins, amount);
    }
private:
    int helper(vector<int>& coins, int amount){
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        // buttom up
        for (int i = 1; i <= amount; i++){
            for (auto& coin: coins){
                // the current value is valid and the dp[current value] can be constructed by coins
                if (i - coin >= 0 && dp[i - coin] != INT_MAX){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1: dp[amount];
    }
};

// Runtime 164 ms Beats 52.36% 
// Memory 14.4 MB Beats 71.83%

// solution 2: 2022/12/03

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return helper(coins, amount);
    }
private:
    int helper(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (auto& coin: coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// Runtime 113 ms Beats 78.20% 
// Memory 14.4 MB Beats 71.63%
