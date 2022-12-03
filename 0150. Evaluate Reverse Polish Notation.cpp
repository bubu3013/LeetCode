class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        return helper(tokens);
    }
private:
    int helper(vector<string>& tokens) {
        stack<string> st;
        unordered_map<string> s = {"+","-","*","/"};
        for (auto& x: tokens){
            if (s.find(x) == s.end()){
                st.push(x);
            }else {
                string num_2 = st.top(); st.pop();
                string num_1 = st.top(); st.pop();
                if (x == "+"){
                    st.push(to_string(stoll(num_1) + stoll(num_2)));
                }else if (x == "-"){
                    st.push(to_string(stoll(num_1) - stoll(num_2)));
                }else if (x == "*"){
                    st.push(to_string(stoll(num_1) * stoll(num_2)));
                }else {
                    st.push(to_string(stoll(num_1) / stoll(num_2)));
                }
            }
        }
        string tmp = st.top();
        return stoi(tmp);
    }
};

// stoll: from string to long long int
// stoi: from string to int

// solution 2: with unordered_set

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        unordered_set<string> s = {"+","-","*","/"};

        for (auto& iter: tokens){
            if (s.find(iter) == s.end()){
                st.push(iter);
            }else{
                string num_2 = st.top(); st.pop();
                string num_1 = st.top(); st.pop();
                if (iter =="+"){
                    st.push(to_string(stoll(num_1) + stoll(num_2)));
                }else if (iter =="-"){
                    st.push(to_string(stoll(num_1) - stoll(num_2)));
                }
                else if (iter =="*"){
                    st.push(to_string(stoll(num_1) * stoll(num_2)));
                }
                else if (iter =="/"){
                    st.push(to_string(stoll(num_1) / stoll(num_2)));
                }
            }
        }
        string ans = st.top();
        return stoi(ans);
    }
};

// stoll: from string to long long int
// stoi: from string to int
// to_string(int/long long int ...)

// Runtime 15 ms Beats 79.5% 
// Memory 12.9 MB Beats 9.16%
