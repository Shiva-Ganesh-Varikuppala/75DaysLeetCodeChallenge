class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Compute sum of first window
        long long windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        
        long long maxSum = windowSum;
        
        // Step 2: Slide the window
        for (int i = k; i < n; i++) {
            windowSum += nums[i];      // add next element
            windowSum -= nums[i - k];  // remove left element
            
            maxSum = max(maxSum, windowSum);
        }
        
        // Step 3: Return max average
        return (double)maxSum / k;
    }
};