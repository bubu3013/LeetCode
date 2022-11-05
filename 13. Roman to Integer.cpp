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
