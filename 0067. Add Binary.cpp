class Solution {
public:
    string addBinary(string a, string b) {
        //reverse strings
        //let the two strings have the same length 
        if (a.length() < b.length())
        {
            reverse(a.begin(), a.end());
            while (a.length() < b.length()){
                a.push_back('0');
            }
            reverse(b.begin(), b.end());
        }
        else if (a.length() > b.length())
        {
            reverse(b.begin(), b.end());
            while (a.length() > b.length()){
                b.push_back('0');
            }
            reverse(a.begin(), a.end());
        }
        else
        {
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
        }
        string ans = "";
        bool carry = false;

        for (int i = 0, j = 0; i < a.length(); i++, j++){
            if (a[i] == '1' && b[i] == '1' && carry)
            {
                carry = true;
                ans.push_back('1');
            }
            else if ((a[i] == '0' && b[i] == '1' && carry) || (a[i] == '1' && b[i] == '0' && carry) || (a[i] == '1' && b[i] == '1' && !carry))
            {
                carry = true;
                ans.push_back('0');
            }
            else if ((a[i] == '1' && b[i] == '0' && !carry) || (a[i] == '0' && b[i] == '1' && !carry) || (a[i] == '0' && b[i] == '0' && carry))
            {
                carry = false;
                ans.push_back('1');
            }
            else
            {
                carry = false;
                ans.push_back('0');
            }
        }
        //additional carry
        if (carry){
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Runtime 0 ms Beats 100%
// Memory 6.4 MB Beats 36.79%
