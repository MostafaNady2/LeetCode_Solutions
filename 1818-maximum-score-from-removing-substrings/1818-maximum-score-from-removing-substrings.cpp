class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans1 = 0;
        if (x > y) {
            for (char c : s) {
                if (!st.empty() && st.top() == 'a' && c == 'b') {
                    ans1 += x;
                    st.pop();
                } else {
                    st.push(c);
                }
            }
            string m;
            while (!st.empty()) {
                m += st.top();
                st.pop();
            }
            reverse(m.begin(), m.end());
            for (char c : m) {
                if (!st.empty() && st.top() == 'b' && c == 'a') {
                    ans1 += y;
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        } else {
            for (char c : s) {
                if (!st.empty() && st.top() == 'b' && c == 'a') {
                    ans1 += y;
                    st.pop();
                } else {
                    st.push(c);
                }
            }
            string m;
            while (!st.empty()) {
                m += st.top();
                st.pop();
            }
            reverse(m.begin(), m.end());
            for (char c : m) {
                if (!st.empty() && st.top() == 'a' && c == 'b') {
                    ans1 += x;
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }
        return ans1;
    }
};