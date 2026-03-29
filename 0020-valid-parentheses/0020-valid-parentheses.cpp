class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> mp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            // If closing bracket
            if (mp.count(c)) {
                // Check if stack is empty or mismatch
                if (st.empty() || st.top() != mp[c])
                    return false;
                st.pop();
            } else {
                // Opening bracket
                st.push(c);
            }
        }

        return st.empty();
    }
};