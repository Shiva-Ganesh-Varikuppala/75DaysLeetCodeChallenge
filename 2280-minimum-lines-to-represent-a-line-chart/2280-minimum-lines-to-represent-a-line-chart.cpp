#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if (n <= 1) return 0;          // no segment with <=1 point

        sort(stockPrices.begin(), stockPrices.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];   // sort by day (x)
             });

        if (n == 2) return 1;          // exactly one segment

        long long prevDx = stockPrices[1][0] - stockPrices[0][0];
        long long prevDy = stockPrices[1][1] - stockPrices[0][1];

        int lines = 1;                 // first segment

        for (int i = 2; i < n; ++i) {
            long long dx = stockPrices[i][0] - stockPrices[i - 1][0];
            long long dy = stockPrices[i][1] - stockPrices[i - 1][1];

            // Check if slope (prevDy / prevDx) == (dy / dx)
            // Using cross multiplication to avoid floating errors:
            if (prevDy * dx != dy * prevDx) {
                ++lines;
                prevDx = dx;
                prevDy = dy;
            }
        }

        return lines;
    }
};