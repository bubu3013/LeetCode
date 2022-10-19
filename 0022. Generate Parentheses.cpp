class Solution {
public:
    vector <string> ans;
    void generator(string str, int left, int right){
//         when we do not need any "(" and ")"
        if (left == 0 && right == 0){
            ans.push_back(str);
            return;
        }
//         if we still need any "("
        if (left > 0)generator(str + "(", left - 1, right);
//         if we still need any ")"
        if (right > left)generator(str + ")", left, right - 1);
        return;
    }
    vector<string> generateParenthesis(int n) {
        generator ("", n, n);
        return ans;
    }
};

// Runtime: 7 ms, faster than 59.39% of C++ online submissions for Generate Parentheses.
// Memory Usage: 13.9 MB, less than 36.28% of C++ online submissions for Generate Parentheses.
