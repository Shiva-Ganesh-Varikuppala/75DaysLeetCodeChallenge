class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited, int prevHeight) {
        int m = heights.size();
        int n = heights[0].size();
        
        if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }
        
        visited[r][c] = true;
        
        dfs(r + 1, c, heights, visited, heights[r][c]);
        dfs(r - 1, c, heights, visited, heights[r][c]);
        dfs(r, c + 1, heights, visited, heights[r][c]);
        dfs(r, c - 1, heights, visited, heights[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if (heights.empty() || heights[0].empty()) return result;
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            dfs(i, 0, heights, pacific, heights[i][0]);
            dfs(i, n - 1, heights, atlantic, heights[i][n - 1]);
        }
        
        for (int j = 0; j < n; ++j) {
            dfs(0, j, heights, pacific, heights[0][j]);
            dfs(m - 1, j, heights, atlantic, heights[m - 1][j]);
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};
