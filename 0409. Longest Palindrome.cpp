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

// solution 2: 2022/11/25

class Solution {
public:
    int longestPalindrome(string s) {
        return helper(s);
    }
private:
    int helper(string& s){
        unordered_map<char, int> m;
        int n = s.length();
        int ans = 0;
        int count = 0;
        bool with_center = false;
        
        for (int i = 0; i < n; i++){
            m[s[i]]++;
        }
        for (auto& x: m){
            if (m[x.first] >= 2){ // can build panlindrome
                count += m[x.first] / 2;
            }
            if (m[x.first] % 2 == 1){// odd with center
                with_center = true;
            }
        }
        return with_center ? count * 2 + 1 : count * 2;
    }
};

// Runtime 0 ms Beats 100% 
// Memory 6.7 MB Beats 49.99%
