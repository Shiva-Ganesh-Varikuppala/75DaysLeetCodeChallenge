class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for (int pile : piles) {
            right = max(right, pile);
        }

        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hoursSpent = 0;

            for (int pile : piles) {
                hoursSpent += (pile + mid - 1) / mid;
            }

            if (hoursSpent <= h) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};