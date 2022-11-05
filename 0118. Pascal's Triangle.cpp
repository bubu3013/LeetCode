// solution 1: pascal's triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; i++){
            vector<int> ans;
            for (int j = 0; j <= i; j++){
                if (j == 0 || i == j){
                    ans.push_back(1);
                }
                else{
                    ans.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                } 
            }
            res.push_back(ans);
        }
        return res;
    }
};

// Runtime 0 ms Beats 100%
// Memory 6.5 MB Beats 70.24%
