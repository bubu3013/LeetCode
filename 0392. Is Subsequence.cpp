using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length())return false;
        int idx = 0;
        for (int i = 0; i < t.length(); i++){
            if (s[idx] == t[i]){
                idx++;
            }
        }
        if (idx != s.length())return false;
        return true;
    }
};

// Two pointer
// to check is s[idx] is a letter of t
// if true, then check the next character of s by idx++
// in the end,
// if all characters of s are checked, then s is a subsequence of s
// else s is not a subsequence of t.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Is Subsequence.
// Memory Usage: 6.4 MB, less than 23.70% of C++ online submissions for Is Subsequence.
