class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = cost[0];
        int second = cost[1];
        int n = cost.size();
        
        for (int i = 2; i < n; ++i) {
            int current = cost[i] + min(first, second);
            first = second;
            second = current;
        }
        
        return min(first, second);
    }
};