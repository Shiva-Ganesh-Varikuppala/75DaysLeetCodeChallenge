class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_element = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < min_element){
                min_element = nums[i];
            }
        }
        return min_element;
    }
};