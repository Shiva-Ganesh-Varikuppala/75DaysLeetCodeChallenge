class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        long long actualSum = 0;
        long long actualSqSum = 0;

        int N = grid.size() * grid.size();

        for (auto &row : grid) {
            for (int x : row) {
                actualSum += x;
                actualSqSum += 1LL * x * x;
            }
        }

        long long expectedSum = 1LL * N * (N + 1) / 2;
        long long expectedSqSum = 1LL * N * (N + 1) * (2LL * N + 1) / 6;

        long long diff = actualSum - expectedSum;              // a - b
        long long sum = (actualSqSum - expectedSqSum) / diff;  // a + b

        int repeated = (diff + sum) / 2;
        int missing = repeated - diff;

        return {repeated, missing};
    }
};
/* BRUTE-FORCE */
// vector<int> temp;

// for(int i = 0; i < grid.size(); i++){
//     for(int j = 0; j < grid[i].size(); j++){
//         temp.push_back(grid[i][j]);
//     }
// }

// sort(temp.begin(), temp.end());

// int repeated = 0;

// for (int i = 0; i < temp.size() - 1; i++) {
//     if (temp[i] == temp[i + 1]) {
//         repeated = temp[i];
//         break;
//     }
// }

// int sum = 0;
// for (int x : temp)
//     sum += x;

// sum -= repeated;

// int N = grid.size() * grid.size();
// int missing = N * (N + 1) / 2 - sum;

// return {repeated, missing};