class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        
        while (n != 0) {
            n = n & (n - 1); // Clears the lowest set bit
            count++;         // Increment count for each cleared bit
        }
        
        return count;
    }
};