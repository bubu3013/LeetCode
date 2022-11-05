// solution 1: 
class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int n = s.length();
        int ans = 0;

        while (i < n){
            if (s[i] == 'C' && s[i + 1] == 'M'){
                ans += 900;
                i += 2;
            }
            else if (s[i] == 'M' ){
                ans += 1000;
                i += 1;
            }
            else if (s[i] == 'C' && s[i + 1] == 'D'){
                ans += 400;
                i += 2;
            }
            else if (s[i] == 'D'){
                ans += 500;
                i += 1;
            }
            else if (s[i] == 'X' && s[i + 1] == 'C'){
                ans += 90;
                i += 2;
            }
            else if (s[i] == 'C'){
                ans += 100;
                i += 1;
            }
            else if (s[i] == 'X' && s[i + 1] == 'L'){
                ans += 40;
                i += 2;
            }
            else if (s[i] == 'L'){
                ans += 50;
                i += 1;
            }
            else if (s[i] == 'I' && s[i + 1] == 'X'){
                ans += 9;
                i += 2;
            }
            else if (s[i] == 'X'){
                ans += 10;
                i += 1;
            }
            else if (s[i] == 'I' && s[i + 1] == 'V'){
                ans += 4;
                i += 2;
            }
            else if (s[i] == 'V'){
                ans += 5;
                i += 1;
            }
            else if (s[i] == 'I'){
                ans += 1;
                i += 1;
            }
        }
        return ans;
    }
};

// Runtime 17 ms Beats 65.99%
// Memory 6 MB Beats 87.48%

// solution 2: hashmap

class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int n = s.length();
       return helper(s, n);
    }
private:
    unordered_map <char, int> m;
    int helper(string s, int n)
    {
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int i = 0;
        int ans = 0;
        while (i < n){
            if (s[i] == 'I' && s[i + 1] == 'V'){
                ans += 4;
                i += 2;
            }
            else if (s[i] == 'I' && s[i + 1] == 'X'){
                ans += 9;
                i += 2;
            }
            else if (s[i] == 'X' && s[i + 1] == 'L'){
                ans += 40;
                i += 2;
            }
            else if (s[i] == 'X' && s[i + 1] == 'C'){
                ans += 90;
                i += 2;
            }
            else if (s[i] == 'C' && s[i + 1] == 'D'){
                ans += 400;
                i += 2;
            }
            else if (s[i] == 'C' && s[i + 1] == 'M'){
                ans += 900;
                i += 2;
            }
            else{
                ans += m[s[i]];
                i += 1;
            } 
        }
        return ans;
    }
};

// Runtime 15 ms Beats 74.1%
// Memory 8.1 MB Beats 41.46%
