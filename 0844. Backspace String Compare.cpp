class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return helper(s, t, s.length(), t.length());
    }
private:
    stack<char> s_st;
    stack<char> t_st;
    bool helper(string s, string t, int m, int n){
//         stack for s
        for (int i = 0; i < m; i++){
            char c = s[i];
            if (c == '#' && s_st.empty() == false){
                s_st.pop();
            }else if (c != '#'){
                s_st.push(c);
            }
        }
//         stack for t
        for (int i = 0; i < n; i++){
            char c = t[i];
            if (c == '#' && t_st.empty() == false){
                t_st.pop();
            }else if (c != '#'){
                t_st.push(c);
            }
        }
        return s_st == t_st;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
// Memory Usage: 6.4 MB, less than 26.80% of C++ online submissions for Backspace String Compare.
