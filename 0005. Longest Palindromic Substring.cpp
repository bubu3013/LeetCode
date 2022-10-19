class Solution {
public:
    vector <vector<int>> dp;
    int isPalin(string &s, int i, int j){
//         base 
        if (i >= j) return 1;
        else if (dp[i][j] != (-1)) return dp[i][j]; 
//         recursion
        else if (s[i] == s[j]){
//             to check if the next iteration is the same 
            return dp[i][j] = isPalin(s, i + 1, j -1);
        }
//         if the current case is different 
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int max = 0;
        string ans = "";
        dp.resize(n, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
//                 to check if 
//                 (1) it is longer than the max
//                 (2) the substring from i to j is palindromic
                if ((j - i + 1) > max && isPalin(s, i, j)){
                    ans = s.substr(i, j - i + 1);
                    max = j - i + 1;
                }
            }
        }
        return ans;
    }
};

// Runtime: 784 ms, faster than 15.01% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 287.2 MB, less than 7.53% of C++ online submissions for Longest Palindromic Substring.
