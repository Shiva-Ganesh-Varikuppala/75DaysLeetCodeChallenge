class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_scores(n + 1, 0);
        
        for (const auto& relation : trust) {
            trust_scores[relation[0]]--;
            trust_scores[relation[1]]++;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (trust_scores[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};