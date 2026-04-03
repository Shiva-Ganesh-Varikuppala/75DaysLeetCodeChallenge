/*
 * @lc app=leetcode id=2815 lang=cpp
 *
 * [2815] Max Pair Sum in an Array
 */
#include<algorithm>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSum(vector<int>& nums) {
        // Map: max digit (0-9) -> the two largest numbers having this max digit
        vector<pair<int,int>> best(10, {-1, -1}); // {largest, second largest}

        for (int x : nums) {
            int t = x;
            int mx = 0;
            while (t > 0) {
                mx = max(mx, t % 10);
                t /= 10;
            }

            auto &p = best[mx];
            if (x > p.first) {
                p.second = p.first;
                p.first = x;
            } else if (x > p.second) {
                p.second = x;
            }
        }

        int ans = -1;
        for (int d = 0; d < 10; d++) {
            if (best[d].first != -1 && best[d].second != -1) {
                ans = max(ans, best[d].first + best[d].second);
            }
        }
        return ans;
    }
};
// @lc code=end

