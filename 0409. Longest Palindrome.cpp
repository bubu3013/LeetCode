// solution 1 - build map and check
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> p;
        int count = 0;
        bool center = false;
        
        for (int i = 0; i < s.length(); i++){
            char c = s[i];
            if (p.find(c) == p.end()){
                p.insert(pair<char, int>(c, 1));
            }else{
                p[c]++;
            }
        }
        
        for (int i = 0; i < p.size(); i++){
            if (p[i] >= 2){
                count = count + p[i] / 2;
            }
            if (p[i] % 2 == 1){
                center = true;
            }
        }
        return count * 2 + center;
    }
};

// Runtime: 19 ms, faster than 5.30% of C++ online submissions for Longest Palindrome.
// Memory Usage: 7.4 MB, less than 5.32% of C++ online submissions for Longest Palindrome.
