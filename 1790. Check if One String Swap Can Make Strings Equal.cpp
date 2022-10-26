class Solution {
public:
    bool areAlmostEqual(string s, string t) {
        if (s == t)return true;
        
        map <char, char> m;
        int count = 0;
//         check if one string can swap to make equal
        for (int i = 0; i < s.length(); i++){
            if (s[i] != t[i]){
                count++;
                if (count == 1){ // the first time diff
                    m[s[i]] = t[i];
                }else if (count == 2){ // the second time diff
                    if (m[t[i]] == s[i]){ //can swap
                        m.erase(t[i]);
                    }else if (m[t[i] != s[i]]){ //cannot swap
                        return false;
                    } 
                }else{ //if count is more than 3 -> 3 diff
                    return false;
                }
            }
            cout<<m.size()<<" ";
        }
        if (m.size() == 0)return true;
        else return false;
    }
};

// Runtime: 8 ms, faster than 14.19% of C++ online submissions for Check if One String Swap Can Make Strings Equal.
// Memory Usage: 6.1 MB, less than 87.27% of C++ online submissions for Check if One String Swap Can Make Strings Equal.
