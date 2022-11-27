//solution 1: 
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

// solution 2:
// string to judge
class Solution {
public:
    string addBinary(string a, string b) {
        // 0. reverse them
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        return helper(a, b);
    }
private:
    string helper(string& a, string& b) {
        int i = 0;
        string c;
        bool cin = false; // for carry in
        // 1. append zero for the shorter string
        while (a.length() < b.length()){
            a += '0';
        }
        while (a.length() > b.length()) {
            b += '0';
        }
        // 2. sum the two strings
        while (i < a.length()){
            if (a[i] == '0' && b[i] == '0'){
                if (cin){
                    c += '1';
                    cin = false;
                }else{
                    c += '0';
                    cin = false;
                }
            }else if ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0')){
                if (cin){
                    c += '0';
                    cin = true;
                }else{
                    c += '1';
                    cin = false;
                }
            }else{ // a[i] == b[i] == '1'
                if (cin){
                    c += '1';
                    cin = true;
                }else{
                    c += '0';
                    cin = true;
                }
            }
            i++;
        }
        // 3. one extra carry in
        if (cin){
            c += '1';
        }
        // 4. reverse the string and return
        reverse(c.begin(), c.end());
        return c;
    }
};

// solution 3: concise method

// sum cin res
// 3   1    1
// 2   1    0
// 1   0    1
// 0   0    0  
// sum = a[i] + b[j] + cin
// cin = sum / 2
// res = sum % 2

class Solution {
public:
    string addBinary(string a, string b) {
        return helper(a, b);
    }
private:            
    string helper(string& a, string& b) {
        // add from the last
        int i = a.length() - 1; 
        int j = b.length() - 1;
        int sum = 0;
        int cin = 0;
        string res = "";
        while ( i >= 0 || j >= 0){
            // calculate how much is it in this digit
            sum = cin;
            // convert char to in
            if (i >= 0){
                sum += (a[i] - '0');
            } 
            if (j >= 0){
                sum += (b[j] - '0');
            } 
            cin = sum / 2;
            res = ((sum % 2 == 1) ? '1' : '0') + res; 
            i--; j--;
        }
        // the extra digit to add
        if (cin){
            res = '1' + res;
        }

        return res;
    }
};

// Runtime 3 ms Beats 82.36% 
// Memory 7 MB Beats 21.65%
