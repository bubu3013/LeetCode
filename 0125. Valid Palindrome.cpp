class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 1)return true;
        return helper(s, 0, s.length()-1);
    }
private:
    bool helper(string s, int left, int right)
    {
        while(left <= right)
        {
            if (left == right)return true;
            while(isalpha(s[left]) == false && isdigit(s[left]) == false && (left <= right))
            {
                left++;
            }
            while(isalpha(s[right]) == false && isdigit(s[right]) == false && (left <= right)){
                right--;
            }
            if ((isalpha(s[left]) || isdigit(s[left])) && (isalpha(s[right]) || isdigit(s[right]))&& tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }  
            else 
            {
                left++;right--;
            }
        }
        return true;
    }
};

// Runtime 3 ms Beats 97.56%
// Memory 7.6 MB Beats 49.56%
