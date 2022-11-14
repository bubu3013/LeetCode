class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return helper(s);
    }
private:
    unordered_map <char, int> m;
    int helper(string& s){
        int longest = 0;
        int cur = 0;
        int i = 0;
        int size = s.length();

        for (int j = 0; j < size; j++){ // within the string
            i = j;
            m.clear();
            cur = 0;
            while (m[s[i]] == 0 && i < size){ // no repeating
                m[s[i]] += 1;
                cur += 1;
                i++;
            }
            if (longest < cur){
                longest = cur;
            }
        }
        return longest;
    }
};

// Runtime 1780 ms Beats 5.1%
// Memory 150.5 MB Beats 6.9%
