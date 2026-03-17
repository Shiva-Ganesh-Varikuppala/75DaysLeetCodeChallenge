class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        
        for(int n : nums)
            freq[n]++;
        
        int n = nums.size();
        
        vector<vector<int>> bucket(n + 1);
        
        for(auto &p : freq)
            bucket[p.second].push_back(p.first);
        
        vector<int> result;
        
        for(int i = n; i >= 0 && result.size() < k; i--) {
            for(int num : bucket[i]) {
                result.push_back(num);
                if(result.size() == k)
                    break;
            }
        }
        
        return result;
    }
};