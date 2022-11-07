class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() == 1)return 1;
        return helper(s);
    }
private:
    int helper(string s){
        int start = s.length() - 1;
        int end = s.length() - 1;
        //   char compare with ' ' (single quote)
        while(s[end] == ' '){
            end--;
        }
        start = end;//the length of the string may equals to 1

        while (s[start] != ' '){
            start--;
            if (start == -1)break;
        }
        return end - start;
    }
};

// Runtime 3 ms Beats 71.54%
// Memory 6.5 MB Beats 51.49%
