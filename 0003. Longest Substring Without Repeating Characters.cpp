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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return helper(s, s.length());
    }
private:
    int helper(string& s, int size){
        if (size == 0)return 0;

        int left = 0;
        int longest = 1; // we exclude the situation with the length of 0
        unordered_map<char, int> m; // <char, idx>
        for (int i = 0; i < size; i++){
            if (m.find(s[i]) == m.end()){ // no repetition
                m[s[i]] = i;
                longest = max(longest, i - left + 1);
            }else { // with repetition
                if (m[s[i]] < left){ // does not afftect the result if the left pointer is greater than the repetitive char, ex.'t'mmzux't'
                    longest = max(longest, i - left + 1);
                }else { // afftect the result if the left pointer is smaller than the repetitive char, we need a new starting point
                    left = max(m[s[i]] + 1, left); //exclude the repetitive one
                }
                m[s[i]] = i; // update the new position
            }
        }
        return longest;
    }
};

// Runtime 31 ms Beats 59.97% 
// Memory 8.3 MB Beats 76.5%
