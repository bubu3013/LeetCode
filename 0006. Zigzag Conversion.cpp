class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        return helper(s, numRows);
    }
private:
    vector<string> v;
    string helper(string& s, int numRows){
        int i = 0;
        int j = 0;
        int n = s.size();
        bool isFirst = true;
        v.resize(numRows);
        while (i < n){
            j = isFirst ? 0 : 1;
            isFirst = false;
            while (j < numRows && i < n){
                v[j].push_back(s[i]);
                j++; i++;
            }
            //notice for being out of range!
            j = j - 2;
            while (j >= 0 && i < n){
                v[j].push_back(s[i]);
                j--; i++;
            }
        }
        string res = "";
        for (int m = 0; m < numRows; m++){
            res += v[m];
        }
        return res;
    }
};

// Runtime 17 ms Beats 74.67%
// Memory 10.7 MB Beats 40.83%
