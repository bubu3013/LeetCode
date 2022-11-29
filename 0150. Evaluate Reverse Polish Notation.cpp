class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        return helper(tokens);
    }
private:
    int helper(vector<string>& tokens) {
        stack<string> st;
        unordered_map<string, > s = {"+","-","*","/"};
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
