class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prevSum;
        int count = 0;
        int sum = 0;
        
        prevSum[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (prevSum.find(sum - k) != prevSum.end()) {
                count += prevSum[sum - k];
            }
            prevSum[sum]++;
        }
        
        return count;
    }
};