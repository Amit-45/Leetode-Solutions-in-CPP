class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (st.empty()) {
                    return false;
                }
                char topChar = st.top();
                st.pop();
                if ((s[i] == ')' && topChar != '(') ||
                    (s[i] == ']' && topChar != '[') ||
                    (s[i] == '}' && topChar != '{')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
