#include <vector>
using namespace std;

class Solution {
public:
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};
    vector<pair<int, int>> emptyCells;

    void solveSudoku(vector<vector<char>>& board) {
        // Initialize bitmasks and collect empty cells
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '1';
                    setMask(i, j, val);
                } else {
                    emptyCells.push_back({i, j});
                }
            }
        }
        backtrack(board, 0);
    }

    void setMask(int i, int j, int val) {
        rows[i] |= (1 << val);
        cols[j] |= (1 << val);
        boxes[(i / 3) * 3 + j / 3] |= (1 << val);
    }

    void clearMask(int i, int j, int val) {
        rows[i] &= ~(1 << val);
        cols[j] &= ~(1 << val);
        boxes[(i / 3) * 3 + j / 3] &= ~(1 << val);
    }

    bool canPlace(int i, int j, int val) {
        int mask = 1 << val;
        int boxIndex = (i / 3) * 3 + j / 3;
        return !(rows[i] & mask) && !(cols[j] & mask) && !(boxes[boxIndex] & mask);
    }

    bool backtrack(vector<vector<char>>& board, int idx) {
        if (idx == emptyCells.size()) return true;

        int i = emptyCells[idx].first;
        int j = emptyCells[idx].second;
        int boxIndex = (i / 3) * 3 + j / 3;

        int mask = ~(rows[i] | cols[j] | boxes[boxIndex]) & 0x1FF; // Possible digits

        while (mask) {
            int bit = mask & -mask; // lowest set bit
            int val = __builtin_ctz(bit); // bit position (0-8)
            mask ^= bit; // remove current bit

            board[i][j] = val + '1';
            setMask(i, j, val);

            if (backtrack(board, idx + 1)) return true;

            clearMask(i, j, val);
            board[i][j] = '.';
        }

        return false;
    }
};
