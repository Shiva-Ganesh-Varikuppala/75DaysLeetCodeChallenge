class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> seen;

        for(int num1 : nums1){
            for(int num2 : nums2){
                if(num1 == num2 && !seen.count(num1)){
                    result.push_back(num1);
                    seen.insert(num1);
                    break;
                }
            }
        }
        return result;
    }
};