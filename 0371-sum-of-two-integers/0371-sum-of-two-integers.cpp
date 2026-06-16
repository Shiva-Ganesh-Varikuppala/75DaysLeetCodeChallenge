class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // Find the carry bits
            int carry = a & b;
            
            // Sum without carrying
            a = a ^ b;
            
            // Shift carry to the left to add it in the next iteration
            // Casting to unsigned int prevents undefined behavior with negative left shifts in C++
            b = (unsigned int)carry << 1;
        }
        return a;
    }
};