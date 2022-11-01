class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return helper(s, t) && helper(t, s); // (1)
    }
private:
    bool helper(string s, string t){
        unordered_map <char, char> m;
        int n = s.length();

        for (int i = 0; i < n; i++){
            char key = s[i];
            char value = t[i];
            if (m.find(key) != m.end()){
                if (m[key] != value){
                    return false;
                }
            }else {
                m[key] = value;
            }
        }
        return true;
    }
};

// (1) to avoid: "badc" "baba"
// No two characters may map to the same character
// helper(s, t)
// b: b
// a: a (!
// d: b
// c: a (!
// helper(t, s)，反過來做就會得到collision。
// b: b
// a: a (!
// b: d
// a: c (!
// now both 'c' and 'a' map to 'a'

// Runtime: 14 ms, faster than 54.66% of C++ online submissions for Isomorphic Strings.
// Memory Usage: 7.2 MB, less than 19.27% of C++ online submissions for Isomorphic Strings.
