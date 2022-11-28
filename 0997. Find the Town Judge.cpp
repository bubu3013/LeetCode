class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        return helper(n, trust);
    }
private:
    int helper(int n, vector<vector<int>>& trust){
        unordered_map<int, int> out_deg;
        unordered_map<int, int> in_deg;
        for (int i = 1; i <= n; i++){
            in_deg[i] = 0;
            out_deg[i] = 0;
        }
        // if i is trusted, then in_deg[i]++
        // if i trust sb, then out_deg[i]++
        for (auto& x: trust){
            out_deg[x[0]]++;
            in_deg[x[1]]++;
        }
        int judge = -1;
        for (int i = 1; i <= n; i++){
            if (in_deg[i] == n - 1 && out_deg[i] == 0){
                judge = i;
                break;
            }
        }
        return judge;
    }
};

// Runtime 246 ms Beats 78.58% 
// Memory 62.3 MB Beats 56.57%
