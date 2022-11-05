class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        vector<int> v;
        for (int i = 0; i <= rowIndex; i++){
            vector<int> ans;
            for (int j = 0; j <= i; j++){
                if (j == 0 || i == j){
                    ans.push_back(1);
                }
                else{
                    ans.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
            }
            if (i == rowIndex){
                v = ans;
                break;
            }
            res.push_back(ans);
        }
        return v;
    }
};

// Runtime 0 ms Beats 100%
// Memory 6.6 MB Beats 18.5%
