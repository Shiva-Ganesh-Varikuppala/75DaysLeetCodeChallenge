class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;

        vector<int> s1_freq(26, 0), window_freq(26, 0);
        for (int i = 0; i < n1; i++) {
            s1_freq[s1[i] - 'a']++;
            window_freq[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1_freq[i] == window_freq[i]) matches++;
        }

        for (int i = 0; i < n2 - n1; i++) {
            if (matches == 26) return true;

            int right = s2[i + n1] - 'a';
            window_freq[right]++;
            if (window_freq[right] == s1_freq[right]) {
                matches++;
            } else if (window_freq[right] == s1_freq[right] + 1) {
                matches--;
            }

            int left = s2[i] - 'a';
            window_freq[left]--;
            if (window_freq[left] == s1_freq[left]) {
                matches++;
            } else if (window_freq[left] == s1_freq[left] - 1) {
                matches--;
            }
        }

        return matches == 26;
    }
};